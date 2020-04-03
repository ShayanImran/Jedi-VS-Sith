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
const long Jedi_VS_SithFrame::ID_STATICTEXT1 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT2 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT3 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT4 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT5 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT6 = wxNewId();
const long Jedi_VS_SithFrame::ID_STATICTEXT7 = wxNewId();
const long Jedi_VS_SithFrame::ID_PANEL2 = wxNewId();
const long Jedi_VS_SithFrame::ID_SCROLLEDWINDOW1 = wxNewId();
const long Jedi_VS_SithFrame::ID_PANEL3 = wxNewId();
const long Jedi_VS_SithFrame::ID_SCROLLEDWINDOW2 = wxNewId();
const long Jedi_VS_SithFrame::ID_PANEL4 = wxNewId();
const long Jedi_VS_SithFrame::ID_SCROLLEDWINDOW3 = wxNewId();
const long Jedi_VS_SithFrame::ID_PANEL5 = wxNewId();
const long Jedi_VS_SithFrame::ID_SCROLLEDWINDOW4 = wxNewId();
const long Jedi_VS_SithFrame::ID_PANEL6 = wxNewId();
const long Jedi_VS_SithFrame::ID_SCROLLEDWINDOW5 = wxNewId();
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

bool started = false;
int subArena = 2;

