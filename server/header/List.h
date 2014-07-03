#ifndef LIST_H_
# define LIST_H_

# include "Server.h"
# include "Network.h"
# include "Player.h"

int 	add_elem(Player **, int, int, int);
int 	del_elem(Player **, int);
void  	display_list(Player *);
int 	add_player(Player **, Player *);

#endif /* LIST_H_ */