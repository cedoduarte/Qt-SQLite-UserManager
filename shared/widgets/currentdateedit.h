#ifndef CURRENTDATEEDIT_H
#define CURRENTDATEEDIT_H

#include <QDateEdit>

class CurrentDateEdit : public QDateEdit
{
    Q_OBJECT
public:
    CurrentDateEdit(QWidget *parent = nullptr);
    virtual ~CurrentDateEdit() {}
};

#endif // CURRENTDATEEDIT_H
