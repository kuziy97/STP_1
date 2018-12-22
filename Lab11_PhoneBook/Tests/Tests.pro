INCLUDEPATH += "gtest/include"
INCLUDEPATH += "gtest/"
INCLUDEPATH += "../"
QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    ../contactsbook.cpp \
    gtest/src/gtest.cc \
    gtest/src/gtest-all.cc \
    gtest/src/gtest-death-test.cc \
    gtest/src/gtest-filepath.cc \
    gtest/src/gtest-port.cc \
    gtest/src/gtest-printers.cc \
    gtest/src/gtest-test-part.cc \
    gtest/src/gtest-typed-test.cc \
    main.cpp

HEADERS += \
    tests.h
