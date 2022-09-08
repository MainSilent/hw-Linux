#include <stdio.h>

int main() {
    // Clear screen
    printf("\e[1;1H\e[2J");

    printf("Hello, world!\n");

    // The kernel expects the initial program to run forever, or else it throws a panic error.
    while(1){}
}