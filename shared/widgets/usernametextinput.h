#ifndef USERNAMETEXTINPUT_H
#define USERNAMETEXTINPUT_H

#include <QLineEdit>

class UsernameTextInput : public QLineEdit
{
    Q_OBJECT
public:
    UsernameTextInput(QWidget *parent = nullptr);
    virtual ~UsernameTextInput() {}
    bool isValid() const;
};

#endif // USERNAMETEXTINPUT_H
