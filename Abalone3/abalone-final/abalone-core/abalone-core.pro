QT -= gui

TEMPLATE = lib
DEFINES += ABALONECORE_LIBRARY

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abalone.model/Board.cpp \
    abalone.model/Game.cpp \
    abalone.model/Hexagon.cpp \
    abalone.model/Marble.cpp \
    abalone.model/Player.cpp \
    abalone.model/Position.cpp \
    abalone.observer/Subject.cpp

HEADERS += \
    abalone-core_global.h \
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
    abalone.observer/Subject.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    abalone.model/model.qmodel
