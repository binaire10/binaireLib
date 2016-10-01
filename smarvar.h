#ifndef SMARVAR
#define SMARVAR
#include "functiontool.h"
namespace binaire
{
    typedef unsigned uint_t;
    namespace expiremental
    {
        template<typename Type>
        class SmartReference
        {
        public:
            SmartReference()
            {}

            SmartReference(Type &val) : m_ptr(&val)
            {}

            SmartReference(Type *val) : m_ptr(val)
            {}

            //Ref Compatibility
            //

            template<typename... IN>
            auto operator ()(IN&&... arg)
            {return (*m_ptr)(arg...);}

            //assignment operator

            template<typename OUT, typename IN>
            OUT operator +=(IN &a)
            {return (*m_ptr)+=a;}

            template<typename OUT, typename IN>
            OUT operator -=(IN &a)
            {return (*m_ptr)-=a;}

            template<typename OUT, typename IN>
            OUT operator =(IN a)
            {return (*m_ptr)=a;}

            template<typename OUT, typename IN>
            OUT operator *=(IN a)
            {return (*m_ptr)*=a;}

            template<typename OUT, typename IN>
            OUT operator /=(IN a)
            {return (*m_ptr)/=a;}

            template<typename OUT, typename IN>
            OUT operator %=(IN q)
            {return (*m_ptr)%=a;}

            template<typename OUT, typename IN>
            OUT operator &=(IN a)
            {return (*m_ptr)&=a;}

            template<typename OUT, typename IN>
            OUT operator |=(IN a)
            {return (*m_ptr)|=a;}

            template<typename OUT, typename IN>
            OUT operator ^=(IN a)
            {return (*m_ptr)^=a;}

            template<typename OUT, typename IN>
            OUT operator <<=(IN a)
            {return (*m_ptr)<<=a;}

            template<typename OUT, typename IN>
            OUT operator >>=(IN a)
            {return (*m_ptr)>>=a;}

            //bitwise operator

            bool operator ~()
            {return ~(*m_ptr);}

            template<typename IN>
            bool operator &(IN &&a)
            {return (*m_ptr)&a;}

            template<typename IN>
            bool operator |(IN &&a)
            {return (*m_ptr)|a;}

            template<typename IN>
            bool operator ^(IN &&a)
            {return (*m_ptr)^a;}

            template<typename IN>
            bool operator <<(IN &&a)
            {return (*m_ptr)<<a;}

            //logical operator

            bool operator !()
            {return !(*m_ptr);}

            template<typename IN>
            bool operator &&(IN &&a)
            {return (*m_ptr)&&a;}

            template<typename IN>
            bool operator ||(IN &&a)
            {return (*m_ptr)||a;}

            //Comparison operator

            template<typename IN>
            bool operator ==(IN &&a)
            {return (*m_ptr)==a;}

            template<typename IN>
            bool operator !=(IN &&a)
            {return (*m_ptr)!=a;}

            template<typename IN>
            bool operator <=(IN &&a)
            {return (*m_ptr)<=a;}

            template<typename IN>
            bool operator <(IN &&a)
            {return (*m_ptr)<a;}

            template<typename IN>
            bool operator >=(IN &&a)
            {return (*m_ptr)>=a;}

            template<typename IN>
            bool operator >(IN &&a)
            {return (*m_ptr)>a;}

            //Arithmetic operator

            template<typename IN>
            auto operator /(IN &&a)
            {return (*m_ptr)/a;}

            template<typename IN>
            auto operator %(IN &&a)
            {return (*m_ptr)%a;}

            template<typename IN>
            auto operator *(IN &&a)
            {return (*m_ptr)*a;}

            template<typename IN>
            auto operator -(IN &&a)
            {return (*m_ptr)-a;}

            template<typename IN>
            auto operator +(IN &&a)
            {return (*m_ptr)+a;}

            auto operator --()
            {return --(*m_ptr);}

            auto operator --(int)
            {return (*m_ptr)--;}

            auto operator ++()
            {return ++(*m_ptr);}

            auto operator ++(int)
            {return (*m_ptr)++;}

            //ptr and member operator
            Type &operator *()
            {return *m_ptr;}

            Type *operator &()
            {return m_ptr;}

            Type &operator *() const
            {return *m_ptr;}

            Type *operator &() const
            {return m_ptr;}

            auto operator [](const size_t &n)
            {return (*m_ptr)[n];}

            Type *operator ->()
            {return m_ptr;}

            template<typename Member>
            auto operator ->*(Member member)
            {
                return getFunction(*m_ptr, member);
            }

            operator Type& ()
            {return *m_ptr;}

            void set(Type &Val)
            {m_ptr = &Val;}

            void set(Type *Val)
            {m_ptr = Val;}
        private:
            Type *m_ptr = nullptr;
        };
    }
}
#endif // SMARVAR

