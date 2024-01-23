#include "urlvalidator.h"

#include <QRegularExpression>

bool UrlValidator::isValid(const QString &url) const
{
    static const QRegularExpression pattern("^(http|https)://[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}(/\\S*)?$");
    return pattern.match(url).hasMatch();
}
