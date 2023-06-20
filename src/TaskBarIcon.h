#pragma once

#include <eventpp/callbacklist.h>
#include <wx/wx.h>
#include <wx/taskbar.h>

namespace twt
{
    class TaskBarIcon : public wxTaskBarIcon
    {
        public:
            eventpp::CallbackList<void()> onRestore;
            eventpp::CallbackList<void()> onExit;

        public:
            TaskBarIcon();
            virtual wxMenu *CreatePopupMenu() override;

        private:
            void OnMenuRestore(wxCommandEvent &event);
            void OnMenuExit(wxCommandEvent &event);

        wxDECLARE_EVENT_TABLE();
    };
}