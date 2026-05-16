// VA: 0045A9E0 RGE_Missile_Object::init_missile (Combat+4 floats, 137 B)
// PDB source: misl_obj.cpp lines 114-122
// Attempt log:
// - Same EH frame basin as 0045A950: original has SEH FS:[0] prologue with try level
// - VC5 doesn't generate FS:[0] frame for new+destructor without try/catch
// - Struct sizing: RGE_Action_Missile = 0x54, RGE_Missile_Object fields at +0x184/+0x1C4
// - Param layout: (RGE_Combat_Object*, float, float, float, float), ret 14h
// - init call: obj->init(this, p1, 0, f1, f2, f3) — 6 stack args
// - Left in scratch: same EH frame generation mismatch as 0045A950

struct RGE_Action_Object {
    void* vtable;
};

struct RGE_Combat_Object {
    void* vtable;
};

struct RGE_Action_Missile : RGE_Action_Object {
    char pad[0x50];
    ~RGE_Action_Missile();
    void init(RGE_Action_Object* owner, RGE_Combat_Object* target,
              int zero, float f1, float f2, float f3);
};

RGE_Action_Missile::~RGE_Action_Missile() {}

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

    void init_missile(RGE_Combat_Object* target, float f1, float f2, float f3, float range);
};

void RGE_Missile_Object::init_missile(RGE_Combat_Object* target, float f1, float f2, float f3, float range)
{
    RGE_Action_Missile* obj = new RGE_Action_Missile;
    if (obj) {
        obj->init((RGE_Action_Object*)this, target, 0, f1, f2, f3);
    }
    if (obj) {
        this->action_list->add_action(obj);
    }
    this->max_range = range;
}
