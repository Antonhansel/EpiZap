#include "Inventory.h"

static void 		init_func_ptr(Inventory *);

static int 			get_linemate(Inventory *);
static void 		set_linemate(Inventory *, int);
static int 			get_deraumere(Inventory *);
static void 		set_deraumere(Inventory *, int);
static int 			get_sibur(Inventory *);
static void 		set_sibur(Inventory *, int);
static int 			get_mendiane(Inventory *);
static void 		set_mendiane(Inventory *, int);
static int 			get_phiras(Inventory *);
static void 		set_phiras(Inventory *, int);
static int   		get_thystame(Inventory *);
static void 		set_thystame(Inventory *, int);
static int 			get_food(Inventory *);
static void 		set_food(Inventory *, int);

/*
static int 			get_object(Inventory *, char *);
static void 		set_object(Inventory *, char *, int);
*/

int					init_inventory(Inventory *this)
{
	this->linemate = 0;
	this->deraumere = 0;
	this->sibur = 0;
	this->mendiane = 0;
	this->phiras = 0;
	this->thystame = 0;
	this->food = 0;
	init_func_ptr(this);

	/*
	this->nbPlayer = -1;

	this->tab[0] = &this->linemate;
	this->tab[1] = &this->deraumere;
	this->tab[2] = &this->sibur;
	this->tab[3] = &this->mendiane;
	this->tab[4] = &this->phiras;
	this->tab[5] = &this->thystame;
	this->tab[6] = &this->food;
	this->tab[7] = &this->nbPlayer;
	init_inventory_next(this);
	*/

	return (0);
}

int 			destroy_inventory(Inventory *this)
{
	return (0);
}

static void		init_func_ptr(Inventory *this)
{
	this->get_linemate = &get_linemate;
	this->set_linemate = &set_linemate;
	this->get_deraumere = &get_deraumere;
	this->set_deraumere = &set_deraumere;
	this->get_sibur = &get_sibur;
	this->set_sibur = &set_sibur;
	this->get_mendiane = &get_mendiane;
	this->set_mendiane = &set_mendiane;
	this->get_phiras = &get_phiras;
	this->set_phiras = &set_phiras;
	this->get_thystame = &get_thystame;
	this->set_thystame = &set_thystame;
	this->get_food = &get_food;
	this->set_food = &set_food;
}

/*
static void		init_inventory_next(Inventory *this)
{
	strcat(this->tab_corresp[0], "linemate");
	strcat(this->tab_corresp[1], "deraumere");
	strcat(this->tab_corresp[2], "sibur");
	strcat(this->tab_corresp[3], "mendiane");
	strcat(this->tab_corresp[4], "phiras");
	strcat(this->tab_corresp[5], "thystame");
	strcat(this->tab_corresp[6], "food");
	strcat(this->tab_corresp[7], "nbPlayer");
}
*/
/*
static int 		get_object(Inventory *this, char *obj_name)
{
	int 		i;

	i = 0;
	while (this->tab_corresp[i] != 0)
	{
		if (strcmp(this->tab_corresp[i], obj_name) == 0)
			return (*(this->tab[i]));
		i++;
	}
	return (-1);
}

static void			set_object(Inventory *this, char *obj_name, int new_val)
{
	int 			i;

	i = 0;
	while ()
	{
		if (strcmp(this->tab_corresp[i], obj_name) == 0)
			return (*(this->tab[i]));
		i++;
	}
}
*/

static int 			get_linemate(Inventory *this)
{
	return (this->linemate);
}

static void 		set_linemate(Inventory *this, int new_val)
{
	this->linemate = new_val;
}

static int 			get_deraumere(Inventory *this)
{
	return (this->deraumere);
}

static void 		set_deraumere(Inventory *this, int new_val)
{
	this->deraumere = new_val;
}

static int 			get_sibur(Inventory *this)
{
	return (this->sibur);
}

static void 		set_sibur(Inventory *this, int new_val)
{
	this->sibur = new_val;
}

static int 			get_mendiane(Inventory *this)
{
	return (this->mendiane);
}

static void 		set_mendiane(Inventory *this, int new_val)
{
	this->mendiane = new_val;
}

static int 			get_phiras(Inventory *this)
{
	return (this->phiras);
}

static void 		set_phiras(Inventory *this, int new_val)
{
	this->phiras = new_val;
}

static int   		get_thystame(Inventory *this)
{
	return (this->thystame);
}

static void 		set_thystame(Inventory *this, int new_val)
{
	this->thystame = new_val;
}

static int 			get_food(Inventory *this)
{
	return (this->food);
}

static void 		set_food(Inventory *this, int new_val)
{
	this->food = new_val;
}