// TribeInformationAIModule::gameIDsOwnedBy (004D9970)
// taiinfmd.cpp:1559-1635, 279 bytes
// __thiscall: ecx=this, 3 stack params, ret 0Ch
// No SEH
//
// Status: PARKED — VC5 codegen drift (37.3% positional, 24.7% edit diff)
//
// Attempt log:
// Probe 1: Existing scratch — 37.3% positional, 24.7% edit diff (best result)
// Probe 2: Rewrite with proper struct hierarchy — 88.5% positional (worse, 3 locals vs 2)
// Probe 3: while loop — 86.7% positional (worse)
// Probe 4: Back to Probe 1 structure — 37.3% positional (restored best result)
//
// Key findings:
// - This->md at +0x100 = TribeMainDecisionAIModule* (size 0x125C8)
// - md->aiPlayer at +0x1256C = TRIBE_Player*
// - aiPlayer->world at +0x3C = RGE_Game_World*
// - importantObjectMemory at +0x114, maxImportantObjectMemory at +0x110
// - ObjectMemory: id(+0x00), owner(+0x0B), stride 0x24
// - Capacity starts at 10, grows by *2, allocation is capacity*8
// - Output array stores int IDs at 4-byte indices
// - Uses platform-appropriate new/delete (not C++ new[])
//
// Remaining drift (all VC5 register/scheduling):
// - esi/ebx register swap: out_ptr vs byte_offset
// - Prologue param load interleaving difference
// - Copy/free flow: merged vs separate conditional branches

class RGE_Game_World;

class RGE_Static_Object {
public:
    char gap_00[0x8];
    void* master_obj;
    void* owner;
};

class RGE_Game_World {
public:
    char gap_00[0x88];
    void** objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    void** negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;

    RGE_Static_Object* object(int index);
};

class ObjectMemory {
public:
    int id;
    char gap_04[0x7];
    unsigned char owner;
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0x1256C];
    void* aiPlayer;
};

class TribeInformationAIModule {
public:
    char gap_00[0x100];
    TribeMainDecisionAIModule* md;
    char gap_104[0xC];
    int maxImportantObjectMemory;
    ObjectMemory* importantObjectMemory;

    int gameIDsOwnedBy(int owner_filter, int** out, int owner_id);
};

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);

int TribeInformationAIModule::gameIDsOwnedBy(int owner_filter, int** out, int owner_id)
{
    int count = 0;
    int capacity = 10;
    int i = 0;
    *out = 0;

    if (this->maxImportantObjectMemory > 0) {
        int byte_offset = 0;
        do {
            if (*(int*)((char*)this->importantObjectMemory + byte_offset) != -1) {
                void* world = *(void**)((char*)*(void**)((char*)this->md + 0x1256C) + 0x3C);
                RGE_Static_Object* obj = ((RGE_Game_World*)world)->object(
                    *(int*)((char*)this->importantObjectMemory + byte_offset)
                );
                if (obj != 0) {
                    int ownerId = *(short*)((char*)obj->owner + 0x4A);
                    if (ownerId == owner_id) {
                        if (owner_filter == -1 || owner_filter == *(unsigned char*)((char*)this->importantObjectMemory + byte_offset + 0x0B)) {
                            if (count == capacity || *out == 0) {
                                int* new_arr = (int*)operator_new(capacity * 8);
                                if (*out != 0) {
                                    for (int j = 0; j < capacity; j++) {
                                        new_arr[j] = (*out)[j];
                                    }
                                    operator_delete(*out);
                                }
                                capacity *= 2;
                                *out = new_arr;
                            }
                            (*out)[count] = *(int*)((char*)this->importantObjectMemory + byte_offset);
                            count++;
                        }
                    }
                }
            }
            i++;
            byte_offset += 0x24;
        } while (i < this->maxImportantObjectMemory);
    }

    return count;
}
