#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int number[], int first, int last) {
    int i, j, pivot, temp;
    if (first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while (number[i] <= number[pivot] && i < last) i++;
            while (number[j] > number[pivot]) j--;
            if (i < j) {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort(number, first, j - 1);
        quicksort(number, j + 1, last);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number! Enter a valid number.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    srand(time(NULL));  // Seed for random numbers

    // Generate random numbers
    printf("Generated Random Numbers: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Random numbers between 0-999
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sorting and timing
    clock_t start = clock();
    quicksort(arr, 0, n - 1);
    clock_t end = clock();

    // Print sorted numbers
    printf("Sorted Numbers: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print time taken
    printf("Time taken: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);
    return 0;
}