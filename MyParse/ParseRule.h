#pragma once

#include <utility>
#include <string>
namespace binaire
{
    class ParseRule
    {
    public:

        /**
     * @param begin
     * @param end
     */
        virtual ~ParseRule() = default;
        virtual std::string::const_iterator next(std::string::const_iterator begin, const std::string::const_iterator &end) = undefined;
        virtual std::string::const_iterator nextEnd(std::string::const_iterator begin, const std::string::const_iterator &end) = undefined;
        virtual size_t beginSize() const noexcept = undefined;/*
    virtual bool isWaiting() const noexcept = undefined;
    virtual void *getContext() const noexcept = undefined;
    virtual void setContext(void *) const noexcept = undefined;*/
        //                                           FIRST                         <=                                  SECOND
        static bool existAt(std::string::const_iterator strBegin, const std::string::const_iterator &strEnd, std::string::const_iterator beginValue, const std::string::const_iterator &endValue) noexcept
        {
            while(strBegin != strEnd && beginValue != endValue)
            {
                if(*strBegin != *beginValue)
                    return false;
                ++strBegin;
                ++beginValue;
            }

            return beginValue == endValue;
        }
    };
}
