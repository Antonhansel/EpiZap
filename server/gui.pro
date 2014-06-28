######################################################################
# Automatically generated by qmake (3.0) mer. juin 18 16:27:26 2014
######################################################################

TEMPLATE = app
TARGET = gui
INCLUDEPATH += . header

QT += widgets
QT += opengl
QT += 3dquick

CONFIG += c++11
LIBS = -lglut -lGLU

OBJECTS_DIR = ./.obj
MOC_DIR = ./.moc

# Input
HEADERS += header/MainUI.hpp header/MainGUI.hpp header/Connexion.hpp header/Network.h header/Server.h header/NetworkC.hpp header/Player.h header/Inventory.h header/Team.h header/Map.h header/Box.h header/Incantation.h header/List.h header/GLView.hpp header/Window.hpp header/Square.h header/xfunction.h
SOURCES += srcs/main.cpp srcs/MainUI.cpp srcs/MainGUI.cpp srcs/Connexion.cpp srcs/Network.c srcs/Server.c srcs/NetworkC.cpp srcs/Player.c srcs/Inventory.c srcs/Team.c srcs/Map.c srcs/Box.c srcs/Incantation.c srcs/List.c srcs/GLView.cpp srcs/Window.cpp srcs/Square.c srcs/xmalloc.c
