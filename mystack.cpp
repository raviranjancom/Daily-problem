#include<bits/stdc++.h>
using namespace std;
class mystack{
    private:
        vector<int> v;
        int size;
        int min;
    public:
        mystack(){
            size=0;
            min=INT_MAX;
        }
        ~mystack(){

        }

        void push(int x){
            if (size==0){
                v.push_back(x);
                min=x;
            }
            else{
                if(x < v.back()){
                    v.push_back(2*x-min);
                    min=x;
                }
                else v.push_back(x);
            }
            size++;
        }
        void pop(){
            int x=v.back();
            v.pop_back();
            size--;
            if(x==min){
                min=2*min-x;
            }
        }

        int top(){
            int x=v.back();
            if(x<min){
                return min;
            }
            return x;
        }

        int minimum(){
            return min;
        }

        int length(){
            return size;
        }
};
int main(){
    mystack ds;
    ds.push(10);
    ds.push(5);
    ds.push(20);
    cout<<ds.minimum()<<endl;
    cout<<ds.length()<<endl;
    cout<<ds.top()<<endl;
    return 0;
}
