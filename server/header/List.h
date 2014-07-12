#ifndef LIST_H_
# define LIST_H_

# include "Server.h"
# include "Network.h"
# include "Player.h"

int	add_elem(t_player **, int);
int	del_elem(t_player **, int);
void	display_list(t_player *);
int	add_player(t_player **, t_player *);
int	add_square(t_player **, t_player *);
int	del_square(t_player **, int);

#endif /* LIST_H_ */
