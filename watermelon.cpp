#include<iostream>
using namespace std;
int main(){
    int n,i;
    cin>>n;
    for(i=2;i<=n/2;i++){
        int a,b;
        a=i;
        b=n-i;
        if(a%2==0 && b%2==0){
            cout<<"YES"<<endl;
            break;
        }
    }
    if(i>n/2) cout<<"NO\n";
}
