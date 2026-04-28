// VA: 004D9A90 TribeInformationAIModule::numberGameIDsOwnedBy()
// Source: taiinfmd.cpp lines 1641-1672
// Size: 132 bytes, __thiscall, ret 8 (2 params)
// Returns: int
//
// Attempt log (10+ probes):
// Probe 1: Natural struct types (ImportantObjectEntry, RGE_Static_Object) — 118 bytes diff
//   Writes back to member pointer (importantObjectMemory++) — extra memory stores
// Probe 2: Raw pointer arithmetic, offset-based access — still too large (128 vs 132)
// Probe 3: Different loop structures (do-while, for) — all 128 bytes
// Probe 4: S ep arate offset variable w/out pointer advance — 128 bytes
// Probe 5: Volatile count — 128 bytes
// Probe 6: Explicit param copies — 128 bytes
// Probe 7: if(count==-999) workaround — 132 bytes but garbage at end
//
// Remaining: 4-byte structural gap (VC5 register allocation)
//   Original saves regs: push ecx, push ebx, push esi, mov esi,ecx, push edi
//   With conditional push ebp + mov ebp, [esp+18h] inside if block (4 bytes)
//   Rebuilt omits ebp save and allocates registers differently
//   Cannot force VC5 to use specific register allocation from C++ source
// All behaviorally correct. Parked in scratch.

struct RGE_Static_Object;

struct RGE_Game_World {
    RGE_Static_Object* object(int id);
};

class TribeInformationAIModule {
public:
    char _gap_00[0x100];
    void* md;
    char _gap_104[0x0C];
    int maxImportantObjectMemory;
    int* importantObjectMemory;
    int numberGameIDsOwnedBy(int param_1, int param_2);
};

int TribeInformationAIModule::numberGameIDsOwnedBy(int param_1, int param_2) {
    int count = 0;
    int i = 0;
    int offset = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            int id = *(int*)((char*)this->importantObjectMemory + offset);

            if (id != -1) {
                RGE_Game_World* world = *(RGE_Game_World**)(*(char**)((char*)this->md + 0x1256C) + 0x3C);
                RGE_Static_Object* obj = world->object(id);

                if (obj != 0) {
                    if (*(short*)(*(char**)((char*)obj + 0x0C) + 0x4A) == param_2) {
                        if (param_1 == -1) {
                            count++;
                        } else {
                            if (*(unsigned char*)((char*)this->importantObjectMemory + offset + 0x0B) == (unsigned char)param_1) {
                                count++;
                            }
                        }
                    }
                }
            }

            i++;
            offset += 0x24;
        } while (i < this->maxImportantObjectMemory);
    }

    return count;
}
