#include "Graphic.hpp"

Graphic::Graphic(const int height, const int width)
{
	_width = width;
	_height = height;
}

void	Graphic::initSDL()
{
	Lib::xSDL_Init(SDL_INIT_VIDEO | SDL_DOUBLEBUF);
	_screen = Lib::xSDL_SetVideoMode(1200, 800, 32, SDL_HWSURFACE); 
	SDL_WM_SetCaption("Zappy", NULL);
	Lib::xTTF_Init();
}

Graphic::~Graphic()
{
	TTF_Quit();
	SDL_Quit();
}