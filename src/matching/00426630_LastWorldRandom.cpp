#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Communications_Synchronize {
public:
    void SetLastWorldRandom(unsigned long param);
};
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0[0x14D8];
    RGE_Communications_Synchronize *Sync;
    void LastWorldRandom(int param);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::LastWorldRandom(int param) {
    this->Sync->SetLastWorldRandom(param);
}
