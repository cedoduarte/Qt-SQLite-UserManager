#ifndef PASSWORDEXPLANATIONPOPUP_H
#define PASSWORDEXPLANATIONPOPUP_H

#include <QWidget>

class NoTextSelectionTextBrowser;

class PasswordExplanationPopup : public QWidget
{
    Q_OBJECT
public:
    PasswordExplanationPopup(QWidget *parent = nullptr);
    virtual ~PasswordExplanationPopup() {}
signals:
    void keyPressed(int key);
protected:
    bool event(QEvent* event) override;
private:
    NoTextSelectionTextBrowser *m_textBrowser;
};

#endif // PASSWORDEXPLANATIONPOPUP_H
