#include<iostream>
using namespace std;

// Function to swap two elements
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;

}

// Function to partition the array and return the pivot index
int partition(int Arr[], int LB, int UB)
{
    int pivot = Arr[LB];        // Choosing the first element as the pivot
    int start = LB;             // Initialize the start index
    int end = UB;               // Initialize the end index

    while (start < end)
    {
        // Move 'start' to the right until an element greater than pivot is found
        while (Arr[start] <= pivot && start < end)
        {
            start++;
        }

        // Move 'end' to the left until an element less than or equal to pivot is found
        while (Arr[end] > pivot)
        {
            end--;
        }

        if (start < end)
        {
            swap(Arr[start], Arr[end]);             // Swap the elements at 'start' and 'end'
        }
    }

    swap(Arr[LB], Arr[end]);                        // Swap the pivot element with the element at 'end'
    return end;                                     // Return the pivot index
}

// Function to perform Quick Sort
void quickSort(int Arr[], int LB, int UB)
{
    if (LB < UB)
    {
        int loc = partition(Arr, LB, UB);       // Partition the array and get the pivot index
        quickSort(Arr, LB, loc - 1);            // Recursively sort the left subarray
        quickSort(Arr, loc + 1, UB);            // Recursively sort the right subarray
    }
}

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int Arr[n];

    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }

    quickSort(Arr, 0, n - 1);               // Call Quick Sort function to sort the array

    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " ";
    }

    return 0;
}
