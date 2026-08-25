#ifndef PLAYER_GROUPED_TU
class RGE_Static_Object;
class RGE_Command_Move { public: void command_move(RGE_Static_Object** list, short list_num, RGE_Static_Object* target, float x, float y); };
class RGE_Command { public: char gap_00[0x58]; RGE_Command_Move* command_obj; };
class RGE_Static_Object { public:
    void play_move_sound();
};
extern void __cdecl free(void*);
class RGE_Player { public:
    char gap_00[0x3C];
    RGE_Command* command;
    unsigned char get_selected_objects_to_command(RGE_Static_Object*** list, void* local_4, int a, int b, int c, int d);
    unsigned char command_make_move(RGE_Static_Object* target, float x, float y);
};
#endif
extern void __cdecl free(void*);
unsigned char RGE_Player::command_make_move(RGE_Static_Object* target, float x, float y) {
    RGE_Static_Object** list;
    short list_num;
    short local_4[2];
    if (get_selected_objects_to_command(&list, local_4, -1, -1, -1, -1)) {
        list[0]->play_move_sound();
        this->world->command->command_order(list, local_4[0], target, x, y);
        free(list);
        return 1;
    }
    return 0;
}
