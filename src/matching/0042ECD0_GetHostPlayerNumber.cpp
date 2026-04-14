class TCommunications_Handler {
public:
    virtual ~TCommunications_Handler();
    char gap_0[0x1710];
    int field_1714;
    int GetHostPlayerNumber();
};

int TCommunications_Handler::GetHostPlayerNumber() { return this->field_1714; }
