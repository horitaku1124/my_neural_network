
struct FilterParam {
    int num;
    int size;
    int pad;
    int stride;
};

struct ParamsArray {
    MyNum W1, b1;
    MyNum W2, b2;
    MyNum W3, b3;
    MyNum W4, b4;
    MyNum W5, b5;
    MyNum W6, b6;
    MyNum W7, b7;
    MyNum W8, b8;
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

        MyNum wight_init_scales = MyNum(8, 1*3*3, 16*3*3, 16*3*3, 32*3*3, 32*3*3, 64*3*3, 64*4*4, hidden_size);
        wight_init_scales.divideOf(2.0);
        wight_init_scales.sqrt();
        
        int pre_channel_num = _input_dim[0];

        ParamsArray params = ParamsArray();
        params.W1 = randome_randn(4, _param1.num, pre_channel_num, _param1.size, _param1.size) * wight_init_scales.getInt(0);
        params.b1 = zeros(_param1.num);

        params.W2 = randome_randn(4, _param2.num, pre_channel_num, _param2.size, _param2.size) * wight_init_scales.getInt(1);
        params.b2 = zeros(_param2.num);

        params.W3 = randome_randn(4, _param3.num, pre_channel_num, _param3.size, _param3.size) * wight_init_scales.getInt(2);
        params.b3 = zeros(_param3.num);

        params.W4 = randome_randn(4, _param4.num, pre_channel_num, _param4.size, _param4.size) * wight_init_scales.getInt(3);
        params.b4 = zeros(_param4.num);

        params.W5 = randome_randn(4, _param5.num, pre_channel_num, _param5.size, _param5.size) * wight_init_scales.getInt(4);
        params.b5 = zeros(_param5.num);

        params.W6 = randome_randn(4, _param6.num, pre_channel_num, _param6.size, _param6.size) * wight_init_scales.getInt(5);
        params.b6 = zeros(_param6.num);

    }
};