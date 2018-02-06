
struct FilterParam {
    int num;
    int size;
    int pad;
    int stride;
};
struct DeepConvNet {
    int *input_dim;
    FilterParam param1,
                param2,
                param3,
                param4,
                param5,
                param6;
    int hidden_size, output_size;
    DeepConvNet() {
        int _input_dim[3] = {1, 28, 28};
        input_dim = _input_dim;
        FilterParam _param1 = {16, 3, 1, 1};
        param1 = _param1;
        FilterParam _param2 = {16, 3, 1, 1};
        param2 = _param2;
        FilterParam _param3 = {32, 3, 1, 1};
        param3 = _param3;
        FilterParam _param4 = {32, 3, 2, 1};
        param4 = _param4;
        FilterParam _param5 = {64, 3, 1, 1};
        param5 = _param5;
        FilterParam _param6 = {64, 3, 1, 1};
        param6 = _param6;
        hidden_size = 50;
        output_size = 10;

        MyNum pre_node_nums = MyNum(8, 1*3*3, 16*3*3, 16*3*3, 32*3*3, 32*3*3, 64*3*3, 64*4*4, hidden_size);
        pre_node_nums.divideOf(2.0);
        pre_node_nums.sqrt();
        
    }
};