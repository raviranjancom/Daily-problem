#include<bits/stdc++.h>
using namespace std;
string prefix2postfix(string s){
    int n=s.length();
    stack<string> ans;
    for(int i=0;i<n;i++){
        if((s[n-1-i]>='A' && s[n-1-i]<='Z') || (s[n-1-i]>='a' && s[n-1-i]<='z') || (s[n-1-i]>='0' && s[n-1-i]<='9')){
            string str="";
            str+=s[n-1-i];
            ans.push(str);
        }
        else{
            string a=ans.top();
            ans.pop();
            string b=ans.top();
            ans.pop();
            ans.push(a+b+s[n-1-i]);
        }
    }
    return ans.top();
}
int main(){
    string s="AB-DE+F*/";
    cout<<prefix2postfix(s)<<endl;
    return 0;
}
