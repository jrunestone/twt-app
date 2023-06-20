#include "TaskBarIcon.h"

enum
{
    PU_RESTORE = 10001,
    PU_EXIT
};

wxBEGIN_EVENT_TABLE(twt::TaskBarIcon, wxTaskBarIcon)
    EVT_MENU(PU_RESTORE, twt::TaskBarIcon::OnMenuRestore)
    EVT_MENU(PU_EXIT, twt::TaskBarIcon::OnMenuExit)
wxEND_EVENT_TABLE()

twt::TaskBarIcon::TaskBarIcon()
{

}

void twt::TaskBarIcon::OnMenuRestore(wxCommandEvent&)
{
    onRestore();
}

void twt::TaskBarIcon::OnMenuExit(wxCommandEvent&)
{
    onExit();
}

wxMenu *twt::TaskBarIcon::CreatePopupMenu()
{
    wxMenu *menu = new wxMenu;

    menu->Append(PU_RESTORE, "Open Time will tell");
    // menu->AppendSeparator();
    menu->Append(PU_EXIT, "E&xit");

    return menu;
}