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
	_xhud = 0;
	_yhud = 0;
	_parent = parent;
	_mouseClick = false;
	_realUpdate = false;
	_mouseDrag = false;
	_stuff[LINEMATE] = std::make_pair("<br><img src=\"./textures/linemate.png\"/> Linemate : ", 0);
	_stuff[DERAUMERE] = std::make_pair("<img src=\"./textures/deraumere.png\"/> Deraumere : ", 0);
	_stuff[SIBUR] = std::make_pair("<img src=\"./textures/sibur.png\"/> Sibur : ", 0);
	_stuff[MENDIANE] = std::make_pair("<img src=\"./textures/mendiane.png\"/> Mendiane : ", 0);
	_stuff[PHIRAS] = std::make_pair("<img src=\"./textures/phiras.png\"/> Phiras : ", 0);
	_stuff[THYSTAME] = std::make_pair("<img src=\"./textures/thystame.png\"/> Thystame : ", 0);
	_stuff[FOOD] = std::make_pair("<img src=\"./textures/food.png\"/> Food : ", 0);
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
	_mouseReleased = true;
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
		updateHud(_lastPointPress.x()/64, _lastPointPress.y()/64);
	}
}

void	Graphic::updateHud(const int x, const int y)
{
	_xhud = x;
	_yhud = y;
}

void 	Graphic::mouseMoveEvent(QMouseEvent *e)
{
	_currentPos = e->pos();
}

void 	Graphic::dragMouse()
{
	if ((_lastPointPress.x() - _currentPos.x()) != 0 
		|| (_lastPointPress.y() - _currentPos.y()) != 0)
	{
		if (((_lastPointPress.x() - _currentPos.x())/64) >= 1)
			_viewx -= 1;
		else if (((_lastPointPress.x() - _currentPos.x())/64) <= -1)
			_viewx += 1;
		if (((_lastPointPress.y() - _currentPos.y())/64) >= 1)
			_viewy -= 1;
		else if (((_lastPointPress.y() - _currentPos.y())/64) <= -1)
			_viewy += 1;
		if (_viewy + 11 >= _map->width)
			_viewy = _map->width - 11;
		if (_viewx + 23 >= _map->height)
			_viewx = _map->height - 23;
		if (_viewx < 0)
			_viewx = 0;
		if (_viewy < 0)
			_viewy = 0;
	}
}

bool 	Graphic::update()
{
	if (_realUpdate)
	{
		if (_mouseReleased)
		{
			_mouseDrag = false;
			_mouseReleased = false;
		}
		if (_mouseDrag)
			dragMouse();
		if (_mouseClick)
		{
			_mouseDrag = true;
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
			if (_map->map[x + _viewx][y + _viewy].inventory->get_object(_map->map[x + _viewx][y + _viewy].inventory, LINEMATE))
				Lib::applySurface((x * SP_SIZE) + 15, (y * SP_SIZE) + 10, _ressource[LINEMATE], _screen);
			if (_map->map[x + _viewx][y + _viewy].inventory->get_object(_map->map[x + _viewx][y + _viewy].inventory, DERAUMERE))
				Lib::applySurface((x * SP_SIZE) + 20, (y * SP_SIZE) + 15, _ressource[DERAUMERE], _screen);
			if (_map->map[x + _viewx][y + _viewy].inventory->get_object(_map->map[x + _viewx][y + _viewy].inventory, SIBUR))
				Lib::applySurface((x * SP_SIZE) + 30, (y * SP_SIZE) + 25, _ressource[SIBUR], _screen);
			if (_map->map[x + _viewx][y + _viewy].inventory->get_object(_map->map[x + _viewx][y + _viewy].inventory, MENDIANE))
				Lib::applySurface((x * SP_SIZE) + 40, (y * SP_SIZE) + 10, _ressource[MENDIANE], _screen);
			if (_map->map[x + _viewx][y + _viewy].inventory->get_object(_map->map[x + _viewx][y + _viewy].inventory, PHIRAS))
				Lib::applySurface((x * SP_SIZE) + 30, (y * SP_SIZE) + 10, _ressource[PHIRAS], _screen);
			if (_map->map[x + _viewx][y + _viewy].inventory->get_object(_map->map[x + _viewx][y + _viewy].inventory, THYSTAME))
				Lib::applySurface((x * SP_SIZE) + 15, (y * SP_SIZE) + 30, _ressource[THYSTAME], _screen);
			if (_map->map[x + _viewx][y + _viewy].inventory->get_object(_map->map[x + _viewx][y + _viewy].inventory, FOOD))
				Lib::applySurface((x * SP_SIZE) + 15, (y * SP_SIZE) + 45, _ressource[FOOD], _screen);
		}
	}
}

void 	Graphic::initRealUpdate(Map *map)
{
	_map = map;
	_realUpdate = true;
}

void 	Graphic::loopHud()
{
	QString data;

	data = "Position: ";
	data += QString::number(_xhud);
	data += " - ";
	data += QString::number(_yhud);
	_parent->addData(data, true);
	data = "Block type: ";
	data += QString::number(_map->map[_xhud][_yhud].square_type);
	_parent->addData(data, false);
	_stuff[LINEMATE].second = _map->map[_xhud][_yhud].inventory->get_object(_map->map[_xhud][_yhud].inventory, LINEMATE);
	_stuff[DERAUMERE].second = _map->map[_xhud][_yhud].inventory->get_object(_map->map[_xhud][_yhud].inventory, DERAUMERE);
	_stuff[SIBUR].second = _map->map[_xhud][_yhud].inventory->get_object(_map->map[_xhud][_yhud].inventory, SIBUR);
	_stuff[MENDIANE].second = _map->map[_xhud][_yhud].inventory->get_object(_map->map[_xhud][_yhud].inventory, MENDIANE);
	_stuff[PHIRAS].second = _map->map[_xhud][_yhud].inventory->get_object(_map->map[_xhud][_yhud].inventory, PHIRAS);
	_stuff[THYSTAME].second = _map->map[_xhud][_yhud].inventory->get_object(_map->map[_xhud][_yhud].inventory, THYSTAME);
	_stuff[FOOD].second = _map->map[_xhud][_yhud].inventory->get_object(_map->map[_xhud][_yhud].inventory, FOOD);
	for (std::map<ROCK, std::pair<QString, int> >::const_iterator it = _stuff.begin(); it != _stuff.end(); ++it)
		_parent->addData((*it).second.first + QString::number((*it).second.second), false);
}

void 	Graphic::draw()
{
	if (_realUpdate)
	{
		apply_floor();
		loopHud();
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
	_ressource[LINEMATE] = Lib::loadImage("./textures/linemate.png");
	_ressource[DERAUMERE] = Lib::loadImage("./textures/deraumere.png");
	_ressource[SIBUR] = Lib::loadImage("./textures/sibur.png");
	_ressource[MENDIANE] = Lib::loadImage("./textures/mendiane.png");
	_ressource[PHIRAS] = Lib::loadImage("./textures/phiras.png");
	_ressource[THYSTAME] = Lib::loadImage("./textures/thystame.png");
	_ressource[FOOD] = Lib::loadImage("./textures/food.png");
}
