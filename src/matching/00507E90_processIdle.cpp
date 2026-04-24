class RGE_Static_Object;
class RGE_Game_World;

extern int numberDifferentPlayerObjectsVisible;

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    char gap_04[0x8];
    RGE_Player* owner;
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int);
};

class UnitAIModule {
public:
    void* vtable_ptr;
    RGE_Static_Object* objectValue;
};

class UnitAIModuleCallShim {
public:
    void* vtable_ptr;
    virtual int vf00(int, int, int, int, int*);
    virtual int vf01(int, int, int, int, int*);
    virtual int vf02(int, int, int, int, int*);
    virtual int vf03(int, int, int, int, int*);
    virtual int vf04(int, int, int, int, int*);
    virtual int vf05(int, int, int, int, int*);
    virtual int vf06(int, int, int, int, int*);
    virtual int vf07(int, int, int, int, int*);
    virtual int vf08(int, int, int, int, int*);
    virtual int vf09(int, int, int, int, int*);
    virtual int vf10(int, int, int, int, int*);
    virtual int vf11(int, int, int, int, int*);
    virtual int vf12(int, int, int, int, int*);
    virtual int vf13(int, int, int, int, int*);
    virtual int vf14(int, int, int, int, int*);
    virtual int vf15(int, int, int, int, int*);
    virtual int closestObject(int, int, int, int, int*);
};

class RGE_Static_ObjectCallShim {
public:
    void* vtable_ptr;
    char gap_04[0x8];
    RGE_Player* owner;
    virtual void vf00(void);
    virtual void vf01(void);
    virtual void vf02(void);
    virtual void vf03(void);
    virtual void vf04(void);
    virtual void vf05(void);
    virtual void vf06(void);
    virtual void vf07(void);
    virtual void vf08(void);
    virtual void vf09(void);
    virtual void vf10(void);
    virtual void vf11(void);
    virtual void vf12(void);
    virtual void vf13(void);
    virtual void vf14(void);
    virtual void vf15(void);
    virtual void vf16(void);
    virtual void change_ownership(RGE_Player*);
};

class TribeArtifactUnitAIModule : public UnitAIModule {
public:
    int processIdle(int);
};

int TribeArtifactUnitAIModule::processIdle(int param_1) {
    int iVar1;
    RGE_Static_Object *pRVar2;

    iVar1 = ((UnitAIModuleCallShim*)this)->closestObject(-1, -1, -1, -1, 0);
    if ((numberDifferentPlayerObjectsVisible <= 1) && (iVar1 != -1)) {
        pRVar2 = this->objectValue->owner->world->object(iVar1);
        if (pRVar2 != 0) {
            if (this->objectValue->owner != pRVar2->owner) {
                ((RGE_Static_ObjectCallShim*)this->objectValue)->change_ownership(pRVar2->owner);
                return 6;
            }
        }
    }
    return 5;
}
