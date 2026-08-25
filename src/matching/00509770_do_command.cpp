// VA: 00509770 TRIBE_Command::do_command
// PDB: tcommand.cpp lines 62-125.

#include "../tcommand_context.h"

extern "C" int __cdecl debug_rand(const char* file, int line);

void TRIBE_Command::do_command(void* cmd)
{
    debug_rand("C:\\msdev\\work\\age1_x1\\tcommand.cpp", 0x3F);
    switch (*(unsigned char*)cmd) {
    case 0x64:
        do_command_make((TRIBE_Command_Make*)cmd);
        return;
    case 0x65:
        do_command_research((TRIBE_Command_Research*)cmd);
        return;
    case 0x66:
        do_command_build((TRIBE_Command_Build*)cmd);
        return;
    case 0x69:
        do_command_build_wall((TRIBE_Command_Build_Wall*)cmd);
        return;
    case 0x68:
        do_command_explore((TRIBE_Command_Explore*)cmd);
        return;
    case 0x67:
        do_command_game((TRIBE_Command_Game*)cmd);
        return;
    case 0x04:
        do_command_tribe_create((RGE_Command_Create*)cmd);
        return;
    case 0x6A:
        do_command_cancel_build((TRIBE_Command_Cancel_Build*)cmd);
        return;
    case 0x6B:
        do_command_attack_ground((TRIBE_Command_Attack_Ground*)cmd);
        return;
    case 0x6C:
        do_command_give_attribute((TRIBE_Command_Give_Attribute*)cmd);
        return;
    case 0x6D:
        do_command_trade_attribute((TRIBE_Command_Trade_Attribute*)cmd);
        return;
    case 0x6E:
        do_command_repair((TRIBE_Command_Repair*)cmd);
        return;
    case 0x6F:
        do_command_unload((TRIBE_Command_Unload*)cmd);
        return;
    case 0x77:
        do_command_queue((TRIBE_Command_Queue*)cmd);
        return;
    default:
        RGE_Command::do_command(cmd);
        return;
    }
}
