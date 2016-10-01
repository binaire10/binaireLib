#pragma once

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
}
