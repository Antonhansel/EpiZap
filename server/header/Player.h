/*
** Client.h for Client.h in /home/david_c/B4/systemUnix/psu_2013_zappy/server/header
**
** Made by jeremie taboada-alvarez
** Login   <david_c@epitech.net>
**
** Started on  mer. juin  18 16:42:32 2014 jeremie taboada-alvarez
** Last update mer. juin  18 16:42:32 2014 jeremie taboada-alvarez
*/

#ifndef PLAYER_H_
# define PLAYER_H_

typedef struct 	Player
{
	int			fd;
	int			nbRequest;
	int			x;
	int			y;
	int			lvl;
	float		time;
}				Player;

#endif /* PLAYER_H_ */