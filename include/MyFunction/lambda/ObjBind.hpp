#pragma once

namespace binaire
{
    template<typename Obj, typename Out, typename... Arg>
    auto lambdaBind(Obj &obj, Out(Obj::*Member)(Arg...)) noexcept
    {
        return [&obj, &Member](Arg... arg) mutable -> Out {
            return (obj.*Member)(arg...);
        };
    }

    template<typename Obj, typename Out, typename... Arg>
    auto lambdaBind(Obj &obj, Out(Obj::*Member)(Arg...) const) noexcept
    {
        return [&obj, &Member](Arg... arg) -> Out {
            return (obj.*Member)(arg...);
        };
    }
}
