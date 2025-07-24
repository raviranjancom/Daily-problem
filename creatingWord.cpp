#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        string a,b;
        cin>>a>>b;
        char ch=a[0];
        a[0]=b[0];
        b[0]=ch;
        cout<<a<<" "<<b<<endl;
        t--;
    }
}
