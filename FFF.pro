#-------------------------------------------------
#
# Project created by QtCreator 2020-04-24T12:01:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FFF
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    newdbdialog.cpp \
    newtabledialog.cpp \
    selectdatadialog.cpp \
    updatadialog.cpp \
    insertdatadialog.cpp \
    sqliteoperat.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    newdbdialog.h \
    newtabledialog.h \
    selectdatadialog.h \
    updatadialog.h \
    insertdatadialog.h \
    sqliteoperat.h

FORMS    += mainwindow.ui \
    dialog.ui \
    newdbdialog.ui \
    newtabledialog.ui \
    selectdatadialog.ui \
    updatadialog.ui \
    insertdatadialog.ui



INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lsqlite3
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lsqlite3d

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/sqlite3.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/sqlite3d.lib

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lsqlite3
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lsqlite3d
else:unix: LIBS += -L$$PWD/lib/ -lsqlite3

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lsqlite3
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lsqlite3d
else:unix: LIBS += -L$$PWD/lib/ -lsqlite3

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/
