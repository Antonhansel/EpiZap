#ifndef PLAYER_H_
# define PLAYER_H_

# include <stdlib.h>
# include "Inventory.h"
# include "CircularBuffer.h"

enum	mode
{
  READ,
  WRITE,
  NONE
};

enum	DIR
{
  NORTH,
  EAST,
  SOUTH,
  WEST
};

typedef struct		s_player
{
  int			fd;
  int			lvl;
  float			time;
  int			x;
  int			y;
  t_inventory		*inventory;
  int			nb_request;
  struct s_player	*next;
  struct s_player	*next_square;
  struct s_player	*next_team;
  t_circular_buffer	*buffer_circular;
  int			mode;
  int			dir;
  int			intro;
  int			sent;
  int			range;
  char			*team_name;
  int			is_alive;
  t_inventory		*(*get_inventory)(struct s_player *);
  void			(*set_inventory)(struct s_player *, t_inventory *);
  int			(*fct_read)(struct s_player *, void *);
}			t_player;

int			init_player(t_player *, int);
int			destroy_player(t_player *, void *);
int			fct_read(t_player *, void *);
void			copy_player(t_player *, t_player *);
void			set_player_data(t_player *, int, int);

#endif /* PLAYER_H_ */
