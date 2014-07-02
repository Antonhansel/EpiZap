#ifndef GRAPHIC_HPP_
# define  GRAPHIC_HPP_

# include <QtCore>
# include <QWidget>
# include <SDL/SDL.h>
# include <SDL/SDL_ttf.h>
# include <SDL/SDL_mixer.h>
# include <utility>
# include "LibSDL.hh"
# include "Map.h"
#undef main

# include <QMouseEvent>

# define NB_SPRITE 10
# define NB_FLOORTEXT 8
# define SP_SIZE 64
# define NB_RESSOURCE 7

class MainUI;
class Graphic : public QWidget
{
	Q_OBJECT
public:
	Graphic(MainUI *);
	void 	initSDL();
	bool 	update();
	void 	draw();
	void 	apply_floor();
	void 	loader();
	void 	initRealUpdate(Map *);
	void 	mouseReleaseEvent(QMouseEvent *);
  	void 	mousePressEvent(QMouseEvent *);
  	void 	caseClicked();
  	void 	updateHud(const int, const int);
	~Graphic();
private:
	int 			_xhud;
	int 			_yhud;
	int				_width;
	int				_height;
	Mix_Music		*_music;
	SDL_Surface		*_screen;
	SDL_Surface		*_floor[NB_FLOORTEXT];
	SDL_Surface		*_player[NB_SPRITE];
	SDL_Surface		*_ressource[NB_RESSOURCE];
	TTF_Font		*_font;
	SDL_Event 		_event;
	MainUI			*_parent;
	bool 			_mouseClick;
	bool 			_mouseDrag;
	bool 			_realUpdate;
	QPoint 			_lastPointPress;
	QPoint			_lastPointReleased;
	Map 			*_map;
	int 			_viewx;
	int 			_viewy;
	std::map<ROCK, std::pair<QString, int> > _stuff;
};

#endif /* !GRAPHIC_HPP_ */