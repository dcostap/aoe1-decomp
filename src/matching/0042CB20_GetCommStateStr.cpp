#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    virtual ~TCommunications_Handler();
    char* GetCommStateStr();
};
#endif // COM_HAND_TU_CONTEXT


char* TCommunications_Handler::GetCommStateStr() { return 0; }
