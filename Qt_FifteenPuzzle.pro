QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt_FifteenPuzzle
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamesettings.cpp

HEADERS  += mainwindow.h \
    gamesettings.h

FORMS    += mainwindow.ui \
    gamesettings.ui
