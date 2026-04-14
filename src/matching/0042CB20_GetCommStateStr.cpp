class TCommunications_Handler {
public:
    virtual ~TCommunications_Handler();
    int GetCommStateStr();
};

int TCommunications_Handler::GetCommStateStr() { return 0; }
