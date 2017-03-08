TARGET = MyMetaData
TEMPLATE = lib
CONFIG += staticlib MyParse MyMemory MyFunction
CONFIG -= app_bundle qt

HEADERS += \
    MetaClass.h \
    MetaData.h \
    MetaFunction.h \
    MetaValue.h \
    Registry.h \
    MetaDirectory.h

SOURCES += \
    MetaClass.cpp \
    Registry.cpp \
    MetaDirectory.cpp

include(../build.pri)
include(../config.pri)
