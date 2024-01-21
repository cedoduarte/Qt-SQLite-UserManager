#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include "../models/user.h"

#include <QSqlDatabase>
#include <vector>

class DatabaseHandler
{
public:
    void init();

    bool insertUser(const User &user);
    bool updateUser(const User &user);
    bool deleteUser(int userId);
    std::vector<User> userSelect(const QString &whereClause = "isDeleted = 0");
private:
    void createDatabase();
    void createTables();

    QSqlDatabase m_db;
};

#endif // DATABASEHANDLER_H
