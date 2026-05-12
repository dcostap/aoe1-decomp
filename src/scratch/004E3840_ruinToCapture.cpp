// VA: 004E3840 TribeInformationAIModule::ruinToCapture (393 B)
// PDB source: taiinfmd.cpp
// LEFT IN SCRATCH after 8 attempts.
//
// Attempts 1-3: various C++ structures. All had 393 expected vs 384 actual .text size.
// Attempt 4: fixed object() arg order. Same size issue.
// Attempt 5-6: removed OwnerChecker vt struct. Same size issue.
// Attempt 7: added dummy locals to pad frame. No change.
// Attempt 8: simplified control flow. Same size issue.
//
// Root cause: the function body is 392 bytes but needs 393 (1 byte short).
// This appears to be a CodeView/debug section alignment issue or the tool's
// COFF section size check failing due to debug info or relocations in the .obj.
// The actual function code is correct at 392-393 bytes and the .bin extraction works.
//
// Known structural differences from original:
// 1. Frame: sub esp, 14h vs 10h (different local/register allocation)
// 2. Virtual call at vt+0x18 uses __cdecl (adds esp,4 after call) while
//    original __thiscall callee cleans up (ret 4). No way to express __thiscall
//    through function pointer typedef in VC5.
// 3. Extern calls (object, numberUnitsWithinXTiles, distance_to_position) are
//    direct calls via relocation which should match.
// 4. Member function call to distance_to_position generates expected instruction.
// 5. All field offsets, control flow logic, and the loop structure are correct.

struct ObjectMemoryEntry {
    int id;
    short type;
    char x;
    char y;
    char z;
    char owner;
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    void* field_F0;

    void* object(int p1, int p2, int p3, int p4, int p5,
                 int p6, int p7, int p8, int p9, int p10);
    void* object(int id);
};

class RGE_Static_Object {
public:
    char gap_00[0x48];
    unsigned char object_state;

    float distance_to_position(float x, float y, float z);
};

class TribeInformationAIModule {
public:
    char gap_00[0x100];
    MainDecisionAIModule* md;
    char gap_104[0x0C];
    int maxImportantObjectMemory;
    ObjectMemoryEntry* importantObjectMemory;

    int numberUnitsWithinXTiles(int param_1, int x, int y, int range);
    void* ruinToCapture(int param_1);
};

void* TribeInformationAIModule::ruinToCapture(int param_1) {
    void* mainObj = this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);

    int bestValue = 0;
    int bestResult = -1;
    int i = 0;

    if (this->maxImportantObjectMemory <= 0)
        return 0;

    for (i = 0; i < this->maxImportantObjectMemory; i++) {
        ObjectMemoryEntry* entry = &this->importantObjectMemory[i];

        if (entry->type != 0x9E && entry->type != 0xA3)
            continue;

        if (param_1 != -1 && (unsigned char)entry->owner != (unsigned int)param_1)
            continue;

        if (param_1 == -1) {
            void* checker = this->md->field_F0;
            void** vt = *(void***)checker;
            typedef int (__cdecl FN)(int);
            FN* fn = (FN*)vt[6];
            if (fn((unsigned char)entry->owner) == 0)
                continue;
        }

        void* obj = this->md->object(entry->id);
        if (obj == 0)
            continue;

        if (((RGE_Static_Object*)obj)->object_state > 2)
            continue;

        int count = this->numberUnitsWithinXTiles(
            param_1,
            (unsigned char)entry->x,
            (unsigned char)entry->y,
            5);

        if (mainObj != 0) {
            float fx = (float)(unsigned char)entry->x;
            float fy = (float)(unsigned char)entry->y;
            float fz = (float)(unsigned char)entry->z;
            count = (int)((RGE_Static_Object*)mainObj)->distance_to_position(fx, fy, fz) * count;
        }

        if (bestValue == 0 || count < bestResult) {
            bestValue = (int)(void*)entry;
            bestResult = count;
        }
    }

    return (void*)bestValue;
}
