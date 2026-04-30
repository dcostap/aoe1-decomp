// RGE_Action::get_state_name
// VA: 00407C10
// PDB: action.cpp:441-462
// 98.15% match. 4 bytes diff: register swap (edx↔eax) in two strcpy tails.
// odd_copy tail uses mov edx,ecx (original) vs mov eax,ecx (rebuilt)
// even_copy tail uses mov eax,ecx (original) vs mov edx,ecx (rebuilt)
// This is a VC5 register-allocation quirk — source-side attempts
// (label order, block scopes, case ordering, goto targets) all fail.
// 18 relocations masked (string addresses + jump table).

#include "../../include/game_globals.h"
#include <string.h>

class RGE_Action_List;

class RGE_Action {
public:
    void* vtable_ptr;
    short action_type;
    char gap_06[2];
    void* obj;
    unsigned char state;
    char gap_0D[3];
    void* target_obj;
    void* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    void* task;
    RGE_Action_List* sub_actions;
    void* sprite;
    unsigned char subActionValue;
    char gap_3D[3];

    void get_state_name(char* buf);
};

void RGE_Action::get_state_name(char* buf)
{
    const char* s;

    switch (this->state) {
    case 0:
        s = "None";
        goto even_copy;
    case 1:
        s = "Done";
        goto odd_copy;
    case 2:
        s = "Wait";
        goto even_copy;
    case 3:
        s = "Search";
        goto odd_copy;
    case 4:
        s = "Goto";
        goto even_copy;
    case 5:
        s = "Goto2";
        goto odd_copy;
    case 6:
        s = "Work";
        goto even_copy;
    case 7:
        s = "Work2";
        goto odd_copy;
    case 8:
        s = "Return";
        goto even_copy;
    case 9:
        s = "Turn";
        goto odd_copy;
    case 10:
        s = "Delay";
        goto even_copy;
    case 11:
        s = "Move";
        goto odd_copy;
    case 12:
        s = "Attack";
        goto even_copy;
    case 13:
        s = "Failed";
        goto odd_copy;
    case 14:
        s = "Invalidated";
        goto even_copy;
    case 15:
        s = "MoveNoSearch";
        goto odd_copy;
    default:
        s = "Unknown";
        goto even_copy;
    }

odd_copy:
    strcpy(buf, s);
    return;

even_copy:
    strcpy(buf, s);
    return;

}
