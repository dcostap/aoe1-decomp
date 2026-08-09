// 004ECD80 TacticalAIGroup::isGathered(TribeTacticalAIModule*, TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 1487-1529
// Size: 232 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Status: MATCHED — canonical sibling-mirror reconstruction
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
// Probe 9 (prior claim, baseline): canonical mirror of exact sibling isTightGathered
//   (004ECE70): while (i < 40) loop, `if (obj == 0 || obj->unitAI() == 0) { remove; }
//   else { body }` so the rare remove path is laid out late, natural float fields
//   gatherX/Y/Z (float, matching the sibling donor), literals -1.0f / 0.0f /
//   strategic threshold. Sibling used literals, not extern const symbols, and VC5
//   merged the constants into the shared .data slots (5756F0/5756F4).
//   Result: 207 bytes (-25), edit diff 15.68% (was 32.27% on the goto version),
//   exact-block coverage 78.48%; block order now matches original exactly
//   (remove block late, increment, return 1, return 0).
// Probe 10 (prior claim): swapped compare spelling on the integer-threshold form;
//   byte-identical output, so that form did not alter VC5's FPU fold.
//
// Probe 11 (this claim): added donor-backed `TribeTacticalAIModule` storage
//   (`gap_00[0x194]` and `strategicNumbers[226]`); no codegen change.
// Probe 12 (this claim): made the threshold a float and converted each
//   branch-local strategicNumber result; both calls stayed duplicated and the
//   output reached 232 bytes with 70 differing bytes.
// Probe 13 (this claim): spelled the final predicate as `dist > n`; with the
//   branch-local float conversion this selects the original `fld`/`fcomp` /
//   `test ah,41h` sequence and produces an exact 232-byte match.
// Main-agent audit restored the canonical polymorphic RGE_Static_Object and
// TacticalAIGroup ownership surfaces; emitted code remains exact.
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
class UnitAIModule {
public:
    int currentAction();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[4];
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
    char gap_00[0x194];
    int strategicNumbers[226];
    int strategicNumber(int index);
};

class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[0x10];
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
    float n;

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
                    n = (float)tactical->strategicNumber(0x17);
                else
                    n = (float)tactical->strategicNumber(0x29);
                if (dist > n) {
                    return 0;
                }
            }
        }
        i = i + 1;
        p = p + 1;
    }
    return 1;
}
