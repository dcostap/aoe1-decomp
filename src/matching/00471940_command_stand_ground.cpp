// VA: 00471940 RGE_Player::command_stand_ground
// PDB: player.cpp lines 2459-2490 (138 bytes, 51 asm lines)
// MATCH: `python tools/check_function.py --va 00471940` -> 0.0000%.
// Key fixes 2026-05-19:
// - get_selected_objects_to_command's list-count out parameter must be modeled as int*,
//   not short*, so stack locals place list at [esp+4] and the other out slot at [esp].
// - command_group_ai_order's first two player-id parameters must be int, not short;
//   this forces VC5 to emit `movsx eax, word [esi+4Ah]` before the pushes instead of
//   delaying a 16-bit load until the call setup.

extern "C" void __cdecl free(void*);

#ifndef PLAYER_GROUPED_TU
class RGE_Static_Object {
public:
    void play_move_sound();
};

class RGE_Command {
public:
    void command_group_ai_order(int, int, RGE_Static_Object**, short, int, int, int, float, float, float, float, unsigned char, unsigned char, unsigned char);
};

class RGE_World {
public:
    char gap[0x58];
    RGE_Command* commands;
};

class RGE_Player {
public:
    char gap00[0x3c];
    RGE_World* world;
    char gap40[0x0a];
    short id;

    unsigned char get_selected_objects_to_command(RGE_Static_Object*** list, int* listNum, int, int, int, int);
    unsigned char command_stand_ground();
};
#endif

unsigned char RGE_Player::command_stand_ground() {
    RGE_Static_Object** list;
    int listNum;
    int local_4;

    if (get_selected_objects_to_command(&list, &listNum, -1, -1, -1, -1)) {
        list[0]->play_move_sound();
        this->world->command->command_group_ai_order(this->id, this->id, list, (short)local_4, 0x2d5, -1, -1, -1.0f, -1.0f, -1.0f, 1.0f, 1, 0, 100);
        free(list);
        return 1;
    }

    return 0;
}
