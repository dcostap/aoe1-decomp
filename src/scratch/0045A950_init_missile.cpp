// VA: 0045A950 RGE_Missile_Object::init_missile (Combat+Static+float variant)
// PDB source: misl_obj.cpp
// Attempt log:
// - 96-144 bytes, no FS:[0] generated despite operator new + /GX
// - VC5 doesn't generate EH frame without stack destructors or try/catch
// - Seems the original source used a different pattern with local destructors
// - Left in scratch

struct RGE_Action_Missile {
    char base[0x54];
    void init(void* p1, void* p2, void* p3, float f1, float f2, float f3);
};

struct RGE_Action_List {
    char base[4];
    void add_action(void* action);
};

struct RGE_Missile_Object {
    char base[0x1C8];
    float max_range;
    void init_missile(void* p1, void* p2, float p3);
};

void RGE_Missile_Object::init_missile(void* p1, void* p2, float p3)
{
    RGE_Action_Missile* obj = new RGE_Action_Missile;
    if (obj) {
        float f1 = *(float*)((char*)p2 + 0x38);
        float f2 = *(float*)((char*)p2 + 0x3C);
        float f3 = *(float*)((char*)p2 + 0x40);
        obj->init(this, p1, p2, f1, f2, f3);
    }
    if (obj) {
        ((RGE_Action_List*)(*(int*)((char*)this + 0x184)))->add_action(obj);
    }
    *(float*)((char*)this + 0x1C4) = p3;
}
