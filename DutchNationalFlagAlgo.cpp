#include <iostream>
using namespace std;
int main(){
  int ar[]={1,0,2,2,2,1,0,1,0};
  int n=9;
  int l=0,m=0,h=n-1;
  while(m<=h){
    if(ar[m]==0){
      swap(ar[l],ar[m]);
      l++;
      m++;
    }
    else if(ar[m]==1) m++;
    else{
      swap(ar[m],ar[h]);
      h--;
    }
  }
  for(int i=0;i<n;i++){
    cout<<ar[i]<<" ";
  }
}
