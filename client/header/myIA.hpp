#ifndef MYIA_HPP
# define MYIA_HPP

class myIA
{
private:
	std::list<std::string> receive;
	std::list<std::string> send;
public:
	myIA();
	~myIA();
	const std::string	&sendCommand();
	bool				addCommand(const std::string &);
	std::string			&recieveAwser();
	void				addRecieveAwser(std::string &);
};

#endif /* !MYIA_HPP */