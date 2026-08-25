#ifndef PLAYER_GROUPED_TU
class RGE_Static_Object {
public:
    void play_move_sound();
};
class RGE_Command {
public:
    void command_order(RGE_Static_Object**, short, RGE_Static_Object*, float, float);
};
class RGE_Game_World {
public:
    char gap_00[0x58];
    RGE_Command* command;
};
class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    unsigned char get_selected_objects_to_command(RGE_Static_Object***, void*, int, int, int, int);
    unsigned char command_make_do(RGE_Static_Object*, float, float);
};
#endif

extern void __cdecl free(void*);

unsigned char RGE_Player::command_make_do(RGE_Static_Object* target, float x, float y) {
    RGE_Static_Object** list;
    short local_4[2];
    if (get_selected_objects_to_command(&list, local_4, -1, -1, -1, -1)) {
        list[0]->play_move_sound();
        this->world->command->command_order(list, local_4[0], target, x, y);
        free(list);
        return 1;
    }
    return 0;
}
