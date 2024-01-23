#include "urltextinput.h"
#include "../validators/urlvalidator.h"

#include <QRegularExpression>
#include <QRegularExpressionValidator>

UrlTextInput::UrlTextInput(QWidget *parent)
    : QLineEdit(parent)
{
    static const QRegularExpression urlPattern("^((http|https|ftp)://)?([a-zA-Z0-9_-]+\\.)*[a-zA-Z]{2,}(/[a-zA-Z0-9_+-]*)*(\\?[a-zA-Z0-9_&=]*)?$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(urlPattern, this);
    setValidator(validator);
}

bool UrlTextInput::isValid() const
{
    UrlValidator validator;
    return validator.isValid(text());
}
