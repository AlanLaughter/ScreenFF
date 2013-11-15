/***************************************************************
 * Name:      ScreenFFMain.cpp
 * Purpose:   Desktop recording front end for ffmpeg
 * Author:    Alan Laughter (laughterrichard@aol.com)
 * Created:   2013-11-08
 * Copyright: Alan Laughter (Burnward.net)
 * License: GNU GPL v.3 or later
 **************************************************************/

#include "ScreenFFMain.h"
#include <wx/msgdlg.h>
#include <stdlib.h>
#include <wx/thread.h>

//(*InternalHeaders(ScreenFFFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(ScreenFFFrame)
const long ScreenFFFrame::ID_BUTTON1 = wxNewId();
const long ScreenFFFrame::ID_BUTTON2 = wxNewId();
const long ScreenFFFrame::ID_TEXTCTRL1 = wxNewId();
const long ScreenFFFrame::idMenuQuit = wxNewId();
const long ScreenFFFrame::idMenuAbout = wxNewId();
const long ScreenFFFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ScreenFFFrame,wxFrame)
    //(*EventTable(ScreenFFFrame)
    //*)
END_EVENT_TABLE()

ScreenFFFrame::ScreenFFFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(ScreenFFFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(275,181));
    Button1 = new wxButton(this, ID_BUTTON1, _("Start"), wxPoint(16,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("Stop"), wxPoint(16,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Time"), wxPoint(104,16), wxSize(160,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ScreenFFFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ScreenFFFrame::OnButton2Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ScreenFFFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ScreenFFFrame::OnAbout);
    //*)
}

ScreenFFFrame::~ScreenFFFrame()
{
    //(*Destroy(ScreenFFFrame)
    //*)
}

void ScreenFFFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void ScreenFFFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void ScreenFFFrame::OnButton2Click(wxCommandEvent& event)
{
}

void ScreenFFFrame::OnButton1Click(wxCommandEvent& event)
{
    system("ffmpeg\\bin\\ffmpeg -f dshow -i video=\"UScreenCapture\":audio=\"Microphone (2- Logitech USB Microphone)\" -r 30 -vcodec mpeg4 -q 12 -f mp4 -qscale 0 -vf crop=1366:768:0:0 output\\output.mp4");
}
