#include<bits/stdc++.h>
using namespace std;

string reverse(string str){
    stack<char> ds;
    int n=str.length();
    for(int i=0;i<n;i++){
        if(str[i]=='(') ds.push(')');
        else if(str[i]==')') ds.push('(');
        else ds.push(str[i]);
    }
    str="";
    while(!ds.empty()){
        str+=ds.top();
        ds.pop();
    }
    return str;
}

int priority(char ch){
    if(ch=='^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    else return -1;
}

string infix2postfix(string s){
    stack<char> ds;
    string ans;
    int n=s.length();
    int i=0;
    while(i<n){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            ans.push_back(s[i]);
        }
        else if(s[i]=='('){
            ds.push('(');
        }
        else if(s[i]==')'){
            while(!ds.empty() && ds.top()!='('){
                ans+=ds.top();
                ds.pop();
            }
            ds.pop();
        }
        else{
            while(priority(s[i]) <= priority(ds.top())){
                ans+=ds.top();
                ds.pop();
            }
            ds.push(s[i]);
        }
        i++;
    }
    while(!ds.empty()){
        ans+=ds.top();
        ds.pop();
    }
    return ans;
}

string infix2prefix(string s){
    string str=reverse(s);
    string ans=infix2postfix(str);
    return reverse(ans);
}

int main(){
    string s="a+b*(c/d-e)";
    cout<<infix2postfix(s)<<endl;
    cout<<infix2prefix(s)<<endl;
    return 0;
}
