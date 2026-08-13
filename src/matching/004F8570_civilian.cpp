// VA: 004F8570 TribeTacticalAIModule::civilian
// Attempt log:
// initial decompiler-style implementation with explicit expandable civilian array and tasked duplicate scan: same 573-byte size but broad mismatch from offset 2; rebuilt uses 0x0c frame, ESI this, EBX/EBP as byte-offset/count pair instead of original 0x08 frame with EBP as index.
// tried register int i; no codegen change.
// tried hoisted world/obj locals vs inline object lookup; hoisted locals required declarations before goto and did not improve register basin.
// tried for-loop topology instead of do/while; no codegen change.
// tried natural method calls for object/unitAI/currentOrder/distance; call set looks plausible but scheduling/register family remains broad.
// tried canonical inline ManagedArray growth and typed md/player/world ownership;
// this is the current source-shape hypothesis, not a compiler-steering variant.
// probe 2: canonical operator[] growth plus typed md->player->world reduced the
// rebuild to 606 bytes and restored the inline growth topology.
// probe 3: the inlined utmarray.h contains surface and MainDecision +f0 layout
// reached exact size/frame, 13 calls, and 93.9% shape similarity.
// probes 4-5: float/integer zero spelling and best-local declaration order were
// duplicate codegen; probe 6's natural bestDistance > dist spelling restored the
// original x87 compare family and moved to the exact-codegen stage.
// probes 7 and 9: copied the exact contains local/parameter source surface;
// duplicate. Probe 8 reordered ordinary entry initialization, giving the
// immediate zero store and 175-instruction body, but emitted the two entry
// stores in reverse order and left a six-byte tasked-scan register permutation.
// probe 10: ordinary civilians/task references around contains fixed that
// register permutation. The clean source was exact in size/frame/CFG/ordered
// calls with a 10-byte strict drift only in the two entry initialization stores.
// probe 11: natural sentinel-first initialization (bestUnitID=-1, then
// bestUnitDistance=0) produced a full MATCH; no inline asm or opaque scaffolding.

void* operator_new(unsigned int);
void operator_delete(void*);

struct XYPoint { int x; int y; };
class UnitAIModule { public: int currentOrder(); };
struct MasterObj { char gap[0x10]; short id; };
class RGE_Static_Object {
public:
    char gap_00[4];
    int id;
    MasterObj* master_obj;
    char gap_0c[0x40 - 0x0c];
    int world_z;
    UnitAIModule* unitAI();
    float distance_to_position(float x, float y, int z);
};
class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    char gap_00[0x3c];
    RGE_Game_World* world;
};

class MainDecisionAIModule {
public:
    char gap_00[0xf0];
    RGE_Player* player;
};

struct ManagedArray_int {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            int* new_data = (int*)operator_new(new_size * 4);
            if (new_data != 0) {
                for (int i = 0; i < this->maximumSizeValue && i < new_size; i++) {
                    new_data[i] = this->value[i];
                }
                operator_delete(this->value);
                this->value = new_data;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }

    int contains(const int& value) const {
        int i;
        int wanted;
        int current;

        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                return 0;
            current = this->value[i];
            wanted = value;
            if (current == wanted)
                return 1;
        }
        return 0;
    }
};

class TribeTacticalAIModule {
public:
    char gap_000[0x0f0];
    MainDecisionAIModule* md;  // +f0
    ManagedArray_int civilians; // +f4
    char gap_104[0xd58 - 0x104];
    ManagedArray_int unitsTaskedThisUpdate; // +d58

    int civilian(XYPoint& pos, int chooseMode, int order1, int order2, int order3, int allow103);
};

int TribeTacticalAIModule::civilian(XYPoint& pos, int chooseMode, int order1, int order2, int order3, int allow103)
{
    float bestUnitDistance;
    int bestUnitID;
    int i;
    RGE_Static_Object* obj;
    ManagedArray_int& civilians = this->civilians;
    ManagedArray_int& tasked = this->unitsTaskedThisUpdate;

    bestUnitID = -1;
    bestUnitDistance = 0;
    i = 0;
    if (this->civilians.numberValue > 0) {
        do {
            if (tasked.contains(civilians[i]) != 0)
                goto next;

            obj = this->md->player->world->object(this->civilians[i]);
            if (obj != 0 && obj->unitAI() != 0) {
                if (allow103 != 0 || obj->master_obj->id != 0x103) {
                    if (obj->unitAI()->currentOrder() != order1 &&
                        obj->unitAI()->currentOrder() != order2 &&
                        obj->unitAI()->currentOrder() != order3) {
                        float dist = obj->distance_to_position((float)pos.x, (float)pos.y, obj->world_z);
                        if (bestUnitID == -1) {
                            bestUnitDistance = dist;
                            bestUnitID = obj->id;
                        } else if ((chooseMode == 1 && bestUnitDistance > dist) ||
                                   (chooseMode == 0 && bestUnitDistance < dist)) {
                            bestUnitDistance = dist;
                            bestUnitID = obj->id;
                        }
                    }
                }
            }
next:
            ++i;
        } while (i < this->civilians.numberValue);
    }
    return bestUnitID;
}
