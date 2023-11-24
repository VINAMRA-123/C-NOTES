// second largest element
int print2largest(int arr[], int n) {
	    // code here
	    int largest = arr[0];
	    int secl = INT_MIN;
	    for(int i=1;i<n;i++){
	        if(largest<arr[i]){
	            secl = largest;
	            largest = arr[i];
	            
	        }
	        if(secl<arr[i] && largest>arr[i]){
	            secl = arr[i];
	        }
	    }
	    if( secl == INT_MIN){
	        return -1;
	    }
	    return secl;
	}
// remove duplicate element 

#include<bits/stdc++.h>

using namespace std;
int removeDuplicates(int arr[], int n)
{
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}
int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}
// rotate element by d elements
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if(k!=0)
        {
            reverse(nums.end() - k, nums.end());
            reverse(nums.begin(), nums.end() - k);
            reverse(nums.begin(), nums.end());
        }
    }
};
// move zero to end
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(),j=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
               swap(nums[i],nums[j]);
               j++;
            }
        }
    }
};
// union of two sorted array
#include <bits/stdc++.h>

using namespace std;

vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  int i = 0, j = 0; // pointers
  vector < int > Union; // Uninon vector
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) // Case 1 and 2
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    } else // case 3
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}

int main()

{
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12}; 
  vector < int > Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is  " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}
// intersection of 2 sorted arrays
#include <bits/stdc++.h>
using namespace std;
vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  int i = 0, j = 0; // pointers
  vector < int > Union; // Uninon vector
  while (i < n && j < m) {
    if (arr1[i] < arr2[j]) // Case 1 and 2
    {
      i++;
    } 
    else if (arr1[i]>arr2[j])
    {
        j++;
    }
    
    else // case 3
    {
        Union.push_back(arr2[j]);
        j++;
        i++;
    }
  }
  return Union;
}
int main()
{
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12}; 
  vector < int > Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is  " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}
// find missing number 
/*for this we can use xor of number from 1 to n with number in array or 
sum of n elements - sum of number in an array*/

// longest subarray with sum k
#include <bits/stdc++.h>
using namespace std;
int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.
    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }
    return maxLen;
}
int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
// two sum problem
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        sort(nums.begin(),nums.end());
        vector<int>ans;
        while(i<j){
            if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else{
                j--;
            }
        }
        if(ans.empty()){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};
// sort 0,1 and 2 in array
// optimised from dutch national flag algo
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int high= nums.size()-1;
        int mid=0;
        int low =0;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        // return nums
    }
};
// majority element using moore's voting algo
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        // int ele;
        set<int>ans;
        int cnt1 =0;
        int cnt2 =0;
        int ele1=0 ,ele2=0;
        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i]!=ele2){
                ele1 = nums[i];
                cnt1=1;
            }
            else if(cnt2==0 && nums[i]!=ele1){
                ele2 =nums[i];
                cnt2 =1;
            }
            else if (ele1 == nums[i]) {
                cnt1++;
            } 
            else if (ele2 == nums[i]) {
                cnt2++;
            } 
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2 =0;
        int threshold = n/3;
        for(int i=0;i<n;i++){
            if(ele1 == nums[i]){
                cnt1++;
            }
            if(ele2==nums[i]){
                cnt2++;
            }
        }
        if(cnt1>threshold){
            ans.insert(ele1);
        }
        if(cnt2>threshold){
            ans.insert(ele2);
        }
        vector<int>res;
        // ans.push_back(ele);
        for(auto x:ans){
            res.push_back(x);
        }
        return res;
    }
};
// next permutation - doubt

// leader in array
vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    int n =a.size();
    vector<int>res;
    int maxi = INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(a[i]>maxi){
            res.push_back(a[i]);
            maxi = a[i];
        }
    }
    return res;
}
// longest successive element
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    unordered_set<int>st;
    for(int i=0;i<n;i++){
        st.insert(a[i]);
    }
    int longest = 0;
    for(auto x:st){
        if(st.find(x-1)==st.end()){
            int count =1;
            int y = x;
            while(st.find(y+1)!=st.end()){
                y++;
                count++;
            }
            longest = max(longest,count);
        }
    }
    return longest;
}
// continous subarray sum
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        mp[0] = 1;
        int cnt =0;
        int presum =0;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            int remove = presum-k;
            cnt+= mp[remove];
            mp[presum]+=1;
        }
        return cnt;
    }
};
// pascal triangle
#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}

int main()
{
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: "
            << element << "n";
    return 0;
}
// optimal approach
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> triplet(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;
        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
// 4 sum problem
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>st;
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            for(int j= i+1;j<n-1;j++){
                set<long long>hash;
                for(int k =j+1;k<n;k++){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth = target-(sum);
                    if(hash.find(fourth)!=hash.end()){
                        vector<int>temp = {nums[i],nums[j],nums[k],(int)fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);  
                    }
                    hash.insert(nums[k]);
                }
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
    }
};
// optimal solution
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // Write your code here
    int n=  nums.size();
    set<vector<int>>st;
    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++){
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for(int j=i+1;j<n;j++){
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int k=j+1;
            int l = n-1;
            while(k<l){
                int sum = nums[i]+nums[j]+nums[k]+nums[l];
                if(sum==target){
                    vector<int>temp = {nums[i],nums[j],nums[k],nums[l]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                    l--;
                    k++;
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum>target){
                    l--;
                }
                else{
                    k++;
                }
            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}
// tricky  - count-the-number-of-subarrays-with-given-xor-k
#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int xr = 0;
    map<int, int> mpp; //declaring the map.
    mpp[xr]++; //setting the value of 0.
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        // prefix XOR till index i:
        xr = xr ^ a[i];
        //By formula: x = xr^k:
        int x = xr ^ k;
        // add the occurrence of xr^k
        // to the count:
        cnt += mpp[x];
        // Insert the prefix xor till index i
        // into the map:
        mpp[xr]++;
    }
    return cnt;
}
int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}
// merge overlapping intervals
#include<vector>
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	// Write your code here.
	vector<vector<int>>ans;
	sort(arr.begin(),arr.end());
	int n = arr.size();
	for(int i=0;i<n;i++){
		if(ans.empty() || ans.back()[1]<arr[i][0]){
			ans.push_back(arr[i]);
		}
		else{
			ans.back()[1] = max(ans.back()[1], arr[i][1]);
		}
	}
	return ans;
}
// maximum product subarray
#include<bits/stdc++.h>
using namespace std;
int maxProductSubArray(vector<int>& nums) {
    int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    
    for(int i=1;i<nums.size();i++) {
        int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1 = temp;
        
        result = max(result,prod1);
    }
    
    return result;
}
int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}
