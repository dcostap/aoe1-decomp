// TRIBE_Action_Hunt::work (004D0080)
// PDB source: tact_hnt.cpp:890-948
// Size: 207 bytes
// Calling convention: __thiscall

// Abstract vtable interface for virtual function dispatch at +0x54, +0x58, +0x5C
struct THuntVTable {
    virtual void dd00() = 0; virtual void dd01() = 0;
    virtual void dd02() = 0; virtual void dd03() = 0;
    virtual void dd04() = 0; virtual void dd05() = 0;
    virtual void dd06() = 0; virtual void dd07() = 0;
    virtual void dd08() = 0; virtual void dd09() = 0;
    virtual void dd0A() = 0; virtual void dd0B() = 0;
    virtual void dd0C() = 0; virtual void dd0D() = 0;
    virtual void dd0E() = 0; virtual void dd0F() = 0;
    virtual void dd10() = 0; virtual void dd11() = 0;
    virtual void dd12() = 0; virtual void dd13() = 0;
    virtual void dd14() = 0; virtual void vf54(void*) = 0;  // vt[21] = 0x54
    virtual void vf58(void*) = 0;  // vt[22] = 0x58
    virtual void vf5C(int) = 0;     // vt[23] = 0x5C
};

struct RGE_Static_Object {
    unsigned char gap_00[0x08];
    void* master_obj;   // +0x08
    void* owner;        // +0x0C
};

struct TRIBE_Action_Hunt {
    unsigned char gap_00[0x08];
    void* info_ptr;     // +0x08
    unsigned char gap_0C[0x14];
    float field_0x20;
    float field_0x24;
    float field_0x28;
    int field_0x2C;

    int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
};

int TRIBE_Action_Hunt::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4)
{
    if (param_1 != 0)
    {
        void* info = info_ptr;
        if (param_1->owner == *(void**)((char*)info + 0x0C))
        {
            void* tgtInfo = *(void**)((char*)info + 0x08);
            short objId = *(short*)((char*)param_1->master_obj + 0x10);
            if (objId == *(short*)((char*)tgtInfo + 0xE8) || objId == *(short*)((char*)tgtInfo + 0xEA))
            {
                if (*(float*)((char*)info + 0x44) > 0.0f)
                {
                    ((THuntVTable*)this)->vf54(0);
                    field_0x2C = 0;
                    field_0x20 = -1.0f;
                    field_0x24 = -1.0f;
                    field_0x28 = -1.0f;
                    ((THuntVTable*)this)->vf58(param_1);
                    ((THuntVTable*)this)->vf5C(8);
                    return 1;
                }
            }
        }

        ((THuntVTable*)this)->vf54(param_1);
        ((THuntVTable*)this)->vf58(0);
        ((THuntVTable*)this)->vf5C(4);
        return 1;
    }

    // Path 1: param_1 == 0 (at end, jump target)
    field_0x20 = param_2;
    field_0x24 = param_3;
    field_0x28 = param_4;
    ((THuntVTable*)this)->vf54(0);
    ((THuntVTable*)this)->vf5C(0x0F);
    return 1;
}
