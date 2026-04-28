// TRIBE_Action_Make_Tech::get_info
// VA: 004D25E0
// PDB: tact_tek.cpp:151-164
// No EH framing
// tried correcting get_name as one-arg thiscall and leaving strncpy length under the method call; call cleanup shape got closer but register allocation shifted
// tried early dest/max_len locals; still chooses ESI for this instead of original EDI/EBX/ESI topology
// current gap: needs original register topology: EDI=this, EBX=dest, ESI=max_len for the name-copy block

#include "../../include/game_globals.h"

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

void TRIBE_Action_Make_Tech::get_info(short* param_1, short* param_2, char* param_3, short param_4)
{
    char* dest = param_3;
    int max_len = param_4;

    *param_1 = this->tech_id;

    if (this->status == 1) {
        *param_2 = 100;
    } else {
        void* scenario = this->action_obj->obj_ptr;
        TRIBE_Player_Tech* player_tech = *(TRIBE_Player_Tech**)((char*)scenario + 0x220);
        *param_2 = player_tech->get_progress(this->tech_id);
    }

    if (dest) {
        void* scenario = this->action_obj->obj_ptr;
        TRIBE_Player_Tech* player_tech = *(TRIBE_Player_Tech**)((char*)scenario + 0x220);
        char* name = player_tech->get_name(this->tech_id);
        strncpy(dest, name, max_len);
        dest[max_len - 1] = 0;
    }
}
