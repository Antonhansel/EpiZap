#include "Server.h"
#include "List.h"
#include "command_functions.h"
#include "cmd_functions.h"

void 	fct_write_next(t_player *, t_server *, char *);
int 	fct_read_next(t_player *, t_server *, char *, int);
void      display_list_square(t_player *front_ptr);


void 	player_socket_problem(t_player *this, t_server *s)
{
	snprintf(s->msg, 200,
		"%s<font color=\"Red\">*** PLAYER %d DISCONNECTED ***</font>",
		(s->msg != NULL) ? s->msg : "", this->fd);
	if (this->intro == FALSE)
	{
		/*printf("----- BEFORE DELETIN PLAYER IN SQUARE DUE TO DEATH ----\n");
		display_list_square(s->map->map[this->x][this->y].player);
	*/	del_square(&s->map->map[this->x][this->y].player, this->fd);
	/*	printf("----- BEFORE ADDING PLAYER IN SQUARE DUE TO DEATH ----\n");
		display_list_square(s->map->map[this->x][this->y].player);
	*/}
	destroy_player(this, s);
	close(this->fd);
	del_cmd_of_player(&s->cmd_list, this);
	del_elem(&s->player, this->fd);
	if (this->fd == s->max_fd)
		s->max_fd--;
}

int 		fct_read(t_player *this, void *p)
{
	char	buf[BUFFER_SIZE];
	t_server	*s;
	int 	ret;

	s = ((t_server *)(p));
	memset(buf, 0, BUFFER_SIZE);
	if ((ret = read(this->fd, buf, BUFFER_SIZE - 1)) > 0)
		return (fct_read_next(this, s, buf, ret));
	else
		player_socket_problem(this, s);
	return (FALSE);
}

int 		fct_read_next(t_player *this, t_server *s, char *buf, int ret)
{
	char 	*ptr;
	int 	old_mode;
	t_cmd 	*new_cmd;

	old_mode = this->mode;
	this->mode = NONE;
	if ((ret - 1) <= BUFFER_SIZE && this->nb_request < 9
		&& add_str_in_buffer(&this->buffer_circular, buf) == TRUE)
	{
		if (this->intro == FALSE)
		{
			ptr = get_data_of_buffer(this->buffer_circular);
			reset_elem_in_buffer(&this->buffer_circular, strlen(ptr) + 1);
			this->buffer_circular = this->buffer_circular->head;
			new_cmd = create_new_cmd(s, this, ptr);
			add_cmd_in_list(&s->cmd_list, new_cmd);
			old_mode = this->mode;
			this->nb_request++;
			free(ptr);
		}
		return (TRUE);
	}
	this->mode = old_mode;
	return (FALSE);
}

int					fct_write(t_player *this, void *p)
{
	t_server			*s;
	t_circular_buffer 	*tmp;
	char 			buf[BUFFER_SIZE];
	int 			i;

	s = ((t_server *)(p));
	s->max_fd = s->max_fd;
	tmp = this->buffer_circular->head;
	i = 0;
	if (tmp->c != BUFFER_CHAR)
	{
		while (tmp->c != BUFFER_CHAR)
		{
			buf[i] = tmp->c;
			++i;
			tmp = tmp->next;
		}
		buf[i] = 0;
		fct_write_next(this, s, buf);
		if (this->is_alive == FALSE)
			player_socket_problem(this, s);
	}
	return (TRUE);
}

void 				fct_write_next(t_player *this, t_server *s, char *buf)
{
	unsigned int	ret;

	if ((ret = write(this->fd, buf, strlen(buf))) > 0)
	{
		reset_elem_in_buffer(&this->buffer_circular, ret);
		if (ret == strlen(buf))
		{
			this->mode = READ;
			this->buffer_circular = this->buffer_circular->head;
		}
	}
	else
		player_socket_problem(this, s);
}