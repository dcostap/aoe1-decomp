// attempt log:
// first pass: natural local list/list_num spelling around the selection helper and follow-up command dispatch
// second pass: switch to the decompiler-ish local_4 array spelling to mirror the helper call/stack shape
// third pass: explicitly copy the returned short into list_num before the command dispatch
// fourth pass: revert to the original fallthrough success block so the branch layout matches the asm
// target shape: get selected objects, call the selected object's +0xAC vfunc, forward to command_stop, free the list, return 1/0

void __cdecl free(void*);

#ifndef PLAYER_GROUPED_TU
class RGE_Static_Object;
class RGE_Command;

class SelectedObject {
public:
    void play_move_sound(void);
};

class RGE_Command {
public:
    void command_stop(RGE_Static_Object** list, short list_num);
};

class PlayerWorld {
public:
    char gap_00[0x58];
    RGE_Command* commands;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    PlayerWorld* world;

    unsigned char get_selected_objects_to_command(RGE_Static_Object*** list, short* list_num, int a, int b, int c, int d);
    unsigned char command_stop(void);
};
#endif

unsigned char RGE_Player::command_stop(void) {
    RGE_Static_Object** list;
    short local_4[2];

    if (this->get_selected_objects_to_command(&list, local_4, 3, -1, -1, -1)) {
        (*list)->play_move_sound();
        this->world->command->command_order(list, local_4[0], 0, 0.0f, 0.0f);
        free(list);
        return 1;
    }

    return 0;
}
