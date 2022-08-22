//
// Created by Diego De Grazia on 10/08/22.
//

#ifndef ESAME_LABORATORIO_PROGRAMMAZIONE_SUBJECT_H
#define ESAME_LABORATORIO_PROGRAMMAZIONE_SUBJECT_H


#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = default;

    virtual void subscribe(Observer *ob) = 0;

    virtual void unsubscribe() = 0;

    virtual void notify() = 0;
};


#endif //ESAME_LABORATORIO_PROGRAMMAZIONE_SUBJECT_H
