#pragma once

#include <memory>
#include <wx/wx.h>
#include "TaskBarIcon.h"
#include "TimeService.h"

namespace twt
{
    class PopupFrame : public wxFrame
    {
        public:
            PopupFrame();

        private:
            void Restore();
            void Exit();

            void OnFocusLost(wxFocusEvent &event);
            void OnKeyDown(wxKeyEvent &event);

            void UpdateEntryList();

        private:
            twt::TimeService timeService;
            std::shared_ptr<twt::TaskBarIcon> taskBarIcon;

            wxFlexGridSizer *timeEntrySizer;
            wxTextCtrl *textInput;
    };
}