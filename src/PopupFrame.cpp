#include <wx/artprov.h>
#include "PopupFrame.h"

twt::PopupFrame::PopupFrame() : wxFrame(nullptr, 
                                        wxID_ANY, 
                                        "Time will tell",
                                        wxDefaultPosition,
                                        wxSize(400, 150),
                                        wxFRAME_TOOL_WINDOW | wxNO_BORDER | wxFRAME_NO_TASKBAR)
{
    taskBarIcon = std::make_shared<twt::TaskBarIcon>();
    
    taskBarIcon->SetIcon(wxArtProvider::GetBitmapBundle(wxART_WX_LOGO, wxART_OTHER, wxSize(32, 32)), "Time will tell");
    taskBarIcon->onRestore.append(std::bind(&twt::PopupFrame::Restore, this));
    taskBarIcon->onExit.append(std::bind(&twt::PopupFrame::Exit, this));
}

void twt::PopupFrame::Restore()
{
    Show(true);
    SetFocus();
}

void twt::PopupFrame::Exit()
{
    Close();
}