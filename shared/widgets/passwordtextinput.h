#ifndef PASSWORDTEXTINPUT_H
#define PASSWORDTEXTINPUT_H

#include <QLineEdit>

class PasswordTextInput : public QLineEdit
{
    Q_OBJECT
public:
    PasswordTextInput(QWidget *parent = nullptr);
    virtual ~PasswordTextInput() {}
    bool isValid() const;
protected:
    void mousePressEvent(QMouseEvent *event) override;
private slots:
    void passwordExplanationPopupKeyPressed(int qkey);
};

#endif // PASSWORDTEXTINPUT_H
