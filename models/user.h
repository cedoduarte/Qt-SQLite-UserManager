#ifndef USER_H
#define USER_H

#include <QObject>
#include <QDateTime>

class User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged FINAL)
    Q_PROPERTY(QString firstName READ firstName WRITE setFirstName NOTIFY firstNameChanged FINAL)
    Q_PROPERTY(QString lastName READ lastName WRITE setLastName NOTIFY lastNameChanged FINAL)
    Q_PROPERTY(QString country READ country WRITE setCountry NOTIFY countryChanged FINAL)
    Q_PROPERTY(QString province READ province WRITE setProvince NOTIFY provinceChanged FINAL)
    Q_PROPERTY(QString city READ city WRITE setCity NOTIFY cityChanged FINAL)
    Q_PROPERTY(QString zipCode READ zipCode WRITE setZipCode NOTIFY zipCodeChanged FINAL)
    Q_PROPERTY(QDate birthdate READ birthdate WRITE setBirthdate NOTIFY birthdateChanged FINAL)
    Q_PROPERTY(QString phoneNumber READ phoneNumber WRITE setPhoneNumber NOTIFY phoneNumberChanged FINAL)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged FINAL)
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged FINAL)
    Q_PROPERTY(QString passwordHash READ passwordHash WRITE setPasswordHash NOTIFY passwordHashChanged FINAL)
    Q_PROPERTY(QString linkedInProfileUrl READ linkedInProfileUrl WRITE setLinkedInProfileUrl NOTIFY linkedInProfileUrlChanged FINAL)
    Q_PROPERTY(bool isDeleted READ isDeleted WRITE setIsDeleted NOTIFY isDeletedChanged FINAL)
    Q_PROPERTY(QDateTime lastModification READ lastModification WRITE setLastModification NOTIFY lastModificationChanged FINAL)
public:
    enum Field
    {
        ID,
        FIRST_NAME,
        LAST_NAME,
        COUNTRY,
        PROVINCE,
        CITY,
        ZIP_CODE,
        BIRTHDATE,
        PHONE_NUMBER,
        EMAIL,
        USERNAME,
        PASSWORD_HASH,
        LINKEDIN_PROFILE_URL,
        IS_DELETED,
        LAST_MODIFICATION
    };

    User(QObject *parent = nullptr);

    User(const User &other);

    User(int id,
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
         QObject *parent = nullptr);

    virtual ~User() {}

    int id() const { return m_id; }
    QString firstName() const { return m_firstName; }
    QString lastName() const { return m_lastName; }
    QString country() const { return m_country; }
    QString province() const { return m_province; }
    QString city() const { return m_city; }
    QString zipCode() const { return m_zipCode; }
    QDate birthdate() const { return m_birthdate; }
    QString phoneNumber() const { return m_phoneNumber; }
    QString email() const { return m_email; }
    QString username() const { return m_username; }
    QString passwordHash() const { return m_passwordHash; }
    QString linkedInProfileUrl() const { return m_linkedInProfileUrl; }
    bool isDeleted() const { return m_isDeleted; }
    QDateTime lastModification() const { return m_lastModification; }

    User* setId(int id);
    User* setFirstName(const QString &firstName);
    User* setLastName(const QString &lastName);
    User* setCountry(const QString &country);
    User* setProvince(const QString &province);
    User* setCity(const QString &city);
    User* setZipCode(const QString &zipCode);
    User* setBirthdate(const QDate &birthdate);
    User* setPhoneNumber(const QString &phoneNumber);
    User* setEmail(const QString &email);
    User* setUsername(const QString &username);
    User* setPasswordHash(const QString &passwordHash);
    User* setLinkedInProfileUrl(const QString &linkedInProfileUrl);
    User* setIsDeleted(bool isDeleted);
    User* setLastModification(const QDateTime &lastModification);

    static const QString SQL_CREATE_TABLE_PLACEHOLDER;
    static const QString SQL_INSERT_PLACEHOLDER;
    static const QString SQL_UPDATE_PLACEHOLDER;
signals:
    void idChanged(int id);
    void firstNameChanged(const QString &firstName);
    void lastNameChanged(const QString &lastName);
    void countryChanged(const QString &country);
    void provinceChanged(const QString &province);
    void cityChanged(const QString &city);
    void zipCodeChanged(const QString &zipCode);
    void birthdateChanged(const QDate &birthdate);
    void phoneNumberChanged(const QString &phoneNumber);
    void emailChanged(const QString &email);
    void usernameChanged(const QString &username);
    void passwordHashChanged(const QString &passwordHash);
    void linkedInProfileUrlChanged(const QString &linkedInProfileUrl);
    void isDeletedChanged(bool isDeleted);
    void lastModificationChanged(const QDateTime &lastModification);
private:
    int m_id;
    QString m_firstName;
    QString m_lastName;
    QString m_country;
    QString m_province;
    QString m_city;
    QString m_zipCode;
    QDate m_birthdate;
    QString m_phoneNumber;
    QString m_email;
    QString m_username;
    QString m_passwordHash;
    QString m_linkedInProfileUrl;
    bool m_isDeleted;
    QDateTime m_lastModification;
};

#endif // USER_H
