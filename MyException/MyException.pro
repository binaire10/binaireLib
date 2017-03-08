TARGET = MyException
TEMPLATE = lib
CONFIG += staticlib MyMetaData

include(../build.pri)
include(../config.pri)

HEADERS += \
    CodeException.h \
    InvalideArgument.h

SOURCES += \
    CodeException.cpp \
    InvalideArgument.cpp
