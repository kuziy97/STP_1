#include "contactsbook.h"
#include <gtest/gtest.h>

TEST(ContactsBook, insertRemoveClearTest) {
    ContactsBook test;
    test.insert("test", "111");
    test.insert("test2", "222");
    EXPECT_EQ(test.getContactsMap().find("test")->second, "111");
    EXPECT_EQ(test.getContactsMap().find("test2")->second, "222");
    test.remove("test2");
    EXPECT_EQ(test.getContactsMap().size(), 1);
    test.clear();
    EXPECT_EQ(test.getContactsMap().size(), 0);
}

TEST(ContactsBook, isUniqueNameTest) {
    ContactsBook test;
    test.insert("test", "111");
    test.insert("test2", "222");
    EXPECT_EQ(test.isUniqueName("test"), false);
    EXPECT_EQ(test.isUniqueName("test2"), false);
    EXPECT_EQ(test.isUniqueName("test3"), true);
}

TEST(ContactsBook, findTest) {
    ContactsBook test;
    test.insert("a", "1");
    test.insert("b", "2");
    test.insert("c", "3");
    test.insert("abc", "123");

    auto map = test.find("a");
    EXPECT_EQ(map.size(), 2);
    EXPECT_EQ(map.find("a")->second, "1");
    EXPECT_EQ(map.find("abc")->second, "123");

    map = test.find("b");
    EXPECT_EQ(map.size(), 2);
    EXPECT_EQ(map.find("b")->second, "2");
    EXPECT_EQ(map.find("abc")->second, "123");

    map = test.find("c");
    EXPECT_EQ(map.size(), 2);
    EXPECT_EQ(map.find("c")->second, "3");
    EXPECT_EQ(map.find("abc")->second, "123");

    map = test.find("1");
    EXPECT_EQ(map.size(), 2);
    EXPECT_EQ(map.find("a")->second, "1");
    EXPECT_EQ(map.find("abc")->second, "123");

    map = test.find("2");
    EXPECT_EQ(map.size(), 2);
    EXPECT_EQ(map.find("b")->second, "2");
    EXPECT_EQ(map.find("abc")->second, "123");

    map = test.find("3");
    EXPECT_EQ(map.size(), 2);
    EXPECT_EQ(map.find("c")->second, "3");
    EXPECT_EQ(map.find("abc")->second, "123");

    map = test.find("abc");
    EXPECT_EQ(map.size(), 1);
    EXPECT_EQ(map.find("abc")->second, "123");

    map = test.find("123");
    EXPECT_EQ(map.size(), 1);
    EXPECT_EQ(map.find("abc")->second, "123");

    map = test.find("d");
    EXPECT_EQ(map.size(), 0);
}

