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
	_parent = parent; 
	_width = width;
	_height = height;
	_mouseClick = false;
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
	std::cout << size().height() << " - " << size().width() << std::endl;
	SDL_WM_SetCaption("Zappy Viewer", NULL);
	Lib::xTTF_Init();
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	_music = Mix_LoadMUS("./music/main.mp3");
	Mix_PlayMusic(_music, -1);
	loader();
}

void Graphic::mousePressEvent(QMouseEvent *e)
{
    _lastPoint = e->pos();
    _mouseClick = true;
}

bool 	Graphic::update()
{
	if (_mouseClick)
	{
		std::cout << "x: " << _lastPoint.x()/64 << " - " << _lastPoint.y()/64 << std::endl;
		_mouseClick = false;
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
