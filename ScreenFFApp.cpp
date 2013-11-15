/***************************************************************
 * Name:      ScreenFFApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Alan Laughter (laughterrichard@aol.com)
 * Created:   2013-11-08
 * Copyright: Alan Laughter (Burnward.net)
 * License:
 **************************************************************/

#include "ScreenFFApp.h"

//(*AppHeaders
#include "ScreenFFMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ScreenFFApp);

bool ScreenFFApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ScreenFFFrame* Frame = new ScreenFFFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
