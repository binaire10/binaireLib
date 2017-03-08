#pragma once
#include <utility>
#include <string>

namespace binaire
{
    typedef std::pair<std::string::const_iterator, std::string::const_iterator> StringRef;

    class Parser {
    public:
        virtual ~Parser() = default;
        virtual bool next() noexcept = 0;
        virtual const StringRef &getOutput() const noexcept = 0;
        virtual void setOutput(const StringRef &interval) noexcept = 0;
        virtual void setInput(const StringRef &src) noexcept = 0;
        virtual StringRef getInput() const noexcept = 0;
        virtual std::string getResult() const noexcept = 0;
    };
}
