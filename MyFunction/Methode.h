/**
 * Project Universe
 */


#pragma once

#include "IFunction.h"

namespace binaire
{
    template<bool isConst, typename...>
    class Methode;

    template<typename Class_t , typename Result_t , typename... Args_t >
    class Methode<false, Class_t, Result_t, Args_t...> : public IFunction<Result_t, Args_t...>
    {
    public:
        typedef Result_t (Class_t::*Member_t)(Args_t...);
        Methode(Class_t *obj, Member_t methode) : m_prt(obj), m_methode(methode)
        {}
        Methode(const Methode &) = default;
        Methode &operator=(const Methode &) = default;

        Result_t call(Args_t... arguments) const final
        {
            return (m_prt->*m_methode)(arguments...);
        }

        void setObject(Class_t *obj)
        {
            m_prt = obj;
        }

    private:
        mutable Class_t *m_prt;
        Member_t m_methode;
    };

    template<typename Class_t , typename... Args_t >
    class Methode<false, Class_t, void, Args_t...> : public IFunction<void, Args_t...>
    {
    public:
        typedef void (Class_t::*Member_t)(Args_t...);
        Methode(Class_t *obj, Member_t methode) : m_prt(obj), m_methode(methode)
        {}
        Methode(const Methode &) = default;
        Methode &operator=(const Methode &) = default;

        void call(Args_t... arguments) const final
        { (m_prt->*m_methode)(arguments...); }

        void setObject(Class_t *obj)
        {
            m_prt = obj;
        }

    private:
        mutable Class_t *m_prt;
        Member_t m_methode;
    };


    template<typename Class_t , typename Result_t , typename... Args_t>
    class Methode<true, Class_t, Result_t, Args_t...> : public IFunction<Result_t, Args_t...>
    {
    public:
        typedef Result_t (Class_t::*Member_t)(Args_t...) const;
        Methode(Class_t *obj, Member_t methode) : m_prt(obj), m_methode(methode)
        {}
        Methode(const Methode &) = default;
        Methode &operator=(const Methode &) = default;

        Result_t call(Args_t... arguments) const final
        {
            return (m_prt->*m_methode)(arguments...);
        }

        void setObject(Class_t *obj)
        {
            m_prt = obj;
        }

    private:
        mutable Class_t *m_prt;
        Member_t m_methode;
    };

    template<typename Class_t , typename... Args_t >
    class Methode<true, Class_t, void, Args_t...> : public IFunction<void, Args_t...>
    {
    public:
        typedef void (Class_t::*Member_t)(Args_t...) const;
        Methode(Class_t *obj, Member_t methode) : m_prt(obj), m_methode(methode)
        {}
        Methode(const Methode &) = default;
        Methode &operator=(const Methode &) = default;

        void call(Args_t... arguments) const final
        { (m_prt->*m_methode)(arguments...); }

        void setObject(Class_t *obj)
        {
            m_prt = obj;
        }

    private:
        mutable Class_t *m_prt;
        Member_t m_methode;
    };

    template<typename...>
    struct _Methode;

    template<typename Class_t , typename Result_t , typename... Args_t>
    struct _Methode <Class_t, Result_t, Args_t...>
    {
        typedef Methode<false, Class_t, Result_t, Args_t...> Target_t;
    };

    template<typename Class_t , typename Result_t , typename... Args_t>
    struct _Methode <Result_t (Class_t::*)(Args_t...) const>
    {
        typedef Methode<true, Class_t, Result_t, Args_t...> Target_t;
    };

    template<typename Class_t , typename Result_t , typename... Args_t>
    struct _Methode <Result_t (Class_t::*)(Args_t...)>
    {
        typedef Methode<false, Class_t, Result_t, Args_t...> Target_t;
    };
}
