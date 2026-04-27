// tplayer.cpp:1310-1323, 111 bytes
// attempt 1: 52.3%, no vfunc
// attempt 2: 30.6%, vfunc at wrong offset
// attempt 3: 28.8%, 44 vfuncs fixed offset to 0xAC
// attempt 4: compile error, ref param
// attempt 5: 28.8%, same
// BEST: 28.8%. BLOCKER: stack offsets off by 4 in command_unload
//   call params. Core logic (vfunc at 0xAC, command_unload, free) correct.
class TRIBE_Command;

class RGE_Static_Object {
public:
    virtual void vf00() {}
    virtual void vf01() {}
    virtual void vf02() {}
    virtual void vf03() {}
    virtual void vf04() {}
    virtual void vf05() {}
    virtual void vf06() {}
    virtual void vf07() {}
    virtual void vf08() {}
    virtual void vf09() {}
    virtual void vf10() {}
    virtual void vf11() {}
    virtual void vf12() {}
    virtual void vf13() {}
    virtual void vf14() {}
    virtual void vf15() {}
    virtual void vf16() {}
    virtual void vf17() {}
    virtual void vf18() {}
    virtual void vf19() {}
    virtual void vf20() {}
    virtual void vf21() {}
    virtual void vf22() {}
    virtual void vf23() {}
    virtual void vf24() {}
    virtual void vf25() {}
    virtual void vf26() {}
    virtual void vf27() {}
    virtual void vf28() {}
    virtual void vf29() {}
    virtual void vf30() {}
    virtual void vf31() {}
    virtual void vf32() {}
    virtual void vf33() {}
    virtual void vf34() {}
    virtual void vf35() {}
    virtual void vf36() {}
    virtual void vf37() {}
    virtual void vf38() {}
    virtual void vf39() {}
    virtual void vf40() {}
    virtual void vf41() {}
    virtual void vf42() {}
    virtual void vf43();
};

extern void __cdecl free(void*);

class TRIBE_Player {
public:
    char gap_00[0x3C];
    TRIBE_Command* command;

    unsigned char get_selected_objects_to_command(RGE_Static_Object*** list, void* local_4, int a, int b, int c, int d);
    unsigned char command_make_unload(float, float);
};

void command_unload(TRIBE_Command* cmd, RGE_Static_Object** list, short list_num, float param_1, float param_2);

unsigned char TRIBE_Player::command_make_unload(float param_1, float param_2) {
    RGE_Static_Object** list;
    short list_num;
    short local_4[2];

    if (get_selected_objects_to_command(&list, local_4, 4, -1, -1, 7)) {
        list[0]->vf43();
        command_unload(command, list, local_4[0], param_1, param_2);
        free(list);
        return 1;
    }
    return 0;
}
