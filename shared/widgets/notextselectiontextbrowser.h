#ifndef NOTEXTSELECTIONTEXTBROWSER_H
#define NOTEXTSELECTIONTEXTBROWSER_H

#include <QTextBrowser>

class NoTextSelectionTextBrowser : public QTextBrowser
{
    Q_OBJECT
public:
    NoTextSelectionTextBrowser(QWidget *parent = nullptr);
    virtual ~NoTextSelectionTextBrowser() {}
protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
};

#endif // NOTEXTSELECTIONTEXTBROWSER_H
