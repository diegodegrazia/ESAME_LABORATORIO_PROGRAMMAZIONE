//
// Created by Diego De Grazia on 01/09/22.
//

#include "gtest/gtest.h"
#include "../FlexGridSizer.h"
#include "../CellObserver.h"
#include "TestProject.h"

class ObserverFixture : public ::testing::Test {
protected:
    TestProject *app;

    CellObserver *max;
    CellObserver *min;
    CellObserver *mean;
    CellObserver *sum;

    CellSubject *cs1_max;
    CellSubject *cs2_max;
    CellSubject *cs3_max;
    CellSubject *cs1_min;
    CellSubject *cs2_min;
    CellSubject *cs3_min;
    CellSubject *cs1_mean;
    CellSubject *cs2_mean;
    CellSubject *cs3_mean;
    CellSubject *cs1_sum;
    CellSubject *cs2_sum;
    CellSubject *cs3_sum;


    void SetUp() override {
        char appname[] = "wxUnitTest.exe";
        int argc = 1;
        char *argv[1] = {appname};
        app = new TestProject();
        wxApp::SetInstance(app);
        wxEntryStart(argc, argv);
        app->OnInit();

        wxPanel *panel = new wxPanel(app->fgs, -1);

        max = new CellObserver(Operation::MAX, panel, -1);
        min = new CellObserver(Operation::MIN, panel, -1);
        mean = new CellObserver(Operation::MEAN, panel, -1);
        sum = new CellObserver(Operation::SUM, panel, -1);

        cs1_max = new CellSubject(panel, -1);
        cs2_max = new CellSubject(panel, -1);
        cs3_max = new CellSubject(panel, -1);
        cs1_min = new CellSubject(panel, -1);
        cs2_min = new CellSubject(panel, -1);
        cs3_min = new CellSubject(panel, -1);
        cs1_mean = new CellSubject(panel, -1);
        cs2_mean = new CellSubject(panel, -1);
        cs3_mean = new CellSubject(panel, -1);
        cs1_sum = new CellSubject(panel, -1);
        cs2_sum = new CellSubject(panel, -1);
        cs3_sum = new CellSubject(panel, -1);

        cs1_max->subscribe(max);
        cs2_max->subscribe(max);
        cs3_max->subscribe(max);
        cs1_min->subscribe(min);
        cs2_min->subscribe(min);
        cs3_min->subscribe(min);
        cs1_mean->subscribe(mean);
        cs2_mean->subscribe(mean);
        cs3_mean->subscribe(mean);
        cs1_sum->subscribe(sum);
        cs2_sum->subscribe(sum);
        cs3_sum->subscribe(sum);

    }

    void TearDown() override {
        app->OnExit();
        wxEntryCleanup();
    }

};

TEST_F(ObserverFixture, Update) {
    cs1_max->SetValue("1");
    cs2_max->SetValue("5");
    cs3_max->SetValue("f");
    cs1_min->SetValue("5");
    cs2_min->SetValue("1");
    cs3_min->SetValue("f");
    cs1_mean->SetValue("1");
    cs2_mean->SetValue("5");
    cs3_mean->SetValue("f");
    cs1_sum->SetValue("1");
    cs2_sum->SetValue("5");
    cs3_sum->SetValue("f");

    cs3_max->notify();
    cs3_min->notify();
    cs3_mean->notify();
    cs3_sum->notify();

    wxString string_max = max->GetValue();
    double app_max;
    string_max.ToDouble(&app_max);

    wxString string_min = min->GetValue();
    double app_min;
    string_min.ToDouble(&app_min);

    wxString string_mean = mean->GetValue();
    double app_mean;
    string_mean.ToDouble(&app_mean);

    wxString string_sum = sum->GetValue();
    double app_sum;
    string_sum.ToDouble(&app_sum);

    EXPECT_EQ(5, app_max);
    EXPECT_EQ(1, app_min);
    EXPECT_EQ(3, app_mean);
    EXPECT_EQ(6, app_sum);
}

TEST_F(ObserverFixture, Unsubscribe) {
    cs1_max->SetValue("1");
    cs2_max->SetValue("5");
    cs3_max->SetValue("f");
    cs1_min->SetValue("5");
    cs2_min->SetValue("1");
    cs3_min->SetValue("f");
    cs1_mean->SetValue("1");
    cs2_mean->SetValue("5");
    cs3_mean->SetValue("f");
    cs1_sum->SetValue("1");
    cs2_sum->SetValue("5");
    cs3_sum->SetValue("f");

    cs2_max->unsubscribe();
    cs2_min->unsubscribe();
    cs2_mean->unsubscribe();
    cs2_sum->unsubscribe();

    wxString string_max = max->GetValue();
    double app_max;
    string_max.ToDouble(&app_max);

    wxString string_min = min->GetValue();
    double app_min;
    string_min.ToDouble(&app_min);

    wxString string_mean = mean->GetValue();
    double app_mean;
    string_mean.ToDouble(&app_mean);

    wxString string_sum = sum->GetValue();
    double app_sum;
    string_sum.ToDouble(&app_sum);

    EXPECT_EQ(1, app_max);
    EXPECT_EQ(5, app_min);
    EXPECT_EQ(1, app_mean);
    EXPECT_EQ(1, app_sum);

}