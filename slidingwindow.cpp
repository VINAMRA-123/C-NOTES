// slinding windows are used mostly in subarrays
#include<iostream>
using namespace std;
int maxsumsub(int arr[],int n,int k,int x){
    int sum=0,maxi=0;
     for(int i=0; i<k; i++){
        sum += arr[i];
    }
    if (sum<=x)
    {
        maxi = sum;
    }
    for (int i = k; i < n; i++)
    {
        sum-=arr[i-k]+arr[i];
        maxi = max(sum,maxi);
    }
    if (maxi<=x)
    {
        maxi= max(maxi, sum);
    }return maxi;
}
int main(){
    int arr[] = {7, 5, 4, 6, 8, 9};
    int n = 6;
    cout<<maxsumsub(arr, 6, 3, 20);
    return 0;

}
// minimum subarray sum
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX,n = nums.size(),start = 0,sum = 0;
        for(int i = 0;i < n;i++)
        {
            sum += nums[i];
            if(sum >= target)
            {
                ans = min(ans,i - start + 1);
            }
            while(sum > target && start < i)
            {
                sum -= nums[start++];
                if(sum >= target)
                {
                    ans = min(i - start + 1,ans);
                }
            }
        }
        if(ans == INT_MAX)
        {
            return 0;
        }
        return ans;
    }
};
// form number divisible by 3
void computenumber(vector<int> arr,int k){
    pair<int,int> ans;
    int sum =0;
    for (int i = 0; i < k; i++)
    {
        sum +=1;
    }
    bool found = false;
    if(sum%3==0) {
        ans = make_pair(0,k-1);
        found = true;
    } 
    for (int j = k; j<arr.size() ; j++)
    {
        if (found)
        {
            break;
        }
        sum = sum + arr[j] - arr[j-k];
        if (sum%3==0)
        {
            ans = make_pair(j-k-1,j);
            found = true;
        }   
    }
    if (!found)
    {
        ans = make_pair(-1,0);
    }
    if (ans.first ==-1)
    {
        cout<<"no such subarray exists"<<endl;
    }
    else
    {
        for (int i = ans.first; i < ans.second; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<< endl;
    }
}
// subarray with palandronic concatenation
bool ispal(int n){
    int temp = n , number = 0;
    while (temp<n)
    {
        number = number*10 + temp%10;
        temp/=10;
        if (number==n)
        {
            return true;
        }return false;
        
    }
    
}
int findpal(vector<int> arr,int k){
    int num =0;
    for (int i = 0; i < k; i++)
    {
        m = num*10 + arr[i];
    }
    if (ispal(num))
    {
        return 0;
    }
    for (int j = k; j < arr.size(); j++)
    {
        num = (num%(int)pow(10,j-k-1))*10 +arr[i];
        if (ispal(num))
        {
            return j-k-1;
        }
        
    }
    return -1;
    
}
// perfect number int subarray
bool isperf(int n){
    int sum =1;
    for (int i = 0; i < sqrt(n); i++)
    {
        if (n%i==0)
        {
            if (i==n%i)
            {
                sum+=i;
            }
            else
            {
                sum+= i + (n/i);
            }
        }
    }
    if (sum == n && n!=1)
    {
        return true;
    }return false;
    
    
}
int maxsum(int arr[],int n,int k){
    if (n<k)
    {
        return -1;
    }
    
    int res;
    for (int  i = 0; i < k; i++)
    {
        res+= arr[i];
    }
    int sum = res;
    for (int j = k; j < n; j++)
    {
        sum += arr[j] -arr[j-k];
        res = max(sum,res);
    }return res;
    
}
int perfectnum(int arr[],int n,int k ){
    for (int i = 0; i < n; i++)
    {
        if (isperf(arr[i]))
        {
            arr[i]= 1;
        }
        else
        {
            arr[i] = 0;
        }    
    }return maxsum(arr,n,k);
}