#ifndef GPXCONTROLLER_H
#define GPXCONTROLLER_H

#include <QObject>
#include <QPair>

class GpxHelper
{
public:
    static QList<QPair<float, float> > litFichier();
};

#endif // GPXCONTROLLER_H
