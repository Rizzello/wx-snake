#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

#ifdef HAVE_CONFIG_H
	#include <config.h>
#endif

#include "snake.view.h"
#include "snake.model.h"

class Main : public wxApp
{
	public:
		virtual bool OnInit();
		virtual int OnExit();
};

IMPLEMENT_APP(Main)

bool Main::OnInit()
{
	SnakeView* frame = new SnakeView(NULL);
	SetTopWindow(frame);
	frame->Show();
	return TRUE;
}

int Main::OnExit ()
{
	return 0;
}
