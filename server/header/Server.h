#ifndef SERVER_H_
# define SERVER_H_

# include "Network.h"
# include "Player.h"
# include "Map.h"
# include "Team.h"
# include "list_team.h"
# include "cmd.h"

enum	cmd_type
{
  AVANCE,
  DROITE,
  GAUCHE,
  VOIR,
  INVENTAIRE,
  PREND_OBJET,
  POSE_OBJET,
  EXPULSE,
  BROADCAST_TEXTE,
  INCANTATION,
  FORK,
  CONNECT_NBR
};

enum	obj_type
{
  LINEMATE,
  DERAUMERE,
  SIBUR,
  MENDIANE,
  PHIRAS,
  THYSTAME,
  FOOD
};

enum	inc_lvl
{
  LVL1,
  LVL2,
  LVL3,
  LVL4,
  LVL5,
  LVL6,
  LVL7,
  LVL8
};

typedef struct	s_server
{
  int		port;
  int		socket;
  int		ctime;
  int		max_fd;
  int		nb_player;
  int		nb_player_co;
  int		initialize;
  int		nb_teams;
  int		nb_player_team;
  char		msg[BUFFER_SIZE];
  fd_set	rfds;
  fd_set	wfds;
  t_player	*player;
  t_team	*team;
  t_map		*map;
  char		cmd_type[12][15];
  double	time_tab[12];
  char		obj_type[10][15];
  int		(*cmd_tab[12])(void *, t_player *, char *);
  int		inc_tab[8][7];
  t_cmd		*cmd_list;
  int		(*loop)(struct s_server *);
  int		(*accept_socket)(struct s_server *);
  void		(*init_fd)(struct s_server *, fd_set *);
  void		(*check_fd)(struct s_server *, fd_set *);
}		t_server;

# ifdef __cplusplus
extern "C" {
# endif
	char	*init_server(t_server *, int, int);
	char	*destroy_server(t_server *);
	void	init_all_team(t_server *, char *);
# ifdef __cplusplus
}
# endif

int		init_bits_fields(t_server *, fd_set *, fd_set *);
int		check_bits_fields(t_server *, fd_set *, fd_set *);
int		accept_socket(t_server *);
int		fct_write(t_player *, void *);
void		init_cmd_tab(t_server *);
void		init_time_tab(t_server *);
void		init_obj_tab(t_server *);
void		init_tab_ptr(t_server *);
void		init_inc_tab(t_server *);
void		init_inc_tab_1(t_server *);
void		init_inc_tab_2(t_server *);
void		init_inc_tab_3(t_server *);

#endif /* !SERVER_H_ */
