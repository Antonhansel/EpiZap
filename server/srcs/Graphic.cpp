#include "Graphic.hpp"
#include "MainUI.hpp"

Graphic::Graphic(const int height, const int width, MainUI *parent)
{
	_parent = parent; 
	_width = width;
	_height = height;
	initSDL();
}

Graphic::~Graphic()
{
	SDL_FreeSurface(_screen);
	SDL_FreeSurface(_grass);
	Mix_FreeMusic(_music);
	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();
}

void	Graphic::initSDL()
{
	Lib::xSDL_Init(SDL_INIT_VIDEO | SDL_DOUBLEBUF);
	_screen = Lib::xSDL_SetVideoMode(960, 960, 32, SDL_HWSURFACE); 
	SDL_WM_SetCaption("Zappy Viewer", NULL);
	Lib::xTTF_Init();
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	_music = Mix_LoadMUS("./music/main.mp3");
	Mix_PlayMusic(_music, -1);
	loader();
}

bool 	Graphic::update()
{
	int key;
	while (SDL_PollEvent(&_event))
	{
		key = _event.key.keysym.sym;
		if (key == SDLK_ESCAPE || _event.type == SDL_QUIT)
			return (false);
		if (_event.button.button == SDL_BUTTON_LEFT)
		{
			int x, y;
			SDL_GetMouseState(&x, &y);
			std::cout << "x: " << x << " - y:" << y << std::endl;
		}
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

void 	Graphic::loader()
{
	_grass = Lib::loadImage("./textures/grass.png");
}
