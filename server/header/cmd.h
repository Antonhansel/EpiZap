#ifndef CMD_H_
# define CMD_H_

# include "Player.h"

typedef struct 		s_cmd
{
	char 			*cmd;
	int 			type;
	int 			time;
	Player			*owner;
	int 			num_cmd;
	int 			(*func)(void *, Player *, char *);
	struct s_cmd 	*next;
}					t_cmd;

t_cmd		*create_new_cmd(void *, Player *);
int 		add_cmd_in_list(t_cmd *, t_cmd *);
int 		del_cmd_in_list(t_cmd *, t_cmd *);

#endif /* CMD_H_ */