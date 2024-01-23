#include "jsonfilereader.h"

#include <QFile>
#include <QDebug>
#include <QJsonDocument>

QJsonDocument JsonFileReader::read(const QString &filename)
{
    QFile jsonFile(filename);
    if (jsonFile.open(QIODevice::Text | QIODevice::ReadOnly))
    {
        QByteArray jsonData = jsonFile.readAll();
        jsonFile.close();
        return QJsonDocument::fromJson(jsonData);
    }
    else
    {
        qDebug() << jsonFile.errorString() << __FILE__ << __LINE__;
    }
    return QJsonDocument();
}
