//Slip14-1

#include <stdio.h>
#include <time.h>

int main()
{
    int n, i, j, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input elements
    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    clock_t start, end;

    // Start time
    start = clock();

    // Insertion Sort
    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    // End time
    end = clock();

    // Print sorted array
    printf("\nSorted Elements:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Calculate time taken
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n\nTime required for sorting = %f seconds\n", time_taken);

    // Time Complexity
    printf("Time Complexity = O(n^2)\n");

    return 0;
}


/*Enter number of elements: 5

Enter elements:
9 5 1 4 3

Sorted Elements:
1 3 4 5 9

Time required for sorting = 0.000001 seconds

Time Complexity = O(n^2)   */