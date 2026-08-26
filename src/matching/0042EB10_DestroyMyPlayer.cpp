// probe 3: COM-style vtable surface for the DirectPlay object at 62C5EC; self player id at 62CF04

struct DirectPlay;

#if !defined(COM_HAND_TU_CONTEXT)
struct DirectPlayVtbl {
    char gap_00[0x24];
    long (__stdcall* destroyMyPlayer)(DirectPlay* self, int playerId);
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
struct DirectPlay {
    DirectPlayVtbl* lpVtbl;
};
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Comm_Error {
public:
    void ShowReturn(long param_1, char* param_2);
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x10E0];
    unsigned int Me;
    char gap_10E4[0x3FC];
    RGE_Comm_Error* Err;

protected:
    long DestroyMyPlayer();
};
#endif // COM_HAND_TU_CONTEXT


extern DirectPlay* g_comm_player_bits; // 62C5EC
extern int g_self_player;              // 62CF04

long TCommunications_Handler::DestroyMyPlayer()
{
    long result;

    if (g_comm_player_bits == 0)
        return 0;

    if (g_self_player == 0)
        return 0;

    result = g_comm_player_bits->lpVtbl->destroyMyPlayer(g_comm_player_bits, g_self_player);
    this->Err->ShowReturn(result, (char*)0x582FA8);
    if (result == 0) {
        g_self_player = result;
        this->Me = result;
    }
    return result;
}
