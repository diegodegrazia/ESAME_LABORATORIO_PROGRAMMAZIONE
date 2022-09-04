//
// Created by Diego De Grazia on 04/09/22.
//

#ifndef ESAME_LABORATORIO_PROGRAMMAZIONE_TESTPROJECT_H
#define ESAME_LABORATORIO_PROGRAMMAZIONE_TESTPROJECT_H

#include "../FlexGridSizer.h"

class TestProject : public wxApp {
public:
    virtual bool OnInit() override;

    FlexGridSizer *fgs;
};


#endif //ESAME_LABORATORIO_PROGRAMMAZIONE_TESTPROJECT_H
