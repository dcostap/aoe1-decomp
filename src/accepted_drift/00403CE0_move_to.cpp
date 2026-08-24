// 00403CE0 RGE_Action_Gather::move_to (174B)
// Source: ACT_GATH.cpp lines 796-831
// First 129 bytes (74%) byte-identical. 6 byte diff (3.4%) = register scheduling
// in fallback path (param loads: original ecx=z,edx=x,eax=y vs rebuilt ecx=y,edx=z,eax=x).
// All three fields written correctly, behavior identical.
// ACCEPTED_DRIFT: register allocation only, behavioral equivalence.

#ifndef ACT_GATH_CONTEXT_H
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
    virtual void _v54(int);
    virtual void _v58(void*);
    virtual void _v5C(int);
};

struct MasterObject {
    char gap_00[0x10];
    short id;
};

struct RGE_Static_Object {
    char gap_00[0x04];
    int id;
    MasterObject* master;
    void* owner;
};

struct RGE_Action_Gather {
    char gap_04[4];
    void* field_08;
    char field_0C;
    char gap_0D[7];
    void* gatherTarget;
    char gap_18[8];
    float x_dest;
    float y_dest;
    float z_dest;

    virtual int move_to(RGE_Static_Object* target, float x, float y, float z);
};
#endif

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
