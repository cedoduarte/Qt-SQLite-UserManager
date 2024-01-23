#include "usernamevalidator.h"

#include <QRegularExpression>

bool UsernameValidator::isValid(const QString &username) const
{
    static const QRegularExpression pattern("^[a-zA-Z0-9_-]{3,16}$");
    return pattern.match(username).hasMatch();
}
