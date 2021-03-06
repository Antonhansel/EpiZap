/*
** Player.c for Network.c in /home/david_c/B4/systemUnix/psu_2013_zappy/server/srcs
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:05:57 2014 Flavien David
** Last update sam. juil.  12 18:05:57 2014 Flavien David
*/

#include "Player.h"
#include "Server.h"
#include "List.h"

static void		set_inventory(t_player *, t_inventory *);
static t_inventory	*get_inventory(t_player *);

int	init_player(t_player *this, int fd)
{
  this->fd = fd;
  this->x = -1;
  this->y = -1;
  this->mode = WRITE;
  this->intro = TRUE;
  this->buffer_circular = NULL;
  this->get_inventory = &get_inventory;
  this->set_inventory = &set_inventory;
  this->fct_read = &fct_read;
  this->next_square = NULL;
  this->next_team = NULL;
  this->sent = TRUE;
  this->nb_request = 0;
  this->is_alive = TRUE;
  if (!(this->inventory = malloc(sizeof(t_inventory))))
    return (-1);
  init_inventory(this->inventory, NULL, 0);
  if (!(this->buffer_circular = malloc(sizeof(t_circular_buffer))))
    return (-1);
  if (create_circular_buffer(&this->buffer_circular) == FALSE)
    return (-1);
  add_str_in_buffer(&this->buffer_circular, "BIENVENUE\n");
  return (0);
}

void	set_player_data(t_player *this, int width, int height)
{
  this->nb_request = 0;
  this->x = rand() % width;
  this->y = rand() % height;
  this->dir = rand() % 4;
  this->time = 0;
  this->range = 2;
  this->lvl = LVL1;
}

void	copy_player(t_player *this, t_player *to_copy)
{
  this->fd = to_copy->fd;
  this->lvl = to_copy->lvl;
  this->time = to_copy->time;
  this->x = to_copy->x;
  this->y = to_copy->y;
  this->inventory = to_copy->inventory;
  this->nb_request = to_copy->nb_request;
  this->buffer_circular = to_copy->buffer_circular;
  this->mode = to_copy->mode;
  this->intro = to_copy->intro;
  this->get_inventory = to_copy->get_inventory;
  this->set_inventory = to_copy->set_inventory;
  this->fct_read = to_copy->fct_read;
}

static void		set_inventory(t_player *this, t_inventory *i)
{
  this->inventory = i;
}

static t_inventory	*get_inventory(t_player *this)
{
  return (this->inventory);
}
