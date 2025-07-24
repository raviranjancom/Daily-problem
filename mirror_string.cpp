#include<bits/stdc++.h>
using namespace std;
string mirror(string s){
    int n=s.length();
    int i=0,j=n-1;
    while(i<j){
        char ch=s[i];
        s[i]=s[j];
        s[j]=ch;
        if(s[i]=='p') s[i]='q';
        else if(s[i]=='q') s[i]='p';

        if(s[j]=='p') s[j]='q';
        else if(s[j]=='q') s[j]='p';
        i++;
        j--;
    }
    if(n%2==1){
        if(s[n/2]=='p') s[n/2]='q';
        else if(s[n/2]=='q') s[n/2]='p';
    }
    return s;
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        string s;
        cin>>s;
        cout<<"="<<mirror(s)<<endl;
        t--;
    }
}