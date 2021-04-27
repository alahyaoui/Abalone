CONFIG += c++17

CONFIG -= debug_and_release debug_and_release_target

#include($${PWD}/abalone-core/abalone-core.pri)
INCLUDEPATH += $${PWD}/abalone-core

QMAKE_CXXFLAGS += -Wall
