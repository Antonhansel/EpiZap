#include	"Server.h"
#include	"List.h"

int 		fct_read(Player *this, void *p)
{
	char	buf[512];
	Server	*s;

	s = ((Server *)(p));
	memset(buf, 0, 512);
	if (read(this->fd, buf, 511) > 0)
	{
		sprintf(s->msg, "%s<font color=\"Green\">*** %s ***</font>", (s->msg != NULL) ? s->msg : "", buf);
		if (add_str_in_buffer(&this->buffer_circular, buf) == TRUE)
			printf("Good command\n");
		else
			printf("Bad Command\n");
		display_circular_buffer(this->buffer_circular, 0);
	}
	else
	{
		printf("BUFFER EXIT = %s\n", buf);
		sprintf(s->msg, "%s<font color=\"Red\">*** PLAYER %d DISCONNECTED ***</font>", (s->msg != NULL) ? s->msg : "", this->fd);
		printf("----------- AVANT DELETE ----------\n");
		display_list(s->player);
		del_elem(&s->player, this->fd);
		printf("----------- APRES DELETE ----------\n");
		display_list(s->player);
		if (this->fd == s->max_fd)
			s->max_fd--;
		printf("MAX FD = %d\n", s->max_fd);
	}
	return (0);
}