class TCommunications_Handler {
public:
    virtual ~TCommunications_Handler();
    char gap_0[0x1308];
    int field_130C;
    void SetWindowHandle(int v);
};

void TCommunications_Handler::SetWindowHandle(int v) { this->field_130C = v; }
