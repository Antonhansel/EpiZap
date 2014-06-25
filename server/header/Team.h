#ifndef TEAM_H_
# define TEAM_H_

# include "Player.h"

typedef struct 	Team
{
	/* data */
	int			nbPlayerMax;
	int 		nbPlayerActu;
	Player 		*playerList;
}				Team;

#endif