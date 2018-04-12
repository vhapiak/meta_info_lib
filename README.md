# Meta Info Lib (MIL)

MIL is a library to get compile time information about class. Currently it supports:
* class fields list
* base class info

MIL use only a c++11 standard features and minimizes the usage of preprocessor. The set of MIL preprocessor macroses elegantly inject into your code, not interfering and not limiting you (almost :))

## Basic usage

### Class/Struct definition

Instead of writing:

```cpp
struct A {
    int i;
    double d;
};
```

You can write a little more code, that will define the same structure, but with some extra code (hidden from you) that doesn't affect the structure size or another structure properties (it is still POD, etc.):  

```cpp
#include <mil/mil.hpp>

struct A {
    MIL_BEGIN(A);
    MIL_DEFINE_FIELD(int, i);
    MIL_DEFINE_FIELD(double, d);
    MIL_END;
};
```

> Yes, you need to copy paste the structure name in line 4, but we check in compile time that you call `MIL_BEGIN` with right name.

### Getting class fields

Now you can use `mil::meta_info<A>()` to obtain instance of `mil::class_info<A>`. It have `fields()` method that return `std::tuple` with `mil::field_info<A, FIELD_TYPE>` for each field.

There is an example that prints name and value of each field:
```cpp
#include <mil/utils/for_each.hpp>

struct Printer {
    A& ref;

    template <typename T>
    void operator()(const mil::field_info<A, T>& field) const {
        std::cout << field.name() << '=' << field.value(ref) << std::endl;
    }
};

int main() {
    A a = {1, 2.5};
    Printer printer = {a};
    mil::utils::for_each(mil::meta_info<A>().fields(), printer);
}
```

That produce:
```
i=1
d=2.5
```

## More features

### Don't care about access modifiers

You can mark some fields as private (the same way if you don't use our library) and you still can get access to field `d` via MIL classes:
```cpp
struct A {
    MIL_BEGIN(A);
    MIL_DEFINE_FIELD(int, i);

private:
    MIL_DEFINE_FIELD(double, d);
    MIL_END;
};
```

### Templates? Not a problem

This code will work:
```cpp
template <typename T>
struct A {
    MIL_BEGIN(A<T>); // you need to specify there the full type with template parameters
    MIL_DEFINE_FIELD(T, i);
    MIL_END;
};
```

### Inheritance

You can specify the base class via MIL macros and then it will available via `parent()` method of `mil::class_info` class
```cpp
struct A {
    MIL_BEGIN(A);
    MIL_DEFINE_FIELD(int, i);
    MIL_END;
};

struct B : MIL_INHERITANCE(B, A) {
    MIL_BEGIN(B);
    MIL_DEFINE_FIELD(double, d);
    MIL_END;
};

mil::meta_info<B>().parent(); // returns an instance of mil::class_info<A>
mil::meta_info<A>().parent(); // returns an instance of mil::class_info<mil::void_t>
```

> Yes, you must copy paste the struct name again in `MIL_INHERITANCE` call, but we check in compile time that the name is correct
