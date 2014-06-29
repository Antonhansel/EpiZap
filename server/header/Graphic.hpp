#ifndef GRAPHIC_HPP_
# define  GRAPHIC_HPP_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "LibSDL.hh"

# define NB_SPRITE 10

class Graphic
{
public:
	Graphic(const int, const int);
	void initSDL();
	~Graphic();

private:
	int				_width;
	int				_height;
	SDL_Surface		*_screen;
	SDL_Surface		*_floor;
	SDL_Surface		*_player[NB_SPRITE];
	TTF_Font		*_font;

};

#endif /* !GRAPHIC_HPP_ */