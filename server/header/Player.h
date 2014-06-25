#ifndef PLAYER_H_
# define PLAYER_H_

# include "Network.h"

typedef struct 	Player
{
	int				fd;
	int				nbRequest;
	int				x;
	int				y;
	int				lvl;
	float			time;
	struct Player 	*next;
}					Player;

#endif /* PLAYER_H_ */