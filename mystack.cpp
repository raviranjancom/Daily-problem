#include<bits/stdc++.h>
using namespace std;
class mystack{
    private:
        vector<pair<int,int>> v;
        int size;
    public:
        mystack(){
            size=0;
        }
        ~mystack(){

        }

        void push(int x){
            if (size==0) v.push_back({x,x});
            else{
                if(x < v.back().second) v.push_back({x, x});
                else v.push_back({x,v.back().second});
            }
            size++;
        }
        void pop(){
            v.pop_back();
            size--;
        }

        int top(){
            return v.back().first;
        }

        int min(){
            return v.back().second;
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
    cout<<ds.min()<<endl;
    cout<<ds.length()<<endl;
    cout<<ds.top()<<endl;
    return 0;
}
