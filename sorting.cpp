// // FOR SELECTION SORT
// #include <iostream>

// using namespace std;
// int selectionsort(int arr[],int n){
    
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i = 0;i<n;i++){
//         cin>>arr[i];
//     }
//     for(int i = 0;i<(n-1);i++){
//         int min = i;
//         for(int j = i+1;j<n;j++){
//             if(arr[j]<arr[i]){
//                 int temp = arr[j];
//                 arr[j] = arr[i];
//                 arr[i] = temp;
//             }
//         }
//     }
//     for(int i = 0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }cout<<endl;

//     return 0;
// }
// OUTPUT
// 5
// 23
// 25
// 45
// 12
// 20
// 12 20 23 25 45 

// FOR BUBBLE SORT
#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int counter = 0;
    while (counter<n)
    {
        for(int i = 0;i<n-counter;i++){
            if(arr[i]>arr[i+1]){    
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }counter++;
    }

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    return 0;

}
// OUTPUT 

// SELECTION SORT
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    for(int l = 2; l<n;l++){
        int temp = arr[l];
        int k,j;
        k = j-1;
        while(k>=0 && arr[k]>arr[l]){
            arr[k+1] = arr[k];
            k = k-1;
        }
        arr[l+1] = temp;
        
    }
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    return 0;

}
// MERGE SORT
void merge(int arr[],int l,int mid,int r){
    int n1 = mid-l-1;
    int n2 = r-mid;
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i]= arr[l+1];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid+1+i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i<n1 && j<n2){
        if (a[i]<b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    
    
    
}
void mergesort(int arr[], int l,int r){
    
    if (l<r)
    {
        int mid = (l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    int l = arr[0];
    int r = arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    mergesort(arr,l,r);
    

}
// QUICK SORT
#include<iostream>
using namespace std;
void swap(int arr[], int i, int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i=l-1;
    for (int j = l; j < r; j++)
    {
        if (arr[j]<pivot)
        {
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);
    return i+1;
}
void quicksort(int arr[], int l, int r)
{
    if (l<r)
    {
        int pi=partition(arr,l,r);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);
    }
}
int main() 
{
    int arr[5]={5,4,6,2,1};
    quicksort(arr,0,4);
    for(int i=0; i<5; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
return 0;
}
// COUNT SORT
/*The O(N) sort.
Note: Only limited to small positive integers only.
Input: Given an array.
Output: print the sorted array.
Time Complexity: O(N)
Space Complexity: O(max(Arr))*/
void countsort(int arr[],int n){
    int k = arr[0];
    for (int i = 0; i < n; i++)
    {
        k = max(k,arr[i]);
    }
    int count[k]  ={0};
    for (int i = 0; i <=n; i++)
    {
        count[arr[i]]++;
    }
    for (int i = 0; i < k; i++)
    {
        count[i] = count[i-1];
    }
    int output[n];
    for (int i = n-1; i>=0; i++)
    {
        output[--count[i]] = arr[i]; 
    }
    for (int i = 0; i < n; i++)
    {
        output[i] = arr[i];
    }
    
}
// DNF SORT
// complexity  = O(N)
void swap(int arr[], int i, int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void dnfsort(int arr[],int n){
    int l = 0;
    int mid  = 0;
    int h = n-1;
    while (l<=h)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] ==0)
            {
                swap(arr,l,mid);
                l++;
                mid++;
            }
            else if (arr[i]==1)
            {
                mid++;
            }
            else if (arr[i]==2)
            {
                swap(arr,h,mid);
                h--;
                mid++;
            }
        }
    }  
}
// WAVE SORT 
/*Problem
Given an array, transform the array such that
arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= .....
Input: Given an array.
Output: print the sorted array.
Time Complexity: O(N), single pass
Space Complexity: O(1)*/
void wavesort(int arr[],int n){
    for (int i = 0; i < n; i+=2)
    {
        if (arr[i]>arr[i-1])
        {
            swap(arr,i,i-1);
        }
        if (arr[i]>arr[i+1])
        {
            swap(arr,i,i+1);
        }
        
    }
    
}
// question on merge sort
long long merging(int arr[],int l,int mid, int r){
    long long inv = 0;
    int n1 = mid-l+1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];
    for(int i = 0;i<n1;i++){
        a[i] = arr[l+i];
        }

    for(int i = 0;i<n2;i++){
        b[i] = arr[mid+i+1];
    }
    int i = 0,j = 0, k = l;
    while(i<n1 and j<n2){
        if(a[i] <= b[j]){
            arr[k] = a[i];
            k++;i++;
            }
        else{
            arr[k] = b[j];
            inv += n1 - i;
            k++;j++;
        }
    }
    while(i<n1){
        arr[k] = a[i];
        k++;i++;
    }
    while(j<n2){
        arr[k] = b[j];
        k++;j++;
    }
    return inv;
}

long long mergeSort(int arr[],int l,int r){
    long long inv = 0;
    if(l < r){
    int mid = (l+r)/2;
    inv += mergeSort(arr,l,mid);
    inv += mergeSort(arr,mid+1,r);
    inv += merging(arr,mid,l,r);
    }
    return inv;
}

int32_t main(){
    int n;cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
}