#include 			"Player.h"
#include 			"xfunction.h"

static void			init_func_ptr(Player *);

static void			set_inventory(Player *, Inventory *);
static Inventory 	*get_inventory(Player *);
static int			get_pos_x(Player *);
static void			set_pos_x(Player *, int);
static int			get_pos_y(Player *);
static void			set_pos_y(Player *, int);
static int			get_lvl(Player *);
static void			set_lvl(Player *, int);
static float		get_time(Player *);
static void			set_time(Player *, float);

int					init_player(Player *this, int fd)
{
	this->fd = fd;
	this->nbRequest = 0;
	this->x = 0;
	this->y = 0;
	this->time = 0;
	this->lvl = 0;
	if (!(this->inventory = xmalloc(sizeof(Inventory))))
		return (1);
	init_inventory(this->inventory);
	init_func_ptr(this);
	return (0);
}

int 				destroy_player(Player *this)
{
	free(this->inventory);
	return (0);
}

static void			init_func_ptr(Player *this)
{
	this->get_inventory = &get_inventory;
	this->set_inventory = &set_inventory;
	this->get_pos_x = &get_pos_x;
	this->set_pos_x = &set_pos_x;
	this->get_pos_y = &get_pos_y;
	this->set_pos_y = &set_pos_y;
	this->get_lvl = &get_lvl;
	this->set_lvl = &set_lvl;
	this->get_time = &get_time;
	this->set_time = &set_time;
}

static void			set_inventory(Player *this, Inventory *i)
{
	this->inventory = i;
}

static Inventory 	*get_inventory(Player *this)
{
	return (this->inventory);
}

static int			get_pos_x(Player *this)
{
	return (this->x);
}

static void			set_pos_x(Player *this, int new_val)
{
	this->x = new_val;
}

static int			get_pos_y(Player *this)
{
	return (this->y);
}

static void			set_pos_y(Player *this, int new_val)
{
	this->y = new_val;
}

static int 			get_lvl(Player *this)
{
	return (this->lvl);
}

static void			set_lvl(Player *this, int new_val)
{
	this->lvl = new_val;
}

static float		get_time(Player *this)
{
	return (this->time);
}

static void			set_time(Player *this, float new_val)
{
	this->time = new_val;
}