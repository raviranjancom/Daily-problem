#include<bits/stdc++.h>
using namespace std;

class myvector{
    private:
        int size;
        int capacity;
        int *arr;
    public:
        myvector(){
            this->size=0;
            this->capacity=1;
        }
        ~myvector(){

        }

        void push(int x){
            if(this->size==this->capacity){
                capacity*=2;
                int *arr2 = new int[capacity];
                for(int i=0;i<size;i++){
                    arr2[i]=arr[i];
                }
                arr2[size++]=x;
            }
            else{
                arr[size++]=x;
            }
        }
        void pop(){
            size--;
        }
        void display(){
            for(int i=0;i<size;i++){
                cout<<arr[i]<<endl;
            }
        }
};

int main(){
    myvector v;

    return 0;
}
