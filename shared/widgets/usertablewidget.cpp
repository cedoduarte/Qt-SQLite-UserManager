#include "usertablewidget.h"
#include "../databasehandler.h"
#include "removebutton.h"
#include "areyousuredialog.h"

#include <QEvent>
#include <QDebug>
#include <QMessageBox>

UserTableWidget::UserTableWidget(QWidget *parent)
    : QTableWidget(parent)
{
    init();
}

void UserTableWidget::init()
{
    static const QStringList columnNameList {
        "Delete",
        "ID",
        "First name",
        "Last name",
        "Country",
        "Province",
        "City",
        "Zip Code",
        "Birthdate",
        "Phone number",
        "Email",
        "Username",
        "Password hash",
        "LinkedIn Profile URL",
        "Is deleted",
        "Last modification"
    };
    setColumnCount(columnNameList.size());
    setHorizontalHeaderLabels(columnNameList);
    enableEdition(false);
}

void UserTableWidget::appendUser(const User *newUser)
{
    int row = rowCount();
    insertRow(row);
    RemoveButton *removeButton = new RemoveButton(row, this);
    connect(removeButton, &RemoveButton::pushed, this, &UserTableWidget::removeUser);
    setCellWidget(row, 0, removeButton);
    setItem(row, 1 + User::ID, new QTableWidgetItem(QString::number(newUser->id())));
    setItem(row, 1 + User::FIRST_NAME, new QTableWidgetItem(newUser->firstName()));
    setItem(row, 1 + User::LAST_NAME, new QTableWidgetItem(newUser->lastName()));
    setItem(row, 1 + User::COUNTRY, new QTableWidgetItem(newUser->country()));
    setItem(row, 1 + User::PROVINCE, new QTableWidgetItem(newUser->province()));
    setItem(row, 1 + User::CITY, new QTableWidgetItem(newUser->city()));
    setItem(row, 1 + User::ZIP_CODE, new QTableWidgetItem(newUser->zipCode()));
    setItem(row, 1 + User::BIRTHDATE, new QTableWidgetItem(newUser->birthdate().toString("yyyy-MM-dd")));
    setItem(row, 1 + User::PHONE_NUMBER, new QTableWidgetItem(newUser->phoneNumber()));
    setItem(row, 1 + User::EMAIL, new QTableWidgetItem(newUser->email()));
    setItem(row, 1 + User::USERNAME, new QTableWidgetItem(newUser->username()));
    setItem(row, 1 + User::PASSWORD_HASH, new QTableWidgetItem(newUser->passwordHash()));
    setItem(row, 1 + User::LINKEDIN_PROFILE_URL, new QTableWidgetItem(newUser->linkedInProfileUrl()));
    setItem(row, 1 + User::IS_DELETED, new QTableWidgetItem(QString("%1").arg(newUser->isDeleted())));
    setItem(row, 1 + User::LAST_MODIFICATION, new QTableWidgetItem(newUser->lastModification().toString("yyyy-MM-dd hh:mm:ss.zzz")));
}

void UserTableWidget::enableEdition(bool enabled)
{
    m_editionEnabled = enabled;
    setEditTriggers(m_editionEnabled ? AllEditTriggers : NoEditTriggers);
}

void UserTableWidget::saveUpdatedRows()
{
    DatabaseHandler db;
    std::vector<User> updatedUserList;
    for (int row : m_updatedRowList)
    {
        User updatedUser;
        updatedUser.setId(item(row, 1 + User::ID)->text().toInt())
            ->setFirstName(item(row, 1 + User::FIRST_NAME)->text())
            ->setLastName(item(row, 1 + User::LAST_NAME)->text())
            ->setCountry(item(row, 1 + User::COUNTRY)->text())
            ->setProvince(item(row, 1 + User::PROVINCE)->text())
            ->setCity(item(row, 1 + User::CITY)->text())
            ->setZipCode(item(row, 1 + User::ZIP_CODE)->text())
            ->setBirthdate(QDate::fromString(item(row, 1 + User::BIRTHDATE)->text(), "yyyy-MM-dd"))
            ->setPhoneNumber(item(row, 1 + User::PHONE_NUMBER)->text())
            ->setEmail(item(row, 1 + User::EMAIL)->text())
            ->setUsername(item(row, 1 + User::USERNAME)->text())
            ->setPasswordHash(item(row, 1 + User::PASSWORD_HASH)->text())
            ->setLinkedInProfileUrl(item(row, 1 + User::LINKEDIN_PROFILE_URL)->text())
            ->setIsDeleted(item(row, 1 + User::IS_DELETED)->text().toInt())
            ->setLastModification(QDateTime::fromString(item(row, 1 + User::LAST_MODIFICATION)->text(), "yyyy-MM-dd hh:mm:ss.zzz"));
        db.updateUser(updatedUser);
    }
    int updatedUserListSize = m_updatedRowList.size();
    m_updatedRowList.clear();
    if (updatedUserListSize > 0)
    {
        QMessageBox::information(this, "Save", "Records saved successfully!");
    }
}

bool UserTableWidget::event(QEvent *event)
{
    if (m_editionEnabled)
    {
        if (event->type() == QEvent::KeyRelease)
        {
            m_updatedRowList.insert(currentRow());
        }
    }
    return QTableWidget::event(event);
}

void UserTableWidget::removeUser(RemoveButton *button)
{
    AreYouSureDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        int row = button->row();
        int userId = item(row, 1 + User::ID)->text().toInt();
        DatabaseHandler db;
        db.deleteUser(userId);
        removeRow(row);
    }
}

void UserTableWidget::populate()
{
    setRowCount(0);
    DatabaseHandler db;
    std::vector<User> userList = db.userSelect();
    for (const User &user : userList)
    {
        appendUser(&user);
    }
}
