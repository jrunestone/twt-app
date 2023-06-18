#pragma once

#include <wx/wx.h>

namespace twt
{
    class Application : public wxApp 
    {
        public:
            bool OnInit() override;
    };
}