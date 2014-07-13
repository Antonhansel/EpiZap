#include "../header/myIA.hpp"

int  convertToInt(const std::string &s)
{
  std::istringstream iss(s);
  int        val = 0;

  iss >> val;
  return (val);
}

void  setArgument(char **argv, int argc, std::map<std::string, std::string> &flags)
{
  flags["-p"] = "";
  flags["-n"] = "";
  flags["-h"] = "";
  for (int j(0); j != argc; j++)
  {
    for (std::map<std::string, std::string>::iterator it = flags.begin(); it != flags.end(); ++it)
      if (it->first == argv[j] && ((j + 1) <= argc))
      {
      	std::string s(argv[j]);
      	it->second = s;     	
      }
  }
}

int 							main(int argc, char **argv)
{
 	std::map<std::string, std::string>	flags;
	myIA 					ia;
	std::string				s1;
	std::string				s2;
	std::string				s3;

	setArgument(argv, argc, flags);
	for (std::map<std::string, std::string>::iterator it = flags.begin(); it != flags.end(); ++it)
	{
      	if ((*it).second.compare("") == 0 && (*it).first.compare("-n") == 0)
      		{
      			std::cerr << "Bad args" << std::endl;
      			return (0);
      		}
      	else
      		s1.assign((*it).second + "\n");
      	if ((*it).second.compare("") == 0 && (*it).first.compare("-h") == 0)
      		it->second = "127.0.0.1";
      	else
      		s2.assign((*it).second);
      	if ((*it).second.compare("") == 0 && (*it).first.compare("-p") == 0)
          {
          	std::cerr << "Bad args" << std::endl;
      		return (0);
          }
        else
      		s3.assign((*it).second);
      }
	if (ia.initLoop(s1, s2, convertToInt(s3)) == false)
		std::cerr << "Can't initialize server" << std::endl;
	else
		ia.loop();
	return (0);
}
