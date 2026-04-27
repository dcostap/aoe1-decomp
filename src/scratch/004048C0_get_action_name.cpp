// RGE_Action_List::get_action_name
// VA: 004048C0
// PDB: act_list.cpp:529-548
//
// Attempt log:
// - draft 1: switch + strcpy, case values 1,4,5,8,9,10,14,15 → 21% diff.
//   VC5 generates compact direct jump table (cmp eax, 0Eh = 14 entries).
//   Original uses sparse byte-table dispatch (cmp eax, 14h = 21 entries).
// - draft 2: different case values → 39% diff
// - draft 3: added fall-through cases for unused values → same 39% diff
// - Remaining diff: fundamental switch dispatch strategy difference between VC5 and the original compiler.
//   The original compiler (possibly a different VC5 version or flag set) chose sparse byte-table dispatch,
//   while this VC5 uses a compact dispatch. Can't fix through source refactoring.
// Left in scratch.

#include "..\..\include\game_globals.h"
#include <string.h>

class RGE_Action {
public:
    char gap_00[4];
    short action_type;
};

class RGE_Action_Node {
public:
    RGE_Action* action;
};

class RGE_Action_List {
public:
    char gap_00[8];
    RGE_Action_Node* list;

    void get_action_name(char* dest);
};

void RGE_Action_List::get_action_name(char* dest)
{
    const char* name;

    if (this->list) {
        switch (this->list->action->action_type) {
            case 1:  name = "MoveTo";  break;
            case 4:  name = "Explore"; break;
            case 5:  name = "Gather";  break;
            case 8:  name = "Missile"; break;
            case 9:  name = "Attack";  break;
            case 10: name = "Bird";    break;
            case 14: name = "RunAway"; break;
            case 15: name = "Make";    break;
            default: name = "Unknown"; break;
        }
    } else {
        name = "None";
    }

    strcpy(dest, name);
}
