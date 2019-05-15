QT += core widgets
CONFIG +=

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        MainForm.cpp \
        main.cpp

include(../MandelbrotLib/MandelbrotLib.pri)

FORMS += \
    MainForm.ui

HEADERS += \
    MainForm.h
