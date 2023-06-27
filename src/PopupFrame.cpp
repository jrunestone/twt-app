#include <wx/artprov.h>
#include <fmt/core.h>
#include "PopupFrame.h"

twt::PopupFrame::PopupFrame() : wxFrame(nullptr, 
                                        wxID_ANY, 
                                        "Time will tell",
                                        wxDefaultPosition,
                                        wxSize(400, 50),
                                        wxFRAME_TOOL_WINDOW | wxNO_BORDER | wxFRAME_NO_TASKBAR)
{
    taskBarIcon = std::make_shared<twt::TaskBarIcon>();
    
    taskBarIcon->SetIcon(wxArtProvider::GetBitmapBundle(wxART_WX_LOGO, wxART_OTHER, wxSize(32, 32)), "Time will tell");
    taskBarIcon->onRestore.append(std::bind(&twt::PopupFrame::Restore, this));
    taskBarIcon->onExit.append(std::bind(&twt::PopupFrame::Exit, this));

    // main sizer
    wxBoxSizer *topSizer = new wxBoxSizer(wxVERTICAL);

    // main input
    textInput = new wxTextCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxSize(400, 50));

    textInput->Bind(wxEVT_KILL_FOCUS, &twt::PopupFrame::OnFocusLost, this);
    textInput->Bind(wxEVT_KEY_DOWN, &twt::PopupFrame::OnKeyDown, this);

    topSizer->Add(textInput, wxSizerFlags().Expand());

    // time entries
    timeEntrySizer = new wxFlexGridSizer(4, 3, 10);
    topSizer->Add(timeEntrySizer);

    // fin
    SetSizerAndFit(topSizer);
}

void twt::PopupFrame::Restore()
{
    Show(true);
    SetFocus();
}

void twt::PopupFrame::Exit()
{
    Close(true);
}

void twt::PopupFrame::OnFocusLost(wxFocusEvent &event)
{
    event.Skip();
    Hide();
}

void twt::PopupFrame::OnKeyDown(wxKeyEvent &event)
{
    if (event.GetKeyCode() == WXK_ESCAPE) 
    {
        Hide();
    }
    else if (event.GetKeyCode() == WXK_RETURN)
    {
        timeService.StartNewEntry(textInput->GetValue().ToStdString());
        UpdateEntryList();
        textInput->Clear();
    }

    event.Skip();
}

void twt::PopupFrame::UpdateEntryList()
{
    const auto entries = timeService.GetEntries();
    timeEntrySizer->Clear(true);

    for (auto entry : entries)
    {
        timeEntrySizer->Add(new wxStaticText(this, -1, wxString(entry.FormatTimestamp())), wxSizerFlags().Left().Expand());
        timeEntrySizer->Add(new wxStaticText(this, -1, wxString(entry.label)), wxSizerFlags().Expand());
        timeEntrySizer->Add(new wxStaticText(this, -1, wxString(entry.FormatDuration())), wxSizerFlags().Expand());
        timeEntrySizer->Add(new wxStaticText(this, -1, wxString("[o]")), wxSizerFlags().Right().Expand());
    }

    Fit();
}