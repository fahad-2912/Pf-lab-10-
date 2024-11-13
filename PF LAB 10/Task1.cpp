#include <stdio.h>

void reverseMessage() {
    char c;
    if ((c = getchar()) != '\n') {
        reverseMessage();
        putchar(c);
    }
}

int main() {
    printf("Enter the message: ");
    reverseMessage();
    printf("\n");

    return 0;
}

