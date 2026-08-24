// attempt 9: keep the decompiler-style int locals that produced the right SIB/base order,
// but restore the original predicate spellings (>= 4 and >= 0)

#ifndef T_B_OBJ_CONTEXT_H
class TRIBE_Resource_Manager {
public:
    char gap_00[0x88];
};

class TRIBE_Owner {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void give_resources(short amount, int type, int unknown);
};

class TRIBE_Building_Object {
public:
    char gap_00[0x4];
    TRIBE_Resource_Manager* pManager;
    TRIBE_Owner* owner;

    virtual void give_building_attribute_to_owner();
};
#endif

void TRIBE_Building_Object::give_building_attribute_to_owner() {
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;

    iVar4 = 0;
    iVar2 = 0x6A;
    iVar3 = 0x70;
    do {
        iVar1 = (int)this->pManager;
        if (*(unsigned char*)(iVar4 + 0x88 + iVar1) >= 4) {
            short amount = *(short*)(iVar2 + iVar1);
            if (amount >= 0) {
                this->owner->give_resources(amount, *(int*)(iVar3 + iVar1), 0);
            }
        }
        iVar3 = iVar3 + 4;
        iVar4 = iVar4 + 1;
        iVar2 = iVar2 + 2;
    } while (iVar3 < 0x7C);
}
