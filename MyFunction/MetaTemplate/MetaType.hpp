#pragma once
#include <type_traits>

namespace binaire
{
    template<typename Type>
    struct remove_const
    {
        typedef Type type;
    };

    template<typename Type>
    struct remove_const<const Type>
    {
        typedef Type type;
    };

    template<typename Type>
    struct remove_reference
    {
        typedef Type type;
    };

    template<typename Type>
    struct remove_reference<Type &>
    {
        typedef Type type;
    };

    template<typename Type>
    struct remove_reference<Type &&>
    {
        typedef Type type;
    };

    template<typename Type>
    struct remove_volatile
    {
        typedef Type type;
    };

    template<typename Type>
    struct remove_volatile<volatile Type>
    {
        typedef Type type;
    };

    template<typename Type>
    struct remove_all_access
    {
        typedef typename remove_const<typename remove_reference<typename remove_volatile<Type>::type>::type>::type type;
    };

    template<typename Out>
    struct function_info
    {
        typedef Out Result;
    };

    template<typename Out, typename... Arg>
    struct function_info<Out(*)(Arg...)>
    {
        typedef Out Result;
        typedef Out(*Member)(Arg...);
    };

    template<typename Out, typename Obj, typename... Arg>
    struct function_info<Out(Obj::*)(Arg...)>
    {
        typedef Out Result;
        typedef Out(Obj::*Member)(Arg...);
    };

    template<typename...>
    struct Tuple
    {
        enum{
            KSize = 0
        };
    };

    template<typename VType, typename... Arg>
    struct Tuple<VType, Arg...> : public Tuple<Arg...>
    {
        enum{
            KSize = sizeof...(Arg) + 1
        };
        typedef VType type;
        typedef Tuple<Arg...> NextArg;
    };

    template<typename Type_t, Type_t ValueX>
    struct ConstValue
    {
        static constexpr Type_t Value = ValueX;
        typedef Type_t type;
    };

    typedef ConstValue<bool, true>  true_type;
    typedef ConstValue<bool, false> false_type;

    template<typename Type1_t, typename Type2_t>
    struct isSame
    {
        typedef false_type Result;
    };

    template<typename Type1_t>
    struct isSame<Type1_t, Type1_t>
    {
        typedef true_type Result;
    };

    template<bool test>
    struct isTrue;

    template<>
    struct isTrue<true>
    {
        typedef true_type type;
    };

    template<>
    struct isTrue<false>
    {
        typedef false_type type;
    };

    template<typename T, unsigned size>
    struct sizeGreat : public isTrue<(sizeof(T) > size)>
    {};

    template<typename T, unsigned size>
    struct canBeCast
    {};

    template<typename From, typename To>
    struct EqualFail
    {
        static constexpr void test()
        {
            From a = From();
            To b = a;
            static_cast<void>(b);
        }
    };

    template<typename From, bool value>
    struct __OptimalParam;

    template<typename From>
    struct __OptimalParam<From, true>
    {
        typedef const From &type;
    };
    template<typename From>
    struct __OptimalParam<From, false>
    {
        typedef From type;
    };

    template<typename From>
    struct OptimalParam
    {
        typedef typename __OptimalParam<From, (sizeof(From) > sizeof(void *))>::type type;
    };
}
