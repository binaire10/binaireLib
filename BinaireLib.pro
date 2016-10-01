#-------------------------------------------------
#
# Project created by QtCreator 2016-05-20T11:50:11
#
#-------------------------------------------------

TARGET = BinaireLib
TEMPLATE = lib

CONFIG -= app_bundle qt
CONFIG += precompile_header

DEFINES += BINAIRELIB_LIBRARY

QMAKE_CXXFLAGS += -pedantic -Wwrite-strings -Weffc++ -std=c++14

CONFIG += staticlib

SOURCES += binairelib.cpp \
    impl/SignalStack.cpp \
    include/MyFile/idir.cpp \
    include/MyFile/IFile.cpp \
    main.cpp \
    check.cpp \
    impl/console.cpp \
    impl/SmartPtr.cpp \
    impl/IThread.cpp \
    impl/IStream.cpp \
    impl/cstringstream.cpp \
    impl/parse/CharParse.cpp \
    impl/parse/LexicalParseur.cpp \
    impl/parse/LimitedSequenceParse.cpp \
    impl/parse/StringParse.cpp \
    impl/parse/SymboleParse.cpp \
    impl/parse/WordParse.cpp

PRECOMPILED_HEADER  = compiledheader.hpc

HEADERS += binairelib.h\
    include/MetaTemplate/MetaReturn.hpp \
    include/MetaTemplate/MetaType.hpp \
    include/MyArgument/PackedArgument.hpp \
    include/MyFile/IDir.h \
    include/MyFile/IFile.h \
    include/MyFunction/class/TMember.hpp \
    include/MyFunction/function/TFunction.hpp \
    include/MyFunction/lambda/ObjBind.hpp \
    include/MyFunction/lambda/TFonctor.hpp \
    include/MyFunction/CFunction.hpp \
    include/MyMemory/SmartPtr.hpp \
    include/MyMemory/swap.hpp \
    include/MySignal/CSlot.hpp \
    include/MySignal/FonctionAdapter.hpp \
    include/MySignal/SignalStack.h \
    include/MySystem/CException/CException.h \
    include/MySystem/CException/CException.hpp \
    include/MySystem/Device/IDevice.h \
    include/MySystem/Output/IOutput.h \
    include/MySystem/Thread/IThread.hpp \
    include/MySystem/CException.h \
    include/MyType/clonetype.h \
    include/MyType/natiftype.h \
    include/MyValidator/MyPredicat.hpp \
    include/MyValidator/MyValidator.hpp \
    include/IDumpable.h \
    CstCodErr.h \
    functiontool.h \
    IEditable.h \
    nsUtil.h \
    smarvar.h \
    vectorRef.h \
    include/MyMemory/RefPtr.hpp \
    include/MyMemory/IPtr.hpp \
    check.h \
    include/binairelib_global.h \
    include/SystemFunction.h \
    include/MySystem/Input/IInput.h \
    include/MySystem/Console.h \
    include/allDeclaration.h \
    include/MySystem/Mutex/IMutex.h \
    include/MyFunction/IFunction.h \
    include/MyFunction/utility.hpp \
    include/MyFunction/utility.h \
    include/MyFunction/CFunction.h \
    include/MyFunction/IFunction.hpp \
    include/MySystem/IIOstream.h \
    include/MySignal/CSignal/CSignal.h \
    include/MySignal/CSignal/CSignal.hpp \
    include/MySignal/CSignal.hpp \
    include/MySignal/CSlot/CSlot.h \
    include/MySignal/CSlot/CSlot.hpp \
    include/MySignal/CSlot.hpp \
    include/MyArgument/Message.hpp \
    include/MySystem/CStreamString.h \
    include/MySystem/IStream.h \
    include/MyParse/CharParse.h \
    include/MyParse/LexicalParseur.h \
    include/MyParse/LimitedSequenceParse.h \
    include/MyParse/StringParse.h \
    include/MyParse/SymboleParse.h \
    include/MyParse/WordParse.h \
    include/MyMemory/ultimateptr.h \
    include/MyMemory/SmartPtr.h

DISTFILES += \
    import.pri

# only for unix system with pthread
unix{
 LIBS += -static
#message(build for pthread model)
SOURCES += impl/thread_pthread.cpp\
           impl/mutex_pthread.cpp
}

# only for win32 system with native threading
win32 {
#message(build for win32 model)
SOURCES += impl/thread_win32.cpp \
           impl/mutex_win32.cpp
}
