#include "contactsbook.h"
#include <QString>

void ContactsBook::insert(const QString &name, const QString &phoneNumber) {
    contactsMap.insert(std::make_pair(name, phoneNumber));
}

void ContactsBook::remove(const QString &name) {
    contactsMap.erase(name);
}

void ContactsBook::clear() {
    contactsMap.clear();
}

std::multimap<QString, QString> ContactsBook::getContactsMap() {
    return contactsMap;
}

bool ContactsBook::isUniqueName(const QString &name) {
    bool isUnique = false;

    auto result = contactsMap.find(name);
    if (result == contactsMap.end()) {
        isUnique = true;
    }
    return isUnique;
}

std::multimap<QString, QString> ContactsBook::find(const QString &searchText) {
    std::multimap<QString, QString> result;

    for (auto& item : contactsMap) {
        if (item.first.toLower().contains(searchText)  || item.second.toLower().contains(searchText)) {
            result.insert(std::make_pair(item.first, item.second));
        }
    }
    return result;
}
