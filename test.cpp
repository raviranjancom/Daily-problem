#include<iostream>
using namespace std;
void test(int n){
    if(n>0){
        for(int i=0;i<n;i++){
            cout<<i<<" ";
        }
        cout<<"\n";
        test(n-1);
    }
}
int main(){
    test(3);
}