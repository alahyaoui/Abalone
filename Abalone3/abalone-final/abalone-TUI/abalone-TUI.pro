TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        abalone.controller/Controller.cpp \
        abalone.main/Main.cpp \
        abalone.view/View.cpp

HEADERS += \
    abalone.controller/Controller.h \
    abalone.view/InterfaceView.h \
    abalone.view/View.h
