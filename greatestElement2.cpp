#include<bits/stdc++.h>
using namespace std;
vector<int> NGE2(vector<int> v){
    vector<int> ans;
    int n=v.size();
    stack<int> st;
    for(int i=0;i<n-1;i++){
        while(!st.empty() && st.top() < v[i]){
            st.pop();
        }
        if(v[i] > st.top()){
            st.push(v[i]);
        }
    }
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && v[i] > st.top()){
            st.pop();
        }
        if(v[i] < st.top()){
            ans.push_back(st.top());
            st.push(v[i]);
        }
        if(st.empty()){
            ans.push_back(-1);
        }
    }
    return ans;
}
int main(){
    vector<int> v={2,10,12,1,11};
    vector<int> a=NGE2(v);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
