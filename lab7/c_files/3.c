#include <stdio.h>

#define GREETING "Hello, World!"
#define SQR(x) ((x) * (x))

int main() {
    printf("%s\n", GREETING);
    printf("Cube of 3: %d\n", CUBE(3));
    return 0;
}
