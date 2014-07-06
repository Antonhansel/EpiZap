#include "../header/myIA.hpp"

int 	main()
{
	std::string str = "{,,,linemate, food,,,,}";
	myIA 	toto;

	toto.initRock();
	toto.initTabElevation();
	std::cout << toto.checkRock(str) << std::endl;
}