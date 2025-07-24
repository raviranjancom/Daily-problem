#include<bits/stdc++.h>
using namespace std;
int water(vector<int> height){
    int n=height.size();
    int l=0,r=n-1;
    int rightMax=-1,leftMax=-1,ans=0;
    while(l<r){
        if(height[l] <= height[r]){
            leftMax=max(leftMax, height[l]);
            l++;
            
        }
        else{
            rightMax=max(rightMax, height[r]);
            r--;
        }
    }
}
int main(){

}
