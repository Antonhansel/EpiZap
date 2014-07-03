#include "Server.h"
#include "List.h"
#include "command_functions.h"

void 	fct_write_next(Player *, Server *, char *);

void 		player_socket_problem(Player *this, Server *s)
{
	sprintf(s->msg, "%s<font color=\"Red\">*** PLAYER %d DISCONNECTED ***</font>", (s->msg != NULL) ? s->msg : "", this->fd);
	printf("----------- AVANT DELETE ----------\n");
	display_list(s->player);
	del_elem(&s->player, this->fd);
	destroy_player(this);
	printf("----------- APRES DELETE ----------\n");
	display_list(s->player);
	if (this->fd == s->max_fd)
		s->max_fd--;
}

int 		fct_read(Player *this, void *p)
{
	char	buf[512];
	Server	*s;
	char 	*ptr;

	s = ((Server *)(p));
	memset(buf, 0, 512);
	if (read(this->fd, buf, 511) > 0)
	{
		sprintf(s->msg, "%s<font color=\"Green\">*** %s ***</font>", (s->msg != NULL) ? s->msg : "", buf);
		if (add_str_in_buffer(&this->buffer_circular, buf) == TRUE)
		{
			printf("Good command\n");
			ptr = get_data_of_buffer(this->buffer_circular);
			command_functions(s, this, ptr);
			reset_elem_in_buffer(&this->buffer_circular, strlen(ptr));
			free(ptr);
		}
		else
			printf("Bad Command\n");
		//display_circular_buffer(this->buffer_circular, 0);
	}
	else
		player_socket_problem(this, s);
	return (0);
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