Jedi_VS_SithFrame::Jedi_VS_SithFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Jedi_VS_SithFrame)
    wxBoxSizer* BoxSizer1;

    Create(parent, wxID_ANY, _("Frame"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(984,650), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Notebook1 = new wxNotebook(Panel1, ID_NOTEBOOK1, wxPoint(0,0), wxSize(984,645), 0, _T("ID_NOTEBOOK1"));
    ScrolledWindow1 = new wxScrolledWindow(Notebook1, ID_SCROLLEDWINDOW1, wxPoint(52,68), wxSize(476,169), wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW1"));
    Panel2 = new wxPanel(ScrolledWindow1, ID_PANEL2, wxDefaultPosition, wxSize(1439,9500), wxTAB_TRAVERSAL|wxFULL_REPAINT_ON_RESIZE, _T("ID_PANEL2"));
    StaticText1 = new wxStaticText(Panel2, ID_STATICTEXT1, _("Remaining Jedi: "), wxPoint(40,500), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(Panel2, ID_STATICTEXT2, _("Remaining Sith: "), wxPoint(40,525), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Remaining Monsters: "), wxPoint(40,550), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText4 = new wxStaticText(Panel2, ID_STATICTEXT4, _("None"), wxPoint(240,500), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText5 = new wxStaticText(Panel2, ID_STATICTEXT5, _("None"), wxPoint(240,525), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    StaticText6 = new wxStaticText(Panel2, ID_STATICTEXT6, _("None"), wxPoint(240,550), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticText7 = new wxStaticText(Panel2, ID_STATICTEXT7, _("Press F3 to run, or use the Simulation Parameters menu to start. Setting the parameters is currently disabled, due to wxWidgets complications."), wxPoint(8,450), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    ScrolledWindow2 = new wxScrolledWindow(Notebook1, ID_SCROLLEDWINDOW2, wxPoint(29,73), wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW2"));
    Panel3 = new wxPanel(ScrolledWindow2, ID_PANEL3, wxDefaultPosition, wxSize(1439,1500), wxTAB_TRAVERSAL|wxFULL_REPAINT_ON_RESIZE, _T("ID_PANEL3"));
    ScrolledWindow3 = new wxScrolledWindow(Notebook1, ID_SCROLLEDWINDOW3, wxPoint(83,112), wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW3"));
    Panel4 = new wxPanel(ScrolledWindow3, ID_PANEL4, wxDefaultPosition, wxSize(1439,1500), wxTAB_TRAVERSAL|wxFULL_REPAINT_ON_RESIZE, _T("ID_PANEL4"));
    ScrolledWindow4 = new wxScrolledWindow(Notebook1, ID_SCROLLEDWINDOW4, wxPoint(94,117), wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW4"));
    Panel5 = new wxPanel(ScrolledWindow4, ID_PANEL5, wxDefaultPosition, wxSize(1439,1500), wxTAB_TRAVERSAL|wxFULL_REPAINT_ON_RESIZE, _T("ID_PANEL5"));
    ScrolledWindow5 = new wxScrolledWindow(Notebook1, ID_SCROLLEDWINDOW5, wxPoint(85,129), wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW5"));
    Panel6 = new wxPanel(ScrolledWindow5, ID_PANEL6, wxDefaultPosition, wxSize(1439,1500), wxTAB_TRAVERSAL|wxFULL_REPAINT_ON_RESIZE, _T("ID_PANEL6"));
    ScrolledWindow6 = new wxScrolledWindow(Notebook1, ID_SCROLLEDWINDOW6, wxPoint(63,111), wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW6"));
    Panel7 = new wxPanel(ScrolledWindow6, ID_PANEL7, wxDefaultPosition, wxSize(1439,1500), wxTAB_TRAVERSAL|wxFULL_REPAINT_ON_RESIZE, _T("ID_PANEL7"));
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

    Panel2->Connect(wxEVT_PAINT,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnPanel2Paint,0,this);
    ScrolledWindow1->Connect(wxEVT_SIZE,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnScrolledWindow1Resize,0,this);
    Panel3->Connect(wxEVT_PAINT,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnPanel3Paint,0,this);
    Panel4->Connect(wxEVT_PAINT,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnPanel4Paint,0,this);
    Panel5->Connect(wxEVT_PAINT,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnPanel5Paint,0,this);
    Panel6->Connect(wxEVT_PAINT,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnPanel6Paint,0,this);
    Panel7->Connect(wxEVT_PAINT,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnPanel7Paint,0,this);
    ScrolledWindow6->Connect(wxEVT_MOUSEWHEEL,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnScrolledWindow6MouseWheel,0,this);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnQuit);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnAbout);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnSetData);
    Connect(ID_MENUITEM4,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnRun);
    Connect(wxEVT_MOUSEWHEEL,(wxObjectEventFunction)&Jedi_VS_SithFrame::OnScrolledWindow6MouseWheel);
    //*)

    //Initialize the values to their defaults
    numJedi = 300;
    numSith = 300;
    numArenas = 6;
    numObstacles = 300;
    columns = 25;
    rows = 25;
    numIterations = 100;

    //All this just initializes the windows and scroll bars
    ScrolledWindow1->SetVirtualSize(900, 9500);
    ScrolledWindow1->SetScrollbar(wxVERTICAL, 0, 25, 1500);
    ScrolledWindow1->SetScrollbar(wxHORIZONTAL, 0, 10, 15);
    ScrolledWindow1->AlwaysShowScrollbars();
    ScrolledWindow1->SetScrollRate(1,20);
    ScrolledWindow2->Show(false);

    ScrolledWindow2->SetVirtualSize(900,1500);
    ScrolledWindow2->SetScrollbar(wxVERTICAL, 0, 25, 162);
    ScrolledWindow2->SetScrollbar(wxHORIZONTAL, 0, 10, 45);
    ScrolledWindow2->AlwaysShowScrollbars();
    ScrolledWindow2->SetScrollRate(1,1);

    ScrolledWindow3->Show(false);
    ScrolledWindow3->SetVirtualSize(900,1500);
    ScrolledWindow3->SetScrollbar(wxVERTICAL, 0, 25, 162);
    ScrolledWindow3->SetScrollbar(wxHORIZONTAL, 0, 10, 45);
    ScrolledWindow3->AlwaysShowScrollbars();
    ScrolledWindow3->SetScrollRate(1,1);

    ScrolledWindow4->Show(false);
    ScrolledWindow4->SetVirtualSize(900,1500);
    ScrolledWindow4->SetScrollbar(wxVERTICAL, 0, 25, 162);
    ScrolledWindow4->SetScrollbar(wxHORIZONTAL, 0, 10, 45);
    ScrolledWindow4->AlwaysShowScrollbars();
    ScrolledWindow4->SetScrollRate(1,1);

    ScrolledWindow5->Show(false);
    ScrolledWindow5->SetVirtualSize(900,1500);
    ScrolledWindow5->SetScrollbar(wxVERTICAL, 0, 25, 162);
    ScrolledWindow5->SetScrollbar(wxHORIZONTAL, 0, 10, 45);
    ScrolledWindow5->AlwaysShowScrollbars();
    ScrolledWindow5->SetScrollRate(1,1);

    ScrolledWindow6->Show(false);
    ScrolledWindow6->SetVirtualSize(900,1500);
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
/*
    this->numJedi = temp.numJedi;
    this->numSith = temp.numSith;
    this->numArenas = temp.numArenas;
    this->numObstacles = temp.numObstacles;
    this->columns = temp.columns;
    this->rows = temp.rows;
    this->numIterations = temp.numIterations;
*/

}


void Jedi_VS_SithFrame::OnRun(wxCommandEvent& event)
{
    started = true;
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

    for(int r = 0; r < numArenas; r++)
    {
        arenaHolder.push_back( Arena(subArena, rows, columns) );
        arenaHolder[r].create3DArray();
        arenaHolder[r].fill3DArrayRandomly(numJedi, numSith, 20, numObstacles);

    }

    wxClientDC canvas1(Panel2);
    PrepareDC(canvas1);


        int offsetX = 5;
        int offsetY = 5;
        for(int i = 0; i < subArena; i++)
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

            offsetX = offsetX + (rows * 17);
        }

    for(int t = 0; t < numIterations; t++)
    {
        arenaHolder[0].callTick();
        arenaHolder[1].callTick();
        arenaHolder[2].callTick();
        arenaHolder[3].callTick();
        arenaHolder[4].callTick();
        arenaHolder[5].callTick();
        sleep(1);
        StaticText4->SetLabel(std::to_string(arenaHolder[0].numJedi));
        StaticText5->SetLabel(std::to_string(arenaHolder[0].numSith));
        StaticText6->SetLabel(std::to_string(arenaHolder[0].numMonsters));
        Panel2->Update();
        Panel2->Refresh();
        Panel3->Update();
        Panel3->Refresh();
        Panel4->Update();
        Panel4->Refresh();
        Panel5->Update();
        Panel5->Refresh();
        Panel6->Update();
        Panel6->Refresh();
        Panel7->Update();
        Panel7->Refresh();
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

void Jedi_VS_SithFrame::OnPanel2Paint(wxPaintEvent& event)
{
    if(!started)
    {
        //Prevents crashes
    }
    else{
    wxClientDC canvas1(Panel2);
    PrepareDC(canvas1);


        int offsetX = 5;
        int offsetY = 5;
        for(int i = 0; i < subArena; i++)
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

            offsetX = offsetX + (rows * 17);
        }
    }
}

void Jedi_VS_SithFrame::OnScrolledWindow2LeftUp(wxMouseEvent& event)
{

}

void Jedi_VS_SithFrame::OnScrolledWindow3LeftUp(wxMouseEvent& event)
{

}


void Jedi_VS_SithFrame::OnScrolledWindow4LeftUp(wxMouseEvent& event)
{


}

void Jedi_VS_SithFrame::OnScrolledWindow5LeftUp(wxMouseEvent& event)
{

}

void Jedi_VS_SithFrame::OnScrolledWindow6LeftUp(wxMouseEvent& event)
{

}

void Jedi_VS_SithFrame::OnScrolledWindow6MouseWheel(wxMouseEvent& event)
{
  //Disables mouse scroll but does nothing.
    for(int i = 0; i< 10; i++)
    {
        std::cout<<"This does nothing";
    }
}

void Jedi_VS_SithFrame::OnPanel3Paint(wxPaintEvent& event)
{

    if(!started)
    {
        //Prevents crashes
    }
    else{
    wxClientDC canvas1(Panel3);
    PrepareDC(canvas1);


        int offsetX = 5;
        int offsetY = 5;
        for(int i = 0; i < subArena; i++)
        {
            for(int j = 0; j < rows; j++)
            {
                for(int k = 0;k < columns; k++)
                {
                    if(arenaHolder[1].gameWorld[i][j][k] == 0)
                    {
                        canvas1.DrawText("--", j * 15 + offsetX, (k * 17) + offsetY);
                    }
                    else
                    {
                        canvas1.DrawText(arenaHolder[1].gameWorld[i][j][k]->teamIcon, j * 15 + offsetX, (k * 17) + offsetY);
                    }

                }
            }

            offsetX = offsetX + (rows * 17);
        }
    }
}

void Jedi_VS_SithFrame::OnPanel4Paint(wxPaintEvent& event)
{

    if(!started)
    {
        //Prevents crashes
    }
    else{
    wxClientDC canvas1(Panel4);
    PrepareDC(canvas1);


        int offsetX = 5;
        int offsetY = 5;
        for(int i = 0; i < subArena; i++)
        {
            for(int j = 0; j < rows; j++)
            {
                for(int k = 0;k < columns; k++)
                {
                    if(arenaHolder[2].gameWorld[i][j][k] == 0)
                    {
                        canvas1.DrawText("--", j * 15 + offsetX, (k * 17) + offsetY);
                    }
                    else
                    {
                        canvas1.DrawText(arenaHolder[2].gameWorld[i][j][k]->teamIcon, j * 15 + offsetX, (k * 17) + offsetY);
                    }

                }
            }

            offsetX = offsetX + (rows * 17);
        }
    }
}

void Jedi_VS_SithFrame::OnPanel5Paint(wxPaintEvent& event)
{
        if(!started)
    {
        //Prevents crashes
    }
    else{
    wxClientDC canvas1(Panel5);
    PrepareDC(canvas1);


        int offsetX = 5;
        int offsetY = 5;
        for(int i = 0; i < subArena; i++)
        {
            for(int j = 0; j < rows; j++)
            {
                for(int k = 0;k < columns; k++)
                {
                    if(arenaHolder[3].gameWorld[i][j][k] == 0)
                    {
                        canvas1.DrawText("--", j * 15 + offsetX, (k * 17) + offsetY);
                    }
                    else
                    {
                        canvas1.DrawText(arenaHolder[3].gameWorld[i][j][k]->teamIcon, j * 15 + offsetX, (k * 17) + offsetY);
                    }

                }
            }

            offsetX = offsetX + (rows * 17);
        }
    }
}

void Jedi_VS_SithFrame::OnPanel6Paint(wxPaintEvent& event)
{
    if(!started)
    {
        //Prevents crashes
    }
    else{
    wxClientDC canvas1(Panel6);
    PrepareDC(canvas1);


        int offsetX = 5;
        int offsetY = 5;
        for(int i = 0; i < subArena; i++)
        {
            for(int j = 0; j < rows; j++)
            {
                for(int k = 0;k < columns; k++)
                {
                    if(arenaHolder[4].gameWorld[i][j][k] == 0)
                    {
                        canvas1.DrawText("--", j * 15 + offsetX, (k * 17) + offsetY);
                    }
                    else
                    {
                        canvas1.DrawText(arenaHolder[4].gameWorld[i][j][k]->teamIcon, j * 15 + offsetX, (k * 17) + offsetY);
                    }

                }
            }

            offsetX = offsetX + (rows * 17);
        }
    }
}

void Jedi_VS_SithFrame::OnPanel7Paint(wxPaintEvent& event)
{
    if(!started)
    {
        //Prevents crashes
    }
    else{
    wxClientDC canvas1(Panel7);
    PrepareDC(canvas1);


        int offsetX = 5;
        int offsetY = 5;
        for(int i = 0; i < subArena; i++)
        {
            for(int j = 0; j < rows; j++)
            {
                for(int k = 0;k < columns; k++)
                {
                    if(arenaHolder[5].gameWorld[i][j][k] == 0)
                    {
                        canvas1.DrawText("--", j * 15 + offsetX, (k * 17) + offsetY);
                    }
                    else
                    {
                        canvas1.DrawText(arenaHolder[5].gameWorld[i][j][k]->teamIcon, j * 15 + offsetX, (k * 17) + offsetY);
                    }

                }
            }

            offsetX = offsetX + (rows * 17);
        }
    }
}
