

#define MAX_ITEMS 5 // runs before compiler
// macro --> static IN LINE
//  it defines a constant value MAX_ITEMS with a value of 5. This means that anywhere in the code where MAX_ITEMS is used, it will be replaced with the value 5 by the preprocessor before the code is compiled.

static inline int square(int x)
{
    return x * x;
}