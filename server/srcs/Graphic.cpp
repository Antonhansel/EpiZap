#include "Graphic.hpp"
#include "MainUI.hpp"

Graphic::Graphic(const int height, const int width, MainUI *parent)
{
	char windowid[64];
	sprintf(windowid, "SDL_WINDOWID=0x%llx", winId());
	SDL_putenv(windowid);
	setAttribute(Qt::WA_NoSystemBackground);
	setAttribute(Qt::WA_OpaquePaintEvent);
	setFocusPolicy(Qt::StrongFocus);
	setAttribute(Qt::WA_InputMethodEnabled);
	//move(size().height());
 	// resize(Size);
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
	_screen = Lib::xSDL_SetVideoMode(1440, 704, 32, SDL_HWSURFACE); 
	//_screen = Lib::xSDL_SetVideoMode(size().height(), size().width(), 32, SDL_HWSURFACE); 
	std::cout << size().height() << " - " << size().width() << std::endl;
	SDL_WM_SetCaption("Zappy Viewer", NULL);
	Lib::xTTF_Init();
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	_music = Mix_LoadMUS("./music/main.mp3");
	Mix_PlayMusic(_music, -1);
	loader();
}

bool 	Graphic::update()
{
	std::cout << size().height() << " " << size().width() << std::endl;
	int key;
	while (SDL_PollEvent(&_event))
	{
		std::cout << "Event!" << std::endl;
		key = _event.key.keysym.sym;
		if (key == SDLK_ESCAPE || _event.type == SDL_QUIT)
			return (false);
		if (_event.button.button == SDL_BUTTON_LEFT)
		{
			int x, y;
			SDL_GetMouseState(&x, &y);
			std::cout << "x: " << (x/64) << " - y:" << (y/64) << std::endl;
		}
	}
	draw();
	return (true);
}

void 	Graphic::apply_floor()
{	
	int x = 0;
	int y = 0;
	for (y = 0; y <= 45; y++)
	{
		for (x = 0; x <= 22; x++)
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
