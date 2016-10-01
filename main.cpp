#include <iostream>
#include <vector>
#include "include/MySignal/FonctionAdapter.hpp"
#include "include/MyValidator/MyValidator.hpp"
#include "include/MySystem/Output/IOutput.h"
#include "include/MySignal/SignalStack.h"
#include "include/MySystem/CException.h"
#include "include/MyArgument/Message.hpp"
#include "include/MyMemory/SmartPtr.hpp"
#include "include/MyFunction/utility.hpp"
#include "include/MySignal/CSignal.hpp"
#include "include/MySignal/CSlot.hpp"
#include "include/SystemFunction.h"
#include "CstCodErr.h"
#include "IEditable.h"
#include <string>
#include <unistd.h>
#include "include/MySystem/Thread/IThread.hpp"
#include "include/MyFunction/utility.hpp"
#include "include/MyFunction/CFunction.h"

using namespace std;
using namespace binaire;
using namespace System;


class A : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "hello";
    }
};

void myCall(int a)
{
    cout << a << endl;
}

void prompt()
{
    cout << "x_x" << endl;
}

BINAIRELIBSHARED_EXPORT int test()
{
    CFunction<void> k;
    auto SlotX(binaire::SmartCall::make_IFunction(myCall));

    binaire::System::Call::CSlot<decltype(myCall) *,int> Slot(myCall);
    SmartPtr<IFunction<void, int> > SSlot(&SlotX, new SmartPtr<IFunction<void, int> >::DeleterNothing_t);
    SmartPtr<IFunction<void, int> > SSlot2(&Slot, new SmartPtr<IFunction<void, int> >::DeleterNothing_t);
    binaire::SignalStack StackCall;
    binaire::System::Call::Signal<int> Sig(StackCall);

    Sig.addSlot(SSlot);
    Sig.addSlot(SSlot2);

    Sig.emitSig(13);
    Sig.emitSig(42);
    StackCall.exec();

    SmartPtr<IMutex> xc = CreatMutex();


    return nsUtil::KNoError;
}
