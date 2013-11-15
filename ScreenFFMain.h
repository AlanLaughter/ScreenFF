/***************************************************************
 * Name:      ScreenFFMain.h
 * Purpose:   Defines Application Frame
 * Author:    Alan Laughter (laughterrichard@aol.com)
 * Created:   2013-11-08
 * Copyright: Alan Laughter (Burnward.net)
 * License:
 **************************************************************/

#ifndef SCREENFFMAIN_H
#define SCREENFFMAIN_H

//(*Headers(ScreenFFFrame)
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class ScreenFFFrame: public wxFrame
{
    public:

        ScreenFFFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~ScreenFFFrame();

    private:

        //(*Handlers(ScreenFFFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(ScreenFFFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_TEXTCTRL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(ScreenFFFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // SCREENFFMAIN_H
