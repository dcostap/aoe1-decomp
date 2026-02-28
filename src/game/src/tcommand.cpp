#include "../include/TRIBE_Command.h"
#include "../include/TRIBE_Command_Game.h"

void TRIBE_Command::command_allied_victory(short param_1, uchar param_2) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050AD00 (debug-log side effect intentionally omitted)
    TRIBE_Command_Game* cmd = (TRIBE_Command_Game*)calloc(1, sizeof(TRIBE_Command_Game));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x67;
    cmd->game_command = 5;
    cmd->var1 = param_1;
    cmd->var2 = (short)param_2;

    this->submit(cmd, sizeof(TRIBE_Command_Game));
}

void TRIBE_Command::command_relation(short param_1, short param_2, short param_3) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050AD70 (debug-log side effect intentionally omitted)
    TRIBE_Command_Game* cmd = (TRIBE_Command_Game*)calloc(1, sizeof(TRIBE_Command_Game));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x67;
    cmd->game_command = 0;
    cmd->var1 = param_1;
    cmd->var2 = param_2;
    cmd->var3 = (float)param_3;
    cmd->var4 = param_3;

    this->submit(cmd, sizeof(TRIBE_Command_Game));
}

void TRIBE_Command::command_inventory(short param_1, short param_2, float param_3) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050AE80 (debug-log side effect intentionally omitted)
    TRIBE_Command_Game* cmd = (TRIBE_Command_Game*)calloc(1, sizeof(TRIBE_Command_Game));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x67;
    cmd->game_command = 2;
    cmd->var1 = param_1;
    cmd->var2 = param_2;
    cmd->var3 = param_3;

    this->submit(cmd, sizeof(TRIBE_Command_Game));
}

void TRIBE_Command::command_upgrade_town(short param_1) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050AEE0 (debug-log side effect intentionally omitted)
    TRIBE_Command_Game* cmd = (TRIBE_Command_Game*)calloc(1, sizeof(TRIBE_Command_Game));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x67;
    cmd->game_command = 3;
    cmd->var1 = param_1;

    this->submit(cmd, sizeof(TRIBE_Command_Game));
}

void TRIBE_Command::command_quick_build(short param_1) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050AF30 (debug-log side effect intentionally omitted)
    TRIBE_Command_Game* cmd = (TRIBE_Command_Game*)calloc(1, sizeof(TRIBE_Command_Game));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x67;
    cmd->game_command = 4;
    cmd->var1 = param_1;

    this->submit(cmd, sizeof(TRIBE_Command_Game));
}

void TRIBE_Command::command_shared_los(short param_1) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050AF80 (debug-log side effect intentionally omitted)
    TRIBE_Command_Game* cmd = (TRIBE_Command_Game*)calloc(1, sizeof(TRIBE_Command_Game));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x67;
    cmd->game_command = 7;
    cmd->var1 = param_1;

    this->submit(cmd, sizeof(TRIBE_Command_Game));
}

void TRIBE_Command::command_cheat(short param_1, short param_2) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050B0D0 (debug-log side effect intentionally omitted)
    TRIBE_Command_Game* cmd = (TRIBE_Command_Game*)calloc(1, sizeof(TRIBE_Command_Game));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x67;
    cmd->game_command = 6;
    cmd->var1 = param_1;
    cmd->var2 = param_2;

    this->submit(cmd, sizeof(TRIBE_Command_Game));
}
