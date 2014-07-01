#ifndef LIST_H_
# define LIST_H_

# include "Server.h"
# include "Network.h"
# include "Player.h"

int 	add_elem(Player **, int);
int 	del_elem(Player **, int);
void 	init_fd(Player *, fd_set*);
int 	get_max_fd(Player *);
void  display_list(Player *);

#endif /* LIST_H_ */