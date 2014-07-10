#include "cmd_functions.h"

void 	player_socket_problem(Player *, Server *);
void	do_action(t_cmd **, Server *, t_cmd *);

double		get_min_time(t_cmd *list, double max_timer)
{
	t_cmd	*tmp;
	double	timer;
	int		num_cmd;

	tmp = list;
	if (tmp != NULL)
		num_cmd = tmp->num_cmd;
	timer = max_timer;
	while (tmp)
	{
		if (tmp->num_cmd == num_cmd)
		{
			if (tmp->time < timer)
			{
				timer = tmp->time;
			}
		}
		tmp = tmp->next;
	}
	return (timer);
}

int			set_new_timer(t_cmd **list, Server *s, double timer)
{
	t_cmd	*tmp;
	int		num_cmd;

	num_cmd = -2;
	tmp = (*list);
	while (tmp)
	{
		(num_cmd == -2 && tmp->num_cmd != -1) ? (num_cmd = tmp->num_cmd) : 0;
		if (tmp->num_cmd == num_cmd || tmp->num_cmd == -1)
		{
			tmp->time -= timer;
			if (tmp->time <= 0.0)
				do_action(list, s, tmp);
		}
		else
			return (TRUE);
		tmp = tmp->next;
	}
	return (TRUE);
}

void	do_action(t_cmd **list, Server *s, t_cmd *tmp)
{
	if (tmp->func != NULL)
		(*tmp->func)(((void*)(s)), tmp->owner, tmp->cmd[1]);
	else
	{
		add_str_in_buffer(&tmp->owner->buffer_circular, "ko\n");
		tmp->owner->mode = WRITE;
	}		
	del_cmd_in_list(list, tmp);
	tmp->owner->nb_request--;
}

void		del_cmd_of_player(t_cmd **list, Player *p)
{
	t_cmd	*tmp;

	tmp = (*list);
	while (tmp)
	{
		if (tmp->owner == p)
			del_cmd_in_list(list, tmp);
		tmp = tmp->next;
	}
}

void		update_life(Player **player, int timer, int ctime)
{
	Player 	*tmp;

	tmp = (*player);
	while (tmp)
	{
		if (tmp->intro == FALSE)
		{
			tmp->time -= timer;
			if (tmp->time <= 0.0 && tmp->inventory->get_object(tmp->inventory, FOOD) <= 0)
			{
				add_str_in_buffer(&tmp->buffer_circular, "mort\n");
				tmp->mode = WRITE;
				tmp->is_alive = FALSE;
			}
			else if (tmp->time <= 0.0)
			{
				tmp->inventory->set_object(tmp->inventory, FOOD, -1);
				tmp->time = 126.0 * (1.0 / ctime);
			}
		}
		tmp = tmp->next;
	}
}