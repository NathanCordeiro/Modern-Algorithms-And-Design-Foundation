//Binary search implemented in c++ using iterative method
//Nathan Cordeiro 22co09
#include<iostream>
using namespace std;

//function to sort a given array using simple compare swap approach
void insertionsort(int a[],int n)
{
int i, j, temp;
for (i = 1; i < n; i++)
{
temp = a[i];
j = i - 1;

while(j>=0 && temp <= a[j])
{
a[j+1] = a[j];
j = j-1;
}
a[j+1] = temp;
}
cout<<" Elements are sorted";
}

//function to search an element using divide and conquer 2 pointer approach iteratively
int binarysearch(int a[],int n)
{
int s,low,high,mid;
cout<<"\nEnter the search element:";
cin>>s;
low = 0; //low to act as lower pointer
high = n - 1; //high to act as upper pointer
mid = (low+high)/2; //mid to act as dividing range

if(low > high)
cout<<"\nElement not found! Array out of bound";
while (low <= high)
{
if(a[mid] < s)
low = mid + 1;
if(a[mid] > s)
high = mid - 1;
mid = (low + high)/2;
if (a[mid] == s)
{
cout<<"\nElement "<<s<<" found at location "<<mid+1;
break;
}
}
if(a[mid]!=s)
cout<<" Elemnet not found";

}

int main()
{
int a[20],n;

cout<<"Eneter the number of elements:";
cin>>n;
cout<<"Enter array elements"<<"\n";
for(int i=0;i<n;i++)
cin>>a[i]; //take in values of elements
insertionsort( a, n); //function call to sort elements using insertionsort
cout<<"\n";
for(int i=0;i<n;i++)
cout<<" "<<a[i]<<" "; //display sorted array
binarysearch(a,n); //function call to binary search
return 0;
}
