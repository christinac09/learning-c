#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

// avoid global variables

#define COOL_NUMBER 7
// preprocessor directive that defines a constant value, can be used throughout the program; this is replaced by the preprocessor before compilation, so it doesn't take up memory space
int show_data_types()
{
    int x, y, z;
    x = 5;
    char name[20];
    strcpy(name, "Steve");
    z = COOL_NUMBER * x;
    printf("x is %d, string is %s z is %d \n", x, name, z);
    // %d is for integers, %s is for strings, %f is for floats, %c is for characters
    // \n needed for new line or there'll be error
    return 0; // return 0 to indicate success; all functions must return a value
}

int main()
{
    show_data_types();
    return 0;
}

// strings are actually arrays of characters
// char name[16] = "Hello World";
// char *x = name;
// char *y = &name[0]; <-- gives same as x
// char *z = &name[1];
// printf("X = %p, Y = %p, Z = %p\n", x, y, z);
// shows where the data is saved in memory, uses a pointer
// very last spot is always /0

// running the code in terminal (after installing gcc compiler):
//  wsl to open wsl ubuntu terminal
//  cd into folder
//  gcc -o app app.c
//  ./app