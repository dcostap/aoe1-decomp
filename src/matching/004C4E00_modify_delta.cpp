// VA: 004C4E00 RGE_Static_Object::modify_delta
// PDB source: stat_obj.cpp lines 2471-2486
// Attempt log:
// rewrite 2026-05-19: replaced wrong integer stub with packet-observed float/virtual-call behavior.
// retry: using unsigned int type plus switch(op) was the key for VC5 to emit the original `sub eax,0; je case0; dec eax; jne default` dispatch. Reusing the delta parameter stack slot via `*(int*)&delta` matched the FILD/FSTP stack-slot sequence. check_function: MATCH / 0.0000%.

extern "C" long __cdecl _ftol();

struct RGE_Object_Info {
    char gap_00[0x26];
    short field_26;
    float screen_x_offset; // +0x28
};

class RGE_Static_Object {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8C();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0(); virtual void vB4(); virtual void vB8(); virtual void vBC();
    virtual void vC0(); virtual void vC4(); virtual void vC8(); virtual void vCC();
    virtual void vD0(); virtual void vD4();
    virtual void vfD8(int owner, int a, int b);
    virtual void vfDC(int owner, int a, int b);

    char gap_04[4];
    RGE_Object_Info* object_info; // +8
    int owner; // +C
    char gap_10[0x0C];
    void* tile; // +1C
    char gap_20[0x10];
    float hp; // +30
    char gap_34[0x14];
    unsigned char object_state; // +48

    void modify_delta(float delta, unsigned int type);
};

void RGE_Static_Object::modify_delta(float delta, unsigned int type)
{
    unsigned int op = type & 0xff;
    switch (op) {
    case 1:
        if (this->tile != 0 && this->object_state == 2) {
            int owner = this->owner;
            this->vfDC(owner, 0, -1);
            RGE_Object_Info* info = this->object_info;
            this->vfD8(this->owner, 0, (int)(info->screen_x_offset + delta));
        }
        return;
    case 0: {
        RGE_Object_Info* info = this->object_info;
        float original_delta = delta;
        *(int*)&delta = (int)info->field_26;
        this->hp = (float)(int)(short)((original_delta + (float)*(int*)&delta) * this->hp / (float)*(int*)&delta);
        break;
    }
    default:
        return;
    }
}
