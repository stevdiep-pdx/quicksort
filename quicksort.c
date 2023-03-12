// Steven Diep
// CS450
// 06 Febuary 2023
// cc quicksort.c -lm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Implementation of the Quicksort Algorithm
void quickSort(int arr[], int low, int high) 
{
    // Declare Variables
    int pivotIndex = low;           // Track the location of the pivot, this will make recursing easier
    int pivot = arr[pivotIndex];    // Store the pivot to reduce number of accesses to it

    int left = pivotIndex + 1;      // Left pointer
    int right = high;               // Right pointer

    int temp;                       // Used for swapping

    // Base Case: If this is an array with one element or if the low and high pointers collide, return 
    // and don't recurse any further
    if(low >= high)
        return;

    /* Main Logic: Compare the left and right elements of the array to the pivot and place them in the 
       correct location. Elements less than the pivot go on the left side; Elements greater than the pivot 
       go on the right side. */
    while(left < right)
    {
        // Move the left pointer until it is pointing to an element greater than the pivot
        // Make sure the left pointer is still before the right pointer every time we move it
        while(arr[left] <= pivot && left < right)
            ++left;

        // Move the right pointer until it is pointing to an element less than the pivot
        // Make sure the right pointer is still after the left pointer every time we move it
        while(arr[right] >= pivot && left < right)
            --right;

        // Swap the two elements if there is no collision (left pointer is still before the right pointer)
        if(left < right)
        {
            // Swap
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            // Now that the elements are in the correct location, move on to the next pair of elements
            ++left;
            --right;
        }
    }

    // When there is a collision, we escape the loop and move the pivot into its correct location
    // If the left element is less than the pivot, it should go to the left side of the array
    if(arr[left] < pivot)
    {
        // Swap
        arr[low] = arr[left];
        arr[left] = pivot;

        // Track the new location of the pivot after the swap
        pivotIndex = left;
    }
    // If the left element is greater than the pivot, it should go to the right side of the array
    else 
    {
        // Swap
        arr[low] = arr[left - 1];
        arr[left - 1] = pivot;

        // Track the new location of the pivot after the swap
        pivotIndex = left - 1;
    }

    // Recurse and sort the two remaining sub-arrays before and after the pivot
    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
}

int main() {

    // Declare and get the array size from the user
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);

    // Declare and populate array
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = floor(n * drand48());
    }
    
    // Print array before sorting
    printf("\n\nBefore Sorting\n");
    for(int j = 0; j < n - 1; j++)
    {
        printf("%d, ", arr[j]);
    }
    printf("%d\n\n", arr[n - 1]);

    // Call the sorting algorithm with the array
    quickSort(arr, 0, n - 1);

    // Print array after sorting
    printf("After Sorting\n");
    for(int k = 0; k < n - 1; k++)
    {
        printf("%d, ", arr[k]);
    }
    printf("%d\n\n", arr[n - 1]);

    return 1;
}