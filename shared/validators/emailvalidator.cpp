#include "emailvalidator.h"

#include <QRegularExpression>

bool EmailValidator::isValid(const QString &email) const
{
    static const QRegularExpression emailPattern("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Z|a-z]{2,}$");
    return emailPattern.match(email).hasMatch();
}
