#include<bits/stdc++.h>
using namespace std;
bool isprime(int n){
    for(int i=2;i<=pow(n, 0.5);i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n,max=INT_MIN,ans=2;
        cin>>n;
        for(int i=2;i<=n;i++){
            int v=2;
            if(isprime(i)){
                int mod=n%i;
                int a=i,l=n-mod;
                int d=n/i;
                v=((a+l)*d)/2;
                if(max<v){
                    max=v;
                    ans=i;
                }
            }
        }
        cout<<ans<<endl;
        t--;
    }
}