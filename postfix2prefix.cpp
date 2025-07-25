#include<bits/stdc++.h>
using namespace std;
string postfix2prefix(string s){
    int n=s.length();
    stack<string> ans;
    for(int i=0;i<n;i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            string str="";
            str+=s[i];
            ans.push(str);
        }
        else{
            string b=ans.top();
            ans.pop();
            string a=ans.top();
            ans.pop();
            ans.push(s[i]+a+b);
        }
    }
    return ans.top();
}
int main(){
    string s="AB-DE+F*/";
    cout<<postfix2prefix(s)<<endl;
    return 0;
}
