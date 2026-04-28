// VA: 004E41C0 TribeInformationAIModule::damageInflictedPerSecond()
// Source: taiinfmd.cpp lines 8228-8257
// Size: 121 bytes, __thiscall, returns float
//
// Attempt log (9 probes):
// Probe 1: Virtual class with 66 methods (64 dummies + 2 real) — 81 diff bytes
//   EH overhead from virtual class declaration
// Probe 2: __declspec(novtable) — still 81 bytes
// Probe 3: Raw function pointers via vtable struct — 88 bytes (__cdecl push all args)
// Probe 4: Fixed loop structure (do-while, i=0 before call numberUnits) — 32 bytes!
//   Virtual calls at +0x100 and +0x104 work correctly!
// Probe 5: Declare hp separately — 32 bytes
// Probe 6: rVal = temp / hp + rVal — 32 bytes
// Probe 7: rVal += temp / hp — 32 bytes
// Probe 8: float ratio = temp / hp; rVal += ratio — 32 bytes
// Probe 9: rVal = (temp / hp) + rVal — 32 bytes
//
// Remaining 32 bytes: FPU scheduling + jump target offsets
//   - Both fstp to memory and fdivr/fadd sequence match structurally
//   - Rebuilt uses `fld [mem]; fxch; fstp [mem]; fdiv [mem]` instead of `fdivr [mem]`
//   - Same FPU result, different x87 scheduling (compiler heuristic difference)
//   - Jump offsets shift by the FPU code size difference
// All semantically equivalent. Pure VC5 FPU scheduling artifact.
// Parked in scratch per Boss direction.

class TacticalAIGroup {
public:
    int numberUnits();
    int unit(int index);
};

class MainDecisionAIModule {
public:
    void* object(int unitID);
};

class __declspec(novtable) RGE_Static_Object {
public:
    virtual void d00();  virtual void d01();  virtual void d02();  virtual void d03();
    virtual void d04();  virtual void d05();  virtual void d06();  virtual void d07();
    virtual void d08();  virtual void d09();  virtual void d0a();  virtual void d0b();
    virtual void d0c();  virtual void d0d();  virtual void d0e();  virtual void d0f();
    virtual void d10();  virtual void d11();  virtual void d12();  virtual void d13();
    virtual void d14();  virtual void d15();  virtual void d16();  virtual void d17();
    virtual void d18();  virtual void d19();  virtual void d1a();  virtual void d1b();
    virtual void d1c();  virtual void d1d();  virtual void d1e();  virtual void d1f();
    virtual void d20();  virtual void d21();  virtual void d22();  virtual void d23();
    virtual void d24();  virtual void d25();  virtual void d26();  virtual void d27();
    virtual void d28();  virtual void d29();  virtual void d2a();  virtual void d2b();
    virtual void d2c();  virtual void d2d();  virtual void d2e();  virtual void d2f();
    virtual void d30();  virtual void d31();  virtual void d32();  virtual void d33();
    virtual void d34();  virtual void d35();  virtual void d36();  virtual void d37();
    virtual void d38();  virtual void d39();  virtual void d3a();  virtual void d3b();
    virtual void d3c();  virtual void d3d();  virtual void d3e();  virtual void d3f();
    virtual float getMaxHitPoints();
    virtual float getDamageInflicted(RGE_Static_Object* attacker);
};

class TribeInformationAIModule {
public:
    char _gap_00[0x100];
    MainDecisionAIModule* md;  // +0x100

    float damageInflictedPerSecond(TacticalAIGroup* group, RGE_Static_Object* target);
};

float TribeInformationAIModule::damageInflictedPerSecond(TacticalAIGroup* group, RGE_Static_Object* target) {
    float rVal = 0.0f;
    int i = 0;
    int count = group->numberUnits();

    if (count > 0) {
        do {
            int unitID = group->unit(i);
            RGE_Static_Object* obj = (RGE_Static_Object*)this->md->object(unitID);

            if (obj != 0) {
                float temp = target->getDamageInflicted(obj);
                float hp = obj->getMaxHitPoints();
                rVal += temp / hp;
            }

            i++;
            count = group->numberUnits();
        } while (i < count);
    }

    return rVal;
}
