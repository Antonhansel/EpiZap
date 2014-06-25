#ifndef LIST_H_
# define LIST_H_

# include "Server.h"
# include "Network.h"
# include "Player.h"

int 	add_elem(Player **, int);
int 	del_elem(Player **, int);
int 	check_fd(Player **, fd_set*);
void 	init_fd(Player *, fd_set*);
int 	get_max_fd(Player *);

#endif /* LIST_H_ */