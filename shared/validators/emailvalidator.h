#ifndef EMAILVALIDATOR_H
#define EMAILVALIDATOR_H

#include <QString>

class EmailValidator
{
public:
    EmailValidator() {}
    virtual ~EmailValidator() {}
    bool isValid(const QString &email) const;
};

#endif // EMAILVALIDATOR_H
