#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0[0x10E8];
    int field_10E8;
    int field_10EC;
    void OutOfSync(int a, int b);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::OutOfSync(int a, int b) {
    this->field_10E8 = a;
    this->field_10EC = b;
}
