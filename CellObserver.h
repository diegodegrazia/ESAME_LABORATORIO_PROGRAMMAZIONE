//
// Created by Diego De Grazia on 12/08/22.
//

#ifndef ESAME_LABORATORIO_PROGRAMMAZIONE_CELLOBSERVER_H
#define ESAME_LABORATORIO_PROGRAMMAZIONE_CELLOBSERVER_H


#include <wx/wx.h>
#include <list>
#include "CellSubject.h"

enum class Operation {
    MAX, MIN, MEAN, SUM
};

class CellObserver : public Observer, public wxTextCtrl {
public:
    explicit CellObserver(Operation operation,
                          wxWindow *parent,
                          wxWindowID id,
                          const wxString &value = wxEmptyString,
                          const wxPoint &pos = wxDefaultPosition,
                          const wxSize &size = wxDefaultSize,
                          long style = 0,
                          const wxValidator &validator = wxDefaultValidator,
                          const wxString &name = wxTextCtrlNameStr) : wxTextCtrl(parent, id, value, pos, size, style,
                                                                                 validator, name) {
        opr = operation;
    }

    void update() override;

    void subscribe_subject(Subject *s) override;

    void unsubscribe_subject(Subject *s) override;


protected:
    std::list<Subject *> subjects;
    Operation opr;

};

#endif //ESAME_LABORATORIO_PROGRAMMAZIONE_CELLOBSERVER_H
