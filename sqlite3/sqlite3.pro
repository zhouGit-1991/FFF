#-------------------------------------------------
#
# Project created by QtCreator 2020-05-12T10:41:31
#
#-------------------------------------------------

QT       -= core gui

TARGET = sqlite3
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    sqlite3.c \
    shell.c

HEADERS += sqlite3.h \
    sqlite3ext.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
