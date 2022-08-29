//
// Created by Diego De Grazia on 12/08/22.
//

#include "CellObserver.h"

void CellObserver::update() {
    if (opr == Operation::MAX) {
        wxString temp = (*subjects.begin())->GetValue();
        double app;
        temp.ToDouble(&app);
        double max = app;
        for (auto itr = subjects.begin(); itr != subjects.end(); itr++) {
            temp = (*itr)->GetValue();
            temp.ToDouble(&app);
            if (app > max)
                max = app;
        }
        wxTextCtrl::SetValue(std::to_string(max));
    } else if (opr == Operation::MIN) {
        wxString temp = (*subjects.begin())->GetValue();
        double app;
        temp.ToDouble(&app);
        double min = app;
        for (auto itr = subjects.begin(); itr != subjects.end(); itr++) {
            temp = (*itr)->GetValue();
            temp.ToDouble(&app);
            if (app < min)
                min = app;
        }
        wxTextCtrl::SetValue(std::to_string(min));
    } else if (opr == Operation::MEAN) {
        wxString temp;
        double app;
        double mean = 0;
        int count = 0;
        for (auto itr = subjects.begin(); itr != subjects.end(); itr++) {
            temp = (*itr)->GetValue();
            if (temp.ToDouble(&app)) {
                mean = mean + app;
                count++;
            }
        }
        mean = mean / count;
        wxTextCtrl::SetValue(std::to_string(mean));
    } else if (opr == Operation::SUM) {
        wxString temp;
        double app;
        double sum = 0;
        for (auto itr = subjects.begin(); itr != subjects.end(); itr++) {
            temp = (*itr)->GetValue();
            if (temp.ToDouble(&app))
                sum = sum + app;
        }
        wxTextCtrl::SetValue(std::to_string(sum));

    }

}

void CellObserver::subscribe_subject(CellSubject *cs) {
    subjects.push_back(cs);
}
