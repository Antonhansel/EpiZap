#ifndef CMD_FUNCTIONS_H_
# define CMD_FUNCTIONS_H_

# include "cmd.h"
# include "Server.h"

double	get_min_time(t_cmd *, double);
int		set_new_timer(t_cmd **, Server *, double);

#endif