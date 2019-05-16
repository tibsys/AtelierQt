QT += core widgets
CONFIG +=

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        MainForm.cpp \
        WidgetGraphic.cpp \
        main.cpp

include(../MandelbrotLib/MandelbrotLib.pri)

FORMS += \
    MainForm.ui

HEADERS += \
    MainForm.h \
    WidgetGraphic.h
