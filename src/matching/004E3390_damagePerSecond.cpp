// 004E3390 TribeInformationAIModule::damagePerSecond (taiinfmd.cpp:7640-7716, 292B)
// Calculates total damage per second against units matching criteria.
// FLAGS: /nologo /c /O2 /Oy

extern "C" long __ftol();

struct InnerInnerType {
    void target_method(int param);
};

struct InnerType {
    char gap_00[0x3C];
    InnerInnerType* inner_3C;  // +0x3C
};

struct MainDecisionAIModule {
    char gap_00[0xF0];
    InnerType* member_F0;  // +0xF0

    void* object(int id);
};

// 64 dummies for vtable slots 0-63, then real slots at 0x100 and 0x104
struct UnitFunctionsBase {
    virtual void d00() {} virtual void d01() {} virtual void d02() {} virtual void d03() {}
    virtual void d04() {} virtual void d05() {} virtual void d06() {} virtual void d07() {}
    virtual void d08() {} virtual void d09() {} virtual void d10() {} virtual void d11() {}
    virtual void d12() {} virtual void d13() {} virtual void d14() {} virtual void d15() {}
    virtual void d16() {} virtual void d17() {} virtual void d18() {} virtual void d19() {}
    virtual void d20() {} virtual void d21() {} virtual void d22() {} virtual void d23() {}
    virtual void d24() {} virtual void d25() {} virtual void d26() {} virtual void d27() {}
    virtual void d28() {} virtual void d29() {} virtual void d30() {} virtual void d31() {}
    virtual void d32() {} virtual void d33() {} virtual void d34() {} virtual void d35() {}
    virtual void d36() {} virtual void d37() {} virtual void d38() {} virtual void d39() {}
    virtual void d40() {} virtual void d41() {} virtual void d42() {} virtual void d43() {}
    virtual void d44() {} virtual void d45() {} virtual void d46() {} virtual void d47() {}
    virtual void d48() {} virtual void d49() {} virtual void d50() {} virtual void d51() {}
    virtual void d52() {} virtual void d53() {} virtual void d54() {} virtual void d55() {}
    virtual void d56() {} virtual void d57() {} virtual void d58() {} virtual void d59() {}
    virtual void d60() {} virtual void d61() {} virtual void d62() {} virtual void d63() {}
};

struct UnitFunctions : UnitFunctionsBase {
    virtual float slot100() { return 0.0f; }         // vtable slot 64 = 0x100
    virtual float slot104(void* obj) { return 0.0f; } // vtable slot 65 = 0x104
};

struct MasterObject {
    char gap_00[0x28];
    float los;      // +0x28
    char gap_2C[4];
    float radius_x;  // +0x30
    float radius_y;  // +0x34
};

struct RGE_Static_Object {
    char gap_00[0x08];
    MasterObject* master_obj;    // +0x08
    char gap_0C[0x38 - 0x0C];
    float x;                     // +0x38
    float y;                     // +0x3C
    int world_z;                 // +0x40
    char gap_44[4];
    unsigned char object_state;  // +0x48

    float distance_to_position(float param1, float param2, float param3);
};

// InnerType2 with vtable slot 6 for target_method — same layout as InnerType
struct InnerType2 {
    // vptr at +0x00 (auto-generated for virtual methods)
    virtual void d0() {}
    virtual void d1() {}
    virtual void d2() {}
    virtual void d3() {}
    virtual void d4() {}
    virtual void d5() {}
    virtual int target_method(int arg) { return 0; }
    char gap_04[0x3C - 0x04];
    InnerInnerType* inner_3C;       // +0x3C
};

struct TribeInformationAIModule {
    char gap_00[0x100];
    MainDecisionAIModule* md;           // +0x100
    char gap_104[0x0C];
    int maxImportantObjectMemory;       // +0x110
    char* importantObjectMemory;        // +0x114 (0x24 stride: +0=id(int), +0x0B=owner(byte))

    float damagePerSecond(int param_1, int param_2, int param_3);
};

float TribeInformationAIModule::damagePerSecond(int param_1, int param_2, int param_3) {
    float rateOfFire = 0.0f;

    RGE_Static_Object* target = (RGE_Static_Object*)md->object(param_1);
    if (target == 0) {
        return 0.0f;
    }

    int i = 0;
    if (maxImportantObjectMemory > 0) {
        int base = 0;
        do {
            unsigned char owner = *(unsigned char*)(importantObjectMemory + base + 0x0B);
            if (((InnerType2*)md->member_F0)->target_method(owner)) {
                int id = *(int*)(importantObjectMemory + base);
                RGE_Static_Object* unit = (RGE_Static_Object*)md->object(id);
                if (unit != 0 && unit->object_state <= 2) {
                    float dist = unit->distance_to_position(
                        (float)param_2, (float)param_3, *(float*)&unit->world_z);
                    if (dist <= unit->master_obj->los) {
                        float rVal = ((UnitFunctions*)target)->slot104(unit);
                        float rateTmp = ((UnitFunctions*)unit)->slot100();
                        if (rateTmp != 0.0f && rVal != 0.0f) {
                            rateOfFire = rVal / rateTmp + rateOfFire;
                        }
                    }
                }
            }
            i++;
            base += 0x24;
        } while (i < maxImportantObjectMemory);
    }

    return rateOfFire;
}
