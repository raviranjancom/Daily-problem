#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        vector<int> options={b+a, c-b, d-c};
        int ans=0;
        for(int i=0;i<3;i++){
            vector<int> v={a,b,options[i],c,d};
            int m=0;
            for(int i=2;i<5;i++){
                if(v[i]==v[i-1]+v[i-2]){
                    m++;
                }
            }
            ans=max(ans,m);
        }
        t--;
        cout<<ans<<"\n";
    }
}
