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
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/scrolwin.h>
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
        void OnRun(wxCommandEvent& event);
        void OnScrolledWindow1Paint(wxPaintEvent& event);
        void OnScrolledWindow1Resize(wxSizeEvent& event);
        //*)

        //(*Identifiers(Jedi_VS_SithFrame)
        static const long ID_SCROLLEDWINDOW1;
        static const long ID_SCROLLEDWINDOW2;
        static const long ID_SCROLLEDWINDOW3;
        static const long ID_SCROLLEDWINDOW4;
        static const long ID_SCROLLEDWINDOW5;
        static const long ID_SCROLLEDWINDOW6;
        static const long ID_NOTEBOOK1;
        static const long ID_PANEL1;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM3;
        static const long ID_MENUITEM4;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Jedi_VS_SithFrame)
        wxMenu* Menu1;
        wxMenu* Menu2;
        wxMenu* Menu3;
        wxMenuBar* MenuBar1;
        wxMenuItem* MenuItem1;
        wxMenuItem* MenuItem2;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxNotebook* Notebook1;
        wxPanel* Panel1;
        wxScrolledWindow* ScrolledWindow1;
        wxScrolledWindow* ScrolledWindow2;
        wxScrolledWindow* ScrolledWindow3;
        wxScrolledWindow* ScrolledWindow4;
        wxScrolledWindow* ScrolledWindow5;
        wxScrolledWindow* ScrolledWindow6;
        wxStatusBar* StatusBar1;
        //*)

        int numJedi;
		int numSith;
		int numArenas;
		int numObstacles;
		int columns;
		int rows;
		int numIterations;
		void updateVirtualSize();

        DECLARE_EVENT_TABLE()
};

#endif // JEDI_VS_SITHMAIN_H
