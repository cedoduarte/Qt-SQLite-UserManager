#include "currentdateedit.h"

CurrentDateEdit::CurrentDateEdit(QWidget *parent)
    : QDateEdit(parent)
{
    setDate(QDate::currentDate());
    setCalendarPopup(true);
}
