#ifndef PASSWORDVALIDATOR_H
#define PASSWORDVALIDATOR_H

#include <QString>

class PasswordValidator
{
public:
    PasswordValidator() {}
    virtual ~PasswordValidator() {}
    bool isValid(const QString &password) const;
private:
    bool hasMinimumLength(const QString &password) const;
    bool hasUppercaseLetter(const QString &password) const;
    bool hasLowercaseLetter(const QString &password) const;
    bool hasDigit(const QString& password) const;
    bool hasSpecialCharacter(const QString &password) const;

    static const int s_minimumLength;
};

#endif // PASSWORDVALIDATOR_H
