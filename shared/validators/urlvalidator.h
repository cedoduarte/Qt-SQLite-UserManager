#ifndef URLVALIDATOR_H
#define URLVALIDATOR_H

#include <QString>

class UrlValidator
{
public:
    UrlValidator() {}
    virtual ~UrlValidator() {}
    bool isValid(const QString &url) const;
};

#endif // URLVALIDATOR_H
