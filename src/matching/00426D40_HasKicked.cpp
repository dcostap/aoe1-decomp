#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    virtual ~TCommunications_Handler();
    char gap_0[0x1498];
    int array_149C[1];
    int HasKicked(int idx);
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::HasKicked(int idx) { return this->array_149C[idx]; }
