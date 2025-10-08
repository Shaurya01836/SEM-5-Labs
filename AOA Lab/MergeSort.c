#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 50000

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    int i, j, k;

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[MAX_SIZE], i, n;
    clock_t start, end;
    
    printf("Merge Sort Example with Random Numbers\n");
    printf("Enter number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid number of elements!\n");
        return 1;
    }

    srand(time(NULL));  // Seed for random number generation

    // Generate random numbers
    printf("Generated Random Numbers: ");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  // Random numbers between 0 and 999
        printf("%d ", arr[i]);
    }
    printf("\n");

    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();

    // Print sorted data
    printf("Sorted data: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nTotal Time = %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}