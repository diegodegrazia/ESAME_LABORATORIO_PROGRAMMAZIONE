//
// Created by Diego De Grazia on 12/08/22.
//

#include "CellObserver.h"

void CellObserver::update() {
    if (opr == Operation::MAX) {
        double app;
        double max = (*subjects.begin())->GetValue().ToDouble(&app);
        for (auto itr = subjects.begin(); itr != subjects.end(); itr++) {
            if ((*itr)->GetValue().ToDouble(&app) > max)
                max = app;
        }
        wxTextCtrl::SetValue(std::to_string(max));
    } else if (opr == Operation::MIN) {
        double app;
        double min = (*subjects.begin())->GetValue().ToDouble(&app);
        for (auto itr = subjects.begin(); itr != subjects.end(); itr++) {
            if ((*itr)->GetValue().ToDouble(&app) < min)
                min = app;
        }
        wxTextCtrl::SetValue(std::to_string(min));
    } else if (opr == Operation::MEAN) {
        double app;
        double mean = 0;
        for (auto itr = subjects.begin(); itr != subjects.end(); itr++)
            mean = mean + (*itr)->GetValue().ToDouble(&app);
        mean = mean / subjects.size();
        wxTextCtrl::SetValue(std::to_string(mean));
    } else if (opr == Operation::SUM) {
        double app;
        double sum = 0;
        for (auto itr = subjects.begin(); itr != subjects.end(); itr++)
            sum = sum + (*itr)->GetValue().ToDouble(&app);
        wxTextCtrl::SetValue(std::to_string(sum));

    }

}

void CellObserver::subscribe_subject(CellSubject *cs) {
    subjects.push_back(cs);
}
