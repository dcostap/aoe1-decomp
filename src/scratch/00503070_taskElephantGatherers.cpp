// 00503070 TribeTacticalAIModule::taskElephantGatherers(int,int,int)
// Source: taitacmd.cpp lines 13148-13219
// FLAGS: config/flags/00503070_taskElephantGatherers.rsp
// Attempt log:
// - Initial natural source from packet/decompiler.
// - Kept /GX because original has EH registration and local ManagedArray cleanup/delete path.
// - Modeled local ManagedArray<int> layout to match packet stack use and used explicit resize/new/delete family.
// - Fixed gatherer array stride to 0x18 and local offsets for md +0xF0, gatherers +0x51C, numberGatherers +0x9CC.
// - Adding an inline ManagedArray destructor produced the expected /GX EH-framed size (618 bytes) instead of the earlier 592-byte no-EH body.
// - Also tried inline constructor-zeroing for ManagedArray; improved edit diff slightly but did not fix register allocation/layout.
// - Best current check is same-size but broad mismatch: positional 75.0809%, edit 46.1165%, first mismatch after initial target-object call where original zeroes ESI and rebuilt zeroes EBP. Remaining drift includes zero-register/liveness choice, array scan loop shape, FPU compare form, virtual AI command call surface, and ManagedArray growth/copy path. Not accepted_drift-safe; no inline asm.

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* ptr);

class RGE_Static_Object { public: char gap[0x38]; float world_x; float world_y; void* unitAI(); float distance_to_object(RGE_Static_Object*); };
class MainDecisionAIModule { public: RGE_Static_Object* object(int id); char gap[0x12568]; void* aiPlayer; };
struct Gatherer { int id; int data1; char gap[0x10]; };
struct ManagedArray_int { int* value; int numberValue; int desiredNumberValue; int maximumSizeValue; ManagedArray_int() : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {} int resize(int n); ~ManagedArray_int() { if (value != 0) operator delete(value); } };
class TribeTacticalAIModule { public:
    char gap0[0xF0]; MainDecisionAIModule* md; char gapF4[0x51C-0xF4]; Gatherer* gatherers; char gap520[0x9CC-0x520]; int numberGatherersValue;
    void taskElephantGatherers(int first, int count, int target);
};

typedef void (*TaskFn)(void*, int, int, int, float, float);

void TribeTacticalAIModule::taskElephantGatherers(int first, int count, int target)
{
    RGE_Static_Object* targetObj = this->md->object(target);
    if (targetObj != 0) {
        ManagedArray_int already;
        int loop;
        already.resize(1);
        already.value[already.desiredNumberValue] = first;
        already.numberValue = 0;
        already.desiredNumberValue++;
        if (count > 0) {
            loop = 0;
            do {
                int best = -1;
                float bestDist = -1.0f;
                int gi = 0;
                if (this->numberGatherersValue > 0) {
                    Gatherer* g = this->gatherers;
                    RGE_Static_Object* obj;
                    do {
                        int i = 0;
                        int n = already.desiredNumberValue;
                        if (n > 0) {
                            int* p = already.value;
                            do {
                                if (i >= already.maximumSizeValue) break;
                                if (*p == g->id) goto next_g;
                                i++;
                                p++;
                            } while (i < n);
                        }
                        obj = this->md->object(g->id);
                        if (obj != 0 && obj->unitAI() != 0 && g->data1 == 0) {
                            float d = obj->distance_to_object(targetObj);
                            if (bestDist == -1.0f || d < bestDist) {
                                best = g->id;
                                bestDist = d;
                            }
                        }
next_g:
                        gi++;
                        g++;
                    } while (gi < this->numberGatherersValue);
                }
                if (best == -1) break;
                void* ai = *(void**)((char*)this->md->aiPlayer + 0);
                TaskFn fn = *(TaskFn*)((char*)*(void**)ai + 0x124);
                fn(ai, best, target, 0, targetObj->world_x, targetObj->world_y);
                int i = 0;
                int n = already.desiredNumberValue;
                if (n > 0) {
                    int* p = already.value;
                    do {
                        if (i >= already.maximumSizeValue) break;
                        if (*p == best) goto after_add;
                        i++; p++;
                    } while (i < n);
                }
                if (already.maximumSizeValue - 1 < already.desiredNumberValue) {
                    int newMax = already.desiredNumberValue + 1;
                    int* nv = (int*)operator new(newMax * 4);
                    if (nv != 0) {
                        int j = 0;
                        if (already.maximumSizeValue > 0) {
                            do {
                                if (j >= newMax) break;
                                j++;
                                nv[j-1] = already.value[j-1];
                            } while (j < already.maximumSizeValue);
                        }
                        operator delete(already.value);
                        already.value = nv;
                        already.maximumSizeValue = newMax;
                    }
                }
                already.value[already.desiredNumberValue] = best;
                already.desiredNumberValue++;
after_add:
                loop++;
                already.numberValue = loop;
            } while (loop < count);
        }
    }
}
