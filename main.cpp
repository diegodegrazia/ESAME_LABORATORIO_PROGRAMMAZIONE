#include <iostream>
#include "main.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {
    FlexGridSizer *fgs = new FlexGridSizer(wxT("Foglio di calcolo"));
    fgs->Show(true);
    fgs->Maximize(true);

    return true;
}