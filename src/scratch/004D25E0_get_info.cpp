// TRIBE_Action_Make_Tech::get_info
// VA: 004D25E0
// PDB: tact_tek.cpp:151-164
// No EH framing

#include "../../include/game_globals.h"

extern "C" void __cdecl local_copy(char* dest, char* src, int maxlen);

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
    char* get_name(short tech_id, short max_len);
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
    *param_1 = this->tech_id;

    if (this->status == 1) {
        *param_2 = 100;
    } else {
        void* scenario = this->action_obj->obj_ptr;
        TRIBE_Player_Tech* player_tech = *(TRIBE_Player_Tech**)((char*)scenario + 0x220);
        *param_2 = player_tech->get_progress(this->tech_id);
    }

    if (param_3) {
        void* scenario = this->action_obj->obj_ptr;
        TRIBE_Player_Tech* player_tech = *(TRIBE_Player_Tech**)((char*)scenario + 0x220);
        char* name = player_tech->get_name(this->tech_id, param_4);
        local_copy(param_3, name, param_4);
        param_3[param_4 - 1] = 0;
    }
}
