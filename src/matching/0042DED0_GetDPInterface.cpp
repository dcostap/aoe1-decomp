extern int g_0062C5EC;
#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    virtual ~TCommunications_Handler();
    int GetDPInterface();
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::GetDPInterface() { return g_0062C5EC; }
