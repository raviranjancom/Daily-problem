#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums={5,7,9,6,7,4,5,1,3,7},ans;
    stack<int> st;
    int n=nums.size();
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=nums[i]){
            st.pop();
        }
        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(nums[i]);
    }
    for(auto it : ans){
        cout<<it<<" ";
    }
}
