#pragma once

#include <wx/wx.h>
#include <wx/taskbar.h>

namespace twt
{
    class TaskBarIcon : public wxTaskBarIcon
    {
        public:
            TaskBarIcon();

            void OnMenuRestore(wxCommandEvent&);
            void OnMenuExit(wxCommandEvent&);
            virtual wxMenu *CreatePopupMenu() override;

            wxDECLARE_EVENT_TABLE();
    };
}