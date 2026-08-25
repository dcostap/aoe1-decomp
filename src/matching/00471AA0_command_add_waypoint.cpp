// target: VA 00471AA0 RGE_Player::command_add_waypoint(float,float,float)
// first pass: selected-object list, virtual pre-command call, waypoint command, free list.

extern "C" void __cdecl free(void* ptr);
extern "C" long __cdecl _ftol(void);

#ifndef PLAYER_GROUPED_TU
class RGE_Static_Object {
public:
    void play_move_sound();
};

class RGE_Command {
public:
    void command_group_waypoint(RGE_Static_Object** list, short list_num, int x, int y);
};

class RGE_World {
public:
    char gap_00[0x58];
    RGE_Command* commands;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_World* world;

    unsigned char get_selected_objects_to_command(RGE_Static_Object*** list, short* list_num, int, int, int, int);
    unsigned char command_add_waypoint(float x, float y, float z);
};
#endif

unsigned char RGE_Player::command_add_waypoint(float x, float y, float z) {
    RGE_Static_Object** list;
    short list_num;

    if (this->get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1)) {
        list[0]->play_move_sound();
        this->world->command->command_group_waypoint(list, list_num, (int)x, (int)y);
        free(list);
        return 1;
    }
    return 0;
}
