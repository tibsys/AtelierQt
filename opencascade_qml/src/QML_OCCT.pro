TEMPLATE = app
QT += core gui qml quick opengl widgets

CONFIG += c++17

# Intégration des libs opencascade
INCLUDEPATH +=  \
    /Applications/Developpement/opencascade-7.5.0/build/include/opencascade
LIBS +=         \
    -L/Applications/Developpement/opencascade-7.5.0/build/mac64/clang/lib
## Fin intégration des libs opencascade

DEFINES += QT_DEPRECATED_WARNINGS

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

!contains(QMAKE_TARGET.arch, x86_64) {
	ARCH_BITS_SIZE = 32
	DEFINES += _OCC32
} else {
	ARCH_BITS_SIZE = 64
	DEFINES += _OCC64
}

LIBS +=         \
    -lTKernel   \
    -lTKMath    \
    -lTKG3d     \
    -lTKBRep    \
    -lTKGeomBase\
    -lTKGeomAlgo\
    -lTKTopAlgo \
    -lTKPrim    \
    -lTKBO      \
    -lTKBool    \
    -lTKOffset  \
    -lTKService \
    -lTKV3d     \
    -lTKOpenGl  \
    -lTKFillet

win32: LIBS += -luser32 -lopengl32

HEADERS += OcctView.h
	
SOURCES += main.cpp OcctView.cpp

RESOURCES += qml.qrc
