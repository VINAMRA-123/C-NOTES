// to check palindrome of array
#include<iostream>
using namespace std;
int main(){
    char word[100];
    cin>>word;
    int n;
    cin>>n;
    bool flag;
    flag = true;

    for (int i = 0; i < n/2; i++)

        if(word[i]!=word[n-1-i]){

            flag=false;

            break;

        }



    if(flag==true)

        cout<<"Result :"<<"YES"<<endl;

    else

        cout<<"Result :"<<"NO"<<endl;
}
// largest word in a sentence
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char arr[100] = "do or die";
    int maxlen = 0;
    int currlen = 0;
    int n;
    cin>>n;
    cin.ignore();
    cin.getline(arr,n);
    cin.ignore();
    while (1)
    {
        
    }
    
}