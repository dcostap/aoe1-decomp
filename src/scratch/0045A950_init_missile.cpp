// VA: 0045A950 RGE_Missile_Object::init_missile (137 B)
// PDB source: misl_obj.cpp lines 100-109
// Attempt log:
// - Original has SEH frame (FS:[0] prologue) with try level management
// - Without try/catch: VC5 compiles 96 bytes, NO EH frame (even with /GX + destructor)
// - With try/catch {}: VC5 compiles EBP-based EH frame (different from original's ESP-based)
// - #include <new.h>: no change
// - new RGE_Action_Missile() with parens: no change
// - Non-inline destructor body: no change
// - Struct sizing fixed (pad[0x50] for 0x54 total, gap 0x3C for max_range at +0x1C4)
// Left in scratch: VC5 EH frame generation mismatch — compiler doesn't emit FS:[0] frame
// for this pattern even with /GX and non-trivial destructor.

struct RGE_Action_Object {
    void* vtable;
};

struct RGE_Combat_Object {
    void* vtable;
};

struct RGE_Static_Object {
    void* vtable;
    char gap_00[0x34];
    float world_x;   // +0x38
    float world_y;   // +0x3C
    float world_z;   // +0x40
};

struct RGE_Action_Missile : RGE_Action_Object {
    char pad[0x50];
    ~RGE_Action_Missile();
    void init(RGE_Action_Object* owner, RGE_Combat_Object* target,
              RGE_Static_Object* src_obj, float wx, float wy, float wz);
};

RGE_Action_Missile::~RGE_Action_Missile() { int x = 0; (void)x; }

struct RGE_Action_List {
    int some_field;
    void add_action(RGE_Action_Object* action);
};

struct RGE_Missile_Object {
    void* vtable;
    char gap_00[0x180];
    RGE_Action_List* action_list; // +0x184
    char pad_184_to_1C4[0x3C];
    float max_range; // +0x1C4

    void init_missile(RGE_Combat_Object* target, RGE_Static_Object* src_obj, float range);
};

void RGE_Missile_Object::init_missile(RGE_Combat_Object* target, RGE_Static_Object* src_obj, float range)
{
    RGE_Action_Missile* obj = new RGE_Action_Missile;
    if (obj) {
        float wx = src_obj->world_x;
        float wy = src_obj->world_y;
        float wz = src_obj->world_z;
        obj->init((RGE_Action_Object*)this, target, src_obj, wx, wy, wz);
    }
    if (obj) {
        this->action_list->add_action(obj);
    }
    this->max_range = range;
}
