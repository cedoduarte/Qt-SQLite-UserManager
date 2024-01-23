#ifndef COUNTRYCOMBO_H
#define COUNTRYCOMBO_H

#include <QComboBox>

class CountryCombo : public QComboBox
{
    Q_OBJECT
public:
    CountryCombo(QWidget *parent = nullptr);
    virtual ~CountryCombo() {}
private:
    void populate();
};

#endif // COUNTRYCOMBO_H
