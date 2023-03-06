#include<iostream>
using namespace std;
int main(){
    string str;
    getline(cin,str);//if we simply use cin>>str than it will give the charachter before value.
    cout<<str<<endl;
    return 0;
}
// some functions in string
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string s1 = "abc";
    string s2 = "xyz";
    string s3 = "sjnvdutir";
    string s4 = "786";
    cout<<s1.append(s2)<<endl;// this will append s2 in s1
    cout<<s1 + s2<<endl; // this will simply give the output without changing s1 and s2.
    cout<<s1.compare(s2)<<endl; // this will compare string and output will be 23 for this.
    cout<<s3.erase(2,3)<<endl;//it will erase from which index you will have to erase and how much indices you have to erase  
    cout<<s3.find("nvd")<<endl;// it will return from which index the substring is starting.
    cout<<s1.substr(6,4)<<endl; // it gives the substring of 4 leeter after 6th index
    int x = stoi(s4);
    cout<<x+1<<endl; // it converts string into integer and gives 788
    int y= 799;
    cout<<to_string(y) + "2"<<endl;// it gives integer into string 7992
    // for sorting we use
    sort(s3.begin(),s3.end());
    cout<<s3<<endl; 
    return 0;
}

// question on string 
// to convert string in upper and lower case
#include<iostream>
using namespace std;
int main(){
    string s1 = "hbsvbsievr";
    transform(s1.begin(),s1.end(),s1.begin(),::toupper); // upper 
    string s2 = "SDVDBVTBB";
    transform(s2.begin(),s2.end(),s2.begin(),::tolower);
}
// problem 2
// to find maximum number using string 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s1 = "454927023";
    sort(s1.begin(),s1.end(),greater<int>());
    cout<<s1<<endl;
}
// problem 3
// find the maximum frequency of a string

#include<iostream>

#include<string>

#include<algorithm>

using namespace std;

int main(){

    string s1="abcaacbade";

    sort(s1.begin(),s1.end());

    int freq=1;

    int maxf=0;

    for(int i=0;i<s1.size();i++){

        if(s1[i]==s1[i+1]){

            freq++;

            maxf=max(maxf,freq);

        }

        else{freq=0;}

    }cout<<maxf<<endl;

return 0;} 