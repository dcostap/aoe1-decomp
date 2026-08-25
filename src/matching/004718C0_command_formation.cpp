// 004718C0 RGE_Player::command_formation
// Pattern from neighboring matched command_* helpers.

void __cdecl free(void*);

#ifndef PLAYER_GROUPED_TU
class RGE_Static_Object;

class SelectedObject {
public:
    void play_move_sound(void);
};

class RGE_Command {
public:
    void command_formation(RGE_Static_Object** list, int list_num, int formation);
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
    unsigned char command_formation(int formation);
};
#endif

unsigned char RGE_Player::command_formation(int formation) {
    RGE_Static_Object** list;

    if (formation >= 0 && formation <= 5) {
        int iVar1 = formation;
        if (this->get_selected_objects_to_command(&list, (short*)&formation, -1, -1, -1, -1)) {
            (*list)->play_move_sound();
            this->world->command->command_formation(list, *(short*)&formation, iVar1);
            free(list);
            return 1;
        }
    }

    return 0;
}
