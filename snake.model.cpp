#include "snake.model.h"

Snake::Snake (wxCoord larghezza_, wxCoord altezza_)
{
	larghezza = larghezza_;
	altezza = altezza_;
		
	wxCoord partizione_altezza = altezza_/SNAKE_MAX_Y;
	wxCoord partizione_larghezza = larghezza_/SNAKE_MAX_X;
	
	direzione_precedente = SNAKE_DESTRA;
	
	generaCibo ();
	cresci = false;
	punteggio = 0;
	
	raggio_piccolo = (partizione_altezza < partizione_larghezza) 
		? partizione_altezza/2 
		: partizione_larghezza/2;

	raggio_grande = (partizione_altezza < partizione_larghezza) 
		? 2*partizione_altezza/3 
		: 2*partizione_larghezza/3;
	
	griglia_y[0] = partizione_altezza/2;
	for (unsigned int i = 1; i < SNAKE_MAX_Y; i++)
		griglia_y[i] = griglia_y[i-1]+partizione_altezza;
	
	griglia_x[0] = partizione_larghezza/2;
	for (unsigned int i = 1; i < SNAKE_MAX_X; i++)
		griglia_x[i] = griglia_x[i-1]+partizione_larghezza;	
	
	x.push_back(0);
	x.push_back(1);
	x.push_back(2);
	x.push_back(3);
	x.push_back(4);
	x.push_back(5);
	x.push_back(6);
	x.push_back(7);
	x.push_back(8);
	x.push_back(9);
	y.push_back(0);
	y.push_back(0);
	y.push_back(0);
	y.push_back(0);
	y.push_back(0);
	y.push_back(0);
	y.push_back(0);
	y.push_back(0);
	y.push_back(0);
	y.push_back(0);
}

int Snake::muoviSerpente (wxDC *dc, int direzione)
{
	if (cresci)
		{
		cresci = false;
		switch (direzione)
			{
			case SNAKE_DESTRA:
				x.push_back((x.back()+1)%SNAKE_MAX_X);
				y.push_back(y.back());
				break;
			case SNAKE_SINISTRA:
				{
				unsigned int tmp = x.back();
				x.push_back((tmp) ? tmp-1 : SNAKE_MAX_X-1);
				y.push_back(y.back());
				break;
				}
			case SNAKE_SOPRA:
				{
				unsigned int tmp = y.back();
				y.push_back((tmp) ? tmp-1 : SNAKE_MAX_Y-1);
				x.push_back(x.back());
				break;
				}
			case SNAKE_SOTTO:
				y.push_back((y.back()+1)%SNAKE_MAX_Y);
				x.push_back(x.back());
				break;
			}
		}
	else
		{
		for (unsigned int i = 0; i < x.size()-1; i++)
			{
			x[i] = x[i+1];
			y[i] = y[i+1];
			}
		switch (direzione)
			{
			case SNAKE_DESTRA:
				x[x.size()-1] = (x[x.size()-1]+1)%SNAKE_MAX_X;
				break;
			case SNAKE_SINISTRA:
				{
				unsigned int tmp = x[x.size()-1];
				x[x.size()-1] = (tmp) ? tmp-1 : SNAKE_MAX_X-1;
				break;
				}
			case SNAKE_SOPRA:
				{
				unsigned int tmp = y[y.size()-1];
				y[y.size()-1] = (tmp) ? tmp-1 : SNAKE_MAX_Y-1;
				break;
				}
			case SNAKE_SOTTO:
				y[y.size()-1] = (y[y.size()-1]+1)%SNAKE_MAX_Y;
				break;
			}
		}
	return (controlloSerpente ()) ? VIVO : MORTO;
}

void Snake::stampaPunteggio (wxDC *dc)
{
	dc->SetTextForeground(*wxBLUE);
	wxString punti = wxT("Punteggio: ")+punteggio;
	
	dc->DrawText(punti, griglia_x[20], griglia_y[20]);
}

void Snake::stampaSerpente (wxDC *dc)
{
	dc->SetTextForeground(*wxBLUE);
	wxString punti = wxT("Punteggio: ")+punteggio;
	
	dc->DrawText(punti, griglia_x[20], griglia_y[20]);
	
	dc->SetBackground(*wxWHITE_BRUSH);
	dc->SetPen(*wxBLACK_PEN);
	dc->DrawRectangle(wxCoord(0), wxCoord(0), larghezza, altezza);
	dc->SetPen(wxColour(0xff, 0, 0));
	
	dc->DrawCircle(griglia_x[cibo_x], griglia_y[cibo_y], raggio_piccolo);
	dc->DrawCircle(griglia_x[cibo_x], griglia_y[cibo_y], raggio_grande);
		
	dc->SetBackground(wxColour(0x36, 0xff, 0x00));
	dc->SetPen(wxColour(0x36, 0xff, 0x00));
	
	unsigned int i;
	for (i = 0; i < x.size()-2; i++)
		{
		dc->DrawCircle(griglia_x[x[i]], griglia_y[y[i]], raggio_grande);
		dc->DrawCircle(griglia_x[x[i]], griglia_y[y[i]], raggio_piccolo);
		}
	dc->DrawCircle(griglia_x[x[i]], griglia_y[y[i]], raggio_grande);
	dc->DrawCircle(griglia_x[x[i]], griglia_y[y[i]], raggio_piccolo);
	dc->DrawCircle(griglia_x[x[i]], griglia_y[y[i]], raggio_grande/2);
	dc->DrawCircle(griglia_x[x[i]], griglia_y[y[i]], raggio_piccolo/2);
}

bool Snake::controlloSerpente ()
{
	for (unsigned int i = 0; i < x.size(); i++)
		for (unsigned int j = i+1; j < x.size(); j++)
			if (x[i] == x[j] && y[i] == y[j])
				return false;
	
	if (x.back() == cibo_x && y.back() == cibo_y)
		{
		cresci = true;
		generaCibo ();
		punteggio++;
		}
	return true;
}

void Snake::generaCibo ()
{
	std::srand((unsigned int) time(NULL));
	cibo_x = std::rand() % SNAKE_MAX_X;
	cibo_y = std::rand() % SNAKE_MAX_Y;
}

unsigned int Snake::getPunteggio ()
{
	return punteggio;
}
