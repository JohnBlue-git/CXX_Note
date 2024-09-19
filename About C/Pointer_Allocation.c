
#include <stdio.h>
#include <stdlib.h>

// Function to initialize a 2D array with random values (pass by pointer)
void initializeArray(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100; // Generate random numbers between 0 and 99
        }
    }
}

// Function to print a 2D array (pass by pointer)
void printArray(int **arr, int rows, int cols) {
    printf("Array Elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to double each element of a 2D array (pass by pointer)
void doubleArray(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] *= 2;
        }
    }
}

int main() {
    int rows = 3;
    int cols = 3;
    int **arr1, **arr2;

    // Dynamic memory allocation using malloc for the rows
    arr1 = (int **)malloc(rows * sizeof(int *));
    if (arr1 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        // Dynamic memory allocation using malloc for each row
        arr1[i] = (int *)malloc(cols * sizeof(int));
        if (arr1[i] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
    }
    // Initialize arrays with random values
    initializeArray(arr1, rows, cols);

    // Dynamic memory allocation using calloc for the rows
    // default as 0
    arr2 = (int **)calloc(rows, sizeof(int *));
    if (arr2 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        // Dynamic memory allocation using calloc for each row
        arr2[i] = (int *)calloc(cols, sizeof(int));
        if (arr2[i] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
    }

    // Print the original arrays
    printf("Original Arrays:\n");
    printArray(arr1, rows, cols);
    printArray(arr2, rows, cols);

    // Double each element of the arrays using call by value and call by pointer
    doubleArray(arr1, rows, cols);
    doubleArray(arr2, rows, cols);

    // Print the modified arrays
    printf("\nModified Arrays:\n");
    printArray(arr1, rows, cols);
    printArray(arr2, rows, cols);

    // Free dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(arr1[i]);
        free(arr2[i]);
    }
    free(arr1);
    free(arr2);

    return 0;
}
