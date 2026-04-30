// 004ECD80 TacticalAIGroup::isGathered(TribeTacticalAIModule*, MainDecisionAIModule*)
// Source: taitacmd.cpp lines 1487-1529
// Size: 232 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Status: PARKED — VC5 codegen drift (function body 208 bytes vs original 232)
//
// Attempt log:
// Probe 1: clean for loop — 64.7% positional, 208 bytes
// Probe 2: do-while + pointer arith — same
// Probe 3: *(int*)&dist=0 for zero — same
// Probe 4: var declaration order — same
// Probe 5: dist > (float)n comparison — same
// Probe 6: separate branches for strategicNumber — same, improved [esp+1Ch] usage
// Probe 7: temp float nf var — same
// Probe 8: goto structure — same
//
// Key findings (struct layout correct):
// - TacticalAIGroup: typeValue(+0x14), unitsValue[40](+0x1C, 40 slots)
// - gatherX/Y/Z at +0x19C/1A0/1A4
// - mod1(TribeTacticalAIModule*)=[esp+1Ch], mod2(MainDecisionAIModule*)=[esp+20h]
// - dist at [esp+10h], n at [esp+14h]
// - Constants: [5756F4h]=1.0f, [5756F0h]=0.0f
// - Object call: mod2->object(unitID) = 0040D760h
// - unitAI: obj->unitAI() = 004C7420h
// - distance_to_position: obj->dist(x,y,z) = 004C5F00h
// - strategicNumber: mod1->strategicNumber(0x17/0x29) = 004F6210h
// - removeUnitByIndex: this->func(idx, mod2) = 004EB0C0h
//
// Remaining drift (VC5 codegen):
// - Consistently 208 bytes vs original 232 (24 bytes short)
//   likely from merged strategicNumber call + shorter FPU comparison
// - fcomp [mem] (fild n; fcomp dist_mem; test ah,1) vs
//   fild n; fld dist; fcomp; test ah,41h; fstp st0 (original)
// - removeUnitByIndex param order: push mod2, push idx vs push ecx, push ebx
// - Loop: jge+jmp vs jl

struct RGE_Static_Object;
struct UnitAIModule;
struct TribeTacticalAIModule;
struct MainDecisionAIModule;

extern const float ONE_F;  // [5756F4h] = 1.0f
extern const float ZERO_F; // [5756F0h] = 0.0f

struct MainDecisionAIModule {
    RGE_Static_Object* object(int unitID);
};

struct RGE_Static_Object {
    UnitAIModule* unitAI();
    float distance_to_position(int x, int y, int z);
};

struct TacticalAIGroup {
    char pad_00[0x14];
    int typeValue;              // +0x14
    char pad_18[0x1C - 0x18];
    int unitsValue[40];         // +0x1C
    char pad_BC[0x19C - 0xBC];
    int gatherX;                // +0x19C
    int gatherY;                // +0x1A0
    int gatherZ;                // +0x1A4

    int isGathered(TribeTacticalAIModule* mod1, MainDecisionAIModule* mod2);
    int removeUnitByIndex(int idx, MainDecisionAIModule* mod);
};

struct TribeTacticalAIModule {
    int strategicNumber(int num);
};

int TacticalAIGroup::isGathered(TribeTacticalAIModule* mod1, MainDecisionAIModule* mod2)
{
    int idx;
    int* unitPtr;
    float dist;
    int n;

    idx = 0;
    unitPtr = unitsValue;

    do {
        if (*unitPtr != -1) {
            RGE_Static_Object* obj = mod2->object(*unitPtr);
            if (obj == 0) goto remove_unit;
            if (obj->unitAI() == 0) goto remove_unit;

            dist = obj->distance_to_position(gatherX, gatherY, gatherZ);
            dist = dist - ONE_F;

            if (dist < ZERO_F)
                *(int*)&dist = 0;

            if (typeValue == 0x6D)
                n = mod1->strategicNumber(0x17);
            else
                n = mod1->strategicNumber(0x29);

            goto compare;
        }
        goto loop_continue;

remove_unit:
        removeUnitByIndex(idx, mod2);
        goto loop_continue;

compare:
        if ((float)n < dist)
            return 0;

loop_continue:
        idx++;
        unitPtr++;
    } while (idx < 40);

    return 1;
}
