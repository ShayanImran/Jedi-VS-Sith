/***************************************************************
 * Name:      Jedi_VS_SithMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2020-03-22
 * Copyright:  ()
 * License:
 **************************************************************/

#include "Jedi_VS_SithMain.h"
#include "SimulationDialog.h"
#include "Arena.h"
#include <vector>
#include <wx/msgdlg.h>
#include <wx/dcclient.h>
#include <wx/scrolwin.h>
#include <wx/app.h>
#include <wx/image.h>

//(*InternalHeaders(Jedi_VS_SithFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)
using std::vector;
//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild("To start the simulation with the defaults, press F3 or go to the Simulation Parameters menu and select run. To Set the simulation parameters, go to the Simulation parameters menu and select Set Data, or press F2.");

    return wxbuild;
}

//(*IdInit(Jedi_VS_SithFrame)
const long Jedi_VS_SithFrame::ID_SCROLLEDWINDOW1 = wxNewId();
const long Jedi_VS_SithFrame::ID_SCROLLEDWINDOW2 = wxNewId();
const long Jedi_VS_SithFrame::ID_SCROLLEDWINDOW3 = wxNewId();
const long Jedi_VS_SithFrame::ID_SCROLLEDWINDOW4 = wxNewId();
const long Jedi_VS_SithFrame::ID_SCROLLEDWINDOW5 = wxNewId();
const long Jedi_VS_SithFrame::ID_SCROLLEDWINDOW6 = wxNewId();
const long Jedi_VS_SithFrame::ID_NOTEBOOK1 = wxNewId();
const long Jedi_VS_SithFrame::ID_PANEL1 = wxNewId();
const long Jedi_VS_SithFrame::ID_MENUITEM2 = wxNewId();
const long Jedi_VS_SithFrame::ID_MENUITEM1 = wxNewId();
const long Jedi_VS_SithFrame::ID_MENUITEM3 = wxNewId();
const long Jedi_VS_SithFrame::ID_MENUITEM4 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Jedi_VS_SithFrame,wxFrame)
    //(*EventTable(Jedi_VS_SithFrame)
    //*)
    //EVT_SCROLLWIN(Jedi_VS_SithFrame::OnScroll)
    //EVT_DRAW(Jedi_VS_SithFrame::OnDraw)
END_EVENT_TABLE()

