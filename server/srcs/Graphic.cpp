#include "Graphic.hpp"
#include "MainUI.hpp"

Graphic::Graphic(const int height, const int width, MainUI *parent)
{
	_parent = parent; 
	_width = width;
	_height = height;
	_grass = Lib::loadImage("./textures/grass.png");
	initSDL();
}

void	Graphic::initSDL()
{
	Lib::xSDL_Init(SDL_INIT_VIDEO | SDL_DOUBLEBUF);
	_screen = Lib::xSDL_SetVideoMode(960, 960, 32, SDL_HWSURFACE); 
	SDL_WM_SetCaption("Zappy Viewer", NULL);
	Lib::xTTF_Init();
}

bool 	Graphic::update()
{
	int key;

	while (SDL_PollEvent(&_event))
	{
		key = _event.key.keysym.sym;
		if (key == SDLK_ESCAPE || _event.type == SDL_QUIT)
			return (false);
	}
	draw();
	return (true);
}

void 	Graphic::apply_floor()
{	
	int x = 0;
	int y = 0;
	for (y = 0; y <= 30; y++)
	{
		for (x = 0; x <= 30; x++)
			Lib::applySurface(x * SP_SIZE, y * SP_SIZE, _grass, _screen);
	}
}

void 	Graphic::draw()
{
	apply_floor();
	Lib::xSDL_Flip(_screen);
}

Graphic::~Graphic()
{
	TTF_Quit();
	SDL_Quit();
}