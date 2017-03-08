
TARGET = MyType
TEMPLATE = lib
CONFIG -= app_bundle qt
CONFIG += staticlib MyMemory MyFunction

include(../build.pri)
include(../config.pri)

HEADERS += \
    Index/ManagementType.h \
    Index/NativeIndex.h \
    Index/TypeGestionary.h \
    Index/TypeIndex.h \
    Singleton.h \
    tutility.h

SOURCES += \
    Index/ManagementType.cpp \
    Index/NativeIndex.cpp
