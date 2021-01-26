#ifndef __SNAKE_VIEW_h__
#define __SNAKE_VIEW_h__

#include "snake.model.h"

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
	#include <wx/dc.h>
	#include <wx/defs.h>
	#include <wx/msgdlg.h>
	#include <wx/string.h>
	#include <wx/stattext.h>
#else
	#include <wx/wxprec.h>
#endif

class SnakeView : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		wxTimer *Timer;
		Snake *scord;
		int direzione;
		bool finito;
		wxStaticText *indicatorePunteggio;
	public:
		SnakeView(
			wxWindow *parent, wxWindowID id = wxID_ANY, 
			const wxString &title = wxT("Snake"), 
			const wxPoint& pos = wxDefaultPosition, 
			const wxSize& size = wxSize(600, 400), 
			long style = wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
		);
		virtual ~SnakeView();
		void KeyDown(wxKeyEvent& event);
		void TimerTimer(wxTimerEvent& event);
		void paintEvent(wxPaintEvent& evt);
	private:
		enum
		{
			ID_TIMER = 1002
		};
		
	private:
		void OnClose(wxCloseEvent& event);
};

#endif
