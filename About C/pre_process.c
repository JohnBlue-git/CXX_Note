

/*
What is preprocessor?

The preprocessor is a phase of the C and C++ compilation process that performs various text manipulations on the source code before it is passed to the compiler. 

It operates on the source code file before actual compilation begins and handles directives that start with a # symbol.

# Macro Expansion

# Header File Inclusion

# Conditional Compilation

such as #if, #ifdef, #ifndef, #elif, and #endif

which can help decide the program section based on conditions (like machine Endian Little or Big, ...)

# Line Control

...

3. Pragma Directives:

...

4. Stringification and Token Pasting:

...

*/


/*

#include "" and #include <> ?

#include ""

   the preprocessor just searches for the file in the current directory as where the source file is    present and if not found, it proceeds to search in the standard directories specified by the compiler.

#include <>

   the preprocessor looks for the files in the compiler designated directories where the standard library files usually reside.

*/


#include <stdio.h>





// Macro VS Inline
//   # all aim to reduce the overhead caused by the function call
//   # just insert and replace the code with the Macro or Inline 
//   # but it is possible to increase code size if function code is larger
//                                              or being called too frequent
//                                              (too many duplicate code @@ )
//     (possible to cost more than the overhead of a function call)

// Macro functions are expanded by the preprocessor at the compile time.

// Inline functions are expanded by the compiler.
// Parameter Checking: yes
// Easy to debug: yes
// but compiler can also decide not to inline the function @@
// cannot force compiler to must inline

// Macro definition for calculating the square of a number
#define SQUARE(x) ((x) * (x))
// 多用() 避免x其實很複雜


// Inline function to calculate the cube of a number
inline int cube(int x) {
    return x * x * x;
}

int main() {
    int num = 5;

    // Using the SQUARE macro to calculate the square of num
    printf("Square of %d is: %d\n", num, SQUARE(num));

    // Using the inline function cube to calculate the cube of num
    printf("Cube of %d is: %d\n", num, cube(num));

    return 0;
}
