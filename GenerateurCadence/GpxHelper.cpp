#include "GpxHelper.h"
#include <QFile>
#include <QDebug>
#include <QXmlStreamReader>

QList<QPair<float, float>> GpxHelper::litFichier()
{
    QList<QPair<float, float>> route;

    QFile file(":/Routes/RouteVoiture.gpx");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Impossible d'ouvrir le fichier. " << file.errorString();
        return route;
    }
    QXmlStreamReader inputStream(&file);
    while (!inputStream.atEnd() && !inputStream.hasError())
    {
        inputStream.readNext();
        if (inputStream.isStartElement()) {
            QString name = inputStream.name().toString();
            if (name == "trkpt") {
                float lon = inputStream.attributes().value("lon").toFloat();
                float lat = inputStream.attributes().value("lat").toFloat();

                route << QPair<float, float>(lon, lat);
            }
        }
    }

    return route;
}
