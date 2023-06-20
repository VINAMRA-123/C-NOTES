#include<bits.stdc++>
using namespace std;

signed main(){
    int arr =[1,3,4,6,2,4,1]
    map<int,int>freq;
    for (int i = 0; i < arr.size(); i++)
    {
        freq[arr[i]]++;
    }
    map<int,int> :: iterator it;
    for  (it = freq.begin(); i !=freq.end(); it++)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
}
// vertical order print
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val){
        int data = val;
        left = NULL;
        right = NULL;
    }
};

void verticalprint(Node* root,int hdis,map<int,vector<int>>m){
    if (root == NULL)
    {
        return;
    }

    m[hdis].push_back(root->data);
    verticalprint(root->left,hdis-1,m);
    verticalprint(root->right,hdis+1,m);
    
}
signed main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(6);
    root->left->right = new Node(8);
    root->right->right= new Node(9);
    map<int,vector<int>>m;
    int hdis =0;

    verticalprint(root,hdis,m);
    map<int,vector<int>> :: iterator it;
    for ( it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i <(it->second).size(); i++)
        {
            cout<<(it->second)[i]<<" ";
        }
        cout<<endl;
        
    }
     
}
//Number of Subarrays with Sum Zero 
// conceptutal doubt
signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    map<int,int>cnt;
    int prefixsum =0;
    for (int i = 0; i < n; i++)
    {
        prefixsum +=a[i];
        cnt[prefixsum]++;
    }
    int ans =0;
    map<int,int>  :: iterator it;
    for ( it = cnt.begin(); it !=cnt.end(); it++)
    {
        int c = it->second;
        ans += (c-1)*c/2;
        if (it->first ==0)
        {
            ans+=it->second;
        }
        
    }
    cout<<ans<<endl;
    
    return 0;

}
// Hashing - TOP K MOST FREQUENT ELEMENTS
signed main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    map<int,int>frequency;
    for (int i = 0; i < n; i++)
    {
        int present = frequency.size();
        if (frequency[a[i]]==0 && present ==k)
        {
            break;
        }
        frequency[a[i]]++;
        
    }
    vector<pair<int,int>>ans;
    map<int,int> :: iterator it;
    for ( it = ans.begin(); it != ans.end(); i++)
    {
        if (it->second !=0)
        {
            ans.push_back(it->second,it->first);
        }
        
    }
    sort(ans.begin(),ans.end(),greater<pair<int,int>>());
    vector<pair<int,int>> :: iterator it;
    for ( it = ans.begin(); i != ans.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;   
}
