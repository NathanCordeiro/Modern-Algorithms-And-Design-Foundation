//Binary search implemented in c++ using recursive method
//Nathan Cordeiro 22co09
#include<iostream>
using namespace std;

//function to sort a given array using simple compare swap approach
void bubblesort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
     for (j = 0; j < n - i - 1; j++)
     {
        if (a[j] > a[j + 1])                                //compare adjacent places if j>j+1 swap
        {
         int temp = a[j];
         a[j] = a[j + 1];
         a[j + 1] = temp;
        }
     }
    }
cout<<"Elemts sorted sucessfullly";
}

//function to search an element using divide and conquer 2 pointer approach recursively
void BinarySearch(int a[],int num,int first,int last)
{
int mid;
    if(first > last)
    {
     cout<<"element not existing";
    }
    else
    {
        mid = (first + last)/2;
        if(a[mid]==num)
        {
        cout<<"Element present at location "<<mid+1;

        }
        else if(a[mid] > num)
        {
        BinarySearch(a, num, first, mid-1);                     //recursive call
        }
        else
        {
        BinarySearch(a, num, mid+1, last);                      //recursive call
        }
    }
}

int main()
{
int a[20],n,low,high,num;

cout<<"Enter the number of elements:";
cin>>n;
cout<<"Enter array elements"<<"\n";
for(int i=0;i<n;i++)
cin>>a[i];                              //take in values of elements
bubblesort( a, n);                      //function call to sort elements using bubblesort
cout<<"\n";
for(int i=0;i<n;i++)
cout<<" "<<a[i]<<" ";                   //display the sorted array
low=0;                                  //low to act as lower pointer
high=n-1;                               //high to act as upper pointer
cout<<"\nEnter the value to search:";
cin>>num;                               //enter search element
BinarySearch(a,num,low,high);           //function call to binary search
return 0;
}
