#-------------------------------------------------
#
# Project created by QtCreator 2017-03-03T21:24:53
#
#-------------------------------------------------

TARGET = MyParse
TEMPLATE = lib
CONFIG -= app_bundle qt
CONFIG += staticlib MyMemory MyFunction

HEADERS += \
    Rule/NoRule.h \
    Rule/StringRule.h \
    Rule/SubParseRule.h \
    Rule/SymboleRule.h \
    Rule/WordRule.h \
    DynamicParser.h \
    Parser.h \
    ParseRule.h \
    StaticParse.h \
    putility.h

SOURCES += \
    Rule/NoRule.cpp \
    Rule/StringRule.cpp \
    Rule/SubParseRule.cpp \
    Rule/SymboleRule.cpp \
    Rule/WordRule.cpp \
    DynamicParser.cpp \
    StaticParse.cpp

include(../build.pri)
include(../config.pri)
