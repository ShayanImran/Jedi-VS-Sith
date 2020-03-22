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
        //*)

        //(*Identifiers(Jedi_VS_SithFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Jedi_VS_SithFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // JEDI_VS_SITHMAIN_H
