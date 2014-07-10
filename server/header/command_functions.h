#ifndef COMMAND_FUNCTIONS_H_
# define COMMAND_FUNCTIONS_H_

# include "Server.h"
# include "Player.h"
# include "List.h"

int 	command_functions(void *, Player *, char *);
int 	get_cmd_type(void *, char *);
int 	up_cmd(void *, Player *, char *);
int 	right_cmd(void *, Player *, char *);
int 	left_cmd(void *, Player *, char *);
int 	see_cmd(void *, Player *, char *);
int 	inventory_cmd(void *, Player *, char *);
int 	take_object_cmd(void *, Player *, char *);
int 	put_object_cmd(void *, Player *, char *);
int 	kick_cmd(void *, Player *, char *);
int 	broadcast_text_cmd(void *, Player *, char *);
int 	incantation_cmd(void *, Player *, char *);
int 	fork_cmd(void *, Player *, char *);
int 	connect_nbr_cmd(void *, Player *, char *);
int 	get_obj(void *, int, char *);
int 	fork_egg(void *, Player *, char *);

#endif /* COMMAND_FUNCTIONS_H_ */