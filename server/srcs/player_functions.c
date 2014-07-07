#include "Server.h"
#include "List.h"
#include "command_functions.h"
#include "cmd_functions.h"

void 	fct_write_next(Player *, Server *, char *);
int 	fct_read_next(Player *, Server *, char *, int);

void 	display_list_queue(t_cmd *);

void 	player_socket_problem(Player *this, Server *s)
{
	/*sprintf(s->msg, 
		"%s<font color=\"Red\">*** PLAYER %d DISCONNECTED ***</font>",
		(s->msg != NULL) ? s->msg : "", this->fd);*/
	printf("this = > %s\n", this->team_name);
	destroy_player(this, s);
	del_cmd_of_player(&s->cmd_list, this);
	printf("*** PLAYER %d DISCONNECTED ***", this->fd);
	printf("----------- AVANT DELETE ----------\n");
	display_list(s->player);
	del_elem(&s->player, this->fd);
	printf("----------- APRES DELETE ----------\n");
	display_list(s->player);
	if (this->fd == s->max_fd)
		s->max_fd--;
}

int 		fct_read(Player *this, void *p)
{
	char	buf[512];
	Server	*s;
	int 	ret;

	s = ((Server *)(p));
	memset(buf, 0, 512);
	if ((ret = read(this->fd, buf, 511)) > 0)
	{
		/*sprintf(s->msg, "%s<font color=\"Green\">*** %s ***</font>",
			(s->msg != NULL) ? s->msg : "", buf);*/
		return (fct_read_next(this, s, buf, ret));
	}
	else
		player_socket_problem(this, s);
	return (FALSE);
}

int 		fct_read_next(Player *this, Server *s, char *buf, int ret)
{
	char 	*ptr;
	int 	old_mode;
	t_cmd 	*new_cmd;

	old_mode = this->mode;
	this->mode = NONE;
	if ((ret - 1) <= BUFFER_SIZE && this->nb_request < 9 && add_str_in_buffer(&this->buffer_circular, buf) == TRUE)
	{
		ptr = get_data_of_buffer(this->buffer_circular);
		if (this->intro == FALSE)
		{
			reset_elem_in_buffer(&this->buffer_circular, strlen(ptr) + 1);
			this->buffer_circular = this->buffer_circular->head;
			new_cmd = create_new_cmd(s, this, ptr);
			add_cmd_in_list(&s->cmd_list, new_cmd);
			old_mode = this->mode;
			this->nb_request++;
			printf("---- BEGIN DISPLAY LIST ----\n");
			display_list_queue(s->cmd_list);
			printf("---- END DISPLAY LIST ----\n");
			//printf("X = %d & Y = %d & DIR = %s\n", this->x, this->y, (this->dir == 0) ? "NORTH" : (this->dir == 1) ? "EAST" : (this->dir == 2) ? "SOUTH" : "WEST");
		}
		free(ptr);
		return (TRUE);
	}
	else
		printf("Bad Command\n");
	this->mode = old_mode;
	return (FALSE);
}

int					fct_write(Player *this, void *p)
{
	Server			*s;
	CircularBuffer 	*tmp;
	char 			buf[BUFFER_SIZE];
	int 			i;

	printf("WRITTING\n");
	s = ((Server *)(p));
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
		printf("WRITTING BUFF = %s", buf);
		fct_write_next(this, s, buf);
	}
	return (TRUE);
}

void 				fct_write_next(Player *this, Server *s, char *buf)
{
	unsigned int	ret;

	if ((ret = write(this->fd, buf, strlen(buf))) > 0)
	{
		reset_elem_in_buffer(&this->buffer_circular, ret);
		if (ret == strlen(buf))
		{
			this->mode = READ;
			this->buffer_circular = this->buffer_circular->head;
			printf("---- RESET POINTOR ADDR ON CIRCULAR BUFFER'S HEAD ----\n");				
		}
	}
	else
		player_socket_problem(this, s);
}