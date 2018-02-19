#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#include "../my_num.cc"

int main()
{

    printf("-- 1\n");
    MyNum mynum = MyNum();
    printf("%lu\n", mynum._size);


    printf("-- 2\n");
    MyNum rand0 = zeros(3, 4, 4, 4);
    printf("%lu\n", rand0._size);
    printf("%lu\n", rand0._dimension);
    for(int i = 0;i < rand0._dimension;i++) {
        printf(" shape[%d]=%d\n", i, rand0._shape[i]);
    }
    return 0;
}