#ifndef PLAYER_H_
# define PLAYER_H_

typedef struct 	Player
{
	int			fd;
	int			nbRequest;
	int			x;
	int			y;
	int			lvl;
	float		time;
}				Player;

#endif /* PLAYER_H_ */