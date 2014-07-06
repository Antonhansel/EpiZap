#ifndef LIST_H_
# define LIST_H_

# include "Server.h"
# include "Network.h"
# include "Player.h"

int 	add_elem(Player **, int);
int 	del_elem(Player **, int);
void  	display_list(Player *);
int 	add_player(Player **, Player *);
int 	add_square(Player **, Player *);
int 	del_square(Player **, int);

#endif /* LIST_H_ */