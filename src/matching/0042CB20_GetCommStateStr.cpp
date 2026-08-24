#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    virtual ~TCommunications_Handler();
    int GetCommStateStr();
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::GetCommStateStr() { return 0; }
