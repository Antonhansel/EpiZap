#ifndef GRAPHIC_HPP_
# define  GRAPHIC_HPP_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "LibSDL.hh"

# define NB_SPRITE 10
# define NB_FLOORTEXT 3
# define SP_SIZE 32

class MainUI;
class Graphic
{
public:
	Graphic(const int, const int, MainUI *);
	void initSDL();
	bool update();
	void draw();
	void apply_floor();
	~Graphic();
private:
	int				_width;
	int				_height;
	SDL_Surface	 	*_grass;
	SDL_Surface		*_screen;
	SDL_Surface		*_floor[NB_FLOORTEXT];
	SDL_Surface		*_player[NB_SPRITE];
	TTF_Font		*_font;
	SDL_Event 		_event;
	MainUI			*_parent;
};

#endif /* !GRAPHIC_HPP_ */