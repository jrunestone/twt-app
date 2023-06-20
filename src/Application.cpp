#include "Application.h"
#include "PopupFrame.h"

bool twt::Application::OnInit() 
{
    PopupFrame *frame = new PopupFrame();
    frame->CenterOnScreen();
    frame->Show(true);
    frame->SetFocus();

    return true;
}