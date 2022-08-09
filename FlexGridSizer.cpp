//
// Created by Diego De Grazia on 09/08/22.
//

#include "FlexGridSizer.h"
#include <string.h>

static int rows = 10;
static int columns = 10;

FlexGridSizer::FlexGridSizer(const wxString &title)
        : wxFrame(NULL, -1, title, wxPoint(), wxSize(-1, -1)) {
    menubar = new wxMenuBar;
    file = new wxMenu;

    SetMenuBar(menubar);

    sizer = new wxBoxSizer(wxVERTICAL);

    fgs = new wxFlexGridSizer(rows + 1, columns + 1, -1, -1);

    for (int i = 0; i < rows + 1; i++) {
        for (int j = 0; j < columns + 1; j++) {
            auto tmp = new wxTextCtrl(this, -1, wxT(""), wxPoint(),
                                      wxSize(-1, 40), wxTE_RIGHT);
            if (j == 0 && i != 0) {
                tmp->SetValue(std::to_string(i));
                //tmp->SetDefaultStyle(wxTextAttr(wxNullColour, *wxLIGHT_GREY));
            } else if (i == 0 && j != 0) {
                tmp->SetValue(char(64 + j));
                //tmp->SetDefaultStyle(wxTextAttr(wxNullColour, *wx));
            }

            fgs->Add(tmp, 0, wxEXPAND);
        }
    }

    sizer->Add(fgs, 1, wxEXPAND);
    SetSizer(sizer);
    SetMinSize(wxSize(270, 220));

    Centre();
}