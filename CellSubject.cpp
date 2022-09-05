//
// Created by Diego De Grazia on 12/08/22.
//

#include "CellSubject.h"

void CellSubject::subscribe(Observer *ob) {
    obs = ob;
    obs->subscribe_subject(this);

}

void CellSubject::unsubscribe() {
    obs->unsubscribe_subject(this);
    notify();
    obs = nullptr;
}

wxString CellSubject::getValue() const {
    return wxTextCtrl::GetValue();
}

void CellSubject::notify() const {
    obs->update();
}

void CellSubject::OnEnterButton(wxCommandEvent &event) {
    notify();
}

wxBEGIN_EVENT_TABLE(CellSubject, wxTextCtrl)
                EVT_TEXT_ENTER(0, CellSubject::OnEnterButton)
wxEND_EVENT_TABLE()