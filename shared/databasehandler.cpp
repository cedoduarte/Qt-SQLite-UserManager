#include "databasehandler.h"
#include "../models/user.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

void DatabaseHandler::init()
{
    createDatabase();
    createTables();
}

bool DatabaseHandler::insertUser(const User &user)
{
    QSqlQuery query;
    if (query.prepare(User::SQL_INSERT_PLACEHOLDER))
    {
        query.bindValue(":firstName", user.firstName());
        query.bindValue(":lastName", user.lastName());
        query.bindValue(":country", user.country());
        query.bindValue(":province", user.province());
        query.bindValue(":city", user.city());
        query.bindValue(":zipCode", user.zipCode());
        query.bindValue(":birthdate", user.birthdate());
        query.bindValue(":phoneNumber", user.phoneNumber());
        query.bindValue(":email", user.email());
        query.bindValue(":username", user.username());
        query.bindValue(":passwordHash", user.passwordHash());
        query.bindValue(":linkedInProfileUrl", user.linkedInProfileUrl());
        query.bindValue(":isDeleted", user.isDeleted());
        query.bindValue(":lastModification", user.lastModification());
        if (query.exec())
        {
            qDebug() << "user inserted successfully!";
            return true;
        }
        else
        {
            qDebug() << query.lastError().text() << __FILE__ << __LINE__;
        }
    }
    else
    {
        qDebug() << query.lastError().text() << __FILE__ << __LINE__;
    }
    return false;
}

bool DatabaseHandler::updateUser(const User &user)
{
    QSqlQuery query;
    if (query.prepare(User::SQL_UPDATE_PLACEHOLDER))
    {
        query.bindValue(":firstName", user.firstName());
        query.bindValue(":lastName", user.lastName());
        query.bindValue(":country", user.country());
        query.bindValue(":province", user.province());
        query.bindValue(":city", user.city());
        query.bindValue(":zipCode", user.zipCode());
        query.bindValue(":birthdate", user.birthdate());
        query.bindValue(":phoneNumber", user.phoneNumber());
        query.bindValue(":email", user.email());
        query.bindValue(":username", user.username());
        query.bindValue(":passwordHash", user.passwordHash());
        query.bindValue(":linkedInProfileUrl", user.linkedInProfileUrl());
        query.bindValue(":isDeleted", user.isDeleted());
        query.bindValue(":lastModification", user.lastModification());
        query.bindValue(":id", user.id());
        if (query.exec())
        {
            qDebug() << "user updated successfully!";
            return true;
        }
        else
        {
            qDebug() << query.lastError().text() << __FILE__ << __LINE__;
        }
    }
    else
    {
        qDebug() << query.lastError().text() << __FILE__ << __LINE__;
    }
    return false;
}

bool DatabaseHandler::deleteUser(int userId)
{
    QSqlQuery query;
    if (query.prepare("UPDATE user SET isDeleted = 1 WHERE id = :id"))
    {
        query.bindValue(":id", userId);
        if (query.exec())
        {
            qDebug() << "user deleted successfully";
            return true;
        }
        else
        {
            qDebug() << query.lastError().text() << __FILE__ << __LINE__;
        }
    }
    else
    {
        qDebug() << query.lastError().text() << __FILE__ << __LINE__;
    }
    return false;
}

std::vector<User> DatabaseHandler::userSelect(const QString &whereClause)
{
    QString sqlStatement = "SELECT * FROM user";
    if (!whereClause.isEmpty())
    {
        sqlStatement += " WHERE " + whereClause;
    }
    std::vector<User> userList;
    QSqlQuery query;
    if (query.prepare(sqlStatement))
    {
        if (query.exec())
        {
            while (query.next())
            {
                User user;
                user.setId(query.value("id").toInt())
                    ->setFirstName(query.value("firstName").toString())
                    ->setLastName(query.value("lastName").toString())
                    ->setCountry(query.value("country").toString())
                    ->setProvince(query.value("province").toString())
                    ->setCity(query.value("city").toString())
                    ->setZipCode(query.value("zipCode").toString())
                    ->setBirthdate(QDate::fromString(query.value("birthdate").toString()))
                    ->setPhoneNumber(query.value("phoneNumber").toString())
                    ->setEmail(query.value("email").toString())
                    ->setUsername(query.value("username").toString())
                    ->setPasswordHash(query.value("passwordHash").toString())
                    ->setLinkedInProfileUrl(query.value("linkedInProfileUrl").toString())
                    ->setIsDeleted(query.value("isDeleted").toBool())
                    ->setLastModification(QDateTime::fromString(query.value("lastModification").toString()));
                userList.push_back(user);
            }
        }
        else
        {
            qDebug() << query.lastError().text() << __FILE__ << __LINE__;
        }
    }
    else
    {
        qDebug() << query.lastError().text() << __FILE__ << __LINE__;
    }
    return userList;
}

void DatabaseHandler::createDatabase()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("usermanager.sqlite");
    if (m_db.open())
    {
        qDebug() << "database opened successfully!";
    }
    else
    {
        qDebug() << m_db.lastError().text() << __FILE__ << __LINE__;
    }
}

void DatabaseHandler::createTables()
{
    if (m_db.isOpen())
    {
        QSqlQuery query;
        if (query.prepare(User::SQL_CREATE_TABLE_PLACEHOLDER))
        {
            if (query.exec())
            {
                qDebug() << "user table was created successfully!";
            }
            else
            {
                qDebug() << query.lastError().text() << __FILE__ << __LINE__;
            }
        }
        else
        {
            qDebug() << query.lastError().text() << __FILE__ << __LINE__;
        }
    }
    else
    {
        qDebug() << "tables was not created because the database is not opened!";
    }
}
