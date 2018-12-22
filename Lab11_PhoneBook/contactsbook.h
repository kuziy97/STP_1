#include <map>
#include <string>
#include <QString>

class ContactsBook {
public:
    void insert(const QString &name, const QString &phoneNumber);

    void remove(const QString &name);

    void clear();

    std::multimap<QString, QString> getContactsMap();

    bool isUniqueName(const QString &name);

    std::multimap<QString, QString> find(const QString &searchText);

private:
    std::multimap<QString, QString> contactsMap;
};
