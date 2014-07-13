#include "../header/myIA.hpp"

int 	main()
{
	myIA 	ia;

	if (ia.initLoop() == false)
		std::cerr << "Can't initialize server" << std::endl;
	else
		ia.loop();
	return (0);
}
