// VA: 0049D550 TRIBE_Screen_Info::TRIBE_Screen_Info
// scr_info.cpp lines 32-52

// Attempt log:
// 1-2: Existing natural constructor with /GX had exact size 142 but broad scheduling/register drift around timer/auto_close/vptr/setup.
// 3: Fixed RGE_Base_Game layout so draw_area is at +0x4C; call surface now matches original memory offset, but constructor scheduling still off.
// 4: Tried __declspec(novtable) plus manual vptr store at original source point; vptr placement improved locally but EH state store still stayed before setup rather than before vptr, and auto_close used EDX result family; rolled back.
// 5: Added explicit derived virtual destructor declaration; no EH-state scheduling change.
// 6: Tried `timer_val != 0` / if-else auto_close spelling; worsened to setne family, rolled back.
// 7: Tried volatile zero to force explicit zero local/registers; worsened with stack zero homes, rolled back.
// 8: Tried saved `p2` local and zero local for setup argument pressure; minor register/order changes only.
// 2026-05-19 later pass:
// 9: Re-tried novtable/manual vptr with current p2/zero source; vptr placed earlier but worsened to 76 positional bytes and still used ECX/EDX wrong for auto_close/setup scheduling.
// 10: Removed derived virtual declarations while using novtable/manual vptr; no improvement over try 9, rolled back.
// Retry 2026-05-19 assigned pass:
// 11: separate zero/zero2 locals no change.
// 12: timer_val != 0 spelling produced setne family and worsened to 78 positional bytes; rolled back.
// 13: volatile param2 local also forced setne/bad scheduling; rolled back.
// 14: explicit negative boolean added double neg and worsened; rolled back.
// 15: /Ob0 no codegen change; preserved original custom /GX flags only.
// 16: explicit param3 local and moving p2/p3 declarations around setup did not affect argument scheduling.
// 17: intentionally swapped setup args improved edit diff slightly but is semantically wrong; rolled back.
// 18: /O1 worsened to 103 positional bytes; rolled back.
// 19: novtable/manual vptr improved local vptr placement but worsened positional diff and still scheduled vptr before sbb/state; rolled back.
// 20: auto_close temp and signed zero locals no codegen change.
// GIVEUP: exact size but no match. Existing custom flags file remains /nologo /c /O2 /Oy /GX. Remaining mismatch is broad constructor body scheduling: original zeros EDX/ECX, stores timer, loads param2 into EDX, emits cmp/sbb/neg auto_close with local_4 state before vptr; rebuilt keeps vptr/state and setup arg scheduling in a different basin. No accepted_drift proposed.

class TPanel {
public:
    virtual ~TPanel();
    int handle_idle();
    char gap_04[0x474];
};

class TScreenPanel : public TPanel {
public:
    virtual ~TScreenPanel();
    TScreenPanel(int param);
    int setup(void* draw_area, char* param2, void* param3, int zero);
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    void* draw_area;  // +0x4C
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Info : public TScreenPanel {
public:
    int auto_close;           // +0x478
    unsigned int timer;       // +0x47C
    unsigned int last_time;   // +0x480

    virtual ~TRIBE_Screen_Info();
    void close_screen();
    TRIBE_Screen_Info(char* name, char* param2, long param3, unsigned long timer_val);
};

TRIBE_Screen_Info::TRIBE_Screen_Info(char* name, char* param2, long param3, unsigned long timer_val)
    : TScreenPanel((int)name) {
    int zero = 0;
    this->timer = timer_val;
    int ac = (zero < timer_val);
    this->auto_close = ac;
    this->last_time = zero;
    char* p2 = param2;
    void* p3 = (void*)param3;
    int result = TScreenPanel::setup(rge_base_game->draw_area, p2, p3, zero);
    if (result == 0) {
        *(int*)((char*)this + 0xD8) = 1;
    }
}
