#include "passwordexplanationpopup.h"
#include "notextselectiontextbrowser.h"

#include <QVBoxLayout>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QDebug>

PasswordExplanationPopup::PasswordExplanationPopup(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);

    m_textBrowser = new NoTextSelectionTextBrowser(this);
    m_textBrowser->setText("At least one lowercase letter.\n"
                           "At least one uppercase letter.\n"
                           "At least one digit.\n"
                           "At least one special character (@, $, !, %, *, ?, &).\n"
                           "A minimum length of 8 characters.");
    m_textBrowser->setStyleSheet("color: red");
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(m_textBrowser);
    vbox->setContentsMargins(0,0,0,0);
    setLayout(vbox);

    setFocusPolicy(Qt::WheelFocus);
}

bool PasswordExplanationPopup::event(QEvent *event)
{
    if (event->type() == QEvent::WindowDeactivate)
    {
        close();
        deleteLater();
    }
    else if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = dynamic_cast<QKeyEvent*>(event);
        emit keyPressed(keyEvent->key());
        close();
        deleteLater();
    }
    else if (event->type() == QEvent::MouseButtonPress)
    {
        close();
        deleteLater();
    }
    return QWidget::event(event);
}
