// 00425800 TCommunications_Handler::WaitingOnInfo
// Source: Com_hand.cpp lines 155-201, size 211 bytes
// char* WaitingOnInfo(unsigned int param_1)

// ——— Globals ———
extern void* rge_base_game;               // 0x0062C574 — RGE_Base_Game* pointer
extern char g_status_buffer[0x20];         // 0x0062C588 — string output buffer

// ——— RGE_Base_Game stub (vtable layout only, vt[8] = get_string) ———
struct RGE_Base_Game_Stub {
    void* vtable_ptr;

    virtual ~RGE_Base_Game_Stub() {}
    virtual int func01() { return 0; }
    virtual long func02(void*, unsigned int, unsigned int, long) { return 0; }
    virtual void func03(int) {}
    virtual void func04(int, int) {}
    virtual void func05(short) {}
    virtual int func06() { return 0; }
    virtual char* func07(int, long, char*, int) { return 0; }
    virtual char* get_string(long param_1, char* param_2, int param_3) { return 0; } // vt[8] = 0x20
};

// ——— TCommunications_Handler stub ———
class TCommunications_Handler {
    char pad_0000[0x10C8];
public:
    unsigned long current_turn;            // +0x10C8
    char pad_10CC[0x1720 - 0x10CC];
    unsigned long LastTurnAck[10];         // +0x1720

    int IsPlayerComputer(unsigned int param_1);
    int IsPlayerHuman(unsigned int param_1);
    char* WaitingOnInfo(unsigned int param_1);
};

char* TCommunications_Handler::WaitingOnInfo(unsigned int param_1)
{
    unsigned int player = param_1;

    if (IsPlayerComputer(player)) {
        ((RGE_Base_Game_Stub*)rge_base_game)->get_string(0x4B1, g_status_buffer, 0x20);
        return g_status_buffer;
    }
    if (!IsPlayerHuman(player)) {
        ((RGE_Base_Game_Stub*)rge_base_game)->get_string(0x4B2, g_status_buffer, 0x20);
        return g_status_buffer;
    }
    if (LastTurnAck[player] < 4) {
        ((RGE_Base_Game_Stub*)rge_base_game)->get_string(0x4B3, g_status_buffer, 0x20);
        return g_status_buffer;
    }
    if (LastTurnAck[player] < current_turn) {
        ((RGE_Base_Game_Stub*)rge_base_game)->get_string(0x4B4, g_status_buffer, 0x20);
        return g_status_buffer;
    }

    ((RGE_Base_Game_Stub*)rge_base_game)->get_string(0x4B0, g_status_buffer, 0x20);
    return g_status_buffer;
}
