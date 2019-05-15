QT += core qml quick quickcontrols2
CONFIG +=

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp

RESOURCES += qml.qrc

include(../MandelbrotLib/MandelbrotLib.pri)
