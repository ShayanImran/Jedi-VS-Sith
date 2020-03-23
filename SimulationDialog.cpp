#include "SimulationDialog.h"
#include <wx/msgdlg.h>
//(*InternalHeaders(SimulationDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(SimulationDialog)
const long SimulationDialog::ID_SPINCTRL1 = wxNewId();
const long SimulationDialog::ID_SPINCTRL2 = wxNewId();
const long SimulationDialog::ID_SPINCTRL3 = wxNewId();
const long SimulationDialog::ID_SPINCTRL4 = wxNewId();
const long SimulationDialog::ID_SPINCTRL5 = wxNewId();
const long SimulationDialog::ID_SPINCTRL6 = wxNewId();
const long SimulationDialog::ID_STATICTEXT1 = wxNewId();
const long SimulationDialog::ID_STATICTEXT2 = wxNewId();
const long SimulationDialog::ID_STATICTEXT3 = wxNewId();
const long SimulationDialog::ID_STATICTEXT4 = wxNewId();
const long SimulationDialog::ID_STATICTEXT5 = wxNewId();
const long SimulationDialog::ID_STATICTEXT6 = wxNewId();
const long SimulationDialog::ID_SPINCTRL7 = wxNewId();
const long SimulationDialog::ID_STATICTEXT7 = wxNewId();
const long SimulationDialog::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SimulationDialog,wxDialog)
	//(*EventTable(SimulationDialog)
	//*)
END_EVENT_TABLE()

SimulationDialog::SimulationDialog(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(SimulationDialog)
	Create(parent, wxID_ANY, _("Simulation Parameters"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(400,200));
	SpinCtrl1 = new wxSpinCtrl(this, ID_SPINCTRL1, _T("200"), wxPoint(100,25), wxSize(60,25), 0, 0, 2000, 200, _T("ID_SPINCTRL1"));
	SpinCtrl1->SetValue(_T("200"));
	SpinCtrl2 = new wxSpinCtrl(this, ID_SPINCTRL2, _T("200"), wxPoint(100,65), wxSize(60,25), 0, 0, 2000, 200, _T("ID_SPINCTRL2"));
	SpinCtrl2->SetValue(_T("200"));
	SpinCtrl3 = new wxSpinCtrl(this, ID_SPINCTRL3, _T("1"), wxPoint(100,105), wxSize(60,25), 0, 1, 6, 1, _T("ID_SPINCTRL3"));
	SpinCtrl3->SetValue(_T("1"));
	SpinCtrl4 = new wxSpinCtrl(this, ID_SPINCTRL4, _T("500"), wxPoint(100,145), wxSize(60,25), 0, 1, 2000, 500, _T("ID_SPINCTRL4"));
	SpinCtrl4->SetValue(_T("500"));
	SpinCtrl5 = new wxSpinCtrl(this, ID_SPINCTRL5, _T("70"), wxPoint(304,25), wxSize(60,25), 0, 10, 70, 70, _T("ID_SPINCTRL5"));
	SpinCtrl5->SetValue(_T("70"));
	SpinCtrl6 = new wxSpinCtrl(this, ID_SPINCTRL6, _T("25"), wxPoint(304,65), wxSize(60,25), 0, 2, 25, 25, _T("ID_SPINCTRL6"));
	SpinCtrl6->SetValue(_T("25"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Jedi: "), wxPoint(16,30), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Sith: "), wxPoint(16,70), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Arenas: "), wxPoint(16,110), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Obstacles: "), wxPoint(16,150), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Columns: "), wxPoint(225,30), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Rows: "), wxPoint(225,70), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	SpinCtrl7 = new wxSpinCtrl(this, ID_SPINCTRL7, _T("1000"), wxPoint(304,105), wxSize(60,25), 0, 1, 10000, 1000, _T("ID_SPINCTRL7"));
	SpinCtrl7->SetValue(_T("1000"));
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Iterations: "), wxPoint(225,110), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Done"), wxPoint(250,145), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));

	Connect(ID_SPINCTRL1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&SimulationDialog::OnSpinCtrl1Change);
	Connect(ID_SPINCTRL2,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&SimulationDialog::OnSpinCtrl2Change);
	Connect(ID_SPINCTRL3,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&SimulationDialog::OnSpinCtrl3Change);
	Connect(ID_SPINCTRL4,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&SimulationDialog::OnSpinCtrl4Change);
	Connect(ID_SPINCTRL5,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&SimulationDialog::OnSpinCtrl5Change);
	Connect(ID_SPINCTRL6,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&SimulationDialog::OnSpinCtrl6Change);
	Connect(ID_SPINCTRL7,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&SimulationDialog::OnSpinCtrl7Change);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SimulationDialog::OnButton1Click);
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

SimulationDialog::~SimulationDialog()
{
	//(*Destroy(SimulationDialog)
	//*)
}

/*
* Closes the popup dialog.
*/
void SimulationDialog::OnButton1Click(wxCommandEvent& event)
{
    Close(true);
}
/*
* Updates the value of the number of Jedi in the simulation(s)
*/
void SimulationDialog::OnSpinCtrl1Change(wxSpinEvent& event)
{
    numJedi = event.GetValue();
}
/*
* Updates the value of the number of Sith in the simulation(s)
*/
void SimulationDialog::OnSpinCtrl2Change(wxSpinEvent& event)
{
    numSith = event.GetValue();
}
/*
* Updates the value of the number of arenas used in the simulation(s)
*/
void SimulationDialog::OnSpinCtrl3Change(wxSpinEvent& event)
{
    numArenas = event.GetValue();
}
/*
* Updates the value of the number of obstacles in the simulation(s)
*/
void SimulationDialog::OnSpinCtrl4Change(wxSpinEvent& event)
{
    numObstacles = event.GetValue();
}
/*
* Updates the value of the columns that make up the arena.
*/
void SimulationDialog::OnSpinCtrl5Change(wxSpinEvent& event)
{
    columns = event.GetValue();
}
/*
* Updates the value of the number of rows that make up the arena.
*/
void SimulationDialog::OnSpinCtrl6Change(wxSpinEvent& event)
{
    rows = event.GetValue();
}
/*
* Updates the value of the number iterations that the simulation will run.
*/
void SimulationDialog::OnSpinCtrl7Change(wxSpinEvent& event)
{
    numIterations = event.GetValue();
}
