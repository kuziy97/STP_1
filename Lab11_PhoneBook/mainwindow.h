#include <QFile>
#include <QListWidgetItem>
#include <QMainWindow>
#include "contactsbook.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showError(const QString &message);

    void clearInputFields();

    void deleteContact();

    bool isSearchFieldEmpty();

    bool isUserInputValid(const QString &name, const QString &phoneNumber);

    void on_saveButton_clicked();

    void on_clearButton_clicked();

    void on_deleteButton_clicked();

    void on_changeButton_clicked();

    void on_addButton_clicked();

    void on_searchField_textChanged(const QString &userInput);

    void on_contactList_itemClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    ContactsBook contactsBook;
    QFile *contactsFile;
};
