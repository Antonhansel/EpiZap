#ifndef GRAPHIC_HPP_
# define  GRAPHIC_HPP_

# include <QtCore>
# include <QWidget>
# include <SDL/SDL.h>
# include <SDL/SDL_ttf.h>
# include <SDL/SDL_mixer.h>
# include "LibSDL.hh"
# include "Map.h"
#undef main

# include <QMouseEvent>

# define NB_SPRITE 10
# define NB_FLOORTEXT 3
# define SP_SIZE 64

class MainUI;
class Graphic : public QWidget
{
	Q_OBJECT
public:
	Graphic(MainUI *);
	void initSDL();
	bool update();
	void draw();
	void apply_floor();
	void loader();
	void initRealUpdate(Map *);
	void  mouseReleaseEvent(QMouseEvent *);
  	void  mousePressEvent(QMouseEvent *);
	~Graphic();
private:
	int				_width;
	int				_height;
	Mix_Music		*_music;
	SDL_Surface	 	*_grass;
	SDL_Surface		*_screen;
	SDL_Surface		*_floor[NB_FLOORTEXT];
	SDL_Surface		*_player[NB_SPRITE];
	TTF_Font		*_font;
	SDL_Event 		_event;
	MainUI			*_parent;
	bool 			_mouseClick;
	bool 			_mouseDrag;
	bool 			_realUpdate;
	QPoint 			_lastPointPress;
	QPoint			_lastPointReleased;
	Map 			*_map;
};

#endif /* !GRAPHIC_HPP_ */