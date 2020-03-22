/***************************************************************
 * Name:      Jedi_VS_SithApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2020-03-22
 * Copyright:  ()
 * License:
 **************************************************************/

#include "Jedi_VS_SithApp.h"

//(*AppHeaders
#include "Jedi_VS_SithMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Jedi_VS_SithApp);

bool Jedi_VS_SithApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Jedi_VS_SithFrame* Frame = new Jedi_VS_SithFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
