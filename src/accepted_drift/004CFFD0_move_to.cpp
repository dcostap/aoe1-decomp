// 004CFFD0 TRIBE_Action_Hunt::move_to
// Source: tact_hnt.cpp lines 840-883, size 174 bytes
// Attempt log:
// first: 168/174 bytes match. Same structure as 00403CE0 RGE_Action_Gather::move_to.
// Left in scratch: 6 edit bytes (3.4%) — same false-path param-load scheduling drift.
//   Original: ecx=z→[28h], edx=x→[20h], eax=y→[24h]. Rebuilt: ecx=y→[24h], edx=z→[28h], eax=x→[20h].
//   True path (129 bytes) byte-identical.

#ifndef TACT_HNT_SHARED_CONTEXT
// Vtable helper for virtual method calls at +0x54, +0x58, +0x5C
struct ActionHuntVtable {
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

struct TRIBE_Action_Hunt {
    // vtable at +0x00
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
#endif

int TRIBE_Action_Hunt::move_to(RGE_Static_Object* target, float x, float y, float z) {
#ifdef TACT_HNT_SHARED_CONTEXT
    if (target != 0 && target->owner == this->obj->owner) {
        RGE_Master_Action_Object* master =
            static_cast<RGE_Master_Action_Object*>(this->obj->master_obj);
        short id = target->master_obj->id;
        if ((id == master->drop_site || id == master->backup_drop_site) &&
            this->obj->attribute_amount_held > DAT_00575150) {
            if (target == this->target_obj2 && this->state == 8) {
                return 1;
            }
            this->set_target_obj(0);
            this->target_x = -1.0f;
            this->target_y = -1.0f;
            this->target_z = -1.0f;
            this->set_target_obj2(target);
            this->set_state(8);
            return 1;
        }
    }
    this->target_z = z;
    this->target_x = x;
    this->target_y = y;
    this->set_target_obj(0);
    this->set_state(0x0F);
    return 1;
#else
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
                    ((ActionHuntVtable*)this)->_v54(0);
                    this->x_dest = -1.0f;
                    this->y_dest = -1.0f;
                    this->z_dest = -1.0f;
                    ((ActionHuntVtable*)this)->_v58(target);
                    ((ActionHuntVtable*)this)->_v5C(8);
                    return 1;
                }
            }
        }
    }

    this->z_dest = z;
    this->x_dest = x;
    this->y_dest = y;
    ((ActionHuntVtable*)this)->_v54(0);
    ((ActionHuntVtable*)this)->_v5C(0x0F);
    return 1;
#endif
}
