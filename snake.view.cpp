#include "snake.view.h"
#include "snake.model.h"

BEGIN_EVENT_TABLE(SnakeView,wxFrame)
	EVT_CLOSE(SnakeView::OnClose)
	EVT_PAINT(SnakeView::paintEvent)
	EVT_TIMER(ID_TIMER,SnakeView::TimerTimer)
	EVT_KEY_DOWN(SnakeView::KeyDown)
END_EVENT_TABLE()

SnakeView::SnakeView(
	wxWindow *parent, 
	wxWindowID id, 
	const wxString &title, 
	const wxPoint &position, 
	const wxSize& size, 
	long style
) : wxFrame(parent, id, title, position, size, style)
{
	Timer = new wxTimer();
	Timer->SetOwner(this, ID_TIMER);
	Timer->Start(100);
	
	scord = new Snake(600, 400);
	direzione = Snake::SNAKE_DESTRA;
	finito = false;
	
	this->SetTitle(wxT("Snake : 0"));
	this->SetIcon(wxNullIcon);
	this->Center();
	this->SetSize(0,0,600,400);
}

SnakeView::~SnakeView()
{
}

void SnakeView::OnClose(wxCloseEvent& event)
{
	Destroy();
}

void SnakeView::KeyDown(wxKeyEvent& event)
{
	switch (event.GetKeyCode())
		{
		case WXK_UP:
			if (direzione == Snake::SNAKE_SOTTO)
				{
				direzione = Snake::SNAKE_SOTTO;
				}
			else
				direzione = Snake::SNAKE_SOPRA;
			break;
		case WXK_DOWN:
			if (direzione == Snake::SNAKE_SOPRA)
				direzione = Snake::SNAKE_SOPRA;
			else
				direzione = Snake::SNAKE_SOTTO;
			break;
		case WXK_LEFT:
			if (direzione == Snake::SNAKE_DESTRA)
				direzione = Snake::SNAKE_DESTRA;
			else
				direzione = Snake::SNAKE_SINISTRA;
			break;
		case WXK_RIGHT:
			if (direzione == Snake::SNAKE_SINISTRA)
				direzione = Snake::SNAKE_SINISTRA;
			else
				direzione = Snake::SNAKE_DESTRA;
			break;
		}
}

void SnakeView::TimerTimer(wxTimerEvent& event)
{
	if (!finito)
		{
		wxClientDC dc(this);
		int risultato = scord->muoviSerpente (&dc, direzione);
		if (risultato == Snake::VIVO)
			{
			scord->stampaSerpente(&dc);
			wxString risultato (wxT("Snake : "));
			risultato << scord->getPunteggio();
			this->SetTitle(risultato);
			}
		else
			{
			finito = true;
			unsigned int punti = scord->getPunteggio ();
			wxString risultato (wxT("Hai totalizzato "));
			risultato << punti;
			if (punti == 1)
					risultato << " punto";
			else
					risultato << " punti";
			wxMessageBox(risultato, wxT("Game over"), wxOK);
			}
		}
}

void SnakeView::paintEvent(wxPaintEvent& evt)
{
	wxPaintDC dc(this);
	scord->stampaSerpente(&dc);
}
