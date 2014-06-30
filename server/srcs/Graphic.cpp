#include "Graphic.hpp"
#include "MainUI.hpp"

Graphic::Graphic(MainUI *parent)
{
	char windowid[64];
	sprintf(windowid, "SDL_WINDOWID=0x%llx", winId());
	SDL_putenv(windowid);
	setAttribute(Qt::WA_NoSystemBackground);
	setAttribute(Qt::WA_OpaquePaintEvent);
	setFocusPolicy(Qt::StrongFocus);
	setAttribute(Qt::WA_InputMethodEnabled);
	_parent = parent;
	_mouseClick = false;
	_realUpdate = false;
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
	SDL_WM_SetCaption("Zappy Viewer", NULL);
	Lib::xTTF_Init();
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	_music = Mix_LoadMUS("./music/main.mp3");
	Mix_PlayMusic(_music, -1);
	loader();
}

void Graphic::mousePressEvent(QMouseEvent *e)
{
    _lastPointPress = e->pos();
    _mouseClick = true;
}

void Graphic::mouseReleaseEvent (QMouseEvent *e)
{
	_lastPointReleased = e->pos();
	_mouseDrag = true;
}

bool 	Graphic::update()
{
	if (_mouseDrag)
	{
		_mouseDrag = false;
		if ((_lastPointPress.x() - _lastPointReleased.x()) != 0 || (_lastPointPress.y() - _lastPointReleased.y()) != 0)
			std::cout << "Drag x: " << (_lastPointPress.x()-_lastPointReleased.x())/64 << " - " << (_lastPointPress.y()-_lastPointReleased.y())/64 << std::endl;
	}
	if (_mouseClick)
	{
		std::cout << "Click x: " << _lastPointPress.x()/64 << " - " << _lastPointPress.y()/64 << std::endl;
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

void 	Graphic::initRealUpdate(Map *map)
{
	_map = map;
	_realUpdate = true;
	std::cout << "MAP SIZE : " << _map->width << std::endl;
}

void 	Graphic::draw()
{
	if (_realUpdate)
		apply_floor();
	Lib::xSDL_Flip(_screen);
}

void 	Graphic::loader()
{
	_grass = Lib::loadImage("./textures/grass.png");
}
