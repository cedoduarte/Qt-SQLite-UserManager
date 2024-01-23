#ifndef URLTEXTINPUT_H
#define URLTEXTINPUT_H

#include <QLineEdit>

class UrlTextInput : public QLineEdit
{
    Q_OBJECT
public:
    UrlTextInput(QWidget *parent = nullptr);
    virtual ~UrlTextInput() {}
    bool isValid() const;
};

#endif // URLTEXTINPUT_H
