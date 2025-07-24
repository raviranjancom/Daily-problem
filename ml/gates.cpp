#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

// OR GATE
float train[][3]={
    {0,0,0},
    {0,1,1},
    {1,0,1},
    {1,1,1}
};

float cost(float w1, float w2){
    float result=0.0f;
    for(size_t i=0;i<(sizeof(train)/sizeof(train[0]));i++){
        float x1=train[i][0];
        float x2=train[i][1]; 
        float y=x1*w1 + x2*w2;
        float d= y - train[i][2];
        result += d*d;
    }
    result /=(sizeof(train)/sizeof(train[0]));
    return result;
}

float rand_float(){
    return (float) rand()/(float)RAND_MAX;
}

int main(){
    float esp = 1e-3;
    float rate = 1e-3;

    srand(time(0));
    float w1=rand_float();
    float w2=rand_float();
    // printf("w1 = %f  w2 = %f\n",w1, w2);
    for(size_t i=0;i<5000;i++){
        float c= cost(w1,w2);
        float dw1 = (cost(w1+esp, w2)-cost(w1,w2))/esp;
        float dw2 = (cost(w1, w2 + esp)-cost(w1,w2))/esp;
        w1-=rate*dw1;
        w2-=rate*dw2;
        printf("w1= %f  w2= %f  c = %f\n",w1,w2,c);
    }
    
    return 0;
}
