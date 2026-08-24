// TRIBE_Action_Make_Tech::get_info
// VA: 004D25E0
// PDB: tact_tek.cpp:151-164
// No EH framing
// tried correcting get_name as one-arg thiscall and leaving strncpy length under the method call; call cleanup shape got closer but register allocation shifted
// tried early dest/max_len locals; still chooses ESI for this instead of original EDI/EBX/ESI topology
// register self/local dest/max_len and nested strncpy(get_name(...)) reached a one-byte SIB-only diff in the final terminator store
// final-store variant lab tried subscript/pointer/cast forms; all best forms kept the same [esi+ebx-1] vs original [ebx+esi-1] encoding
// ACCEPTED_DRIFT: remaining diff is only SIB base/index order for `dest[max_len - 1] = 0`; EBX and ESI are added symmetrically with scale 1, so the memory address and all calls/stack/return behavior are equivalent

#include "../../include/game_globals.h"
#include "../../include/tact_tek_context.h"

#ifndef AOE1_TACT_TEK_CONTEXT_H
extern "C" char* __cdecl strncpy(char* dest, const char* src, unsigned int maxlen);

class RGE_Action_Object {
public:
    char gap_00[4];
    int player_id;       // +0x04
    char gap_08[4];
    void* obj_ptr;       // +0x0C
};

class TRIBE_Player_Tech {
public:
    short get_progress(short tech_id);
    char* get_name(short tech_id);
};

class RGE_Action {
public:
    char gap_00[8];
    RGE_Action_Object* action_obj;  // +0x08
    unsigned char status;            // +0x0C
    char pad_0D[0x40 - 0x0D];
    short tech_id;                   // +0x40
    char pad_42[2];
    int unique_id;                   // +0x44
};

class TRIBE_Action_Make_Tech : public RGE_Action {
public:
    void get_info(short* param_1, short* param_2, char* param_3, short param_4);
};
#endif

void TRIBE_Action_Make_Tech::get_info(short& param_1, short& param_2, char* param_3, short param_4)
{
    register TRIBE_Action_Make_Tech* self = this;
    char* dest = param_3;

    param_1 = self->tech_id;

    if (self->status == 1) {
        param_2 = 100;
    } else {
        void* scenario = self->action_obj->obj_ptr;
        TRIBE_Player_Tech* player_tech = *(TRIBE_Player_Tech**)((char*)scenario + 0x220);
        param_2 = player_tech->get_progress(self->tech_id);
    }

    if (dest) {
        int max_len = param_4;
        void* scenario = self->action_obj->obj_ptr;
        TRIBE_Player_Tech* player_tech = *(TRIBE_Player_Tech**)((char*)scenario + 0x220);
        strncpy(dest, player_tech->get_name(self->tech_id), max_len);
        dest[max_len - 1] = 0;
    }
}
