// TRIBE_Action_Wonder::update
// VA: 004D3810
// PDB: tact_wnd.cpp:152-179
//
// Attempt log:
// - draft 1: bare struct → 92% diff, wrong switch form, call conv issues
// - draft 2: fixed switch to use sub-chain, RGE_Base_Game_W class → 34%
// - draft 3: fixed timer>=2000 check nesting inside field_108 check → 13.7%
// - draft 4: inverted timer check (>= return early) → same 13.7%
// - Remaining: VC5 creates separate early exit for field_108!=0 path instead of
//   falling through to shared default exit via fstp st0. This is pure block-layout
//   choice — same logic, same size (204 bytes). Accepting as VC5 drift.
//
// Sibling: ~TRIBE_Action_Wonder (004D34F0), set_state (004D36B0)

#include "..\..\include\game_globals.h"

class RGE_Action {
public:
    virtual ~RGE_Action();
};

class RGE_Base_Game_W {
public:
    char gap_00[0x3F4];
    void* world;
    void set_countdown_timer(int a, int b);
};

class RGE_Player {
public:
    void* vtable;
    void win_game_now();
};

class TRIBE_Action_Wonder : public RGE_Action {
public:
    virtual void d1();  virtual void d2();
    virtual void d3();  virtual void d4();
    virtual void d5();  virtual void d6();
    virtual void d7();  virtual void d8();
    virtual void d9();  virtual void d10();
    virtual void d11(); virtual void d12();
    virtual void d13(); virtual void d14();
    virtual void d15(); virtual void d16();
    virtual void d17(); virtual void d18();
    virtual void d19(); virtual void d20();
    virtual void d21(); virtual void d22();
    virtual void set_state(unsigned char s);

    char gap_04[4];
    void* field_08;
    unsigned char state;
    char gap_0D[0x2C - 0x0D];
    float timer;

    unsigned char update();
};

static const float LIMIT = 2000.0f;

unsigned char TRIBE_Action_Wonder::update()
{
    switch (this->state) {
    case 2:
        if (*(unsigned char*)((char*)this->field_08 + 0x48) != 2)
            return 0;
        this->set_state(6);
        return 0;

    case 6:
        if (this->timer >= LIMIT) return 0;

        {
            float f = *(float*)(*(int*)(*(int*)((char*)this->field_08 + 0x0C) + 0x3C) + 0x84);
            this->timer = (f + f) + this->timer;

            if (*(int*)((char*)((RGE_Base_Game_W*)rge_base_game)->world + 0x108) == 0) {
                int pid = *(short*)(*(int*)((char*)this->field_08 + 0x0C) + 0x4A);
                ((RGE_Base_Game_W*)rge_base_game)->set_countdown_timer(pid, (int)(LIMIT - this->timer));

                if (this->timer >= LIMIT) {
                    RGE_Player* pl = *(RGE_Player**)((char*)this->field_08 + 0x0C);
                    pl->win_game_now();
                    *(char*)((char*)((RGE_Base_Game_W*)rge_base_game)->world + 0x1E) = 100;
                }
            }
        }
        return 0;

    default:
        return 0;
    }
}
