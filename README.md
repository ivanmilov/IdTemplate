# Template for creation numeric based ids.
Usage:
Instead of 'typedef' and 'using' where you can use wrong type:
```c++
    typedef Int32 StateID;
    using RemoteID = UInt32;
    foo(StateID){...}
    ...

    RemoteID rId;
    foo(rId);       // wrong type!
```

you can use this:
```c++
    using SomeId = IdTemplate<uint32_t, struct SomeTag>;
    using SomeAnotherId = IdTemplate<int, struct SomeAnotherTag>;

    bar(SomeId){...}
    ...

    SomeAnotherId anotherId;

    bar(anotherId); // will not compile
```