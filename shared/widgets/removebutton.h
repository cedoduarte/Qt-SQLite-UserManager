#ifndef REMOVEBUTTON_H
#define REMOVEBUTTON_H

#include <QPushButton>

class RemoveButton : public QPushButton
{
    Q_OBJECT
public:
    RemoveButton(int row, QWidget *parent = nullptr);
    virtual ~RemoveButton() {}
    void setRow(int row) { m_row = row; }
    int row() const { return m_row; }
signals:
    void pushed(RemoveButton *button);
private:
    int m_row;
};

#endif // REMOVEBUTTON_H
