#include <stdio.h>

int sumofDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumofDigits(n / 10);
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Sum of digits: %d\n", sumofDigits(number));
    return 0;
}

