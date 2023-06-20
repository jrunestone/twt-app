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

        private:
            std::shared_ptr<twt::TaskBarIcon> taskBarIcon;
    };
}