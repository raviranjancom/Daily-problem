#include<iostream>
using namespace std;

int main(){
    int num[]={-1,2,3,3,4,5,-1};
    int n=sizeof(num)/sizeof(num[0]);
    int k=4,sum=0,l=0,r=0,maxSum=0;
    for(int i=0;i<k;i++){
        sum+=num[r];
        r++;
        maxSum=max(sum, maxSum);
    }
    while(r<n){
        sum+=num[r];
        sum-=num[l];
        r++;
        l++;
        maxSum=max(sum, maxSum);
    }
    cout<<"="<<maxSum;
    return 0;
}
