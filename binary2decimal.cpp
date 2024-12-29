#include<iostream>
#include<math.h>
using namespace std;
int binary2decimal(string s){
    int ans=0;
    int n=s.size();
    int j=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1') ans+=pow(2,j);
        j++;
    }
    return ans;
}
int main(){
    string s;
    cout<<"Enter binary = ";
    cin>>s;
    cout<<binary2decimal(s);
    return 0;
}
