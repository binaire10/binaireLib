#ifndef FUNCTIONTOOL
#define FUNCTIONTOOL
namespace binaire
{
    typedef unsigned uint_t;
    namespace expiremental
    {
        template<typename Out, typename Obj, typename... Arg>
        struct ptrSub
        {
            typedef Out(*function)(Arg...);
            typedef Out(Obj::*member)(Arg...);
            typedef Out &&Result;
        };

        template<typename Obj, typename... Arg>
        struct ptrSub<void, Obj, Arg...>
        {
            typedef void(*function)(Arg...);
            typedef void(Obj::*member)(Arg...);
            typedef void Result;
        };

        template<typename Out, typename Obj, typename... Arg>
        class MFunction
        {
            typedef ptrSub<Out, Obj, Arg...> MemberInfo;
            typedef typename MemberInfo::member FunctionMember;
            typedef typename MemberInfo::Result Result;
            typedef std::pair<Obj*, FunctionMember> linkedMember;

        public:
            MFunction(Obj *o,FunctionMember *ptr) :m_base(linkedMember(o,ptr))
            {}
            MFunction(linkedMember A) :m_base(A)
            {}
            Result operator ()(Arg... arg)
            {
                return (m_base.first->*m_base.second)(arg...);
            }

        private:
            linkedMember m_base;
        };

        template<typename Out, typename Obj, typename... Arg>
        MFunction<Out, Obj, Arg...> getFunction(Obj *base, Out(Obj::*AMem)(Arg...))
        {
            return std::make_pair(base, AMem);
        }
    }
}

#endif // FUNCTIONTOOL

