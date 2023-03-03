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
