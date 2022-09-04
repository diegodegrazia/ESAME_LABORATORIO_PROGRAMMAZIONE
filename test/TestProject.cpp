//
// Created by Diego De Grazia on 04/09/22.
//

#include "TestProject.h"

bool TestProject::OnInit() {
    fgs = new FlexGridSizer(wxT("Foglio di calcolo"));
    fgs->Show(false);
    return true;
}