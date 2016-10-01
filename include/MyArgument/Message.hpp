#pragma once
#include "PackedArgument.hpp"
#include "../MyFunction/IFunction.hpp"
#include "../MyMemory/SmartPtr.hpp"
#include <vector>

namespace binaire
{

    class FastCall
    {
    public:
        virtual ~FastCall() noexcept = default;
        virtual void call() const = 0;
        virtual const unsigned &getId() const = 0;
    };

    template<typename... Arg_t>
    class Message : public FastCall
    {
    public:
        typedef FastCall Parent_t;

    private:
        IPtr< IFunction<void, Arg_t...> > *m_SlotPtr;
        PackedArgument<Arg_t...> m_Arg;
        const unsigned m_Id;

    public:
        Message(const IPtr< IFunction<void, Arg_t...> > &Ref, Arg_t... arg, const unsigned &Id = 0) noexcept : m_SlotPtr(Ref.clone()), m_Arg(arg...), m_Id(Id)
        {}
        Message(const Message &) = default;
        Message &operator=(const Message &) = default;

        ~Message() noexcept override
        {
            delete m_SlotPtr;
        }

        void call() const final
        {
            IFunction<void, Arg_t...> &FastCall = **m_SlotPtr;
            m_Arg.call(FastCall);
        }
        const unsigned &getId() const final
        {
            return m_Id;
        }
    };

    template<>
    class Message<> : public FastCall
    {
    public:
        typedef FastCall Parent_t;

    private:
        IPtr< IFunction<void> > *m_SlotPtr;
        const unsigned m_Id;

    public:
        Message(const IPtr<IFunction<void>> &Ref , const unsigned &Id = 0) noexcept : m_SlotPtr(nullptr), m_Id(Id)
        {
            m_SlotPtr = Ref.clone();
        }
        Message(const Message &) = default;
        Message &operator=(const Message &) = default;
        ~Message() noexcept override
        {}

        void call() const final
        {
            (**m_SlotPtr)();
        }

        const unsigned &getId() const final
        {
            return m_Id;
        }
    };
}
