QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt_FifteenPuzzle
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamesettings.cpp \
    game.cpp \
    gamebutton.cpp \
    about.cpp

HEADERS  += mainwindow.h \
    gamesettings.h \
    game.h \
    gamebutton.h \
    about.h

FORMS    += mainwindow.ui \
    gamesettings.ui \
    about.ui
