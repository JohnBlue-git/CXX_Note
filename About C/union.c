
#include <stdio.h>
#include <string.h>

struct data {
    char a;
    char b;
    char c;
    char d;
};

// Define a union with different types
union Data {
    int a;
    struct data b;
};

int main() {
    union Data data;

    // Example using integer
    data.a = 0;
    data.b.b = 1;//  1,0000,0000
                 // 256
    
    printf("%d", data.a);
    

    return 0;
}
