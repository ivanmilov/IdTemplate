/**
Template for creation numeric based ids.
Usage:
Instead of 'typedef' and 'using' where you can use wrong type:
    typedef Int32 StateID;
    using RemoteID = UInt32;

    foo(StateID){...}
    ...

    RemoteID rId;
    foo(rId);       // wrong!

you can use this:
    using SomeId = IdTemplate<uint32_t, struct SomeTag>;
    using SomeAnotherId = IdTemplate<int, struct SomeAnotherTag>;

    bar(SomeId){...}
    ...

    SomeAnotherId anotherId;

    bar(anotherId); // will not compile
*/

#pragma once
#include <type_traits>

template <typename T, typename Tag, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class IdTemplate
{
public:
    IdTemplate(): value(0){}
    IdTemplate(T value): value(value){}

    inline operator T() const
    {
        return value;
    }

    inline bool operator<(const IdTemplate& other)
    {
        return value < other.value;
    }

    inline bool operator==(const IdTemplate& other)
    {
        return value == other.value;
    }

    inline bool operator!=(const IdTemplate& other) const
    {
        return value != other.value;
    }

    IdTemplate operator++(int)
    {
        value++;
        return *this;
    }

    // TODO: feel free to implement other operators :)

private:
    T value;
};
