// 004ECD80 TacticalAIGroup::isGathered(TribeTacticalAIModule*, TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 1487-1529
// Size: 232 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Status: ACTIVE — canonical sibling-mirror reconstruction
//
// Attempt log:
// Probe 1 (prior worker): clean for loop — 64.7% positional, 208 bytes
// Probe 2 (prior): do-while + pointer arith — same
// Probe 3 (prior): *(int*)&dist=0 for zero — same
// Probe 4 (prior): var declaration order — same
// Probe 5 (prior): dist > (float)n comparison — same
// Probe 6 (prior): separate branches for strategicNumber — same, improved [esp+1Ch] usage
// Probe 7 (prior): temp float nf var — same
// Probe 8 (prior): goto structure — same
// Probe 9 (this claim, baseline): canonical mirror of exact sibling isTightGathered
//   (004ECE70): while (i < 40) loop, `if (obj == 0 || obj->unitAI() == 0) { remove; }
//   else { body }` so the rare remove path is laid out late, natural float fields
//   gatherX/Y/Z (float, matching the sibling donor), literals -1.0f / 0.0f /
//   (float)n < dist. Sibling used literals, not extern const symbols, and VC5
//   merged the constants into the shared .data slots (5756F0/5756F4).
//   Result: 207 bytes (-25), edit diff 15.68% (was 32.27% on the goto version),
//   exact-block coverage 78.48%; block order now matches original exactly
//   (remove block late, increment, return 1, return 0).
// Probe 10 (this claim): swapped compare to `if (dist > (float)n) return 0;` —
//   byte-identical output (0 changed). VC5 canonicalizes both compare spellings;
//   operand order is NOT the axis for the fcomp fold. Negative evidence.
//
// Remaining drift (identified, unresolved at pause):
//   1. strategicNumber if/else tail-merge: rebuilt emits push imm; jmp; shared
//      call (1 call) instead of original's two full call blocks (2 calls).
//      Missing 1 call = the -25 byte size gap. The original loads this (mod1)
//      BEFORE each push (`mov ecx,[esp+1Ch]; push imm; call`) with fild in each
//      branch; the rebuilt cross-jumps at the this-load. Next leads: force the
//      fild into each branch so the FPU stack carries n across the join
//      (e.g. float nf assigned per branch and kept on x87 stack; or split the
//      strategicNumber result into two distinct locals), or a fuller real
//      TribeTacticalAIModule class surface (strategicNumbers[226]) as TU context.
//   2. Final FPU compare folds to `fild n; fcomp [dist_mem]; test ah,1; jne`
//      (11 bytes) instead of original `fld dist; fcomp; test ah,41h; fstp st0;
//      je` (15 bytes). This is downstream of #1: once n stays on the FPU stack
//      at the join (fild in branches), the stack-to-stack compare follows
//      naturally (verified by sibling isTightGathered using fcomp [qword] when
//      its operand is already on st0).
//
// Key facts (from original asm + exact sibling donor):
// - TacticalAIGroup: typeValue(+0x14), unitsValue[40](+0x1C, 40 slots),
//   gatherX/Y/Z at +0x19C/1A0/1A4 (float fields per sibling donor).
// - mod1(TribeTacticalAIModule*)=[esp+1Ch], mod2(MainDecisionAIModule*)=[esp+20h]
// - dist at [esp+10h], n at [esp+14h] (original local order)
// - Constants: [5756F4h]=1.0f, [5756F0h]=0.0f (shared float pool)
// - Object call: mod2->object(unitID) = 0040D760h
// - unitAI: obj->unitAI() = 004C7420h
// - distance_to_position(float,float,float) thiscall ret 0Ch = 004C5F00h
// - strategicNumber: mod1->strategicNumber(0x17/0x29) = 004F6210h
// - removeUnitByIndex(idx, mod2) thiscall = 004EB0C0h
//
// Remaining known drift risk (unresolved at pause):
// - strategicNumber if/else may still tail-merge (push imm; jmp) instead of the
//   original duplicated call blocks, and the final FPU compare may fold to
//   fcomp [dist_mem] instead of original fld dist; fcomp; test ah,41h; fstp st0.
//   Next leads: force n's fild into each branch (e.g. n as float register value
//   assigned in each branch), or probe `if (dist > (float)n) return 0;` after
//   the structural layout is exact.

class UnitAIModule {
public:
    int currentAction();
};

class RGE_Static_Object {
public:
    char gap_00[8];
    void* master_obj;

    UnitAIModule* unitAI();
    float distance_to_position(float x, float y, float z);
};

class TribeMainDecisionAIModule {
public:
    RGE_Static_Object* object(int id);
};

class TribeTacticalAIModule {
public:
    int strategicNumber(int index);
};

class TacticalAIGroup {
public:
    char gap_00[0x14];
    int typeValue;              // +0x14
    char gap_18[0x1C - 0x18];
    int unitsValue[40];         // +0x1C
    char gap_BC[0x19C - 0xBC];
    float gatherX;              // +0x19C
    float gatherY;              // +0x1A0
    float gatherZ;              // +0x1A4

    int removeUnitByIndex(int index, TribeMainDecisionAIModule* md);
    int isGathered(TribeTacticalAIModule* tactical, TribeMainDecisionAIModule* md);
};

int TacticalAIGroup::isGathered(TribeTacticalAIModule* tactical, TribeMainDecisionAIModule* md)
{
    int i;
    int* p;
    int unit;
    RGE_Static_Object* obj;
    float dist;
    int n;

    i = 0;
    p = this->unitsValue;
    while (i < 40) {
        unit = *p;
        if (unit != -1) {
            obj = md->object(unit);
            if (obj == 0 || obj->unitAI() == 0) {
                this->removeUnitByIndex(i, md);
            }
            else {
                dist = obj->distance_to_position(this->gatherX, this->gatherY, this->gatherZ);
                dist = dist - 1.0f;
                if (dist < 0.0f) {
                    dist = 0.0f;
                }
                if (this->typeValue == 0x6D)
                    n = tactical->strategicNumber(0x17);
                else
                    n = tactical->strategicNumber(0x29);
                if ((float)n < dist) {
                    return 0;
                }
            }
        }
        i = i + 1;
        p = p + 1;
    }
    return 1;
}
