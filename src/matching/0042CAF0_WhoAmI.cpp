#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    virtual ~TCommunications_Handler();
    char gap_0[0x10DC];
    int field_10E0;
    int WhoAmI();
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::WhoAmI() { return this->Me; }
