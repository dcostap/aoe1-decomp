// tplayer.cpp:1310-1323, 111 bytes
// attempt 1: 52.3%, no vfunc
// attempt 2: 30.6%, vfunc at wrong offset
// attempt 3: 28.8%, 44 vfuncs fixed offset to 0xAC
// attempt 4: compile error, ref param
// attempt 5: 28.8%, same
// BEST: 28.8%. BLOCKER: stack offsets off by 4 in command_unload
//   call params. Core logic (vfunc at 0xAC, command_unload, free) correct.
#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Static_Object;
class TRIBE_Command { public: char gap_00[0x58]; void* command_obj; };
class TRIBE_Command_Unload { public: void command_unload(RGE_Static_Object** list, short list_num, float param_1, float param_2); };

class RGE_Static_Object {
public:
    virtual void dispose();
    virtual void recycle_in_to_game(); virtual void recycle_out_of_game();
    virtual void draw(); virtual void shadow_draw(); virtual void normal_draw();
    virtual void draw_front_frame(); virtual void draw_back_frame(); virtual void draw_frame();
    virtual void update(); virtual void check_damage_sprites(); virtual void rehook();
    virtual void save(int); virtual void teleport(); virtual void new_sprite();
    virtual void add_overlay_sprite(); virtual void remove_overlay_sprite();
    virtual void change_ownership(); virtual void modify(); virtual void modify_delta();
    virtual void modify_percent(); virtual void transform(); virtual void copy_obj();
    virtual void set_object_state(); virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying(); virtual void destroy_obj();
    virtual void die_die_die(); virtual void damage(); virtual void calculateDamage();
    virtual void rotate(); virtual void can_attack(); virtual void set_attribute();
    virtual void set_attribute_amount(); virtual void heal(); virtual void canRepair();
    virtual void notify_of_relation(); virtual void do_command(); virtual void move_to();
    virtual void work(); virtual void stop(); virtual void set_attack();
    virtual void play_command_sound();
};

extern void __cdecl free(void*);

class TRIBE_Player {
public:
    char gap_00[0x3C];
    TRIBE_Command* command;

    unsigned char get_selected_objects_to_command(RGE_Static_Object*** list, void* local_4, int a, int b, int c, int d);
    unsigned char command_make_unload(float, float);
};
#endif

unsigned char TRIBE_Player::command_make_unload(float param_1, float param_2) {
    RGE_Static_Object** list;
    short list_num;
    short local_4[2];

    if (get_selected_objects_to_command(&list, local_4, 4, -1, -1, 7)) {
        list[0]->play_command_sound();
        ((TRIBE_Command_Unload*)command->command_obj)->command_unload(list, local_4[0], param_1, param_2);
        free(list);
        return 1;
    }
    return 0;
}
