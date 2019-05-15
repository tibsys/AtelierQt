TEMPLATE = lib
CONFIG += staticlib

DEFINES += QT_DEPRECATED_WARNINGS

DESTDIR = $$PWD/../lib

SOURCES += \
    mandelbrot.c \
    MandelbrotControleur.cpp \
    FractalPoint.cpp \
    ThreadControleur.cpp

OTHER_FILES += \
    MandelbrotLib.pri

include(MandelbrotLib.pri)

HEADERS +=
