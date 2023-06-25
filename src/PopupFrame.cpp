#include <wx/artprov.h>
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

    textInput = new wxTextCtrl(this, -1);

    textInput->Bind(wxEVT_KILL_FOCUS, &twt::PopupFrame::OnFocusLost, this);
    textInput->Bind(wxEVT_KEY_DOWN, &twt::PopupFrame::OnKeyDown, this);
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
    Exit();
}

void twt::PopupFrame::OnKeyDown(wxKeyEvent &event)
{
    if (event.GetKeyCode() == WXK_ESCAPE) 
    {
        Exit();
    }
    
    event.Skip();
}