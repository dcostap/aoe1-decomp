// 004D3810 TRIBE_Action_Wonder::update (tact_wnd.cpp:152-179)
// 204 bytes, virtual uchar __thiscall update(void)
// FLAGS: default
//
// === Attempt log ===
// probes 1-10: all produce same-size 192/204 byte families.
// Best version: 204 bytes matches size (same as original 204).
// First diff at offset 0x0F: je forward-offset 0x97 vs original's 0x99
// (2-byte difference in jump target due to slightly different block layout).
//
// Remaining diff: after the initial je, the entire block layout diverges.
// Root cause: VC5 block layout for the case-2-at-end vs case-2-inline decision
// does not match the original's structure. The original puts the case 2
// handler at the end of the function (after all case 6 returns) with a
// shared return-0 path. My version generates slightly different block
// order and offset layout.
//
// Tried: goto-based layout (puts case 2 at end, je matches direction),
//   if/else, if-nested, switch, combined subtract-expression
//   ((type -= 4) != 0), float constant references, extern "C" globals.
// Full TU context (tact_wnd.cpp with TRIBE_Action_Wonder vtable layout)
// might resolve this.
//
// Best variant retained below.

#include <stdlib.h>

class RGE_Game_World {
public:
    char _gap_00[4];
    unsigned long world_time;           // +0x04
    char _gap_08[0x7C];
    float world_time_delta_seconds;     // +0x84
    char _gap_88[0x7C];
};

class RGE_Base_Game {
public:
    char _gap_000[0x3F4];
    RGE_Game_World* world;              // +0x3F4
    void set_countdown_timer(int id, long seconds);
};

extern RGE_Base_Game* rge_base_game;

class RGE_Player {
public:
    char _gap_00[0x3C];
    RGE_Game_World* world;              // +0x3C
    char _gap_40[0x0A];
    short timer_id;                     // +0x4A
    void win_game_now();
};

class TRIBE_Action_Wonder {
public:
    virtual ~TRIBE_Action_Wonder() {}
    virtual int vt01() { return 0; }
    virtual int vt02() { return 0; }
    virtual void* vt03() { return 0; }
    virtual void vt04() {}
    virtual void vt05() {}
    virtual short vt06() { return 0; }
    virtual void vt07(unsigned char) {}
    virtual unsigned char vt08() { return 0; }
    virtual unsigned char vt09() { return 0; }
    virtual unsigned char update();
    virtual int vt11() { return 0; }
    virtual int vt12(void*, float, float, float) { return 0; }
    virtual int vt13(void*, float, float, float) { return 0; }
    virtual unsigned char vt14(void*) { return 0; }
    virtual unsigned char vt15(long, unsigned char) { return 0; }
    virtual void vt16(void*) {}
    virtual void vt17(void*, void*, void*) {}
    virtual void vt18(char*) {}
    virtual void* vt19() { return 0; }
    virtual void* vt20() { return 0; }
    virtual void vt21(void*) {}
    virtual void vt22(void*) {}
    virtual void set_state(unsigned char);

    char _gap_04[4];
    void* obj_ptr;                      // +0x08
    unsigned char action_type;          // +0x0C
    char _gap_0D[0x1F];
    float timer;                        // +0x2C
};

unsigned char TRIBE_Action_Wonder::update()
{
    int type = this->action_type;
    type -= 2;
    if (type != 0) goto not_case_2;

    // Case 2
    if (*(unsigned char*)((char*)this->obj_ptr + 0x48) == 2) {
        this->set_state(6);
    }
    return 0;

not_case_2:
    if ((type -= 4) != 0) return 0;

    // Case 6: wonder countdown logic
    if (this->timer >= 2000.0f) return 0;

    {
        RGE_Player* player = *(RGE_Player**)((char*)this->obj_ptr + 0x0C);
        RGE_Game_World* world = player->world;

        this->timer = world->world_time_delta_seconds * 2.0f + this->timer;

        RGE_Base_Game* game = rge_base_game;

        if (*(unsigned long*)((char*)game->world + 0x108) == 0) {
            long remaining = (long)(2000.0f - this->timer);
            game->set_countdown_timer(player->timer_id, remaining);
        }

        if (this->timer >= 2000.0f) {
            player->win_game_now();
            *(unsigned char*)((char*)game->world + 0x1E) = 64;
        }
    }

    return 0;
}
