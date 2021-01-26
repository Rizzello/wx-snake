#ifndef __SNAKE_MODEL_h__
#define __SNAKE_MODEL_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
	#include <wx/thread.h>
	#include <wx/dc.h>
	#include <wx/pen.h>
	#include <wx/brush.h>
	#include <wx/msgdlg.h>
	#include <cstdlib>
	#include <ctime>
	#include <deque>
#else
	#include <wx/wxprec.h>
#endif

#define SNAKE_MAX_X 50
#define SNAKE_MAX_Y 50

class Snake
{
	private:
		wxCoord larghezza, altezza;
		wxCoord griglia_y[SNAKE_MAX_Y];
		wxCoord griglia_x[SNAKE_MAX_X];
		wxCoord raggio_piccolo;
		wxCoord raggio_grande;
		
		bool cresci;
		unsigned int direzione_precedente;
		unsigned int punteggio;
		
		unsigned int cibo_x;
		unsigned int cibo_y;
		std::deque<unsigned int> x;
		std::deque<unsigned int> y;
	public:
		enum {
			SNAKE_SOPRA = 10, 
			SNAKE_SOTTO =12, 
			SNAKE_SINISTRA = 13, 
			SNAKE_DESTRA = 15, 
			MORTO = 20, 
			VIVO
		};
	public:
		Snake (wxCoord larghezza, wxCoord altezza);
		int muoviSerpente (wxDC *dc, int direzione);
		void stampaSerpente (wxDC *dc);
		void stampaPunteggio (wxDC *dc);
		bool controlloSerpente ();
		void generaCibo ();
		unsigned int getPunteggio ();
};

#endif
