// TRIBE_Action_Wonder::set_state
// VA: 004D36B0
// PDB: tact_wnd.cpp:108-148
//
// Attempt log:
// - draft 1: direct compare, rge_base_game local, null check → 84.9%
// - draft 2: switch statement, no locals → 85.8%
// - draft 3: all locals at top, sub esp,0C → 86.7%
// - draft 4: while loop with players[i] → 336 bytes (9 too short)
// - draft 5: try pointer arithmetic + for loop + no function pointer typedefs

#include "../../include/game_globals.h"

class RGE_Action {
public:
    virtual ~RGE_Action();
};

class RGE_Base_Game_W {
public:
    char gap_00[0x3F4];
    void* world;
    void set_countdown_timer(short player_id, int timeout);
};

class TRIBE_Action_Wonder : public RGE_Action {
public:
    virtual ~TRIBE_Action_Wonder();
    virtual void d2();  virtual void d3();
    virtual void d4();  virtual void d5();
    virtual void d6();  virtual void d7();
    virtual void d8();  virtual void d9();
    virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13();
    virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17();
    virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21();
    virtual void d22();
    virtual void set_state(unsigned char s);

    char gap_04[4];
    void* field_08;
    unsigned char state;

    void update();
};

void TRIBE_Action_Wonder::set_state(unsigned char param_1)
{
    this->state = param_1;

    if (param_1 == 2) {
        void* world = *(void**)((char*)rge_base_game + 0x3F4);
        short player_num = *(short*)((char*)world + 0x3C);
        void** players = *(void***)((char*)world + 0x40);
        void* vt;
        int i;

        for (i = 1; i < player_num; i++) {
            if (i != *(short*)(*(int*)(*(int*)((char*)this->field_08 + 0x0C) + 0x00) + 0x4A)) {
                vt = *(void**)this->field_08;
                ((void (__stdcall *)(void*, int, int))((void**)vt)[0xD8/4])(players[i], 1, -1);
            }
        }

        {
            void* action = this->field_08;
            short pid = *(short*)(*(int*)((char*)action + 0x0C) + 0x4A);
            float f2 = *(float*)((char*)action + 0x38);
            float f1 = *(float*)((char*)action + 0x3C);
            int r1 = (int)f2;
            int r2 = (int)f1;
            vt = *(void**)rge_base_game;
            ((void (__stdcall *)(int, int, int, int, int))((void**)vt)[0x40/4])(0x6C, pid, r1, r2, 0);
        }
        return;
    }

    if (param_1 != 6)
        return;

    {
        void* world = *(void**)((char*)rge_base_game + 0x3F4);
        short player_num = *(short*)((char*)world + 0x3C);
        void** players = *(void***)((char*)world + 0x40);
        void* vt;
        int i;

        for (i = 1; i < player_num; i++) {
            if (i != *(short*)(*(int*)(*(int*)((char*)this->field_08 + 0x0C) + 0x00) + 0x4A)) {
                vt = *(void**)this->field_08;
                ((void (__stdcall *)(void*, int, int))((void**)vt)[0xDC/4])(players[i], 1, -1);
                ((void (__stdcall *)(void*, int, int))((void**)vt)[0xD8/4])(players[i], 0, -1);
            }
        }

        if (*(int*)((char*)world + 0x108) == 0) {
            short pid = *(short*)(*(int*)((char*)this->field_08 + 0x0C) + 0x4A);
            ((RGE_Base_Game_W*)rge_base_game)->set_countdown_timer(pid, 2000);
        }

        {
            void* action = this->field_08;
            short pid = *(short*)(*(int*)((char*)action + 0x0C) + 0x4A);
            float f2 = *(float*)((char*)action + 0x38);
            float f1 = *(float*)((char*)action + 0x3C);
            int r1 = (int)f2;
            int r2 = (int)f1;
            vt = *(void**)rge_base_game;
            ((void (__stdcall *)(int, int, int, int, int))((void**)vt)[0x40/4])(0x6D, pid, r1, r2, 0);
        }
    }
}
