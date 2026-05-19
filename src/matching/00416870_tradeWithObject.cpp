// 00416870 UnitAIModule::tradeWithObject(int, int)
// PDB: aiuaimod.cpp lines 3285-3304 (148 B, 62 asm)
// FLAGS: default
// MATCH: 0.0000% (148/148 bytes exact)
//
// Key insights:
// - tradeWithObject IS virtual (UAEH mangling), giving class a vtable pointer at +0x00
// - canTrade at vtable+0x178 = slot 94: need 94 filler virtual slots via __declspec(novtable)
// - Inverted condition: if(flag || action != 267) { if(canTrade==1) { ... } else return0; } else return0;
//   This forces VC5 to use shared return-0 epilogue instead of inline

class RGE_Static_Object;

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class __declspec(novtable) ObjWithCanTrade {
public:
    virtual void f00();  virtual void f01();  virtual void f02();  virtual void f03();
    virtual void f04();  virtual void f05();  virtual void f06();  virtual void f07();
    virtual void f08();  virtual void f09();  virtual void f10();  virtual void f11();
    virtual void f12();  virtual void f13();  virtual void f14();  virtual void f15();
    virtual void f16();  virtual void f17();  virtual void f18();  virtual void f19();
    virtual void f20();  virtual void f21();  virtual void f22();  virtual void f23();
    virtual void f24();  virtual void f25();  virtual void f26();  virtual void f27();
    virtual void f28();  virtual void f29();  virtual void f30();  virtual void f31();
    virtual void f32();  virtual void f33();  virtual void f34();  virtual void f35();
    virtual void f36();  virtual void f37();  virtual void f38();  virtual void f39();
    virtual void f40();  virtual void f41();  virtual void f42();  virtual void f43();
    virtual void f44();  virtual void f45();  virtual void f46();  virtual void f47();
    virtual void f48();  virtual void f49();  virtual void f50();  virtual void f51();
    virtual void f52();  virtual void f53();  virtual void f54();  virtual void f55();
    virtual void f56();  virtual void f57();  virtual void f58();  virtual void f59();
    virtual void f60();  virtual void f61();  virtual void f62();  virtual void f63();
    virtual void f64();  virtual void f65();  virtual void f66();  virtual void f67();
    virtual void f68();  virtual void f69();  virtual void f70();  virtual void f71();
    virtual void f72();  virtual void f73();  virtual void f74();  virtual void f75();
    virtual void f76();  virtual void f77();  virtual void f78();  virtual void f79();
    virtual void f80();  virtual void f81();  virtual void f82();  virtual void f83();
    virtual void f84();  virtual void f85();  virtual void f86();  virtual void f87();
    virtual void f88();  virtual void f89();  virtual void f90();  virtual void f91();
    virtual void f92();  virtual void f93();
    virtual int canTrade(int targetId, int flag);  // slot 94 = vtable+0x178
};

class UnitAIModule {
public:
    virtual int tradeWithObject(int targetId, int flag);  // slot 0, gives vtable ptr

    ObjWithCanTrade* object;     // +0x04
    char gap_08[0x28];           // +0x08 to +0x2F
    int currentAction;            // +0x30

    void setCurrentAction(int action);
    void setCurrentTarget(int targetId, int grp, int x, int y, int z);
};

int UnitAIModule::tradeWithObject(int targetId, int flag)
{
    if (flag != 0 || this->currentAction != 0x267) {
        int r = this->object->canTrade(targetId, flag);
        if (r == 1) {
            void* owner = *(void**)((char*)this->object + 0x0C);
            RGE_Game_World* world = *(RGE_Game_World**)((char*)owner + 0x3C);
            RGE_Static_Object* target = world->object(targetId);

            this->setCurrentAction(0x267);

            if (!target) {
                this->setCurrentTarget(targetId, -1, 0, 0, 0);
            } else {
                int grp = (int)(short)(*(short*)((char*)(*(void**)((char*)target + 8)) + 0x14));
                this->setCurrentTarget(targetId, grp,
                    *(int*)((char*)target + 0x38),
                    *(int*)((char*)target + 0x3C),
                    *(int*)((char*)target + 0x40));
            }

            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}
