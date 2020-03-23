/***************************************************************
 * Name:      Jedi_VS_SithMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2020-03-22
 * Copyright:  ()
 * License:
 **************************************************************/

#include "Jedi_VS_SithMain.h"
#include <wx/msgdlg.h>
#include "SimulationDialog.h"

//(*InternalHeaders(Jedi_VS_SithFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Jedi_VS_SithFrame)
const long Jedi_VS_SithFrame::ID_PANEL1 = wxNewId();
const long Jedi_VS_SithFrame::idMenuQuit = wxNewId();
const long Jedi_VS_SithFrame::idMenuAbout = wxNewId();
const long Jedi_VS_SithFrame::idMenuSimulation = wxNewId();
const long Jedi_VS_SithFrame::ID_MENUITEM1 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Jedi_VS_SithFrame,wxFrame)
    //(*EventTable(Jedi_VS_SithFrame)
    //*)
END_EVENT_TABLE()

Jedi_VS_SithFrame::Jedi_VS_SithFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Jedi_VS_SithFrame)
    wxBoxSizer* BoxSizer1;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenu* Menu3;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem3;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(480,222), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    Menu3 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu3, idMenuSimulation, _("Set Data\tF2"), _("Set the initial values for each arena"), wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu3, ID_MENUITEM1, _("Run\tF3"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem4);
    MenuBar1->Append(Menu3, _("Simulation Paramaters"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnAbout);
    Connect(idMenuSimulation,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnSetData);
    //*)

    //Initialize the values to their defaults
    numJedi = 200;
    numSith = 200;
    numArenas = 1;
    numObstacles = 500;
    columns = 70;
    rows = 25;
    numIterations = 1000;
}

Jedi_VS_SithFrame::~Jedi_VS_SithFrame()
{
    //(*Destroy(Jedi_VS_SithFrame)
    //*)
}

void Jedi_VS_SithFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Jedi_VS_SithFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Jedi_VS_SithFrame::OnSetData(wxCommandEvent& event)
{
    /*
    wxMiniFrame* temp = new wxMiniFrame();
    temp->Create(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    wxPopupWindow* p = new wxPopupWindow(temp);
    wxPanel* display = new wxPanel;

    p->SetSize(300,150);


    p->Show(true);
    */

    SimulationDialog temp(this);

    int dlg = temp.ShowModal();
    if(dlg == wxID_OK)
    {

    }

    this->numJedi = temp.numJedi;
    this->numSith = temp.numSith;
    this->numArenas = temp.numArenas;
    this->numObstacles = temp.numObstacles;
    this->columns = temp.columns;
    this->rows = temp.rows;
    this->numIterations = temp.numIterations;


}

