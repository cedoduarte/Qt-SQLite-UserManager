#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../shared/databasehandler.h"

#include <sha256jeremy.h>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    ui->tableWidget->populate();
    setTextBoxPlaceHolder();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionClose_triggered()
{
    close();
}

bool MainWindow::validEntries()
{
    QString firstName = ui->txtFirstName->text();
    if (firstName.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "The first name is mandatory!");
        return false;
    }
    QString lastName = ui->txtLastName->text();
    if (lastName.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "The last name is mandatory!");
        return false;
    }
    QString province = ui->txtProvince->text();
    if (province.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "The province is mandatory!");
        return false;
    }
    QString city = ui->txtCity->text();
    if (city.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "The city is mandatory!");
        return false;
    }
    QString zipCode = ui->txtZipCode->text();
    if (zipCode.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "The zip code is mandatory!");
        return false;
    }
    QString phoneNumber = ui->txtPhoneNumber->text();
    if (phoneNumber.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "The phone number is mandatory!");
        return false;
    }
    if (!ui->txtEmail->isValid())
    {
        QMessageBox::warning(this, "Warning", "The email needs to be valid!");
        return false;
    }
    if (!ui->txtUsername->isValid())
    {
        QMessageBox::warning(this, "Warning", "The username needs to be valid!");
        return false;
    }
    if (!ui->txtPassword->isValid())
    {
        QMessageBox::warning(this, "Warning", "The password needs to be valid!");
        return false;
    }
    QString password = ui->txtPassword->text();
    QString confirmPassword = ui->txtConfirmPassword->text();
    if (password != confirmPassword)
    {
        QMessageBox::warning(this, "Warning", "The password needs to be confirmed!");
        return false;
    }
    if (!ui->txtLinkedInProfileUrl->isValid())
    {
        QMessageBox::warning(this, "Warning", "The LinkedIn profile URL needs to be valid!");
        return false;
    }
    return true;
}

void MainWindow::setTextBoxPlaceHolder()
{
    ui->txtFirstName->setPlaceholderText("Enter first name");
    ui->txtLastName->setPlaceholderText("Enter last name");
    ui->txtProvince->setPlaceholderText("Enter province");
    ui->txtCity->setPlaceholderText("Enter city");
    ui->txtZipCode->setPlaceholderText("Enter zip code");
    ui->txtPhoneNumber->setPlaceholderText("Enter phone number");
    ui->txtEmail->setPlaceholderText("Enter email");
    ui->txtUsername->setPlaceholderText("Enter username");
    ui->txtPassword->setPlaceholderText("Enter password");
    ui->txtConfirmPassword->setPlaceholderText("Confirm password");
    ui->txtLinkedInProfileUrl->setPlaceholderText("Enter linkedin profile url");
}

void MainWindow::on_saveButton_clicked()
{
    if (validEntries())
    {
        Sha256jeremy sha256;
        DatabaseHandler db;
        User newUser;
        newUser.setUsername(ui->txtUsername->text())
            ->setBirthdate(ui->dateBirthdate->date())
            ->setCity(ui->txtCity->text())
            ->setCountry(ui->comboCountry->currentText())
            ->setEmail(ui->txtEmail->text())
            ->setFirstName(ui->txtFirstName->text())
            ->setLastName(ui->txtLastName->text())
            ->setLastModification(QDateTime::currentDateTime())
            ->setIsDeleted(false)
            ->setLinkedInProfileUrl(ui->txtLinkedInProfileUrl->text())
            ->setPhoneNumber(ui->txtPhoneNumber->text())
            ->setZipCode(ui->txtZipCode->text())
            ->setProvince(ui->txtProvince->text())
            ->setPasswordHash(sha256.encode(ui->txtPassword->text()));
        int lastInsertedId = db.insertUser(newUser);
        if (lastInsertedId != -1)
        {
            newUser.setId(lastInsertedId);
            ui->tableWidget->appendUser(&newUser);
            QMessageBox::information(this, "OK", "User saved successfully!");
        }
        else
        {
            qDebug() << "Error:" << __FILE__ << __LINE__;
        }
    }
}

void MainWindow::on_refreshButton_clicked()
{
    ui->tableWidget->populate();
}

void MainWindow::on_restoreButton_clicked()
{
    DatabaseHandler db;
    std::vector<User> deletedUserList = db.userSelect("isDeleted = 1");
    for (User &deletedUser : deletedUserList)
    {
        deletedUser.setIsDeleted(false);
        db.updateUser(deletedUser);
    }
    on_refreshButton_clicked();
}

void MainWindow::on_editButton_clicked()
{
    ui->tableWidget->enableEdition(!ui->tableWidget->editionEnabled());
    ui->editButton->setText(ui->tableWidget->editionEnabled() ? "Edit (ON)" : "Edit (OFF)");
}

void MainWindow::on_saveEditionButton_clicked()
{
    ui->tableWidget->saveUpdatedRows();
}

