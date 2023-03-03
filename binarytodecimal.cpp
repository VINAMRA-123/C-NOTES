#include<stdio.h>
#include <iostream>
using namespace std;
int binarytodecimal(int n){
    int x=1;
    int ans = 0;
    while(n>0)
    {
        int y = n%10;
        ans = ans + x*y;
        x = 2*x;
        n = n/10;
    }
    return ans;
}
int hexadecimaltodecimal(int n){
    int x=1;
    int ans = 0;
    while(n>0)
    {
        int y = n%10;
        ans = ans + x*y;
        x = 2*x;
        n = n/10;
    }
    return ans;
}
int octaltodecimal(int n){
    int x=1;
    int ans = 0;
    while(n>0)
    {
        int y = n%10;
        ans = ans + x*y;
        x = 2*x;
        n = n/10;
    }
    return ans;
}
int main(){
    int n;
    std::cin>>n;
    cout<<binarytodecimal(n)<<endl;
    return 0;
}
