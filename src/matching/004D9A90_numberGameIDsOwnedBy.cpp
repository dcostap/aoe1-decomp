// 004D9A90 TribeInformationAIModule::numberGameIDsOwnedBy
// PDB: taiinfmd.cpp:1641-1672, 132 bytes
// __thiscall, int, ret 8 (2 params: int param1, int param2)
// FLAGS: default
//
// Attempt log:
// probe 1: 93% â€” RGE_Game_World::object embedded
// probe 2: 61% â€” prologue/register order wrong, extra local var

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class RGE_Game_World;

class RGE_Static_Object {
public:
    char gap_00[0x8];
    void* master_obj;        // +0x8
    void* owner;             // +0xC
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
    int id;                  // +0x00
    char gap_04[0x7];
    unsigned char owner;     // +0x0B
};

class TribeInformationAIModule {
public:
    char gap_00[0x100];
    void* md;                // +0x100
    char gap_104[0xC];
    int maxImportantObjectMemory;  // +0x110
    ObjectMemory* importantObjectMemory;  // +0x114

    int numberGameIDsOwnedBy(int param1, int param2);
};
#endif

#endif
int TribeInformationAIModule::numberGameIDsOwnedBy(int param1, int param2) {
    int result = 0;
    int i = 0;
    int idx = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            int id = ((int*)((char*)this->importantObjectMemory + idx))[0];
            if (id != -1) {
                void* world = *(void**)((char*)*(void**)((char*)this->md + 0x1256C) + 0x3C);
                RGE_Static_Object* obj = ((RGE_Game_World*)world)->object(id);
                if (obj != 0) {
                    short owner_id = *(short*)((char*)obj->owner + 0x4A);
                    if (owner_id == param2 && (param1 == -1 || param1 == *(unsigned char*)((char*)this->importantObjectMemory + idx + 0x0B))) {
                        result++;
                    }
                }
            }
            i++;
            idx += 0x24;
        } while (i < this->maxImportantObjectMemory);
    }

    return result;
}
