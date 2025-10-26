#include <stdio.h>
int binarySearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int comparisons = 0;
    while (low <= high) {
        comparisons++;
        int mid = low + (high - low) / 2; 
        if (arr[mid] == key) {
            printf("Iterative: Found after %d comparisons\n", comparisons);
            return mid; 
        }
        else if (arr[mid] < key)
            low = mid + 1; 
            high = mid - 1; 
    printf("Iterative: Not found after %d comparisons\n", comparisons);
    return -1; 
}
int binarySearchRecursive(int arr[], int low, int high, int key) {
    static int comparisons = 0;
    if (low <= high) {
        comparisons++;
        int mid = low + (high - low) / 2; 
        if (arr[mid] == key) {
            printf("Recursive: Found after %d comparisons\n", comparisons);
            int result = mid;
            comparisons = 0; 
            return result; 
        }
        else if (arr[mid] < key)
            return binarySearchRecursive(arr, mid + 1, high, key); // Search right
        else
            return binarySearchRecursive(arr, low, mid - 1, key);  // Search left
    }
    printf("Recursive: Not found after %d comparisons\n", comparisons);
    comparisons = 0;
    return -1; 
}
int main() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid number of elements!\n");
        return 1;
    }
    int arr[n];
    printf("Enter %d elements in sorted order: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) {
            printf("Warning: Array is not sorted! Binary search may not work correctly.\n");
            break;
        }
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    printf("\n--- Binary Search Results ---\n");
    int resultIter = binarySearchIterative(arr, n, key);
    if (resultIter != -1)
        printf("Element found at index %d (Iterative)\n", resultIter);
    else
        printf("Element not found (Iterative)\n");
    printf("\n");
    int resultRec = binarySearchRecursive(arr, 0, n - 1, key);
    if (resultRec != -1)
        printf("Element found at index %d (Recursive)\n", resultRec);
    else
        printf("Element not found (Recursive)\n");
    return 0;
}


