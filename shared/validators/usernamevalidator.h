#ifndef USERNAMEVALIDATOR_H
#define USERNAMEVALIDATOR_H

#include <QString>

class UsernameValidator
{
public:
    UsernameValidator() {}
    virtual ~UsernameValidator() {}
    bool isValid(const QString &username) const;
};

#endif // USERNAMEVALIDATOR_H
