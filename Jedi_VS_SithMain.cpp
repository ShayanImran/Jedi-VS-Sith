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
#include <wx/string.h>
#include <wx/intl.h>
//*)
using std::vector;
vector<Arena> arenaHolder;
//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild("To start the simulation with the defaults, press F3 or go to the Simulation Parameters menu and select run. To Set the simulation parameters, go to the Simulation parameters menu and select Set Data, or press F2.");

    return wxbuild;
}

//(*IdInit(Jedi_VS_SithFrame)
const long Jedi_VS_SithFrame::ID_STATICTEXT2 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT3 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT1 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT5 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT6 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT4 = wxNewId();
const long Jedi_VS_SithFrame::ID_PANEL2 = wxNewId();
const long Jedi_VS_SithFrame::ID_SCROLLEDWINDOW1 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT10 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT9 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT7 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT8 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT11 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT12 = wxNewId();
const long Jedi_VS_SithFrame::ID_PANEL3 = wxNewId();
const long Jedi_VS_SithFrame::ID_SCROLLEDWINDOW2 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT13 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT14 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT15 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT16 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT17 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT18 = wxNewId();
const long Jedi_VS_SithFrame::ID_PANEL4 = wxNewId();
const long Jedi_VS_SithFrame::ID_SCROLLEDWINDOW3 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT19 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT20 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT21 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT22 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT23 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT24 = wxNewId();
const long Jedi_VS_SithFrame::ID_PANEL5 = wxNewId();
const long Jedi_VS_SithFrame::ID_SCROLLEDWINDOW4 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT25 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT26 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT27 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT28 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT29 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT30 = wxNewId();
const long Jedi_VS_SithFrame::ID_PANEL6 = wxNewId();
const long Jedi_VS_SithFrame::ID_SCROLLEDWINDOW5 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT31 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT32 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT33 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT34 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT35 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT36 = wxNewId();
const long Jedi_VS_SithFrame::ID_PANEL7 = wxNewId();
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
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(479,261), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Notebook1 = new wxNotebook(Panel1, ID_NOTEBOOK1, wxPoint(0,0), wxSize(480,256), 0, _T("ID_NOTEBOOK1"));
    ScrolledWindow1 = new wxScrolledWindow(Notebook1, ID_SCROLLEDWINDOW1, wxPoint(52,68), wxSize(476,169), wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW1"));
    Panel2 = new wxPanel(ScrolledWindow1, ID_PANEL2, wxDefaultPosition, wxSize(1439,1500), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    StaticText2 = new wxStaticText(Panel2, ID_STATICTEXT2, _("Remaining Jedi: "), wxPoint(8,24), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Remaining Sith: "), wxPoint(8,48), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText1 = new wxStaticText(Panel2, ID_STATICTEXT1, _("Remaining Monsters: "), wxPoint(8,72), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText5 = new wxStaticText(Panel2, ID_STATICTEXT5, _("2000"), wxPoint(160,24), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    StaticText6 = new wxStaticText(Panel2, ID_STATICTEXT6, _("2000"), wxPoint(160,48), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticText4 = new wxStaticText(Panel2, ID_STATICTEXT4, _("2000"), wxPoint(160,72), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    ScrolledWindow2 = new wxScrolledWindow(Notebook1, ID_SCROLLEDWINDOW2, wxPoint(29,73), wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW2"));
    Panel3 = new wxPanel(ScrolledWindow2, ID_PANEL3, wxDefaultPosition, wxSize(1439,1500), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    StaticText10 = new wxStaticText(Panel3, ID_STATICTEXT10, _("Remaining Jedi: "), wxPoint(8,24), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    StaticText9 = new wxStaticText(Panel3, ID_STATICTEXT9, _("Remaining Sith: "), wxPoint(8,48), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    StaticText7 = new wxStaticText(Panel3, ID_STATICTEXT7, _("Remaining Monsters: "), wxPoint(8,72), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    StaticText8 = new wxStaticText(Panel3, ID_STATICTEXT8, _("2000"), wxPoint(160,24), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    StaticText11 = new wxStaticText(Panel3, ID_STATICTEXT11, _("2000"), wxPoint(160,48), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    StaticText12 = new wxStaticText(Panel3, ID_STATICTEXT12, _("2000"), wxPoint(160,72), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    ScrolledWindow3 = new wxScrolledWindow(Notebook1, ID_SCROLLEDWINDOW3, wxPoint(83,112), wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW3"));
    Panel4 = new wxPanel(ScrolledWindow3, ID_PANEL4, wxDefaultPosition, wxSize(1439,1500), wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    StaticText13 = new wxStaticText(Panel4, ID_STATICTEXT13, _("Remaining Jedi: "), wxPoint(8,24), wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    StaticText14 = new wxStaticText(Panel4, ID_STATICTEXT14, _("Remaining Sith: "), wxPoint(8,48), wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    StaticText15 = new wxStaticText(Panel4, ID_STATICTEXT15, _("Remaining Monsters: "), wxPoint(8,72), wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    StaticText16 = new wxStaticText(Panel4, ID_STATICTEXT16, _("2000"), wxPoint(160,24), wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    StaticText17 = new wxStaticText(Panel4, ID_STATICTEXT17, _("2000"), wxPoint(160,48), wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    StaticText18 = new wxStaticText(Panel4, ID_STATICTEXT18, _("2000"), wxPoint(160,72), wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    ScrolledWindow4 = new wxScrolledWindow(Notebook1, ID_SCROLLEDWINDOW4, wxPoint(94,117), wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW4"));
    Panel5 = new wxPanel(ScrolledWindow4, ID_PANEL5, wxDefaultPosition, wxSize(1439,1500), wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    StaticText19 = new wxStaticText(Panel5, ID_STATICTEXT19, _("Remaining Jedi: "), wxPoint(8,24), wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    StaticText20 = new wxStaticText(Panel5, ID_STATICTEXT20, _("Remaining Sith: "), wxPoint(8,48), wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    StaticText21 = new wxStaticText(Panel5, ID_STATICTEXT21, _("Remaining Monsters: "), wxPoint(8,72), wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    StaticText22 = new wxStaticText(Panel5, ID_STATICTEXT22, _("2000"), wxPoint(160,24), wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    StaticText23 = new wxStaticText(Panel5, ID_STATICTEXT23, _("2000"), wxPoint(160,48), wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    StaticText24 = new wxStaticText(Panel5, ID_STATICTEXT24, _("2000"), wxPoint(160,72), wxDefaultSize, 0, _T("ID_STATICTEXT24"));
    ScrolledWindow5 = new wxScrolledWindow(Notebook1, ID_SCROLLEDWINDOW5, wxPoint(85,129), wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW5"));
    Panel6 = new wxPanel(ScrolledWindow5, ID_PANEL6, wxDefaultPosition, wxSize(1439,1500), wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    StaticText25 = new wxStaticText(Panel6, ID_STATICTEXT25, _("Remaining Jedi: "), wxPoint(8,24), wxDefaultSize, 0, _T("ID_STATICTEXT25"));
    StaticText26 = new wxStaticText(Panel6, ID_STATICTEXT26, _("Remaining Sith: "), wxPoint(8,48), wxDefaultSize, 0, _T("ID_STATICTEXT26"));
    StaticText27 = new wxStaticText(Panel6, ID_STATICTEXT27, _("Remaining Monsters: "), wxPoint(8,72), wxDefaultSize, 0, _T("ID_STATICTEXT27"));
    StaticText28 = new wxStaticText(Panel6, ID_STATICTEXT28, _("2000"), wxPoint(160,24), wxDefaultSize, 0, _T("ID_STATICTEXT28"));
    StaticText29 = new wxStaticText(Panel6, ID_STATICTEXT29, _("2000"), wxPoint(160,48), wxDefaultSize, 0, _T("ID_STATICTEXT29"));
    StaticText30 = new wxStaticText(Panel6, ID_STATICTEXT30, _("2000"), wxPoint(160,72), wxDefaultSize, 0, _T("ID_STATICTEXT30"));
    ScrolledWindow6 = new wxScrolledWindow(Notebook1, ID_SCROLLEDWINDOW6, wxPoint(63,111), wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW6"));
    Panel7 = new wxPanel(ScrolledWindow6, ID_PANEL7, wxDefaultPosition, wxSize(1439,1500), wxTAB_TRAVERSAL, _T("ID_PANEL7"));
    StaticText31 = new wxStaticText(Panel7, ID_STATICTEXT31, _("Remaining Jedi: "), wxPoint(8,24), wxDefaultSize, 0, _T("ID_STATICTEXT31"));
    StaticText32 = new wxStaticText(Panel7, ID_STATICTEXT32, _("Remaining Sith: "), wxPoint(8,48), wxDefaultSize, 0, _T("ID_STATICTEXT32"));
    StaticText33 = new wxStaticText(Panel7, ID_STATICTEXT33, _("Remaining Monsters: "), wxPoint(8,72), wxDefaultSize, 0, _T("ID_STATICTEXT33"));
    StaticText34 = new wxStaticText(Panel7, ID_STATICTEXT34, _("2000"), wxPoint(160,24), wxDefaultSize, 0, _T("ID_STATICTEXT34"));
    StaticText35 = new wxStaticText(Panel7, ID_STATICTEXT35, _("2000"), wxPoint(160,48), wxDefaultSize, 0, _T("ID_STATICTEXT35"));
    StaticText36 = new wxStaticText(Panel7, ID_STATICTEXT36, _("2000"), wxPoint(160,72), wxDefaultSize, 0, _T("ID_STATICTEXT36"));
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

    ScrolledWindow1->Connect(wxEVT_SIZE,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnScrolledWindow1Resize,0,this);
    Panel3->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnScrolledWindow1MouseMove,0,this);
    Panel3->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnScrolledWindow2LeftUp,0,this);
    Panel4->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnScrolledWindow1MouseMove,0,this);
    Panel4->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnScrolledWindow3LeftUp,0,this);
    Panel5->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnScrolledWindow1MouseMove,0,this);
    Panel5->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnScrolledWindow4LeftUp,0,this);
    Panel6->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnScrolledWindow1MouseMove,0,this);
    Panel6->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnScrolledWindow5LeftUp,0,this);
    Panel7->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnScrolledWindow1MouseMove,0,this);
    Panel7->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnScrolledWindow6LeftUp,0,this);
    ScrolledWindow6->Connect(wxEVT_MOUSEWHEEL,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnScrolledWindow6MouseWheel,0,this);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnQuit);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnAbout);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnSetData);
    Connect(ID_MENUITEM4,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnRun);
    Connect(wxEVT_MOUSEWHEEL,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnScrolledWindow6MouseWheel);
    //*)

    //Initialize the values to their defaults
    numJedi = 1;
    numSith = 1;
    numArenas = 1;
    numObstacles = 1;
    columns = 5;
    rows = 3;
    numIterations = 1000;

    //All this just initializes the windows and scroll bars
    ScrolledWindow1->SetVirtualSize(1100, 1500);
    ScrolledWindow1->SetScrollbar(wxVERTICAL, 0, 25, 75);
    ScrolledWindow1->SetScrollbar(wxHORIZONTAL, 0, 10, 15);
    ScrolledWindow1->AlwaysShowScrollbars();
    ScrolledWindow1->SetScrollRate(1,1);
    ScrolledWindow2->Show(false);

    ScrolledWindow2->SetVirtualSize(1100,1500);
    ScrolledWindow2->SetScrollbar(wxVERTICAL, 0, 25, 162);
    ScrolledWindow2->SetScrollbar(wxHORIZONTAL, 0, 10, 45);
    ScrolledWindow2->AlwaysShowScrollbars();
    ScrolledWindow2->SetScrollRate(1,1);

    ScrolledWindow3->Show(false);
    ScrolledWindow3->SetVirtualSize(1100,1500);
    ScrolledWindow3->SetScrollbar(wxVERTICAL, 0, 25, 162);
    ScrolledWindow3->SetScrollbar(wxHORIZONTAL, 0, 10, 45);
    ScrolledWindow3->AlwaysShowScrollbars();
    ScrolledWindow3->SetScrollRate(1,1);

    ScrolledWindow4->Show(false);
    ScrolledWindow4->SetVirtualSize(1100,1500);
    ScrolledWindow4->SetScrollbar(wxVERTICAL, 0, 25, 162);
    ScrolledWindow4->SetScrollbar(wxHORIZONTAL, 0, 10, 45);
    ScrolledWindow4->AlwaysShowScrollbars();
    ScrolledWindow4->SetScrollRate(1,1);

    ScrolledWindow5->Show(false);
    ScrolledWindow5->SetVirtualSize(1100,1500);
    ScrolledWindow5->SetScrollbar(wxVERTICAL, 0, 25, 162);
    ScrolledWindow5->SetScrollbar(wxHORIZONTAL, 0, 10, 45);
    ScrolledWindow5->AlwaysShowScrollbars();
    ScrolledWindow5->SetScrollRate(1,1);

    ScrolledWindow6->Show(false);
    ScrolledWindow6->SetVirtualSize(1100,1500);
    ScrolledWindow6->SetScrollbar(wxVERTICAL, 0, 25, 162);
    ScrolledWindow6->SetScrollbar(wxHORIZONTAL, 0, 10, 45);
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
    or cheese it with one update after every character has a turn.
    Removed wrong account.
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
            callDrawArenaFunction()
            displayCurrentStats()
            runArenaSimulation()
                while(!done)
                    displayCurrentStats()
            executeOrder66()
    */


    for(int r = 0; r < numArenas; r++)
    {
        //wxMessageBox(std::to_string(arenaHolder.size()));
        arenaHolder.push_back( Arena(6, rows, columns) );
        arenaHolder[r].create3DArray();
        arenaHolder[r].fill3DArrayRandomly(1, 1, 1, 1);

    }

    wxClientDC canvas1(Panel2);
    PrepareDC(canvas1);

    int offsetX = 250;
    int offsetY = 10;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            for(int k = 0;k < columns; k++)
            {
                if(arenaHolder[0].gameWorld[i][j][k] == 0)
                {
                    canvas1.DrawText("--", j * 15 + offsetX, (k * 17) + offsetY);
                }
                else
                {
                    canvas1.DrawText(arenaHolder[0].gameWorld[i][j][k]->teamIcon, j * 15 + offsetX, (k * 17) + offsetY);
                }

            }
        }

        offsetY = offsetY + (columns * 20);
    }

}

void Jedi_VS_SithFrame::OnScrolledWindow1Paint(wxPaintEvent& event)
{


}

void Jedi_VS_SithFrame::updateVirtualSize()
{
    //int cellWidth =
}

void Jedi_VS_SithFrame::OnScrolledWindow1Resize(wxSizeEvent& event)
{
    updateVirtualSize();
}





void Jedi_VS_SithFrame::OnScrolledWindow1MouseMove(wxMouseEvent& event)
{
    this->Refresh();
    this->Update();
}

void Jedi_VS_SithFrame::OnPanel2LeftUp(wxMouseEvent& event)
{
    wxClientDC canvas1(Panel2);
    PrepareDC(canvas1);

    int offsetX = 250;
    int offsetY = 10;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            for(int k = 0;k < columns; k++)
            {
                if(arenaHolder[0].gameWorld[i][j][k] == 0)
                {
                    canvas1.DrawText("--", j * 15 + offsetX, (k * 17) + offsetY);
                }
                else
                {
                    canvas1.DrawText(arenaHolder[0].gameWorld[i][j][k]->teamIcon, j * 15 + offsetX, (k * 17) + offsetY);
                }

            }
        }

        offsetY = offsetY + (columns * 20);
    }
}

void Jedi_VS_SithFrame::OnScrolledWindow2LeftUp(wxMouseEvent& event)
{

    wxClientDC canvas1(Panel3);
    PrepareDC(canvas1);

    int offsetX = 250;
    int offsetY = 10;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            for(int k = 0;k < columns; k++)
            {
                if(arenaHolder[0].gameWorld[i][j][k] == 0)
                {
                    canvas1.DrawText("--", j * 15 + offsetX, (k * 17) + offsetY);
                }
                else
                {
                    canvas1.DrawText(arenaHolder[0].gameWorld[i][j][k]->teamIcon, j * 15 + offsetX, (k * 17) + offsetY);
                }

            }
        }

        offsetY = offsetY + (columns * 20);
    }
}

void Jedi_VS_SithFrame::OnScrolledWindow3LeftUp(wxMouseEvent& event)
{

    wxClientDC canvas1(Panel4);
    PrepareDC(canvas1);

    int offsetX = 250;
    int offsetY = 10;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            for(int k = 0;k < columns; k++)
            {
                if(arenaHolder[0].gameWorld[i][j][k] == 0)
                {
                    canvas1.DrawText("--", j * 15 + offsetX, (k * 17) + offsetY);
                }
                else
                {
                    canvas1.DrawText(arenaHolder[0].gameWorld[i][j][k]->teamIcon, j * 15 + offsetX, (k * 17) + offsetY);
                }

            }
        }

        offsetY = offsetY + (columns * 20);
    }
}


void Jedi_VS_SithFrame::OnScrolledWindow4LeftUp(wxMouseEvent& event)
{

    wxClientDC canvas1(Panel5);
    PrepareDC(canvas1);

    int offsetX = 250;
    int offsetY = 10;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            for(int k = 0;k < columns; k++)
            {
                if(arenaHolder[0].gameWorld[i][j][k] == 0)
                {
                    canvas1.DrawText("--", j * 15 + offsetX, (k * 17) + offsetY);
                }
                else
                {
                    canvas1.DrawText(arenaHolder[0].gameWorld[i][j][k]->teamIcon, j * 15 + offsetX, (k * 17) + offsetY);
                }

            }
        }

        offsetY = offsetY + (columns * 20);
    }
}

void Jedi_VS_SithFrame::OnScrolledWindow5LeftUp(wxMouseEvent& event)
{
    wxClientDC canvas1(Panel6);
    PrepareDC(canvas1);

    int offsetX = 250;
    int offsetY = 10;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            for(int k = 0;k < columns; k++)
            {
                if(arenaHolder[0].gameWorld[i][j][k] == 0)
                {
                    canvas1.DrawText("--", j * 15 + offsetX, (k * 17) + offsetY);
                }
                else
                {
                    canvas1.DrawText(arenaHolder[0].gameWorld[i][j][k]->teamIcon, j * 15 + offsetX, (k * 17) + offsetY);
                }

            }
        }

        offsetY = offsetY + (columns * 20);
    }
}
/* Replace "F" with the image of the character in the arena object */
void Jedi_VS_SithFrame::OnScrolledWindow6LeftUp(wxMouseEvent& event)
{
    wxClientDC canvas1(Panel7);
    PrepareDC(canvas1);

    int offsetX = 250;
    int offsetY = 10;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            for(int k = 0;k < columns; k++)
            {
                if(arenaHolder[0].gameWorld[i][j][k] == 0)
                {
                    canvas1.DrawText("--", j * 15 + offsetX, (k * 17) + offsetY);
                }
                else
                {
                    canvas1.DrawText(arenaHolder[0].gameWorld[i][j][k]->teamIcon, j * 15 + offsetX, (k * 17) + offsetY);
                }

            }
        }

        offsetY = offsetY + (columns * 20);
    }
}

void Jedi_VS_SithFrame::OnScrolledWindow6MouseWheel(wxMouseEvent& event)
{
  //Gotem
    for(int i = 0; i< 10; i++)
    {
        std::cout<<"This does nothing";
    }
}
