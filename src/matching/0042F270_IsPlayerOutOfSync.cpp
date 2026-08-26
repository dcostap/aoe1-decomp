#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Communications_Synchronize {
public:
    int IsPlayerOutOfSync(unsigned int player, unsigned long turn);
};
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0[0x14D8];
    RGE_Communications_Synchronize* Sync;
    int IsPlayerOutOfSync(unsigned int player, unsigned long turn);
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::IsPlayerOutOfSync(unsigned int player,
                                               unsigned long turn) {
    return this->Sync->IsPlayerOutOfSync(player, turn);
}
