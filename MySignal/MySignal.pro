SOURCES += \
    main.cpp

CONFIG += MyFunction

include(../build.pri)
include(../config.pri)

HEADERS += \
    CSignal.h \
    ICall.h \
    ISignalCall.h \
    ISignalManager.h \
    SignalCallBox.h \
    SignalCallUnique.h \
    SignalManager.h
