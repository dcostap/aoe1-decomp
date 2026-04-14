class TCommunications_Handler {
public:
    virtual ~TCommunications_Handler();
    int OpenMultiplayerConnection();
};

int TCommunications_Handler::OpenMultiplayerConnection() { return -1; }
