#include "usernametextinput.h"
#include "../validators/usernamevalidator.h"

#include <QRegularExpression>
#include <QRegularExpressionValidator>

UsernameTextInput::UsernameTextInput(QWidget *parent)
{
    static const QRegularExpression usernamePattern(R"([a-zA-Z0-9_-]+)");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(usernamePattern, this);
    setValidator(validator);
}

bool UsernameTextInput::isValid() const
{
    UsernameValidator validator;
    return validator.isValid(text());
}
