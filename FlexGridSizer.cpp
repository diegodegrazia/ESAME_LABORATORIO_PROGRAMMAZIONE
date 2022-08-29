//
// Created by Diego De Grazia on 09/08/22.
//

#include "FlexGridSizer.h"
#include "CellSubject.h"
#include "CellObserver.h"

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

    auto max = new CellObserver(Operation::MAX, this, -1, wxT(""), wxPoint(),
                                wxSize(150, 60), wxTE_READONLY | wxTE_CENTER);
    auto min = new CellObserver(Operation::MIN, this, -1, wxT(""), wxPoint(),
                                wxSize(150, 60), wxTE_READONLY | wxTE_CENTER);
    auto mean = new CellObserver(Operation::MEAN, this, -1, wxT(""), wxPoint(),
                                 wxSize(150, 60), wxTE_READONLY | wxTE_CENTER);
    auto sum = new CellObserver(Operation::SUM, this, -1, wxT(""), wxPoint(),
                                wxSize(150, 60), wxTE_READONLY | wxTE_CENTER);

    for (int j = 0; j < columns; j++) {
        switch (j) {
            case 1:
                fgs_2->Add(max, 0, wxEXPAND);
                break;
            case 3:
                fgs_2->Add(min, 0, wxEXPAND);
                break;
            case 5:
                fgs_2->Add(mean, 0, wxEXPAND);
                break;
            case 7:
                fgs_2->Add(sum, 0, wxEXPAND);
                break;
            default:
                auto tmp = new wxTextCtrl(this, -1, wxT(""), wxPoint(),
                                          wxSize(150, 60), wxTE_CENTER | wxTE_READONLY);
                fgs_2->Add(tmp, 0, wxEXPAND);
                if (j == 0)
                    tmp->SetValue("MAX");
                else if (j == 2)
                    tmp->SetValue("MIN");
                else if (j == 4)
                    tmp->SetValue("MEAN");
                else if (j == 6)
                    tmp->SetValue("SUM");

        }
    }
    for (int i = 0; i < rows + 1; i++) {
        for (int j = 0; j < columns; j++) {
            if (j == 0 && i != 0) {
                auto tmp = new CellSubject(this, -1, wxT(""), wxPoint(),
                                           wxSize(-1, 40), wxTE_CENTER | wxTE_READONLY);
                tmp->SetValue(std::to_string(i));
                fgs->Add(tmp, 0, wxEXPAND);
            } else if (i == 0 && j != 0) {
                auto tmp = new CellSubject(this, -1, wxT(""), wxPoint(),
                                           wxSize(-1, 40), wxTE_CENTER | wxTE_READONLY);
                tmp->SetValue(char(64 + j));
                fgs->Add(tmp, 0, wxEXPAND);
            } else {
                if (j == 0 || j == 2 || j == 4 || j == 6) {
                    auto tmp = new CellSubject(this, 0, wxT(""), wxPoint(),
                                               wxSize(150, 60), wxTE_CENTER | wxTE_READONLY);
                    fgs->Add(tmp, 0, wxEXPAND);
                } else {
                    auto tmp = new CellSubject(this, 0, wxT(""), wxPoint(),
                                               wxSize(150, 60), wxTE_CENTER | wxTE_PROCESS_ENTER);
                    tmp->SetBackgroundColour(*wxLIGHT_GREY);
                    fgs->Add(tmp, 0, wxEXPAND);
                    switch (j) {
                        case 1:
                            tmp->subscribe(max);
                            max->subscribe_subject(tmp);
                            break;
                        case 3:
                            tmp->subscribe(min);
                            min->subscribe_subject(tmp);
                            break;
                        case 5:
                            tmp->subscribe(mean);
                            mean->subscribe_subject(tmp);
                            break;
                        case 7:
                            tmp->subscribe(sum);
                            sum->subscribe_subject(tmp);
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }


    sizer->Add(fgs, 1, wxEXPAND);
    sizer->Add(fgs_2, 1, wxEXPAND);
    SetSizer(sizer);
    SetMinSize(wxSize(270, 220));


    Centre();
}