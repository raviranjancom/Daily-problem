#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans;
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        ans=0;
        int a=0,b=s.length()-1;
        while(a<=b){
            if(s[a]=='0' && s[b]=='0'){
                a++;
                b--;
            }
            else if(s[a]=='0' && s[b]=='1'){
                a++;
            }
            else if(s[a]=='1' && s[b]=='0'){
                b--;
            }
            else{
                string x;
                for(int i=a;i<=b;i++){
                    if(x.back() != s[i] || i==a){
                        x=x+s[i];
                    }
                    else{
                        x=x+'*';
                    }
                }
                for(int i=a;i<=b;i++){
                    if(x[i-a]=='1'){
                        s[i]='0';
                    }
                    else if(x[i-a]=='0'){
                        s[i]='1';
                    }
                    else{
                        s[i]=s[i];
                    }
                }
                // cout<<"="<<s<<endl;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
