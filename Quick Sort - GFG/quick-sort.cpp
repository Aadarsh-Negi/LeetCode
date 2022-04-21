// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

 // } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low>high) return;
        // if(low<high){
            int mid = partition(arr,low,high);
            quickSort(arr,low,mid-1);
            quickSort(arr,mid+1,high);
        // }
            
    }
    
    public:
    int partition (int ar[], int low, int high)
    {
        int last = low;
        int pivot = ar[high];
        int j=low;
        for(;j<high;j++){
            if(ar[j]<pivot){
                swap(ar[last],ar[j]);
                last++;
            }
        }
        swap(ar[last],ar[high]);
        return last;
       // Your code here
    }
};


// { Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends