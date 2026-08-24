// 004D3810 TRIBE_Action_Wonder::update (tact_wnd.cpp:152-179)
// 204 bytes, virtual uchar __thiscall update(void)
// FLAGS: default
//
// === Attempt log ===
// probes 1-3: baseline hand-shaped dispatch and switch-only variants; switch improved
// structural alignment but remained 192 bytes and retained wrong FPU/call ownership.
// probe 4: restored the prior natural switch/countdown nesting and f+f timer form;
// this is the best prior period-plausible reconstruction to rebaseline (28-byte drift).
// probes 5-7: switch case reordering, an explicit case-6 cleanup label, and the
// canonical RGE_Base_Game local name did not move emitted bytes.
// probe 8: positive case-2 predicate with direct return on set_state and explicit
// cleanup fallthrough recovered the original cold-case/timer-cleanup block layout.
// probe 9: long,long set_countdown_timer ABI declaration preserved the exact bytes
// and the proven decorated helper identity.
// Exact source shape is intentionally ordinary switch/guard code plus a shared
// cleanup label: the label expresses the binary-proven FPU cleanup before the
// common return and is not register/byte steering or an asm substitute.

#include "../../include/game_globals.h"

#ifndef TACT_WND_CONTEXT_H
class RGE_Action {
public:
    virtual ~RGE_Action();
};

class RGE_Game_World {
public:
    char gap_00[0x1E];
    unsigned char wonder_state;          // +0x1E
    char gap_1F[0x65];
    float world_time_delta_seconds;      // +0x84
    char gap_88[0x80];
    int countdown_active;                // +0x108
};

class RGE_Base_Game {
public:
    char gap_00[0x3F4];
    RGE_Game_World* world;
    void set_countdown_timer(long a, long b);
};

extern RGE_Base_Game* rge_base_game;

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
    void win_game_now();
};

class RGE_Action_Object {
public:
    char gap_00[0x0C];
    RGE_Player* owner;
    char gap_10[0x38];
    unsigned char object_state;
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
    RGE_Action_Object* object;
    unsigned char state;
    char gap_0D[0x2C - 0x0D];
    float field_2C;

    unsigned char update();
};
#endif

static const float LIMIT = 2000.0f;

unsigned char TRIBE_Action_Wonder::update()
{
    switch (this->state) {
    case 6:
        if (this->field_2C >= LIMIT) return 0;

        {
            float f = this->object->owner->world->world_time_delta_seconds;
            this->field_2C = (f + f) + this->field_2C;

            if (rge_base_game->world->countdown_active != 0) {
                goto cleanup;
            }

            int pid = this->object->owner->id;
            rge_base_game->set_countdown_timer(pid, (int)(LIMIT - this->field_2C));

            if (this->field_2C >= LIMIT) {
                RGE_Player* pl = this->object->owner;
                pl->win_game_now();
                rge_base_game->world->wonder_state = 100;
            }
        }
        goto cleanup;

    case 2:
        if (this->object->object_state == 2) {
            this->set_state(6);
            return 0;
        }
        goto cleanup;

cleanup:
        return 0;

    default:
        return 0;
    }
}
