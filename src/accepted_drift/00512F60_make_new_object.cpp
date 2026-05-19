// 00512F60 TRIBE_Player::make_new_object (tplayer.cpp:905-926, 151B)
// STATUS: pending accepted_drift (waiting for Boss approval)
// FLAGS: default
//
// Attempt log (2026-05-19):
// try 1: first pass - 70.86% positional mismatch, wrong param use (z vs y in check_destructables)
// try 2: fixed check_destructables to use y instead of z - prologue matches up to offset 42
// try 3: VirtualTarget vtable approach - vtable call at end matches exactly
// try 4: goto end + no virtual keyword - 149/151 bytes match! Only 2 bytes: ecx vs eax for group ptr
// try 5: group_ptr variable to force ecx - disturbed register allocation, made things worse
// try 6: separate local for group_sub_type - same 2-byte diff persists
// Remaining: 2 bytes at offsets 0x6E/0x72 - eax vs ecx for group pointer after game->prog_mode check.
// Benign register choice; proposed accepted_drift.

struct VirtualTarget {
    virtual void vf00() = 0;
    virtual void vf04() = 0;
    virtual void vf08() = 0;
    virtual void vf0C() = 0;
    virtual void vf10() = 0;
    virtual void vf14() = 0;
    virtual void vf18() = 0;
    virtual void vfn(int a, int b) = 0;
};

class RGE_Master_Static_Object;
class TRIBE_World;

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    int prog_mode;       // +0x1B0
};

extern RGE_Base_Game* rge_base_game;

class RGE_Static_Object {
public:
    char gap_00[8];
    void* group;         // +0x08
    char gap_0C[4];
    int field_10;        // +0x10
    char gap_14[4];
    void* field_18;      // +0x18
};

class RGE_Player {
public:
    char gap_00[0x24];
    RGE_Master_Static_Object** master_objects;

    RGE_Static_Object* make_new_object(long id, float x, float y, float z, int unused);
};

class TRIBE_Building_Object : public RGE_Static_Object {
public:
    int build(float build_speed);
};

class TRIBE_World {
public:
    void check_destructables(short type, long id, float x, float y, int force);
};

class TRIBE_Player : public RGE_Player {
public:
    /* +0x28 */
    char gap_28[0x14];               // +0x28 to +0x3B
    TRIBE_World* world;              // +0x3C
    char gap_40[0x0A];               // +0x40 to +0x49
    short destructable_type;         // +0x4A

    RGE_Static_Object* make_new_object(long id, float x, float y, float z, int unused);
};

RGE_Static_Object* TRIBE_Player::make_new_object(long id, float x, float y, float z, int unused)
{
    RGE_Base_Game* game;
    RGE_Static_Object* obj = RGE_Player::make_new_object(id, x, y, z, unused);
    if (!obj)
        goto end;

    if (unused) {
        world->check_destructables(destructable_type, id, x, y, 0);

        if (*(unsigned char*)((char*)obj->group + 4) == 'P') {
            ((TRIBE_Building_Object*)obj)->build(10000.0f);
        }
    }

    game = rge_base_game;
    if (game->prog_mode == 7) {
        // Check group type using ecx-friendly approach
        void* grp = obj->group;
        short group_sub_type = *(unsigned short*)((char*)grp + 0x14);
        if (group_sub_type == 5 || group_sub_type == 0x21) {
            // call virtual function at vtable+0x1C on obj->field_18
            void* target = obj->field_18;
            int arg = obj->field_10;
            ((VirtualTarget*)target)->vfn(arg, 5);
        }
    }

end:
    return obj;
}
