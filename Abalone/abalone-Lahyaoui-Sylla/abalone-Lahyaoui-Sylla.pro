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
        abalone.test/BoardTest.cpp \
        abalone.test/DirectionTest.cpp \
        abalone.test/MarbleTest.cpp \
        abalone.test/PositionTest.cpp \
        abalone.view/View.cpp

HEADERS += \
    abalone.controller/Controller.h \
    abalone.exception/AbaloneException.hpp \
    abalone.exception/DirectionException.hpp \
    abalone.exception/DirectionNotFoundException.hpp \
    abalone.exception/ImpossibleMovementException.hpp \
    abalone.exception/InvalidDirectionException.hpp \
    abalone.exception/InvalidGameStatusException.hpp \
    abalone.exception/MarbleException.hpp \
    abalone.exception/MarbleNotFoundException.hpp \
    abalone.model/Board.h \
    abalone.model/Color.hpp \
    abalone.model/Direction.hpp \
    abalone.model/Game.h \
    abalone.model/Hexagon.h \
    abalone.model/Marble.h \
    abalone.model/Model.h \
    abalone.model/Observer.h \
    abalone.model/Player.h \
    abalone.model/Position.h \
    abalone.model/Subject.h \
    abalone.test/AbaloneTest.hpp \
    abalone.test/BoardTest.h \
    abalone.test/DirectionTest.h \
    abalone.test/MarbleTest.h \
    abalone.test/PositionTest.h \
    abalone.view/InterfaceView.h \
    abalone.view/View.h \

DISTFILES +=
