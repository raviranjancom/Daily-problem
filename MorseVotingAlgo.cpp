#include <iostream>
using namespace std;
int main(){
  int ar[]={4,2,4,3,4,1,1,4,4};
  int n=9;
  int e,c=0;
  for(int i=0;i<n;i++){
    if(c==0){
      e=ar[i];
      c++;
    }
    else if(e!=ar[i]) c--;
    else c++;
  }
  cout<<e;
}
