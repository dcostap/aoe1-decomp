// VA: 004F8570 TribeTacticalAIModule::civilian
// Attempt log:
// initial decompiler-style implementation with explicit expandable civilian array and tasked duplicate scan: same 573-byte size but broad mismatch from offset 2; rebuilt uses 0x0c frame, ESI this, EBX/EBP as byte-offset/count pair instead of original 0x08 frame with EBP as index.
// tried register int i; no codegen change.
// tried hoisted world/obj locals vs inline object lookup; hoisted locals required declarations before goto and did not improve register basin.
// tried for-loop topology instead of do/while; no codegen change.
// tried natural method calls for object/unitAI/currentOrder/distance; call set looks plausible but scheduling/register family remains broad.
// tried explicit decompiler-style expandable array copies for both civilian resize sites; still same broad expandable-array basin seen in other taitacmd scratch functions.
// tried keeping bestUnitID and bestUnitDistance as the only stack locals; compiler still chose 0x0c frame and different loop state.
// left in scratch: behavior understood, but not accepted_drift-safe due broad prologue/loop/register-basin mismatch across scan and resize regions.

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);

struct XYPoint { int x; int y; };
class UnitAIModule { public: int currentOrder(); };
class RGE_Game_World { public: void* object(int id); };
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
struct MD { char gap[0xf0]; void* player; };

class TribeTacticalAIModule {
public:
    char gap_000[0x0f0];
    MD* md;                    // +f0
    int* civilians_value;      // +f4
    int civilians_number;      // +f8
    char gap_0fc[4];
    int civilians_max;         // +100
    char gap_104[0xd58 - 0x104];
    int* tasked_value;         // +d58
    int tasked_number;         // +d5c
    char gap_d60[4];
    int tasked_max;            // +d64

    int civilian(XYPoint& pos, int chooseMode, int order1, int order2, int order3, int allow103);
};

int TribeTacticalAIModule::civilian(XYPoint& pos, int chooseMode, int order1, int order2, int order3, int allow103)
{
    int bestUnitID;
    float bestUnitDistance;
    int i;

    bestUnitID = -1;
    bestUnitDistance = 0.0f;
    for (i = 0; i < this->civilians_number; ) {
            if (i > this->civilians_max - 1) {
                int newCount = i + 1;
                int* p = (int*)operator_new(newCount * 4);
                if (p != 0) {
                    int j = 0;
                    if (this->civilians_max > 0) {
                        do {
                            if (j >= newCount) break;
                            p[j] = this->civilians_value[j];
                            ++j;
                        } while (j < this->civilians_max);
                    }
                    operator_delete(this->civilians_value);
                    this->civilians_value = p;
                    this->civilians_max = newCount;
                }
            }

            int k = 0;
            int count = this->tasked_number;
            if (count > 0) {
                do {
                    if (k >= this->tasked_max) break;
                    if (this->tasked_value[k] == this->civilians_value[i]) goto next;
                    ++k;
                } while (k < count);
            }

            if (i > this->civilians_max - 1) {
                int newCount2 = i + 1;
                int* p2 = (int*)operator_new(newCount2 * 4);
                if (p2 != 0) {
                    int j2 = 0;
                    if (this->civilians_max > 0) {
                        do {
                            if (j2 >= newCount2) break;
                            p2[j2] = this->civilians_value[j2];
                            ++j2;
                        } while (j2 < this->civilians_max);
                    }
                    operator_delete(this->civilians_value);
                    this->civilians_value = p2;
                    this->civilians_max = newCount2;
                }
            }

            RGE_Static_Object* obj;
            obj = (RGE_Static_Object*)(*(RGE_Game_World**)(*(char**)((char*)this->md->player + 0xf0) + 0x3c))->object(this->civilians_value[i]);
            if (obj != 0 && obj->unitAI() != 0) {
                if (allow103 != 0 || obj->master_obj->id != 0x103) {
                    if (obj->unitAI()->currentOrder() != order1 &&
                        obj->unitAI()->currentOrder() != order2 &&
                        obj->unitAI()->currentOrder() != order3) {
                        float dist = obj->distance_to_position((float)pos.x, (float)pos.y, obj->world_z);
                        if (bestUnitID == -1) {
                            bestUnitDistance = dist;
                            bestUnitID = obj->id;
                        } else if ((chooseMode == 1 && dist < bestUnitDistance) ||
                                   (chooseMode == 0 && bestUnitDistance < dist)) {
                            bestUnitDistance = dist;
                            bestUnitID = obj->id;
                        } else {
                            ;
                        }
                    }
                }
            }
next:
            ++i;
    }
    return bestUnitID;
}
