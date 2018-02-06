#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#include "my_num.cc"
#include "deep_convnet.cc"

int main()
{
    DeepConvNet net = DeepConvNet();
    MyNum mn = MyNum();
    MyNum mn2 = MyNum(3, 10, 20, 30);
    printf("mn2.sum = %d\n", mn2.sum());
    return 0;
}