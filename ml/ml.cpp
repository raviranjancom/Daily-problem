//
// Created by errav on 31-05-2025.
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float train[][2]={
    {0,0},
    {1,2},
    {2,4},
    {3,6},
    {4,8}
};

float rand_float(void) {
    return (float) rand()/ (float) RAND_MAX;
}

float cost(float w){
    float result = 0.0f;
    for(size_t i=0;i< (sizeof(train)/sizeof(train[0]));i++){
        float x=train[i][0];
        float y=x*w;
        float d=y-train[i][1];
        result += d*d;
        // printf("actual = %f, expected = %f\n",y,train[i][1]);
    }
    result/=sizeof(train)/sizeof(train[0]);
    return result;
}
int main() {
    // y = x*w
    srand(time(0));
    // rand(69);
    float w=rand_float()*10.0f;
    
    float esp = 1e-3;
    float rate=1e-3;
    // printf("result = %f\n",cost(w));
    // printf("%f\n",cost(w+esp));
    // printf("%f\n",cost(w-2*esp));
    for(size_t i=0;i<500;i++){
        float dcost=(cost(w+esp)-cost(w))/esp;
        printf("Before = %f\n",cost(w));
        w-=rate*dcost;
        printf("cost = %f, w=%f\n",cost(w),w);
    }
    printf("--------------------\n");
    printf("%f\n",w);
    return 0;
}
