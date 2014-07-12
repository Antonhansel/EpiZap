NAMES	= server_gui

all: $(NAMES)

$(NAMES): 
	cd server && make

clean:
	cd server && make clean

fclean: clean
	cd server && cd .. && rm -f ./server_gui

re: fclean all
