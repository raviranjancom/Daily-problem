#include <iostream>
using namespace std;

int main(){
  int a[]={-2,1,5,1,-1,3,-4};
  int n=7;
  int s=0,m=0;
  int t=0,x=0,y=0;
  for(int i=0;i<n;i++){
    s+=a[i];
    if(s==0) t=i;
    if(s<0) s=0;
    if(s>m){
      m=s;
      y=i;
      x=t;
    }
  }
  cout<<x<<" "<<y<<" "<<m;
}
