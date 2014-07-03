#ifndef COMMAND_FUNCTIONS_H_
# define COMMAND_FUNCTIONS_H_

# include "Server.h"
# include "Player.h"

int 	command_functions(Server *, Player *, char *);
int 	get_cmd_type(char *);
int 	up_cmd(Server *, Player *);
int 	right_cmd(Server *, Player *);
int 	left_cmd(Server *, Player *);
int 	see_cmd(Server *, Player *);
int 	inventory_cmd(Server *, Player *);
int 	take_object_cmd(Server *, Player *);
int 	put_object_cmd(Server *, Player *);
int 	kick_cmd(Server *, Player *);
int 	broadcast_text_cmd(Server *, Player *);
int 	incantation_cmd(Server *, Player *);
int 	fork_cmd(Server *, Player *);
int 	connect_nbr_cmd(Server *, Player *);

#endif /* COMMAND_FUNCTIONS_H_ */