Jedi_VS_SithFrame::Jedi_VS_SithFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Jedi_VS_SithFrame)
    wxBoxSizer* BoxSizer1;

    Create(parent, wxID_ANY, _("Frame"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(480,250), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Notebook1 = new wxNotebook(Panel1, ID_NOTEBOOK1, wxPoint(0,0), wxSize(480,256), 0, _T("ID_NOTEBOOK1"));
    ScrolledWindow1 = new wxScrolledWindow(Notebook1, ID_SCROLLEDWINDOW1, wxPoint(52,68), wxSize(470,216), wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW1"));
    ScrolledWindow2 = new wxScrolledWindow(Notebook1, ID_SCROLLEDWINDOW2, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW2"));
    ScrolledWindow3 = new wxScrolledWindow(Notebook1, ID_SCROLLEDWINDOW3, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW3"));
    ScrolledWindow4 = new wxScrolledWindow(Notebook1, ID_SCROLLEDWINDOW4, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW4"));
    ScrolledWindow5 = new wxScrolledWindow(Notebook1, ID_SCROLLEDWINDOW5, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW5"));
    ScrolledWindow6 = new wxScrolledWindow(Notebook1, ID_SCROLLEDWINDOW6, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW6"));
    Notebook1->AddPage(ScrolledWindow1, _("Arena 1"), false);
    Notebook1->AddPage(ScrolledWindow2, _("Arena 2"), false);
    Notebook1->AddPage(ScrolledWindow3, _("Arena 3"), false);
    Notebook1->AddPage(ScrolledWindow4, _("Arena 4"), false);
    Notebook1->AddPage(ScrolledWindow5, _("Arena 5"), false);
    Notebook1->AddPage(ScrolledWindow6, _("Arena 6"), false);
    BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM2, _("Quit\tAlt+F4"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, ID_MENUITEM1, _("Help\tF1"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    Menu3 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu3, ID_MENUITEM3, _("Set Data\tF2"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu3, ID_MENUITEM4, _("Run\tF3"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem4);
    MenuBar1->Append(Menu3, _("Simulation Parameters"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -10 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    ScrolledWindow1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnScrolledWindow1Paint,0,this);
    ScrolledWindow1->Connect(wxEVT_SIZE,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnScrolledWindow1Resize,0,this);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnQuit);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnAbout);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnSetData);
    Connect(ID_MENUITEM4,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnRun);
    //*)

    //Initialize the values to their defaults
    numJedi = 200;
    numSith = 200;
    numArenas = 1;
    numObstacles = 500;
    columns = 70;
    rows = 25;
    numIterations = 1000;

    //All this just initializes the windows and scroll bars
    ScrolledWindow1->SetVirtualSize(2000,2000);
    ScrolledWindow1->SetScrollbar(wxVERTICAL, 0, 25, 162);
    ScrolledWindow1->SetScrollbar(wxHORIZONTAL, 0, 10, 75);
    ScrolledWindow1->AlwaysShowScrollbars();
    ScrolledWindow1->SetScrollRate(1,1);
    ScrolledWindow2->Show(false);
    ScrolledWindow2->SetVirtualSize(2000,2000);
    ScrolledWindow2->SetScrollbar(wxVERTICAL, 0, 25, 162);
    ScrolledWindow2->SetScrollbar(wxHORIZONTAL, 0, 10, 75);
    ScrolledWindow2->AlwaysShowScrollbars();
    ScrolledWindow2->SetScrollRate(1,1);
    ScrolledWindow3->Show(false);
    ScrolledWindow3->SetVirtualSize(2000,2000);
    ScrolledWindow3->SetScrollbar(wxVERTICAL, 0, 25, 162);
    ScrolledWindow3->SetScrollbar(wxHORIZONTAL, 0, 10, 75);
    ScrolledWindow3->AlwaysShowScrollbars();
    ScrolledWindow3->SetScrollRate(1,1);
    ScrolledWindow4->Show(false);
    ScrolledWindow4->SetVirtualSize(2000,2000);
    ScrolledWindow4->SetScrollbar(wxVERTICAL, 0, 25, 162);
    ScrolledWindow4->SetScrollbar(wxHORIZONTAL, 0, 10, 75);
    ScrolledWindow4->AlwaysShowScrollbars();
    ScrolledWindow4->SetScrollRate(1,1);
    ScrolledWindow5->Show(false);
    ScrolledWindow5->SetVirtualSize(2000,2000);
    ScrolledWindow5->SetScrollbar(wxVERTICAL, 0, 25, 162);
    ScrolledWindow5->SetScrollbar(wxHORIZONTAL, 0, 10, 75);
    ScrolledWindow5->AlwaysShowScrollbars();
    ScrolledWindow5->SetScrollRate(1,1);
    ScrolledWindow6->Show(false);
    ScrolledWindow6->SetVirtualSize(2000,2000);
    ScrolledWindow6->SetScrollbar(wxVERTICAL, 0, 25, 162);
    ScrolledWindow6->SetScrollbar(wxHORIZONTAL, 0, 10, 75);
    ScrolledWindow6->AlwaysShowScrollbars();
    ScrolledWindow6->SetScrollRate(1,1);
}

Jedi_VS_SithFrame::~Jedi_VS_SithFrame()
{
    //(*Destroy(Jedi_VS_SithFrame)
    //*)
}

/*
    When the arena is ran, the windows need to be drawn using a function that passes the current window in

    each arena location is predefined and is drawn there using DrawText()

    once it's done, it needs to redraw on scroll
    the cells need to be mapped. otherwise redrawing them will be impossible
    cells update with every turn for each character
    or cheese it with one update after every character has a turn
*/

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


void Jedi_VS_SithFrame::OnRun(wxCommandEvent& event)
{
    if(numArenas == 2)
    {
        ScrolledWindow2->Show(true);
    }
    if(numArenas == 3)
    {
        ScrolledWindow2->Show(true);
        ScrolledWindow3->Show(true);
    }
    if(numArenas == 4)
    {
        ScrolledWindow2->Show(true);
        ScrolledWindow3->Show(true);
        ScrolledWindow4->Show(true);
    }
    if(numArenas == 5)
    {
        ScrolledWindow2->Show(true);
        ScrolledWindow3->Show(true);
        ScrolledWindow4->Show(true);
        ScrolledWindow5->Show(true);
    }
    if(numArenas == 6)
    {
        ScrolledWindow2->Show(true);
        ScrolledWindow3->Show(true);
        ScrolledWindow4->Show(true);
        ScrolledWindow5->Show(true);
        ScrolledWindow6->Show(true);
    }
    /*
        for each window
            callDrawArenaFunction()
            displayCurrentStats()
            runArenaSimulation()
                while(!done)
                    displayCurrentStats()
            executeOrder66()
    */

    vector<Arena> arenaHolder;
    for(int r = 0; r < numArenas; r++)
    {
        arenaHolder.push_back( Arena(3, rows, columns) );
        arenaHolder[r].create3DArray();
        arenaHolder[r].fill3DArrayRandomly((numSith+numJedi+numObstacles));
    }

}

void Jedi_VS_SithFrame::OnScrolledWindow1Paint(wxPaintEvent& event)
{
    wxClientDC canvas(ScrolledWindow1);
    PrepareDC(canvas);

    int x = 0;
    int y = 0;

    ScrolledWindow1->GetViewStart(&x, &y);

    printf("%d\n",x);

    canvas.DrawLine(10,30,20,70);
    canvas.DrawLine(x * 10 + 100, 30, x * 10 + 200, 70);
    canvas.DrawLine(x * 10 + 500, 100, x * 10 + 300, 200);

}

void Jedi_VS_SithFrame::updateVirtualSize()
{
    //int cellWidth =
}

void Jedi_VS_SithFrame::OnScrolledWindow1Resize(wxSizeEvent& event)
{
    updateVirtualSize();
}

