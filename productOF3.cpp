#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
    for(int i=2;i<=pow(n,0.5);i++){
        if(n%i==0) return false;
    }
    return true;
}
int fun(int n, int x){
    for(int i=2;i<=pow(n, 0.5);i++){
        if(x==i) continue;
        else if(n%i==0) return i;
    }
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int i;
        for(i=2;i<=pow(n,0.5);i++){
            if(n%i==0){
                n=n/i;
                if(!isprime(n)){
                    int x=fun(n, i);
                    if(x !=0 && x != n/x){
                        cout<<"YES\n";
                        cout<<i<<" "<<x<<" "<<n/x<<endl;
                        break;
                    }
                }
            }
        }
        if(i>pow(n,0.5)) cout<<"NO\n";
        t--;
    }
}
