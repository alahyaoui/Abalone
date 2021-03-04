CONFIG += c++17

CONFIG -= debug_and_release debug_and_release_target

include($${PWD}/abalonecore/abalonecore.pri)

QMAKE_CXXFLAGS += -Wall -Wextra -pedantic
