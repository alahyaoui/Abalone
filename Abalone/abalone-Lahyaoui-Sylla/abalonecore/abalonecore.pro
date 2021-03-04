QT -= gui

TEMPLATE = lib
DEFINES += ABALONECORE_LIBRARY

include(../config.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abalonecore.cpp

HEADERS += \
    Board.h \
    Color.h \
    Direction.h \
    Game.h \
    Hexagon.h \
    Marble.h \
    Player.h \
    Position.h \
    abalonecore_global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    abalonecore.pri
