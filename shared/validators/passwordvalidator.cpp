#include "passwordvalidator.h"

#include <QRegularExpression>

const int PasswordValidator::s_minimumLength = 8;

bool PasswordValidator::isValid(const QString &password) const
{
    return hasMinimumLength(password)
           && hasUppercaseLetter(password)
           && hasLowercaseLetter(password)
           && hasDigit(password)
           && hasSpecialCharacter(password);
}

bool PasswordValidator::hasMinimumLength(const QString &password) const
{
    return password.length() >= s_minimumLength;
}

bool PasswordValidator::hasUppercaseLetter(const QString &password) const
{
    return password.contains(QRegularExpression("[A-Z]"));
}

bool PasswordValidator::hasLowercaseLetter(const QString &password) const
{
    return password.contains(QRegularExpression("[a-z]"));
}

bool PasswordValidator::hasDigit(const QString &password) const
{
    return password.contains(QRegularExpression("\\d"));
}

bool PasswordValidator::hasSpecialCharacter(const QString &password) const
{
    return password.contains(QRegularExpression("[^a-zA-Z\\d]"));
}
