##
## Makefile for  in /home/aube_a/Documents/projet/thread
## 
## Made by Mehdi Chouag
## Login   <aube_a@epitech.net>
## 
## Started on  Tue Mar 18 23:25:23 2014 Mehdi Chouag
## Last update Sun Apr 27 18:57:29 2014 ribeaud antonin
##

NAMES	= server_gui

all: $(NAMES)

$(NAMES): 
	cd server && make

clean:
	cd server && make clean

fclean: clean
	cd server && cd .. && rm -f ./server_gui

re: fclean all
