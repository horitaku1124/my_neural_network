
typedef int (*FUNCPTR)(int a,int b);

struct Layer {
    Layer* nextLayer;
    Layer() {
        nextLayer = NULL;
    }
};


struct MyLayers {
    Layer nextLayer;
    
};

struct LayerBase {
    LayerBase() {

    }
    virtual MyNum forward(MyNum x);
    virtual MyNum backward(int dout);
};

struct Convolution :LayerBase {
    MyNum _W, _b;
    int _stride, _pad;
    MyNum _x, col, col_W;
    MyNum dW;
    double db;

    Convolution(MyNum W, MyNum b, int stride, int pad) {
        _W = W;
        _b = b;
        _stride = stride;
        _pad = pad;
    }
    MyNum forward(MyNum x) {
        int FN, C, FH, FW;
        int H,W,N;
        int out_h, out_w;
        FN = _W._shape[0];
        C = _W._shape[1];
        FH = _W._shape[2];
        FW = _W._shape[3];
        N = _x._shape[0];
        C = _x._shape[1];
        H = _x._shape[2];
        W = _x._shape[3];
        out_h = 1 + (H + 2 * _pad - FH) / _stride;
        out_w = 1 + (W + 2 * _pad - FW) / _stride;

        // col = im2col(x, FH, FW, self.stride, self.pad);
        // col_W = self.W.reshape(FN, -1).T;

        // out = np.dot(col, col_W) + self.b;
        // out = out.reshape(N, out_h, out_w, -1).transpose(0, 3, 1, 2);

        // self.x = x;
        // self.col = col;
        // self.col_W = col_W;

        // return out;
    }
};