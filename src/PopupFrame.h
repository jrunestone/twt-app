#pragma once

#include <memory>
#include <wx/wx.h>
#include "TaskBarIcon.h"

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

        private:
            std::shared_ptr<twt::TaskBarIcon> taskBarIcon;
            wxTextCtrl *textInput;
    };
}