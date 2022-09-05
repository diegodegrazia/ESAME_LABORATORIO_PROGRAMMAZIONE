//
// Created by Diego De Grazia on 10/08/22.
//

#ifndef ESAME_LABORATORIO_PROGRAMMAZIONE_SUBJECT_H
#define ESAME_LABORATORIO_PROGRAMMAZIONE_SUBJECT_H

#include <wx/wx.h>

class Subject {
public:
    virtual ~Subject() = default;

    virtual wxString getValue() const = 0;

    virtual void notify() const = 0;
};


#endif //ESAME_LABORATORIO_PROGRAMMAZIONE_SUBJECT_H
