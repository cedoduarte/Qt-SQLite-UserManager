#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../shared/databasehandler.h"

#include <sha256jeremy.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DatabaseHandler db;

    // Sha256jeremy sha256;
    // QString passwordHash = sha256.encode("mypassword:)");

    // User newUser;
    // newUser.setUsername("cedo")
    //     ->setBirthdate(QDate(1995, 2, 5))
    //     ->setCity("Navojoa")
    //     ->setCountry("México")
    //     ->setFirstName("Pedro Francisco")
    //     ->setLastName("Duarte Ortiz")
    //     ->setLastModification(QDateTime::currentDateTime())
    //     ->setEmail("carlosduarte.1@hotmail.com")
    //     ->setIsDeleted(false)
    //     ->setLinkedInProfileUrl("https://www.linkedin.com/in/cedoduarte")
    //     ->setPhoneNumber("+526622769242")
    //     ->setZipCode("83170")
    //     ->setProvince("Sonora")
    //     ->setPasswordHash(passwordHash)
    //     ->setId(1);

    // db.insertUser(newUser);


    //db.updateUser(newUser);

    //db.deleteUser(1);
    // for (const User &user : db.userSelect(""))
    // {
    //     qDebug() << user.username();
    // }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionClose_triggered()
{
    close();
}

