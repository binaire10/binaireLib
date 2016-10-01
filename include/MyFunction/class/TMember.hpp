#pragma once
#include "../IFunction.hpp"

namespace binaire
{
    template<typename...>
    class TMember;

    template<typename Obj_t, typename Member_t>
    TMember<Member_t> make_ObjectBind(Obj_t &Obj, Member_t Member)
    {
        return TMember<Member_t>(Obj, Member);
    }

    template<typename Return_t, typename Obj_t, typename... Arg_t>
    class TMember<Return_t(Obj_t::*)(Arg_t...)> : public virtual IFunction<Return_t, Arg_t...>
    {
    public:
        typedef void (Obj_t::*Member_t)(Arg_t...);
        typedef Obj_t Object_t;
        typedef IFunction<Return_t, Arg_t...> Parent_t;

    private:
        mutable Member_t m_Member;
        mutable Obj_t *m_BaseObject;

    public:
        TMember() noexcept = default;
        TMember(const TMember &) = default;
        TMember &operator=(const TMember &) = default;
        explicit TMember(Obj_t &obj, Member_t Func) noexcept : m_Member(Func), m_BaseObject(&obj)
        {}
        explicit TMember(Obj_t *obj, Member_t Func) noexcept : m_Member(Func), m_BaseObject(obj)
        {}
        virtual ~TMember() noexcept = default;

        Return_t operator()(Arg_t... arg) final
        {return (m_BaseObject->*m_Member)(arg...);}

        Return_t operator()(Arg_t... arg) const final
        {return (m_BaseObject->*m_Member)(arg...);}

        Member_t Member() const noexcept
        {return m_Member;}

        void setMember(Member_t NewMember) noexcept
        {m_Member = NewMember;}

        void setBaseObject(Obj_t *NewBase) noexcept
        {m_BaseObject = NewBase;}

        const Obj_t *BaseObject() const noexcept
        {return m_BaseObject;}

    };

    template<typename Obj_t, typename... Arg_t>
    class TMember<void(Obj_t::*)(Arg_t...)> : public virtual IFunction<void, Arg_t...>
    {
    public:
        typedef void (Obj_t::*Member_t)(Arg_t...);
        typedef Obj_t Object_t;
        typedef IFunction<void, Arg_t...> Parent_t;

    private:
        mutable Member_t m_Member;
        mutable Obj_t *m_BaseObject;

    public:
        TMember() noexcept = default;
        TMember(const TMember &) = default;
        TMember &operator=(const TMember &) = default;
        explicit TMember(Obj_t &obj, Member_t Func) noexcept : m_Member(Func), m_BaseObject(&obj)
        {}
        explicit TMember(Obj_t *obj, Member_t Func) noexcept : m_Member(Func), m_BaseObject(obj)
        {}
        virtual ~TMember() noexcept = default;

        void operator()(Arg_t... arg) final
        {(m_BaseObject->*m_Member)(arg...);}

        void operator()(Arg_t... arg) const final
        {(m_BaseObject->*m_Member)(arg...);}

        Member_t Member() const noexcept
        {return m_Member;}

        void setMember(Member_t NewMember) noexcept
        {m_Member = NewMember;}

        void setBaseObject(Obj_t *NewBase) noexcept
        {m_BaseObject = NewBase;}

        const Obj_t *BaseObject() const noexcept
        {return m_BaseObject;}
    };

    template<typename Return_t, typename Obj_t, typename... Arg_t>
    class TMember<Return_t(Obj_t::*)(Arg_t...) const> : public virtual IFunction<Return_t, Arg_t...>
    {
    public:
        typedef void (Obj_t::*Member_t)(Arg_t...) const;
        typedef Obj_t Object_t;
        typedef IFunction<Return_t, Arg_t...> Parent_t;

    private:
        Member_t m_Member;
        const Obj_t *m_BaseObject;

    public:
        TMember() noexcept = default;
        TMember(const TMember &) = default;
        TMember &operator=(const TMember &) = default;
        explicit TMember(Obj_t &obj, Member_t Func) noexcept : m_Member(Func), m_BaseObject(&obj)
        {}
        explicit TMember(Obj_t *obj, Member_t Func) noexcept : m_Member(Func), m_BaseObject(obj)
        {}
        virtual ~TMember() noexcept = default;

        Return_t operator()(Arg_t... arg) final
        {return (m_BaseObject->*m_Member)(arg...);}

        Return_t operator()(Arg_t... arg) const final
        {return (m_BaseObject->*m_Member)(arg...);}

        Member_t Member() const noexcept
        {return m_Member;}

        void setMember(Member_t NewMember) noexcept
        {m_Member = NewMember;}

        void setBaseObject(Obj_t *NewBase) noexcept
        {m_BaseObject = NewBase;}

        const Obj_t *BaseObject() const noexcept
        {return m_BaseObject;}
    };

    template<typename Obj_t, typename... Arg_t>
    class TMember<void(Obj_t::*)(Arg_t...) const> : public virtual IFunction<void, Arg_t...>
    {
    public:
        typedef void (Obj_t::*Member_t)(Arg_t...) const;
        typedef Obj_t Object_t;
        typedef IFunction<void, Arg_t...> Parent_t;

    private:
        Member_t m_Member;
        const Obj_t *m_BaseObject;

    public:
        TMember() noexcept = default;
        explicit TMember(Obj_t &obj, Member_t Func) noexcept : m_Member(Func), m_BaseObject(&obj)
        {}
        explicit TMember(Obj_t *obj, Member_t Func) noexcept : m_Member(Func), m_BaseObject(obj)
        {}
        virtual ~TMember() noexcept = default;

        void operator()(Arg_t... arg) final
        {(m_BaseObject->*m_Member)(arg...);}

        void operator()(Arg_t... arg) const final
        {(m_BaseObject->*m_Member)(arg...);}

        Member_t Member() const
        {return m_Member;}

        void setMember(Member_t NewMember) noexcept
        {m_Member = NewMember;}

        void setBaseObject(Obj_t *NewBase) noexcept
        {m_BaseObject = NewBase;}

        const Obj_t *BaseObject() const noexcept
        {return m_BaseObject;}
    };
}
