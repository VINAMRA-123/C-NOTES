#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    //Spiral Order Traversal Code
    int row_Start=0;
    int col_Start=0;
    int row_End=n-1;
    int col_End=m-1;
    int count=m*n;

    while(row_Start<=row_End && col_Start<=col_End){
        //1st
        for(int col=col_Start;col<=col_End;col++){
            count--;
            if(count<0){
                break;
            }
            cout<<arr[row_Start][col]<<" ";
        }
        row_Start++;

        //2nd
        for(int row=row_Start;row<=row_End;row++){
            count--;
            if(count<0){
                break;
            }
            cout<<arr[row][col_End]<<" ";
        }
        col_End--;

        //3rd
        for(int col=col_End;col>=col_Start;col--){
            count--;
            if(count<0){
                break;
            }
            cout<<arr[row_End][col]<<" ";
        }row_End--;

        //4th
        for(int row=row_End;row>=row_Start;row--){
            count--;
            if(count<0){
                break;
            }
            cout<<arr[row][col_Start]<<" ";
        }
        col_Start++;
    }
} 

// for matrix multiplication of n*m and m*k
void multiplyMatrices()
{
    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;
    int m1[n1][n2]; int m2[n2][n3]; int ans[n1][n3];
    for(int i=0; i<n1; i++) {
        for(int j=0; j<n2; j++)
            cin >> m1[i][j];
        }
    for(int i=0; i<n2; i++) {
        for(int j=0; j<n3; j++)
        cin >> m2[i][j];
    }
    for(int i=0; i<n1; i++) {
        for(int j=0; j<n3; j++)
            ans[i][j] = 0;
    }
    for(int i=0; i<n1; i++) {
        for(int j=0; j<n3; j++)
        {
            for(int k=0; k<n2; k++) {
                ans[i][j] += m1[i][k]*m2[k][j];
        }
    }
}
    for(int i=0; i<n1; i++) {
        for(int j=0; j<n3; j++)
            cout << ans[i][j] <<" ";
            cout << endl;
        }
    }   

// for finding a number in matrix
/*Optimised Approach [IMP]
1. Start from the top right element.
2. You are at (r,c)
if(matrix[r][c] == target)
return true
If (matrix[r][c] > target)
c--
else
r++;*/
#include "bits/stdc++.h"
using namespace std;
int32_t main() {
    int n, m; cin >> n >> m;
    int target; cin >> target;
    int mat[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    bool found = true;
    int r = 0,c = n-1;
    while (r<m && c>=0)
    {
        if (mat[r][c] == target)
        {
            cout<<r<<" "<<c<<endl;
            found= true;
        }
        else
        {
            if (target> mat[r][c])
            {
                c--;
            }
            else if (target< mat[r][c])
            {
                r++;
            }
            
        }
        
    }if (found)
    {
        cout << "Found";
    }
    else{
        cout << "Not Found";
    }
    
    
    }

// rotatig A MATRIX BY 90 DEGREE
void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0;i<(n+1)/2;i++){
            for(int j = 0;j<n/2;j++){
                int temp =  matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-i-1];
                matrix[j][n-i-1] = matrix[i][j];
                matrix[i][j] = temp;
            }

        }
}
// leetcode
class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
                    
            int rows = grid.size();
            int cols = grid[0].size();
            
            for(int i =  1; i<rows-1; i++){
                    
                    int sum = 0;
                    for(int j = 0; j<cols; j++){
                            sum += grid[i][j];
                    }
                    
                    if(sum==0 || sum==1){
                      
                            return true;
                    }
            }
            
            for(int j = 1; j<cols-1; j++){
                    int sum = 0;
                    for(int i = 0; i<rows; i++){
                            sum += grid[i][j];
                    }
                    
                    if(sum == 0 || sum == 1){
                            
                            return true;
                    }
            }
            
            
            
            if(rows>1 && cols>1){
            for(int j = 1; j<cols; j++){
                    
                    int r = 0;
                    int c = j;
                    
                    int sum = 0;
                    while(r<rows && c>=0){
                            sum += grid[r][c];
                            r++;
                            c--;
                    }
                    
                    if(sum==0 || sum==1){
                            
                            return true;
                    }
            }
            }
            
            return false;
    }
};
// my solution
class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        bool flag = false;
        int rows  =grid.size();
        int column = grid[0].size();
        
        for(int i =  1; i<rows-1; i++){
                int count = 0;
                for(int j = 0; j<count; j++){
                        count += grid[i][j];
                }       
                if(count==0 || count==1){                           
                        return true;
                }
        }
        for(int j = 1; j<column-1; j++){
                int count = 0;
                for(int i = 0; i<rows; i++){
                        count += grid[i][j];
                }       
                if(count== 0 || count== 1){
                        
                        return true;
                }
        }
        if(rows>1 && column>1){
            for(int j=1;j<column;j++){
                int count=0;
                int r = 0;
                int c = j;
                while(r<rows &&c>0){
                    if(grid[r][c]==1){
                        count++;
                    }
                    c--;
                    r++;
                    if(count==0 ||count==1){
                        flag=true;
                    }
                }
            }
            
        }return flag;
    }
};