// int main() est. a stack in memory; a (function) scope; blocks of memory

// heap - global variables; can control memory in heap

// new func = new scope = new memory location
// creates a copy of the var to pass into func; og var still exists in og location

// using pointers will actually manipualte the value:
void double_x(int *x)
{
    *x = *x * 2;
}

int main()
{
    int x = 7;    // 1004
    double_x(&x); // 1004
    return 0;
}
// will manipulate it directly at its source

// array are pointers - passing array to a function passes address of first element of array - so arrays manipulate og array