// 00403CE0 RGE_Action_Gather::move_to
// Source: ACT_GATH.cpp lines 796-831, size 174 bytes
// Attempt log:
// first: all offsets shifted by -4 (missing virtual → no vtable at +0).
// second: virtual fix — first 129 bytes byte-identical. 6 bytes diff in false path.
// third: temporaries/locals didn't change register allocation.
// Left in scratch: 6 edit bytes (3.4%) pure register scheduling drift in false path
//   param loads/stores. Original: ecx=z,edx=x,eax=y → [28h]=z,[20h]=x,[24h]=y.
//   Rebuilt: ecx=y,edx=z,eax=x → [24h]=y,[28h]=z,[20h]=x.
//   Final field values identical. True path (129 bytes) byte-identical.
// FLAGS: none

// Vtable helper for virtual method calls at +0x54, +0x58, +0x5C
struct ActionGatherVtable {
    virtual void _v00();
    virtual void _v04();
    virtual void _v08();
    virtual void _v0C();
    virtual void _v10();
    virtual void _v14();
    virtual void _v18();
    virtual void _v1C();
    virtual void _v20();
    virtual void _v24();
    virtual void _v28();
    virtual void _v2C();
    virtual void _v30();
    virtual void _v34();
    virtual void _v38();
    virtual void _v3C();
    virtual void _v40();
    virtual void _v44();
    virtual void _v48();
    virtual void _v4C();
    virtual void _v50();
    virtual void _v54(int);     // vtable[21]
    virtual void _v58(void*);   // vtable[22]
    virtual void _v5C(int);     // vtable[23]
};

struct MasterObject {
    char gap_00[0x10];
    short id;              // +0x10
};

struct RGE_Static_Object {
    char gap_00[0x04];     // vtable
    int id;                // +0x04
    MasterObject* master;  // +0x08
    void* owner;           // +0x0C
};

struct RGE_Action_Gather {
    // vtable at +0x00 (virtual function below)
    char gap_04[4];        // +0x04
    void* field_08;        // +0x08 (resource/def pointer)
    char field_0C;         // +0x0C (byte compared with 8)
    char gap_0D[7];        // +0x0D to +0x13
    void* gatherTarget;    // +0x14 (compared with param_1)
    char gap_18[8];        // +0x18 to +0x1F
    float x_dest;          // +0x20
    float y_dest;          // +0x24
    float z_dest;          // +0x28

    virtual int move_to(RGE_Static_Object* target, float x, float y, float z);
};

int RGE_Action_Gather::move_to(RGE_Static_Object* target, float x, float y, float z) {
    if (target != 0) {
        void* p1 = this->field_08;
        if (target->owner == *(void**)((char*)p1 + 0x0C)) {
            void* p2 = *(void**)((char*)p1 + 0x08);
            short id = target->master->id;
            if (id == *(short*)((char*)p2 + 0x0E8) || id == *(short*)((char*)p2 + 0x0EA)) {
                if (*(float*)((char*)p1 + 0x44) > 0.0f) {
                    if (target == (RGE_Static_Object*)this->gatherTarget && *(unsigned char*)((char*)this + 0x0C) == 8) {
                        return 1;
                    }
                    ((ActionGatherVtable*)this)->_v54(0);
                    this->x_dest = -1.0f;
                    this->y_dest = -1.0f;
                    this->z_dest = -1.0f;
                    ((ActionGatherVtable*)this)->_v58(target);
                    ((ActionGatherVtable*)this)->_v5C(8);
                    return 1;
                }
            }
        }
    }

    this->z_dest = z;
    this->x_dest = x;
    this->y_dest = y;
    ((ActionGatherVtable*)this)->_v54(0);
    ((ActionGatherVtable*)this)->_v5C(0x0F);
    return 1;
}
