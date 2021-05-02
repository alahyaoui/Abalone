QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abalone.controller/Controller.cpp \
    abalone.main/Main.cpp \
    abalone.model/Board.cpp \
    abalone.model/Game.cpp \
    abalone.model/Hexagon.cpp \
    abalone.model/Marble.cpp \
    abalone.model/Player.cpp \
    abalone.model/Position.cpp \
    abalone.observer/Subject.cpp \
    abalone.view/GHexacell.cpp \
    abalone.view/GMarble.cpp \
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
    abalone.exception/PlayerNotFoundException.hpp \
    abalone.model/Board.h \
    abalone.model/Color.hpp \
    abalone.model/Direction.hpp \
    abalone.model/Game.h \
    abalone.model/Hexagon.h \
    abalone.model/HexagonType.h \
    abalone.model/Marble.h \
    abalone.model/Model.h \
    abalone.model/Player.h \
    abalone.model/Position.h \
    abalone.observer/Observer.h \
    abalone.observer/Subject.h \
    abalone.utils/StringUtils.hpp \
    abalone.view/GHexacell.h \
    abalone.view/GMarble.h \
    abalone.view/View.h

FORMS += \
    abalone.view/View.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore \
    abalone.model/model.qmodel \
    img/blackBall.png \
    img/whiteBall.png
