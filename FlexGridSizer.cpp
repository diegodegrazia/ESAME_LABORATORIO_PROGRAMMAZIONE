//
// Created by Diego De Grazia on 09/08/22.
//

#include "FlexGridSizer.h"
#include <string.h>

static int rows = 10;
static int columns = 8;

FlexGridSizer::FlexGridSizer(const wxString &title)
        : wxFrame(NULL, -1, title, wxPoint(), wxSize(-1, -1)) {
    menubar = new wxMenuBar;
    file = new wxMenu;

    SetMenuBar(menubar);

    sizer = new wxBoxSizer(wxVERTICAL);

    fgs = new wxFlexGridSizer(rows + 1, columns, -1, -1);

    fgs_2 = new wxFlexGridSizer(1, columns, -1, -1);

    auto max = new wxTextCtrl(this, -1, wxT("Max"), wxPoint(),
                              wxSize(-1, 40), wxTE_READONLY | wxTE_CENTER);
    auto min = new wxTextCtrl(this, -1, wxT("Min"), wxPoint(),
                              wxSize(-1, 40), wxTE_READONLY | wxTE_CENTER);
    auto mean = new wxTextCtrl(this, -1, wxT("Mean"), wxPoint(),
                               wxSize(-1, 40), wxTE_READONLY | wxTE_CENTER);
    auto sum = new wxTextCtrl(this, -1, wxT("Sum"), wxPoint(),
                              wxSize(-1, 40), wxTE_READONLY | wxTE_CENTER);

    for (int j = 0; j < columns; j++) {
        switch (j) {
            case 0:
                fgs_2->Add(max, 0, wxEXPAND);
                break;
            case 2:
                fgs_2->Add(min, 0, wxEXPAND);
                break;
            case 4:
                fgs_2->Add(mean, 0, wxEXPAND);
                break;
            case 6:
                fgs_2->Add(sum, 0, wxEXPAND);
                break;
            default:
                auto tmp = new wxTextCtrl(this, -1, wxT(""), wxPoint(),
                                          wxSize(-1, 40), wxTE_CENTER);
                fgs_2->Add(tmp, 0, wxEXPAND);

        }
    }

    /*for (int j = 0; j < columns; j++) {
        auto tmp = new wxTextCtrl(this, -1, wxT(""), wxPoint(),
                                  wxSize(-1, 40), wxTE_CENTER);
        switch(j) {
            case 0: tmp->SetValue("Max");
                break;
            case 2: tmp->SetValue("Min");
                break;
            case 4: tmp->SetValue("Mean");
                break;
            case 6: tmp->SetValue("Sum");
                break;
            default: tmp->SetValue("");
        }
        fgs_2->Add(tmp, 0, wxEXPAND);
    } */

    for (int i = 0; i < rows + 1; i++) {
        for (int j = 0; j < columns; j++) {
            auto tmp = new wxTextCtrl(this, -1, wxT(""), wxPoint(),
                                      wxSize(-1, 40), wxTE_CENTER);
            if (j == 0 && i != 0) {
                //TODO settare colore celle e immodificabile prima riga/colonna.
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
    sizer->Add(fgs_2, 1, wxEXPAND);
    SetSizer(sizer);
    SetMinSize(wxSize(270, 220));


    Centre();
}