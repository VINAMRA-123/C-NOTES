#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int linearsearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
        return -1;
    }
}
int main(){
    int n,arr[n];
    cin>>n;
    int key;
    cin>>key;
    
for(int i =0;i<n;i++){
    cin>>arr[i];
}
    cout<<linearsearch(arr,n,key)<<endl;
    return 0;
  
    
}
// binarysearch
#include<stdio.h>
#include<iostream>
using namespace std;
int binarysearch(int arr[],int n,int key){
    int beg = 0;
    int end = n;
    int mid = (beg+end)/2;
    while(end>=beg){
    
        if (arr[mid] == key){
            return mid;
        }
        else if(arr[mid]<key){
            beg = mid+1;
        }
        else {
            end = mid-1;
        }
        mid = (beg+end)/2;
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
cout<<binarysearch(arr,n,key)<<endl;
    return 0;
}
// OUTPUT
// 5
// 23
// 34
// 45
// 56
// 67
// 34
// 1
// QUESTIONS ON BINARY SEARCH
"Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.
Example 1:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
"
"approach-

    Number of missing numbers can be calculated by comparing arr[i] and i.
    If arr[i] = 5 and i = 3, arr = [1,2,3,5], we can say that arr[i] - i - 1 = 1 numbers are missing.
    After finding the index where arr[i] - i > k, add k to i (i + k) to find the missing number.
    For the abovementioned example if k = 1, arr[i] - i > k at i = 3.
    5 - 3 > 1. Answer is i + k = 3 + 1 = 4, thus 4 is missing
"
class Solution {
public:
    
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] - mid - 1 < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left + k;
 

    }
};
// problem -1 place elements to maximise minimum distance 
bool isfeasible(int mid,int arr[],int n,int k){
    int pos = arr[0],elements =1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]-pos>=mid)
        {
            elements++;
            if (elements==k)
            {
                return true;
            }   
        }
    }return false;
}
int largestmindis(int arr[],int n,int k){
    sort(arr,arr+n);
    int res = -1;
    int first ,mid,last;
    first = 1;last = arr[n-1];
    while (first<last)
    {
        mid = (first+last)/2;
        if(isfeasible(mid,arr,n,k)){
            res = max(res,mid);
            first = mid+1;
        }
        else
        {
            last = mid;
        }
    }return res;   
}
// problem -2 page allocation
bool ispossible(int arr[],int n,int m,int min){
    int studentreq =1,sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>min)
        {
            return false;
        }
        if (sum+arr[i]>min)
        {
            studentreq++;
            sum = arr[i];
            if (studentreq>m)
            {
                return false;
            }
            
        }
        else
        {
            sum +=arr[i];
        }
    }return true;
}
int pagealloc(int arr[],int n,int m){
    int sum=0;
    if(n<m){
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    int start =0,end =sum,ans= INT_MAX;
    while (start<=end)
    {
        int mid = start+(end-start);
        if(ispossible(arr,n,m,mid)){
            ans = min(ans,mid);
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    return ans;
    
}
// problem -3 painters partition

int findfeasible(int arr[],int n,int limit){
    int sum =0,painters =1;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
        if (sum>limit)
        {
            sum = arr[i];
            painters++;
        }
    }
    return painters;
    
}
int painterpart(int arr[],int n,int m){
    int totallen = 0,k=0;
    if (n<m)
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        k = max(k,arr[i]);
        totallen+=arr[i];
    }
    int low = k,high =totallen;
    while (low<high)
    {
        int mid = (low+high)/2;
        int painters = findfeasible(arr,n,mid);
        if(painters<=m){
            high = mid;
        }
        else
        {
            low = mid+1;
        }        
    }
}
// problem -4 search element in sorted and rotated array
int findpivot(int arr[],int key,int left,int right){
    if (left>right)
    {
        return -1;
    }
    
    int mid = (left+right)/2;
    if (arr[mid]==key)
    {
        return mid;
    }
    if(arr[mid]>=arr[left])
    {
        if (key>=arr[left] && key<=arr[mid])
        {
            return findpivot(arr, key, left,mid-1);
        }return findpivot( arr,int key,mid+1, right);        
    }
    
    if (key>=arr[mid] && key<=arr[right])
    {
        return findpivot(arr, key, mid+1,right);
    }return findpivot( arr,int key,left, mid-1);            
    
}
// find the peak element of array
int peakele(int arr[],int low,int high,int n){
    int start = 0,end = n;
    int mid = (start+(end-start))/2;
   
    if ((mid==0 ||arr[mid]>arr[mid-1]) && (mid == n-1 || arr[mid]>arrr[mid+1]))
    {
        return mid;
    }
    else if(arr[mid]<arr[mid-1] && mid>0)
    {
        return peakele(arr,low,mid-1,n);
    }    
    else{
        return peakele(arr,mid+1,high,n);
    }
}
