#ifndef _MAINGUI_HPP_
# define _MAINGUI_HPP_

#include "Network.hpp"

class MainGUI
{
public:
	MainGUI(Network *network);
	~MainGUI();
private:
	Network 	*_network;
};

#endif /*_MAINGUI_HPP_*/