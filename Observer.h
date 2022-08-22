//
// Created by Diego De Grazia on 10/08/22.
//

#ifndef ESAME_LABORATORIO_PROGRAMMAZIONE_OBSERVER_H
#define ESAME_LABORATORIO_PROGRAMMAZIONE_OBSERVER_H


class Observer {
public:
    virtual ~Observer() = default;

    virtual void update() = 0;

};


#endif //ESAME_LABORATORIO_PROGRAMMAZIONE_OBSERVER_H
