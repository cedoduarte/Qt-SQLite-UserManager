#include "countrycombo.h"
#include "../jsonfilereader.h"

#include <QJsonArray>
#include <QJsonValue>

CountryCombo::CountryCombo(QWidget *parent)
    : QComboBox(parent)
{
    populate();
}

void CountryCombo::populate()
{
    JsonFileReader reader;
    QJsonDocument doc = reader.read(":json/country-list.json");
    QJsonArray countryList = doc.array();
    for (const QJsonValue &country : countryList)
    {
        addItem(country.toString());
    }
}
