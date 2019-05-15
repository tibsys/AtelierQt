QT += core

DEFINES += QT_DEPRECATED_WARNINGS

LIBS += -L$$PWD/../lib -lMandelbrotLib

INCLUDEPATH += $$PWD

HEADERS += \
    mandelbrot.h \
    MandelbrotControleur.h \
    FractalPoint.h \
    ThreadControleur.h
