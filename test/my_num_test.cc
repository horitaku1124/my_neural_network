#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <string.h>

#include "../my_num.cc"

int main()
{

    printf("-- 1\n");
    MyNum mynum = MyNum();
    printf("%lu\n", mynum._size);


    printf("-- 2\n");
    {
        MyNum rand0 = zeros(3, 4, 4, 4);
        printf("%lu\n", rand0._size);
        printf("%lu\n", rand0._dimension);
        for(int i = 0;i < rand0._dimension;i++) {
            printf(" shape[%d]=%d\n", i, rand0._shape[i]);
        }
    }

    printf("-- 3\n");
    {
        int shape[] = {3};
        int data[] = {1,2,3};
        MyNum m3 = mynum_array_i(1, shape, data);
        printf("%lu\n", m3._size);
        printf("%lu\n", m3._dimension);
        for(int i = 0;i < m3._dimension;i++) {
            printf(" shape[%d]=%d\n", i, m3._shape[i]);
        }
        m3.printInternal();
    }
    printf("-- 4\n");
    {
        int shape[] = {2,3};
        int data[2][3] = {{1,2,3}, {4,5,6}};
        MyNum m4 = mynum_array_i(2, shape, data);
        m4.printInternal();
    }
    return 0;
}