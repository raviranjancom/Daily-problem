#include<bits/stdc++.h>
using namespace std;
bool isprime(int n){
    int count=0;
    for(int i=2;i<pow(n, 0.5);i++){
        if(n%i==0) count++;
    }
    if(count>0) return true;
    return false;
}

int main(){
    int n=100;
    cout<<isprime(n);
}