#include<iostream>
using namespace std;

int main(){
    int num[]={2, 5, 1 ,7 ,10};
    int n=5;
    int k=14,maxlen=0;
    // for(int i=0;i<n;i++){
    //     int sum=0;
    //     for(int j=i;j<n;j++){
    //         sum+=num[j];
    //         if(sum<=k){
    //             maxlen=max(maxlen, j-i+1);
    //         }
    //     }
    // }
    // cout<<"="<<maxlen;

    int sum=0,l=0,r=0;
    while(r<n){
        sum+=num[r];
        while(sum>k){
            sum-=num[l];
            l++;
        }
        if(sum<=k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    cout<<"="<<maxlen;
    return 0;
}
