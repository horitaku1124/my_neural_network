#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#include "my_num.cc"
#include "my_layer.cc"
#include "deep_convnet.cc"

typedef int (*FUNCPTR)(int a,int b);


int multiple(int a,int b)
{
    return(a*b);
}


int main()
{
    DeepConvNet net = DeepConvNet();
    MyNum mn = MyNum();
    MyNum mn2 = MyNum(3, 10, 20, 30);
    printf("mn2.sum = %d\n", mn2.sum());
    FUNCPTR tFuncPtr;
    tFuncPtr = &multiple;

    int a = 100, b = 20;
    int res = (tFuncPtr)(a,b);
    printf("res = %d\n", res);
    return 0;
}