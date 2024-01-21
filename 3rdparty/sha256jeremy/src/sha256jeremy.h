#ifndef SHA256JEREMY_H
#define SHA256JEREMY_H

#include "sha256jeremy_global.h"

#include <QString>

class SHA256JEREMY_EXPORT Sha256jeremy
{
public:
    Sha256jeremy() {}
    virtual ~Sha256jeremy() {}
    QString encode(const QString &input);
};

#endif // SHA256JEREMY_H
