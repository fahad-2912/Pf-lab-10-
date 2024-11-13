#include <stdio.h>

void printArray(int arr[], int n) {
    if (n == 0) {
        return;
    }
    printArray(arr, n - 1);
    printf("%d ", arr[n - 1]);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    return 0;
}

