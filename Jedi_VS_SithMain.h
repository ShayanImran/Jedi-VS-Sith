/***************************************************************
 * Name:      Jedi_VS_SithMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2020-03-22
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef JEDI_VS_SITHMAIN_H
#define JEDI_VS_SITHMAIN_H

//(*Headers(Jedi_VS_SithFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
//*)

class Jedi_VS_SithFrame: public wxFrame
{
    public:

        Jedi_VS_SithFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Jedi_VS_SithFrame();

    private:

        //(*Handlers(Jedi_VS_SithFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnSetData(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(Jedi_VS_SithFrame)
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long idMenuSimulation;
        static const long ID_MENUITEM1;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Jedi_VS_SithFrame)
        wxMenuItem* MenuItem4;
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        //*)

        int numJedi;
		int numSith;
		int numArenas;
		int numObstacles;
		int columns;
		int rows;
		int numIterations;

        DECLARE_EVENT_TABLE()
};

#endif // JEDI_VS_SITHMAIN_H
