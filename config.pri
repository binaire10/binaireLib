QMAKE_CXXFLAGS += -pedantic -Wall -Wextra -Wold-style-cast -Woverloaded-virtual -Wfloat-equal -Wwrite-strings -Wpointer-arith -Wcast-qual -Wcast-align -Wconversion -Wshadow -Weffc++ -Wredundant-decls -Wdouble-promotion -Winit-self -Wswitch-default -Wswitch-enum -Wundef -Wlogical-op -Winline -include $$PWD/config.h
CONFIG += c++14
QMAKE_CXXFLAGS_GNUCXX14 = -std=c++14
DEFINES += defaultvalue={} undefined=0  unused(X)=void
HEADERS += $$PWD/config.h

MyParse|MyException|MyType|MyMetaData {
    CONFIG(debug, debug|release) {
        LIBS += -L$$PWD/lib/debug
    } else {
        LIBS += -L$$PWD/lib/release
    }
}

# MyMetaData
MyMetaData {
    INCLUDEPATH += $$PWD/MyMetaData
    LIBS += -lMyMetaData
}

# MySignal
MySignal {
    INCLUDEPATH += $$PWD/MySignal
}

# MyType
MyType {
    INCLUDEPATH += $$PWD/MyType
    LIBS += -lMyType
}

# MyParse
MyParse|MyMetaData {
    INCLUDEPATH += $$PWD/MyParse
    LIBS += -lMyParse
}

# MyFunction
MyFunction|MyParse|MySignal|MyMetaData {
    INCLUDEPATH += $$PWD/MyFunction
}

# MyException
MyException {
    INCLUDEPATH += $$PWD/MyException
    LIBS += -lMyException
}

# MyMemory
MyMemory|MyFunction|MyParse|MyMetaData {
    INCLUDEPATH += $$PWD/MyMemory
}
