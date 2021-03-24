TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        abalone.controller/Controller.cpp \
        abalone.main/Main.cpp \
        abalone.model/Board.cpp \
        abalone.model/Game.cpp \
        abalone.model/Hexagon.cpp \
        abalone.model/Marble.cpp \
        abalone.model/Player.cpp \
        abalone.model/Position.cpp \
        abalone.model/Subject.cpp \
        abalone.view/View.cpp

HEADERS += \
    abalone.controller/Controller.h \
    abalone.exception/ImpossibleMovementException.h \
    abalone.exception/InvalidGameStatusException.h \
    abalone.model/Board.h \
    abalone.model/Color.h \
    abalone.model/Direction.h \
    abalone.model/Game.h \
    abalone.model/Hexagon.h \
    abalone.model/Marble.h \
    abalone.model/Model.h \
    abalone.model/Observer.h \
    abalone.model/Player.h \
    abalone.model/Position.h \
    abalone.model/Subject.h \
    abalone.view/InterfaceView.h \
    abalone.view/View.h \

DISTFILES +=
