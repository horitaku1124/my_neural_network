struct MyNum {
    size_t _size;
    short _type;
    int *_int_array;
    double *double_array;
    MyNum() {
        _size = 0;
        _int_array = NULL;
    }
    MyNum(int count, ...) {
        va_list ap;
        va_start(ap, count);
        _int_array = (int *)malloc(sizeof(int) * count);
        _type = 1;
        
        for (int i = 0; i < count; i++ ) {
            _int_array[i] = va_arg(ap, int);
        }
        va_end(ap);
        _size = count;
    }
    int sum() {
        int _sum = 0;
        for (int i = 0;i < _size;i++) {
            _sum += _int_array[i];
        }
        return _sum;
    }

    void divideOf(float n) {
        double_array = (double *)malloc(sizeof(double) * _size);
        for (int i = 0;i < _size;i++) {
            double_array[i] = n / _int_array[i];
        }
        free(_int_array);
    }
    void sqrt() {
        for (int i = 0;i < _size;i++) {
            double_array[i] = ::sqrt(double_array[i]);
        }
        for (int i = 0;i < _size;i++) {
            printf("[%d]=%f\n", i, double_array[i]);
        }
    }
    // ~MyNum(void) {
    // }
};