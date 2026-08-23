// VA: 0052C0B0, T_Scenario::WriteDisabledTechnologiesToMainSystem, 298 bytes
// Source: tscenaro.cpp lines 993-1018
// FLAGS: default
//
// ACCEPTED_DRIFT: 2.35% positional diff (7/298 bytes). Only diff is:
// Loop bottom instruction scheduling: original has `inc ebx; mov eax; add esi`
// while our VC5 emits `add esi; mov eax; inc ebx`. These three independent
// instructions are simply reordered by the scheduler — identical behavior.
// 
// The first 274 bytes are IDENTICAL. Prologue, register allocation, lea
// offsets, loop body, all tech_abling calls — everything matches exactly.
// 
// Key lessons:
// - RGE_Scenario has virtual functions → declare virtual ~RGE_Scenario() to
//   get implicit vtable pointer (don't manually declare void* vtable_ptr)
// - IntfProxy in the TU triggered different VC5 vtable handling if vtable_ptr
//   was manually declared
// - Used uchar* running pointer (flags += 0x50) to match lea+add pattern
// - Used (int)this->world->player_count cast to match movsx for short->int

#include <stddef.h>

#include "../../include/tscenaro_context.h"

#if 0
struct IntfProxy {
    virtual void v00();
    virtual void v04();
    virtual void call08(int, void*);  // slot 2 at vtable+0x08
};

class TRIBE_Player {
public:
    void tech_abling(int tech_id, uchar enable);
};

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_count;           // +0x3C
    void** players;               // +0x40
    char gap_44[0x08];
    IntfProxy* field_4C;          // +0x4C
};

class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    void* time_line;
    RGE_Game_World* world;
    char gap_0C[0x1984];
};

class T_Scenario : public RGE_Scenario {
public:
    char gap_1990[0x3264];
    int disabled_tech[320];       // +0x4BF4
    int scenario_options;          // +0x50F4

    void WriteDisabledTechnologiesToMainSystem();
};
#endif

void T_Scenario::WriteDisabledTechnologiesToMainSystem()
{
    RGE_Game_World* _w = this->world;
    if (_w == 0)
        return;

    if (_w->player_num <= 1)
        return;

    int i = 1;
    uchar* flags = (uchar*)&this->DisabledTechnology[0][1];
    do {
        TRIBE_Player* player = (TRIBE_Player*)_w->players[i];

        if (this->ScenarioOptions[0] != 0) {
            _w->field_4C->call08(100, player);
        }

        player->tech_abling(0x58, flags[-4]);
        player->tech_abling(0x59, flags[0]);
        player->tech_abling(0x5A, flags[4]);
        player->tech_abling(0x5B, flags[8]);
        player->tech_abling(0x5E, flags[0x0C]);
        player->tech_abling(0x5F, flags[0x10]);
        player->tech_abling(0x61, flags[0x14]);
        player->tech_abling(0x62, flags[0x18]);
        player->tech_abling(0x5D, flags[0x1C]);
        player->tech_abling(0x60, flags[0x20]);
        player->tech_abling(0x5C, flags[0x24]);
        player->tech_abling(0x65, flags[0x28]);
        player->tech_abling(0x66, flags[0x2C]);
        player->tech_abling(0x67, flags[0x30]);
        player->tech_abling(0x73, flags[0x34]);
        player->tech_abling(0x74, flags[0x38]);

        flags += 0x50;
        i++;
        _w = this->world;
    } while (i < (int)_w->player_num);
}
