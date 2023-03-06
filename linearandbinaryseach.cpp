#include<stdio.h>
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
