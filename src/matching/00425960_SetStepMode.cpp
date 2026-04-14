class TCommunications_Handler {
public:
    virtual ~TCommunications_Handler();
    char gap_0[0x1284];
    int field_1288;
    void SetStepMode(int v);
};

void TCommunications_Handler::SetStepMode(int v) { this->field_1288 = v; }
