#pragma once
#include "binairelib_global.h"

namespace binaire
{
    template<typename Return_t, typename... Arg_t>
    class IFunction;

    template<typename...>
    class TMember;

    template<typename Fonctor_t>
    class TFonctor;

    template<typename Return_t, typename... Arg_t>
    class TFunction;

    template<typename Return_t, typename... Arg_t>
    class CFunction;

    template<typename Type>
    class SmartPtr;

    template<class Type>
    class RefPtr;

    template<class X>
    class IPtr;

    class SignalStack;
    class FastCall;

    template<typename...>
    class Message;

    namespace System
    {
        class IMutex;
        class IThread;

        class Console;
        namespace Call
        {
                template<typename... Arg_t>
                class Signal;
        }
    }
}
