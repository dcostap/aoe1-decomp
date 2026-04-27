// VA: 0045A9E0 RGE_Missile_Object::init_missile (Combat+4 floats variant)
// PDB source: misl_obj.cpp
// Attempt log:
// - Same EH frame basin as 0045A950 — VC5 needs stack destructors or try/catch for FS:[0]
// - 5 params: (RGE_Combat_Object*, float, float, float, float) via ret 14h
// - Left in scratch

void* operator new(size_t size);

struct RGE_Action_Missile {
    char base[0x54];
    void init(void* p1, void* p2, int zero, float f1, float f2, float f3);
};

struct RGE_Action_List {
    char base[4];
    void add_action(void* action);
};

struct RGE_Missile_Object {
    char base[0x1C8];
    float max_range;
    void init_missile(void* p1, float p2, float p3, float p4, float p5);
};

void RGE_Missile_Object::init_missile(void* p1, float p2, float p3, float p4, float p5)
{
    RGE_Action_Missile* obj = new RGE_Action_Missile;
    if (obj) {
        obj->init(this, p1, 0, p2, p3, p4);
    }
    if (obj) {
        ((RGE_Action_List*)(*(int*)((char*)this + 0x184)))->add_action(obj);
    }
    *(float*)((char*)this + 0x1C4) = p5;
}
