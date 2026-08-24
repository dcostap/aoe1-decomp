// RGE_Action::get_state_name
// VA: 00407C10
// Accepted drift: the two strcpy tails retain a four-byte register swap.

#include "../../include/action_context.h"
#include "../../include/game_globals.h"
#include <string.h>

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
