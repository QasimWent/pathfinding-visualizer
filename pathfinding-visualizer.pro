######################################################################
# Automatically generated by qmake (3.1) Sun Jan 12 16:08:32 2020
######################################################################

TEMPLATE = app
TARGET = pathfinding-visualizer
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += Position.h GridConfig.h Grid2D.h MainWindow.h Node.h
SOURCES += GridConfig.cpp Grid2D.cpp MainWindow.cpp Node.cpp main.cpp

QT += widgets
