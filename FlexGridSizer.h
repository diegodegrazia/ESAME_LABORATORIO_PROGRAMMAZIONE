//
// Created by Diego De Grazia on 09/08/22.
//

#ifndef ESAME_LABORATORIO_PROGRAMMAZIONE_FLEXGRIDSIZER_H
#define ESAME_LABORATORIO_PROGRAMMAZIONE_FLEXGRIDSIZER_H

#include <wx/wx.h>

class FlexGridSizer : public wxFrame {
public:
    FlexGridSizer(const wxString &title);

    wxMenuBar *menubar;
    wxMenu *file;

    wxBoxSizer *sizer;
    wxGridSizer *fgs;
    wxTextCtrl *display;
    wxGridSizer *fgs_2;


};

#endif //ESAME_LABORATORIO_PROGRAMMAZIONE_FLEXGRIDSIZER_H
