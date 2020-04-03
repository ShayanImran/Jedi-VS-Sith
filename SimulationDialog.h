#ifndef SIMULATIONDIALOG_H
#define SIMULATIONDIALOG_H

//(*Headers(SimulationDialog)
#include <wx/spinctrl.h>
#include <wx/dialog.h>
#include <wx/button.h>
#include <wx/stattext.h>
//*)
#include "Jedi_VS_SithMain.h"

class SimulationDialog: public wxDialog
{
	public:

		SimulationDialog(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~SimulationDialog();

		//(*Declarations(SimulationDialog)
		wxSpinCtrl* SpinCtrl4;
		wxSpinCtrl* SpinCtrl7;
		wxButton* Button1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxSpinCtrl* SpinCtrl3;
		wxSpinCtrl* SpinCtrl5;
		wxStaticText* StaticText7;
		wxSpinCtrl* SpinCtrl2;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText2;
		wxStaticText* StaticText6;
		wxSpinCtrl* SpinCtrl1;
		wxSpinCtrl* SpinCtrl6;
		//*)

	protected:

		//(*Identifiers(SimulationDialog)
		static const long ID_SPINCTRL1;
		static const long ID_SPINCTRL2;
		static const long ID_SPINCTRL3;
		static const long ID_SPINCTRL4;
		static const long ID_SPINCTRL5;
		static const long ID_SPINCTRL6;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_SPINCTRL7;
		static const long ID_STATICTEXT7;
		static const long ID_BUTTON1;
		//*)

		int numJedi;
		int numSith;
		int numArenas;
		int numObstacles;
		int columns;
		int rows;
		int numIterations;

		friend class Jedi_VS_SithFrame;
		//friend

	private:

		//(*Handlers(SimulationDialog)
		void OnButton1Click(wxCommandEvent& event);
		void OnSpinCtrl1Change(wxSpinEvent& event);
		void OnSpinCtrl2Change(wxSpinEvent& event);
		void OnSpinCtrl3Change(wxSpinEvent& event);
		void OnSpinCtrl4Change(wxSpinEvent& event);
		void OnSpinCtrl5Change(wxSpinEvent& event);
		void OnSpinCtrl6Change(wxSpinEvent& event);
		void OnSpinCtrl7Change(wxSpinEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
