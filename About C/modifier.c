
#include <stdio.h>

void func() {
    static int persist = 0;
    printf("static variable:%d\n", persist);
}

int main() {
    // "const"
    //
    //const int * ptr; // prevent modification of the integer value through *p
    //int const * ptr;
    //int * const ptr; // prevent ptr from pointing to different memory location.
    //const int * const ptr; // prevent any modification
    //
    // it is possible to modify a const indertly (via pointer)
    const int cx = 3;
    int *cptr = (int*)&cx; // Casting away const-ness
    *cptr = 6; // Modifying through pointer

    // "volatile"
    // "volatile" is mainly used
    //    for preventing a compiler from optimizing a variable
    //    that might change its behaviour unexpectedly.
    // Every time the compiler encounters the variable,
    //    the compiler will check the real address each time (not from the cache).
    // May have performance issue
    volatile int vx = 3;
    // it is no problem to volatile a const
    volatile const int vy;

    // "static"
    //
    // Variables defined with static are initialized once and persists until the end of the program.
    //   (variable life time)
    //
    // It can be defined in a header file. 
    //   But a private copy of the variable of the header file
    //   will be present in each source file the header is included.
    //   This is not preferred and hence it is not recommended to use static variables in a header file.
    //   (variable scope)
    //
    func();
    func();
    func();

    return 0;
}
