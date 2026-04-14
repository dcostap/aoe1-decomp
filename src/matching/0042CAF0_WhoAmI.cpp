class TCommunications_Handler {
public:
    virtual ~TCommunications_Handler();
    char gap_0[0x10DC];
    int field_10E0;
    int WhoAmI();
};

int TCommunications_Handler::WhoAmI() { return this->field_10E0; }
