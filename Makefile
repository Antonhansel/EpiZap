##
## Makefile for Makefile in /home/david_c/B4/unixSystem/my_ftp
## 
## Made by DAVID Flavien
## Login   <david_c@epitech.net>
## 
## Started on  Mon Mar 31 16:43:50 2014 DAVID Flavien
##

CC	= gcc

CCP	= g++

RM	= rm -rf

FILE1	= client/srcs/Command.cpp \
	  client/srcs/myIA.cpp \
	  client/srcs/main.cpp

OBJS1	= $(FILE1:.cpp=.o)

NAME1	= ia

FILE2	= 

OBJS2	= $(FILE2:.c=.o)

NAME2	= server_gui

CFLAGS	= -Wextra -Wall -Werror -W -I ./server/include -I ./customers/include

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS1)
	  $(CCP) $(CFLAGS) $(OBJS1) -o $(NAME1)

$(NAME2): 
	 cd server ; make

clean:
	$(RM) $(OBJS1)
	cd server ; make clean

fclean: clean
	$(RM) $(NAME1)
	rm -f ./server_gui

re: fclean all
