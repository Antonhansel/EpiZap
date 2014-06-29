######################################################################
# Automatically generated by qmake (3.0) mer. juin 18 16:27:26 2014
######################################################################

TEMPLATE = app
TARGET = gui
INCLUDEPATH += . header

QT += widgets
QT += opengl
QT += 3dquick

LIBS = -lglut -lGLU -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer

OBJECTS_DIR = ./.obj
MOC_DIR = ./.moc

# Input
HEADERS += header/MainUI.hpp header/Connexion.hpp header/Network.h header/Server.h header/NetworkC.hpp header/Player.h header/Inventory.h header/Team.h header/Map.h header/Incantation.h header/List.h header/Square.h header/xfunction.h header/Graphic.hpp header/LibSDL.hh header/Exception.hh
SOURCES += srcs/main.cpp srcs/MainUI.cpp srcs/Connexion.cpp srcs/Network.c srcs/Server.c srcs/NetworkC.cpp srcs/Player.c srcs/Inventory.c srcs/Team.c srcs/Map.c srcs/Incantation.c srcs/List.c srcs/Square.c srcs/xmalloc.c srcs/Graphic.cpp srcs/Lib.cpp srcs/Exception.cpp
