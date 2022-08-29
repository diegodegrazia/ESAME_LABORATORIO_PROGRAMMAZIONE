//
// Created by Diego De Grazia on 12/08/22.
//

#ifndef ESAME_LABORATORIO_PROGRAMMAZIONE_CELLSUBJECT_H
#define ESAME_LABORATORIO_PROGRAMMAZIONE_CELLSUBJECT_H


#include <wx/wx.h>
#include "Subject.h"

class CellSubject : public wxTextCtrl, public Subject {
public:
    CellSubject(wxWindow *parent,
                wxWindowID id,
                const wxString &value = wxEmptyString,
                const wxPoint &pos = wxDefaultPosition,
                const wxSize &size = wxDefaultSize,
                long style = 0,
                const wxValidator &validator = wxDefaultValidator,
                const wxString &name = wxTextCtrlNameStr,
                Observer *ob = nullptr) : wxTextCtrl(parent, id, value, pos, size, style, validator, name) {
        obs = ob;
    }

    void subscribe(Observer *ob) override;

    void unsubscribe() override;

    void notify() override;

    void OnEnterButton(wxCommandEvent &event);

protected:
    Observer *obs;
wxDECLARE_EVENT_TABLE();
};


#endif //ESAME_LABORATORIO_PROGRAMMAZIONE_CELLSUBJECT_H
