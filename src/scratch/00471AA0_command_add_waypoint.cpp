// VA: 00471AA0 RGE_Player::command_add_waypoint(float param_1, float param_2, float param_3)
// PDB source: player.cpp lines 2538-2551
// Default flags
//
// __thiscall: this in ecx, 3 stack params (float). ret 0Ch cleanup.
// Returns unsigned char (bool).

#include <stdlib.h>

class RGE_Player {
public:
    virtual void vf00(void) {}
    virtual void vf04(void) {}
    virtual void vf08(void) {}
    virtual void vf0C(void) {}
    virtual void vf10(void) {}
    virtual void vf14(void) {}
    virtual void vf18(void) {}
    virtual void vf1C(void) {}
    virtual void vf20(void) {}
    virtual void vf24(void) {}
    virtual void vf28(void) {}
    virtual void vf2C(void) {}
    virtual void vf30(void) {}
    virtual void vf34(void) {}
    virtual void vf38(void) {}
    virtual void vf3C(void) {}
    virtual void vf40(void) {}
    virtual void vf44(void) {}
    virtual void vf48(void) {}
    virtual void vf4C(void) {}
    virtual void vf50(void) {}
    virtual void vf54(void) {}
    virtual void vf58(void) {}
    virtual void vf5C(void) {}
    virtual void vf60(void) {}
    virtual void vf64(void) {}
    virtual void vf68(void) {}
    virtual void vf6C(void) {}
    virtual void vf70(void) {}
    virtual void vf74(void) {}
    virtual void vf78(void) {}
    virtual void vf7C(void) {}
    virtual void vf80(void) {}
    virtual void vf84(void) {}
    virtual void vf88(void) {}
    virtual void vf8C(void) {}
    virtual void vf90(void) {}
    virtual void vf94(void) {}
    virtual void vf98(void) {}
    virtual void vf9C(void) {}
    virtual void vfA0(void) {}
    virtual void vfA4(void) {}
    virtual void vfA8(void) {}
    virtual void vfAC(void) {}
    virtual void vfB0(void) {}

    char pad_3C[0x3C];
    void* world;                       // +0x3C
    char pad_40[0x58 - 0x40];
    // world->commands at world+0x58

    unsigned char command_add_waypoint(float param_1, float param_2, float param_3);
};

unsigned char RGE_Player::command_add_waypoint(float param_1, float param_2, float param_3) {
    void* list_ptr;
    short extra[2];

    typedef unsigned char (__thiscall RGE_Player::*GetSelectedFunc)(void**, short*, int, int, int, int);
    // Can't use __thiscall on function pointers... 
    // Let me try a different approach.
    
    // Use a helper class for get_selected
    struct Helper {
        unsigned char call_get_selected(RGE_Player* player, void** list_out, short* extra_out, int a, int b, int c, int d);
    };

    return 0;
}
