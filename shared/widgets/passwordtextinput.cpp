#include "passwordtextinput.h"
#include "passwordexplanationpopup.h"
#include "../util.h"
#include "../validators/passwordvalidator.h"

PasswordTextInput::PasswordTextInput(QWidget *parent)
    : QLineEdit(parent)
{
    setEchoMode(Password);
}

bool PasswordTextInput::isValid() const
{
    PasswordValidator validator;
    return validator.isValid(text());
}

void PasswordTextInput::mousePressEvent(QMouseEvent *event)
{
    PasswordExplanationPopup *popup = new PasswordExplanationPopup;
    connect(popup, &PasswordExplanationPopup::keyPressed, this,
            &PasswordTextInput::passwordExplanationPopupKeyPressed);
    popup->resize(popup->sizeHint());
    popup->move(mapToGlobal(mapFromParent(pos())));
    popup->show();
    QLineEdit::mousePressEvent(event);
}

void PasswordTextInput::passwordExplanationPopupKeyPressed(int qkey)
{
    if (Util::keyIsNotPrintable(qkey))
    {
        return;
    }
    QString keyString = QKeySequence(qkey).toString();
    if (Util::capsLockIsActivated())
    {
        keyString = keyString.toUpper();
    }
    else
    {
        keyString = keyString.toLower();
    }
    setText(text() + keyString);
}
