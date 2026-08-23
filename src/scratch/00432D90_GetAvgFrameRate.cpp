struct Inner_2D90 {
    int GetAvg(int count);
};

class TCommunications_Handler {
public:
    char gap_0[0x104];
    Inner_2D90 *ptr;
    int GetAvgFrameRate();
};

int TCommunications_Handler::GetAvgFrameRate() {
    return this->ptr->GetAvg(0x32);
}
