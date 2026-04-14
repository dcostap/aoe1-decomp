class RGE_TimeSinceLastCall {
public:
    char gap_0[0x10C];
    int arr_[100];
    void Test();
};

void RGE_TimeSinceLastCall::Test() {
    for (int i = 0; i < 100; i++) this->arr_[i] = 10;
}
