#include "notextselectiontextbrowser.h"

#include <QMouseEvent>

NoTextSelectionTextBrowser::NoTextSelectionTextBrowser(QWidget *parent)
    : QTextBrowser(parent)
{
}

void NoTextSelectionTextBrowser::mousePressEvent(QMouseEvent *event)
{
    event->ignore();
}

void NoTextSelectionTextBrowser::mouseReleaseEvent(QMouseEvent *event)
{
    event->ignore();
}
