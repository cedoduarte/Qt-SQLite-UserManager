#ifndef EMAILTEXTINPUT_H
#define EMAILTEXTINPUT_H

#include <QLineEdit>

class EmailTextInput : public QLineEdit
{
    Q_OBJECT
public:
    EmailTextInput(QWidget *parent = nullptr);
    virtual ~EmailTextInput() {}
    bool isValid() const;
};

#endif // EMAILTEXTINPUT_H
