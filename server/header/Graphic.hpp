#ifndef GRAPHIC_HPP_
# define  GRAPHIC_HPP_

# include <map>
# include <QtCore>
# include <QWidget>
# include <SDL/SDL.h>
# include <SDL/SDL_ttf.h>
# include <SDL/SDL_rotozoom.h>
# include <SDL/SDL_mixer.h>
# include <utility>
# include "LibSDL.hh"
# include "Map.h"
# include "Server.h"

#undef main

# include <QMouseEvent>

# define NB_SPRITE 4
# define NB_FLOORTEXT 8
# define SP_SIZE 64
# define NB_RESSOURCE 7
# define FIELD_Y 11
# define FIELD_X 22

class MainUI;
class Graphic : public QWidget
{
	Q_OBJECT
public:
	Graphic(MainUI *);
	void 	displayPlayers();
	void 	initSDL();
	bool 	update();
	void 	draw();
	void 	apply_floor();
	void 	loader();
	void 	loopHud();
	void 	teamName();
	void 	initRealUpdate(const Server *);
	void 	mouseReleaseEvent(QMouseEvent *);
  	void 	mousePressEvent(QMouseEvent *);
  	void 	mouseMoveEvent(QMouseEvent *);
  	void 	dragMouse();
  	void 	caseClicked();
  	void 	addPlayerHud(Player *);
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
	SDL_Surface		*_ressource[NB_RESSOURCE];
	TTF_Font		*_font;
	SDL_Event 		_event;
	MainUI			*_parent;
	bool 			_mouseClick;
	bool 			_mouseDrag;
	bool 			_realUpdate;
	QPoint			_currentPos;
	QPoint 			_lastPointPress;
	QPoint			_lastPointReleased;
	Map 			*_map;
	Server			*_server;
	int 			_viewx;
	int 			_viewy;
	std::map<ROCK, std::pair<QString, int> > _stuff;
	std::vector<std::string> 	_teamName;
	bool 			_mouseReleased;

 private:
 	SDL_Surface		*_bot[NB_SPRITE];
};

#endif /* !GRAPHIC_HPP_ */