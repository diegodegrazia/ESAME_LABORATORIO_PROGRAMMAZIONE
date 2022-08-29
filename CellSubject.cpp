//
// Created by Diego De Grazia on 12/08/22.
//

#include "CellSubject.h"

void CellSubject::subscribe(Observer *ob) {
    obs = ob;
}

void CellSubject::unsubscribe() {
    free(obs);
}

void CellSubject::notify() {
    obs->update();
}

void CellSubject::OnEnterButton(wxCommandEvent &event) {
    notify();
}

wxBEGIN_EVENT_TABLE(CellSubject, wxTextCtrl)
                EVT_TEXT_ENTER(0, CellSubject::OnEnterButton)
wxEND_EVENT_TABLE()