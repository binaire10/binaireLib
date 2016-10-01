INCLUDEPATH += $$PWD/include

CONFIG += precompile_header

PRECOMPILED_HEADER  = $$PWD/compiledheader.hpc

QMAKE_CXXFLAGS += -std=c++14

win32 {
    CONFIG(debug, debug|release) {
        LIBS += -L$$shadowed($$PWD)/debug -lBinaireLib
    }else {
        LIBS += -L$$shadowed($$PWD)/release -lBinaireLib
    }
}
unix {
        LIBS += -lBinaireLib -L$$shadowed($$PWD)
}

