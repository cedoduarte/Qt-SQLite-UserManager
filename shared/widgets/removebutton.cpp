#include "removebutton.h"

RemoveButton::RemoveButton(int row, QWidget *parent)
    : QPushButton(parent)
{
    m_row = row;
    setIcon(QIcon(":/img/delete.png"));
    connect(this, &RemoveButton::clicked, this, [&]()
    {
        emit pushed(this);
    });
}
