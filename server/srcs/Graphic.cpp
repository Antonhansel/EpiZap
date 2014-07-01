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
	_viewy = 0;
	_viewx = 0;
	_parent = parent;
	_mouseClick = false;
	_realUpdate = false;
	initSDL();
}

Graphic::~Graphic()
{
	SDL_FreeSurface(_screen);
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

void 	Graphic::caseClicked()
{
	QString data;

	if (_lastPointPress.x() > 0 && _lastPointPress.x() < (_map->width * 64)
		&& _lastPointPress.y() > 0 && _lastPointPress.y() < (_map->height * 64))
	{
		data = "Position: ";
		data += QString::number(_lastPointPress.x()/64);
		data += " - ";
		data += QString::number(_lastPointPress.y()/64);
		_parent->addData(data, true);
		data = "Block type: ";
		data += QString::number(_map->map[_lastPointPress.x()/64]
			[_lastPointPress.y()/64].square_type);
		_parent->addData(data, false);
	}
}

bool 	Graphic::update()
{
	if (_realUpdate)
	{
		if (_mouseDrag)
		{
			_mouseDrag = false;
			if (_map->width > 23 && _map->height > 11)
			{
				if ((_lastPointPress.x() - _lastPointReleased.x()) != 0 
					|| (_lastPointPress.y() - _lastPointReleased.y()) != 0)
				{
					_viewx += ((_lastPointPress.x() - _lastPointReleased.x())/64);
					_viewy += ((_lastPointPress.y() - _lastPointReleased.y())/64);
					if (_viewy + 11 >= _map->width)
						_viewy = _map->width - 11;
					if (_viewx + 23 >= _map->height)
						_viewx = _map->height - 23;
					if (_viewx < 0)
						_viewx = 0;
					if (_viewy < 0)
						_viewy = 0;
				}
				else
				_mouseClick = true;
			}
		}
		if (_mouseClick)
		{
			_mouseClick = false;
			caseClicked();
		}
		draw();
	}
	return (true);
}

void 	Graphic::apply_floor()
{	
	int x = 0;
	int y = 0;
	for (y = 0; y < 11 && y < _map->height; y++)
	{
		for (x = 0; x < 23 && x < _map->width; x++)
		{
			Lib::applySurface(x * SP_SIZE, y* SP_SIZE, 
				_floor[_map->map[x + _viewx][y + _viewy].square_type], _screen);
		}
	}
}

void 	Graphic::initRealUpdate(Map *map)
{
	_map = map;
	_realUpdate = true;
}

void 	Graphic::draw()
{
	if (_realUpdate)
	{
		apply_floor();
		Lib::xSDL_Flip(_screen);
	}
}

void 	Graphic::loader()
{
	_floor[0] = Lib::loadImage("./textures/grass.png");
	_floor[1] = _floor[0];
	_floor[2] = _floor[0];
	_floor[3] = _floor[0];
	_floor[4] = _floor[0];
	_floor[5] = Lib::loadImage("./textures/mud.png");
	_floor[6] = Lib::loadImage("./textures/mud2.png");
	_floor[7] = Lib::loadImage("./textures/mud3.png");
}
