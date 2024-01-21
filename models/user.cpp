#include "user.h"

const QString User::SQL_CREATE_TABLE_PLACEHOLDER = "CREATE TABLE IF NOT EXISTS user "
                                                   "(id INTEGER PRIMARY KEY AUTOINCREMENT,"
                                                   "firstName VARCHAR(256) NOT NULL,"
                                                   "lastName VARCHAR(256) NOT NULL,"
                                                   "country VARCHAR(256) NOT NULL,"
                                                   "province VARCHAR(256) NOT NULL,"
                                                   "city VARCHAR(256) NOT NULL,"
                                                   "zipCode VARCHAR(16) NOT NULL,"
                                                   "birthdate VARCHAR(32) NOT NULL,"
                                                   "phoneNumber VARCHAR(64) NOT NULL,"
                                                   "email VARCHAR(256) NOT NULL,"
                                                   "username VARCHAR(256) NOT NULL,"
                                                   "passwordHash VARCHAR(128) NOT NULL,"
                                                   "linkedInProfileUrl VARCHAR(256) NOT NULL,"
                                                   "isDeleted INTEGER NOT NULL,"
                                                   "lastModification VARCHAR(32) NOT NULL)";

const QString User::SQL_INSERT_PLACEHOLDER = "INSERT INTO user(firstName,lastName,country,province,city,zipCode,"
                                             "birthdate,phoneNumber,email,username,passwordHash,linkedInProfileUrl,"
                                             "isDeleted,lastModification) VALUES(:firstName,:lastName,:country,"
                                             ":province,:city,:zipCode,:birthdate,:phoneNumber,:email,:username,"
                                             ":passwordHash,:linkedInProfileUrl,:isDeleted,:lastModification)";

const QString User::SQL_UPDATE_PLACEHOLDER = "UPDATE user SET firstName = :firstName,lastName = :lastName,"
                                             "country = :country,province = :province,city = :city,zipCode = :zipCode,"
                                             "birthdate = :birthdate,phoneNumber = :phoneNumber,email = :email,"
                                             "username = :username,passwordHash = :passwordHash,"
                                             "linkedInProfileUrl = :linkedInProfileUrl,isDeleted = :isDeleted,"
                                             "lastModification = :lastModification WHERE id = :id";

User::User(QObject *parent)
    : QObject(parent)
{
    m_id = 0;
}

User::User(const User &other)
    : QObject(other.parent())
{
    m_id = other.m_id;
    m_firstName = other.m_firstName;
    m_lastName = other.m_lastName;
    m_country = other.m_country;
    m_province = other.m_province;
    m_city = other.m_city;
    m_zipCode = other.m_zipCode;
    m_birthdate = other.m_birthdate;
    m_phoneNumber = other.m_phoneNumber;
    m_email = other.m_email;
    m_username = other.m_username;
    m_passwordHash = other.m_passwordHash;
    m_linkedInProfileUrl = other.m_linkedInProfileUrl;
    m_isDeleted = other.m_isDeleted;
    m_lastModification = other.m_lastModification;
}

User::User(int id,
           const QString &firstName,
           const QString &lastName,
           const QString &country,
           const QString &province,
           const QString &city,
           const QString &zipCode,
           const QDate &birthdate,
           const QString &phoneNumber,
           const QString &email,
           const QString &username,
           const QString &passwordHash,
           const QString &linkedInProfileUrl,
           bool isDeleted,
           const QDateTime &lastModification,
           QObject *parent)
    : QObject(parent)
{
    m_id = id;
    m_firstName = firstName;
    m_lastName = lastName;
    m_country = country;
    m_province = province;
    m_city = city;
    m_zipCode = zipCode;
    m_birthdate = birthdate;
    m_phoneNumber = phoneNumber;
    m_email = email;
    m_username = username;
    m_passwordHash = passwordHash;
    m_linkedInProfileUrl = linkedInProfileUrl;
    m_isDeleted = isDeleted;
    m_lastModification = lastModification;
}

User* User::setId(int id)
{
    if (m_id != id)
    {
        m_id = id;
        emit idChanged(m_id);
    }
    return this;
}

User* User::setFirstName(const QString &firstName)
{
    if (m_firstName != firstName)
    {
        m_firstName = firstName;
        emit firstNameChanged(m_firstName);
    }
    return this;
}

User* User::setLastName(const QString &lastName)
{
    if (m_lastName != lastName)
    {
        m_lastName = lastName;
        emit lastNameChanged(m_lastName);
    }
    return this;
}

User* User::setCountry(const QString &country)
{
    if (m_country != country)
    {
        m_country = country;
        emit countryChanged(m_country);
    }
    return this;
}

User* User::setProvince(const QString &province)
{
    if (m_province != province)
    {
        m_province = province;
        emit provinceChanged(m_province);
    }
    return this;
}

User* User::setCity(const QString &city)
{
    if (m_city != city)
    {
        m_city = city;
        emit cityChanged(m_city);
    }
    return this;
}

User* User::setZipCode(const QString &zipCode)
{
    if (m_zipCode != zipCode)
    {
        m_zipCode = zipCode;
        emit zipCodeChanged(m_zipCode);
    }
    return this;
}

User* User::setBirthdate(const QDate &birthdate)
{
    if (m_birthdate != birthdate)
    {
        m_birthdate = birthdate;
        emit birthdateChanged(m_birthdate);
    }
    return this;
}

User* User::setPhoneNumber(const QString &phoneNumber)
{
    if (m_phoneNumber != phoneNumber)
    {
        m_phoneNumber = phoneNumber;
        emit phoneNumberChanged(m_phoneNumber);
    }
    return this;
}

User* User::setEmail(const QString &email)
{
    if (m_email != email)
    {
        m_email = email;
        emit emailChanged(m_email);
    }
    return this;
}

User* User::setUsername(const QString &username)
{
    if (m_username != username)
    {
        m_username = username;
        emit usernameChanged(m_username);
    }
    return this;
}

User* User::setPasswordHash(const QString &passwordHash)
{
    if (m_passwordHash != passwordHash)
    {
        m_passwordHash = passwordHash;
        emit passwordHashChanged(m_passwordHash);
    }
    return this;
}

User* User::setLinkedInProfileUrl(const QString &linkedInProfileUrl)
{
    if (m_linkedInProfileUrl != linkedInProfileUrl)
    {
        m_linkedInProfileUrl = linkedInProfileUrl;
        emit linkedInProfileUrlChanged(m_linkedInProfileUrl);
    }
    return this;
}

User* User::setIsDeleted(bool isDeleted)
{
    if (m_isDeleted != isDeleted)
    {
        m_isDeleted = isDeleted;
        emit isDeletedChanged(m_isDeleted);
    }
    return this;
}

User* User::setLastModification(const QDateTime &lastModification)
{
    if (m_lastModification != lastModification)
    {
        m_lastModification = lastModification;
        emit lastModificationChanged(m_lastModification);
    }
    return this;
}
