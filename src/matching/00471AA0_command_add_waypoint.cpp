// target: VA 00471AA0 RGE_Player::command_add_waypoint(float,float,float)
// first pass: selected-object list, virtual pre-command call, waypoint command, free list.

extern "C" void __cdecl free(void* ptr);
extern "C" long __cdecl _ftol(void);

class RGE_Static_Object {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vfAC();
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

unsigned char RGE_Player::command_add_waypoint(float x, float y, float z) {
    RGE_Static_Object** list;
    short list_num;

    if (this->get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1)) {
        list[0]->vfAC();
        this->world->commands->command_group_waypoint(list, list_num, (int)x, (int)y);
        free(list);
        return 1;
    }
    return 0;
}
