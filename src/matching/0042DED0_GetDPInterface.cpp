extern int g_0062C5EC;
#if !defined(COM_HAND_TU_CONTEXT)
struct IDirectPlay3;

class TCommunications_Handler {
public:
    virtual ~TCommunications_Handler();
    IDirectPlay3* GetDPInterface();
};
#endif // COM_HAND_TU_CONTEXT


IDirectPlay3* TCommunications_Handler::GetDPInterface() { return (IDirectPlay3*)g_0062C5EC; }
