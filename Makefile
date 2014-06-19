##
## Makefile for Makefile in /home/david_c/B4/unixSystem/my_ftp
## 
## Made by DAVID Flavien
## Login   <david_c@epitech.net>
## 
## Started on  Mon Mar 31 16:43:50 2014 DAVID Flavien
##

CC	= gcc

RM	= rm -rf

FILE1	= server/srcs/Server.c \
	  server/srcs/getInfos.c \
	  server/srcs/xfunctions.c \
	  server/srcs/Client.c \
	  server/srcs/checkFd.c \
	  server/srcs/main.c

OBJS1	= $(FILE1:.c=.o)

NAME1	= serveur

FILE2	= 

OBJS2	= $(FILE2:.c=.o)

NAME2	= client

CFLAGS	= -Wextra -Wall -Werror -W -I ./server/header -g

all: $(NAME1)

$(NAME1): $(OBJS1)
	  $(CC) $(CFLAGS) $(OBJS1) -o $(NAME1)

$(NAME2): 
	 make -C ./customer/src
	 mv ./customer/src/client ./client

clean:
	$(RM) $(OBJS1)

fclean: clean
	$(RM) $(NAME1)

re: fclean all
