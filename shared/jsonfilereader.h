#ifndef JSONFILEREADER_H
#define JSONFILEREADER_H

#include <QJsonDocument>

class JsonFileReader
{
public:
    JsonFileReader() {}
    virtual ~JsonFileReader() {}
    QJsonDocument read(const QString &filename);
};

#endif // JSONFILEREADER_H
