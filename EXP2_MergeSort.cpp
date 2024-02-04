//Implementation of mergesort in c++
#include<iostream>
using namespace std;

// Function to merge two halves of an array
void merge(int Arr[], int start, int mid, int end)
{
    int temp[end - start + 1];                  //Temporary array to store merged result
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end)
    {
        if (Arr[i] <= Arr[j])                   //Merge elements in both halves in sorted order
        {
         temp[k] = Arr[i];
         k += 1;
         i += 1;
        }
        else
        {
         temp[k] = Arr[j];
         k += 1;
         j += 1;
        }
    }

    while (i <= mid)                       //Copy remaining elements from first half
    {
     temp[k] = Arr[i];
     k += 1;
     i += 1;
    }

    while (j <= end)                       //Copy remaining elements from second half
    {
     temp[k] = Arr[j];
     k += 1;
     j += 1;
    }

for (i = start; i <= end; i += 1)          //Copy merged elements back to original array
{
Arr[i] = temp[i - start];
}

}

// Function to perform Merge Sort
void mergeSort(int Arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;        //calculate the middle index
        mergeSort(Arr, start, mid);         //recursively sort the first half
        mergeSort(Arr, mid + 1, end);       //recursively sort the second half
        merge(Arr, start, mid, end);        //Function call to merge sorted halves
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

    mergeSort(Arr, 0, n - 1);           //Function call to merge sort
    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++)
    {
     cout << Arr[i] << " ";
    }

    return 0;
}
