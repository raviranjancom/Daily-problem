#include<iostream>
using namespace std;
int main(){
    int n;
    while(n>0){
        int x,t;
        cin>>t>>x;
        if(t==1 || t==2) return 1;
        else{
            int i=1;
            while(true){
                if(t>x*(i-1)+2 && t<=x*i+2){
                    cout<<i+1<<endl;
                    break;
                }
                i++;
            }
        }
        n--;
    }
}
