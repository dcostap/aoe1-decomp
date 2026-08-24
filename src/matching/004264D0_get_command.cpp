#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Communications_Queue {
public:
    void* GetNextItemSingle(void);
    void* GetNextItemOrdered(int current_turn);
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x10C8];
    int current_turn;
    char gap_10CC[0x18];
    int Multiplayer;
    char gap_10E8[0x3DC];
    RGE_Communications_Queue* InQ;
    char gap_14C8[0x90];
    int ProgramState;

    void* get_command(void);
};
#endif // COM_HAND_TU_CONTEXT


void* TCommunications_Handler::get_command(void) {
    if (this->Multiplayer == 0) {
        return this->InQ->GetNextItemSingle();
    }
    if (this->PlayerOptions.ProgramState == 3) {
        return this->InQ->GetNextItemSingle();
    }
    return this->InQ->GetNextItemOrdered(this->current_turn);
}
