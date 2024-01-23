#include "emailtextinput.h"
#include "../validators/emailvalidator.h"

#include <QRegularExpression>
#include <QRegularExpressionValidator>

EmailTextInput::EmailTextInput(QWidget *parent)
{
    static const QRegularExpression emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(emailPattern, this);
    setValidator(validator);
}

bool EmailTextInput::isValid() const
{
    EmailValidator validator;
    return validator.isValid(text());
}
