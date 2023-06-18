#include "Application.h"
#include "PopupFrame.h"

bool twt::Application::OnInit() 
{
    PopupFrame *frame = new PopupFrame();
    frame->Show(true);
    return true;
}