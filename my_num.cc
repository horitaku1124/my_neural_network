#define TYPE_INT 1;
#define TYPE_FLOAT 2;


struct MyNum {
    size_t _size;
    size_t _dimension;
    int* _shape;
    short _type;
    int *_int_array;
    float *_float_array;
    double *_double_array;
    MyNum() {
        _size = 0;
        _dimension = 0;
        _int_array = NULL;
    }
    MyNum(int count, ...) {
        va_list ap;
        va_start(ap, count);
        _int_array = (int *)malloc(sizeof(int) * count);
        _type = TYPE_INT;
        _dimension = 1;
        
        for (int i = 0; i < count; i++ ) {
            _int_array[i] = va_arg(ap, int);
        }
        va_end(ap);
        _size = count;
        _shape = (int *)malloc(sizeof(int) * 1);
        _shape[0] = count;
    }
    int sum() {
        int _sum = 0;
        for (int i = 0;i < _size;i++) {
            _sum += _int_array[i];
        }
        return _sum;
    }

    void divideOf(float n) {
        _double_array = (double *)malloc(sizeof(double) * _size);
        for (int i = 0;i < _size;i++) {
            _double_array[i] = n / _int_array[i];
        }
        free(_int_array);
    }
    void sqrt() {
        for (int i = 0;i < _size;i++) {
            _double_array[i] = ::sqrt(_double_array[i]);
        }
    }
    // ~MyNum(void) {
    // }

    int getInt(size_t index) {
        return _int_array[index];
    }
    MyNum operator*(int x) {
        MyNum _res = MyNum();
        _res._size = _size;
        _res._dimension = _dimension;
        _res._type = _type;
        int t_int = TYPE_INT;
        int t_float = TYPE_FLOAT;
        if (_type == t_int) {

        } else if (_type == t_float) {
            _res._float_array = _float_array;
            for (size_t i = 0;i < _size;i++) {
                _res._float_array[i] *= x;
            }
        }
        return _res;
    }

    void printInternal() {
        printf("size=%lu\n", _size);
        printf("dimenstion=%lu\n", _dimension);
        printf(" -- data --\n");
        for(size_t i = 0;i < _size;i++) {
            printf(" %d", _int_array[i]);
        }
        printf("\n");
    }
};

MyNum operator*(int x, MyNum y) {
    return y * x;
}

MyNum randome_randn(int count, ...) {
    va_list ap;
    va_start(ap, count);

    MyNum data;

    int size = 1;
    for (int i = 0; i < count; i++ ) {
        size *= va_arg(ap, int);
    }
    va_end(ap);
    data._size = size;
    data._type = TYPE_FLOAT;
    data._float_array = (float *)malloc(sizeof(float) * size);
    for (size_t i = 0;i < size;i++) {
        data._float_array[i] = (float)rand() / RAND_MAX;
    }
    return data;
}
MyNum zeros(int count, ...) {
    va_list ap;
    va_start(ap, count);

    MyNum data;

    data._shape = (int *)malloc(sizeof(int) * count);
    int size = 1;
    for (int i = 0; i < count; i++ ) {
        int arg = va_arg(ap, int);
        size *= arg;
        data._shape[i] = arg;
    }
    va_end(ap);
    data._dimension = count;
    data._size = size;
    data._type = TYPE_INT;
    data._int_array = (int *)malloc(sizeof(int) * size);
    for (size_t i = 0;i < size;i++) {
        data._int_array[i] = 0;
    }
    return data;
}
MyNum mynum_pad(MyNum input_data, int** padNum, char* mode) {
    MyNum pad;
    return pad;
}

MyNum mynum_array_i(int dimension, int* shape, void* data) {
    MyNum num;
    num._dimension = dimension;
    num._shape = (int*)malloc(sizeof(int) * dimension);
    size_t size = 1;
    for (int i = 0;i < dimension;i++) {
        size *= shape[i];
        num._shape[i] = shape[i];
    }
    num._type = TYPE_INT;
    num._size = size;
    num._int_array = (int*)malloc(sizeof(int) * size);
    memcpy(num._int_array, (int*)data, size * sizeof(int));
    return num;
}