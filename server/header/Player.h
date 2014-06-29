#ifndef 			PLAYER_H_
# define 			PLAYER_H_

# include			<stdlib.h>
# include 			"Inventory.h"

typedef struct 		Player
{
	/* Attributes */
	int				fd;
	int				lvl;
	float			time;
	int 		 	x;
	int 			y;
	Inventory		*inventory;

	int				nbRequest;
	
	struct Player 	*next;

	/* Methods */
	Inventory 		*(*get_inventory)(struct Player *);
	void			(*set_inventory)(struct Player *, Inventory *);
	int				(*get_lvl)(struct Player *);
	void			(*set_lvl)(struct Player *, int);
	float			(*get_time)(struct Player *);
	void			(*set_time)(struct Player *, float);
	int 			(*get_pos_x)(struct Player *);
	void 			(*set_pos_x)(struct Player *, int);
	int 			(*get_pos_y)(struct Player *);
	void 			(*set_pos_y)(struct Player *, int);
}					Player;

int 				init_player(struct Player *, int);
int 				destroy_player(struct Player *);

#endif 				/* PLAYER_H_ */