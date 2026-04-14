extern int g_0062C5EC;
class TCommunications_Handler {
public:
    virtual ~TCommunications_Handler();
    int GetDPInterface();
};

int TCommunications_Handler::GetDPInterface() { return g_0062C5EC; }
