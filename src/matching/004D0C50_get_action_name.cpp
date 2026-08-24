// 004D0C50 TRIBE_Action_List::get_action_name
// PDB source: tact_lst.cpp:160-183
// BINARY NOTE: The list node and action type are read through the canonical
// RGE_Action_List and RGE_Action layouts before the inherited fallback.

#include "../../include/tact_lst_context.h"
#include <string.h>

void TRIBE_Action_List::get_action_name(char* dest)
{
    const char* name;
    if (this->list == 0) {
        name = "None";
        strcpy(dest, name);
        return;
    }

    switch (this->list->action->action_type) {
    case 3:
        name = "Enter";
        strcpy(dest, name);
        return;
    case 0x0C:
        name = "Transport";
        strcpy(dest, name);
        return;
    case 0x65:
        name = "Build";
        strcpy(dest, name);
        return;
    case 0x66:
        name = "MakeObject";
        strcpy(dest, name);
        return;
    case 0x67:
        name = "MakeTech";
        strcpy(dest, name);
        return;
    case 0x68:
        name = "Convert";
        strcpy(dest, name);
        return;
    case 0x69:
        name = "Heal";
        strcpy(dest, name);
        return;
    case 0x6A:
        name = "Repair";
        strcpy(dest, name);
        return;
    case 0x6B:
        name = "Artifact";
        strcpy(dest, name);
        return;
    case 0x6C:
        name = "DiscoveryArtifact";
        strcpy(dest, name);
        return;
    case 0x6E:
        name = "Hunt";
        strcpy(dest, name);
        return;
    case 0x6F:
        name = "Trade";
        strcpy(dest, name);
        return;
    default:
        RGE_Action_List::get_action_name(dest);
        return;
    }
}
