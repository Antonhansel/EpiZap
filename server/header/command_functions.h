#ifndef COMMAND_FUNCTIONS_H_
# define COMMAND_FUNCTIONS_H_

# include "Server.h"
# include "Player.h"
# include "List.h"

int 	command_functions(Server *, Player *, char *);
int 	get_cmd_type(char *);
int 	up_cmd(Server *, Player *, char *);
int 	right_cmd(Server *, Player *, char *);
int 	left_cmd(Server *, Player *, char *);
int 	see_cmd(Server *, Player *, char *);
int 	inventory_cmd(Server *, Player *, char *);
int 	take_object_cmd(Server *, Player *, char *);
int 	put_object_cmd(Server *, Player *, char *);
int 	kick_cmd(Server *, Player *, char *);
int 	broadcast_text_cmd(Server *, Player *, char *);
int 	incantation_cmd(Server *, Player *, char *);
int 	fork_cmd(Server *, Player *, char *);
int 	connect_nbr_cmd(Server *, Player *, char *);
int 	get_obj(Server *, int, char *);

#endif /* COMMAND_FUNCTIONS_H_ */