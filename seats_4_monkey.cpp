#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int m,a,b,c,ans=0;
        cin>>m>>a>>b>>c;
        int row=m,col=m;
        if(row>=a){
            ans+=a;
            row-=a;
        }
        else{
            ans+=row;
            row=0;
        }

        if(col>=b){
            ans+=b;
            col-=b;
        }
        else{
            ans+=col;
            col=0;
        }

        if((row+col)>=c){
            ans+=c;
        }
        else{
            ans+=row+col;
        }
        cout<<ans<<endl;
        t--;
    }
}
