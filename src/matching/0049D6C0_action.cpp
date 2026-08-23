// BINARY NOTE: the direct base target is TEasy_Panel::action.
#include "../../include/scr_info_context.h"

long TRIBE_Screen_Info::action(TPanel* panel, long command,
                               unsigned long param3, unsigned long param4)
{
    return TEasy_Panel::action(panel, command, param3, param4);
}
