// VA: 004C4F10 transform (151B)
// stat_obj.cpp: 2508-2536
// void __thiscall RGE_Static_Object::transform(RGE_Master_Static_Object *param_1)
// Pure virtual class (implicit vptr) + fdivr pattern

class RGE_Master_Static_Object;
#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Static_Object {
public:
    virtual void dummy_v00();
    virtual void dummy_v04();
    virtual void dummy_v08();
    virtual void dummy_v0C();
    virtual void dummy_v10();
    virtual void dummy_v14();
    virtual void dummy_v18();
    virtual void dummy_v1C();
    virtual void dummy_v20();
    virtual void dummy_v24();
    virtual void dummy_v28();
    virtual void dummy_v2C();
    virtual void dummy_v30();
    virtual void dummy_v34();
    virtual void setSprite(void* sprite) = 0;
    virtual void dummy_v3C();
    virtual void dummy_v40();
    virtual void dummy_v44();
    virtual void dummy_v48();
    virtual void dummy_v4C();
    virtual void dummy_v50();
    virtual void dummy_v54();
    virtual void dummy_v58();
    virtual void update(int mode) = 0;
    virtual void dummy_v60();
    virtual void dummy_v64();
    virtual void dummy_v68();
    virtual void dummy_v6C();
    virtual void dummy_v70();
    virtual void dummy_v74();
    virtual void dummy_v78();
    virtual void dummy_v7C();
    virtual void dummy_v80();
    virtual void dummy_v84();
    virtual void dummy_v88();
    virtual void dummy_v8C();
    virtual void dummy_v90();
    virtual void dummy_v94();
    virtual void dummy_v98();
    virtual void dummy_v9C();
    virtual void dummy_vA0();
    virtual void dummy_vA4();
    virtual void dummy_vA8();
    virtual void dummy_vAC();
    virtual void dummy_vB0();
    virtual void dummy_vB4();
    virtual void dummy_vB8();
    virtual void dummy_vBC();
    virtual void dummy_vC0();
    virtual void dummy_vC4();
    virtual void dummy_vC8();
    virtual void dummy_vCC();
    virtual void dummy_vD0();
    virtual void dummy_vD4();
    virtual void tileOp0(void* owner, int zero, int neg1) = 0;
    virtual void tileOp1(void* owner, int zero, int neg1) = 0;

    // Fields - implicit vptr at +0x00
    int id;                   // +0x04
    RGE_Master_Static_Object* master_obj;  // +0x08
    void* owner;                            // +0x0C
    char pad_10[0x1C - 0x10];
    void* tile;                             // +0x1C
    char pad_20[0x30 - 0x20];
    float hp;                               // +0x30
    char pad_34[0x48 - 0x34];
    unsigned char object_state;             // +0x48

    void transform(RGE_Master_Static_Object* param_1);
    void removeFromObstructionMap(int mode);
    void addToObstructionMap(int mode);
};

struct RGE_Master_Static_Object {
    char pad_00[0x18];
    void* sprite;             // +0x18
    char pad_1C[0x26 - 0x1C];
    short hp;                 // +0x26
};
#endif

void RGE_Static_Object::transform(RGE_Master_Static_Object* param_1) {
    float ratio = (float)(signed short)(master_obj->hp);
    ratio = hp / ratio;

    if (tile != 0) {
        tileOp1(owner, 0, -1);
    }

    removeFromObstructionMap(2);

    master_obj = param_1;

    if (tile != 0) {
        tileOp0(owner, 0, -1);
    }

    addToObstructionMap(2);

    setSprite(param_1->sprite);

    hp = (float)param_1->hp;
    hp = hp * ratio;
    object_state = 0;

    update(2);
}
