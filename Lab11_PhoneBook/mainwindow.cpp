#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    contactsFile = new QFile("C:/Ucheba/STP/Lab11_PhoneBook/contacts.txt");
    contactsFile->open(QIODevice::ReadOnly);
    contactsBook.clear();

    while (!contactsFile->atEnd()) {
        QByteArray line = contactsFile->readLine();
        QList<QByteArray> fields = line.split(',');
        for (int i = 0; i < fields.size(); i += 2) {
            QString contact = QString("ФИО: %1\tТелефон: %2").arg(QString(fields[i])).arg(QString(fields[i + 1]).trimmed());
            contactsBook.insert(fields[i], fields[i + 1]);
            ui->contactList->addItem(contact);
        }
    }
    contactsFile->close();
}

void MainWindow::showError(const QString &message) {
    QMessageBox messageBox;
    messageBox.critical(0, "Ошибка", message);
    messageBox.setFixedSize(500, 200);
}

void MainWindow::clearInputFields() {
    ui->nameField->clear();
    ui->phoneField->clear();
}

void MainWindow::deleteContact() {
    QList<QListWidgetItem *> selectedItems = ui->contactList->selectedItems();
    for (int i = 0; i < selectedItems.size(); ++i) {
        QStringList fields = selectedItems[i]->text().split('\t');
        QString name = fields[0].remove(0, 5);
        contactsBook.remove(name);
        ui->contactList->removeItemWidget(selectedItems[i]);
        delete selectedItems[i];
    }
    clearInputFields();
}

bool MainWindow::isSearchFieldEmpty() {
    bool isEmpty = false;

    if (!ui->searchField->text().isEmpty()) {
        showError("Невозможно выполнить действие, т.к вы находитесь в режиме поиска!");
    } else isEmpty = true;

    return isEmpty;
}

bool MainWindow::isUserInputValid(const QString &name, const QString &phoneNumber) {
    bool isValid = false;

    int digitsCounter = 0;
    for (QChar digit : phoneNumber) {
        if (digit.isDigit()) digitsCounter++;
    }

    int lettersCounter = 0;
    for (QChar letter : name) {
        if (letter.isLetter() || letter == ' ') lettersCounter++;
    }

    if (name.isEmpty() || phoneNumber.isEmpty()) {
        showError("Нужно заполнить оба поля!");
    } else if (lettersCounter != name.length() || name.simplified().remove(' ').length() == 0) {
        showError("ФИО контакта должно состоять только из букв!");
    } else if (digitsCounter != phoneNumber.length()) {
        showError("Номер телефона должен состоять только из цифр!");
    } else isValid = true;

    return isValid;
}

void MainWindow::on_saveButton_clicked() {
    if (!isSearchFieldEmpty()) return;
    contactsFile->open(QIODevice::WriteOnly | QIODevice::Text);
    for (int i = 0; i < ui->contactList->count(); ++i) {
        QListWidgetItem *item = ui->contactList->item(i);
        QStringList fields = item->text().split('\t');
        contactsFile->write(QString("%1,%2\n").arg(fields[0].mid(5)).arg(fields[1].mid(9)).toUtf8());
    }
    contactsFile->close();
}

void MainWindow::on_clearButton_clicked() {
    ui->contactList->clear();
    contactsBook.clear();
    clearInputFields();
}

void MainWindow::on_deleteButton_clicked() {
    if (isSearchFieldEmpty()) {
        deleteContact();
    }
}

void MainWindow::on_changeButton_clicked() {
    if (!isSearchFieldEmpty()) return;

    QString name = ui->nameField->text();
    QString phoneNumber = ui->phoneField->text();

    if (isUserInputValid(name, phoneNumber)) {
        deleteContact();
        contactsBook.insert(name, phoneNumber);
        ui->contactList->addItem(QString("ФИО: %1\tТелефон: %2").arg(name).arg(phoneNumber));
    }
}

void MainWindow::on_addButton_clicked() {
    if (!isSearchFieldEmpty()) return;
    QString name = ui->nameField->text();
    QString phoneNumber = ui->phoneField->text();

    if (!contactsBook.isUniqueName(name)) {
        showError("ФИО контакта должно быть уникально!");
        return;
    }
    if (isUserInputValid(name, phoneNumber)) {
        contactsBook.insert(name, phoneNumber);
        ui->contactList->addItem(QString("ФИО: %1\tТелефон: %2").arg(name).arg(phoneNumber));
        clearInputFields();
    }
}

void MainWindow::on_searchField_textChanged(const QString &userInput) {
    std::multimap<QString, QString> suitableContacts = contactsBook.find(userInput.toLower());
    ui->contactList->clear();
    clearInputFields();

    if (userInput.isEmpty()) {
        for (auto& item : contactsBook.getContactsMap()) {
            QString contact = QString("ФИО: %1\tТелефон: %2").arg(QString(item.first)).arg(QString(item.second).trimmed());
            ui->contactList->addItem(contact);
        }
        return;
    }

    for (auto& item : suitableContacts) {
        QString name = item.first;
        QString phoneNumber = item.second;
        ui->contactList->addItem(QString("ФИО: %1\tТелефон: %2").arg(name).arg(phoneNumber).trimmed());
    }
}

void MainWindow::on_contactList_itemClicked(QListWidgetItem *item) {
    int position = item->text().toStdString().find("\t");

    std::string name = item->text().toStdString().erase(position, item->text().toStdString().length()).erase(0, 8);
    std::string phoneNumber = item->text().toStdString().erase(0, position + 17);

    ui->nameField->setText(QString::fromStdString(name));
    ui->phoneField->setText(QString::fromStdString(phoneNumber));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::warning(this, "Сообщение","Мы смогли");
}
