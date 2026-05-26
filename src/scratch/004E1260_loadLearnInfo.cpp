// 004E1260 TribeInformationAIModule::loadLearnInfo
// Attempt log:
// initial reconstruction from packet/decompiler: filename build, rge_read temp stack blocks, natural add/grow int-array helpers.
// try 1: static add_unique helper compiled too small (.text 880 vs 1212), because helper not inlined/parent inlining missing.
// try 2: macro-expanded add_unique to inline the three grow/list blocks; compiles to full size but broad mismatch.
// try 3: fixed storeAttackMemory visible arity to 11 explicit params (matching wrapper in 004E0F90); still broad drift.
// try 4: switched temp from struct ObjectMemory24 to raw char[0x24] and named filename/civ locals to test stack/local scheduling; edit diff improved 71% -> 55.6%, frame still wrong.
// try 5: tested /GX flag; no change (original has no EH frame); removed flag.
// left in scratch: current mismatch is not accepted_drift quality. First mismatch at frame/prologue: original sub esp,34 and saves this before suffix load; rebuilt sub esp,3c and loads suffix before mov esi,ecx. Needs exact stack-window/local topology and source-shaped inline ManagedArray<int>::add/contains blocks.

#include <stdio.h>

#define rge_base_game (*(RGE_Base_Game**)0x0062C574)

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern int rge_open(char*, int);
extern void rge_read(int, void*, int);
extern int rge_close(int);
void* operator new(unsigned int);
void operator delete(void*);

class RGE_Game_Info { public: char* get_current_player_name(); };
class RGE_Base_Game { public: char gap[4]; RGE_Game_Info* info; };
struct MainDecision { char gap[0xF0]; char* player; char gap2[0x46]; short civ; };

struct ObjectMemory24 { char b[0x24]; };
struct ObjectMemory18 { char b[0x18]; };
struct ResourceBlob { int count; int unk; void* ptr; int count2; int unk2; };

class TribeInformationAIModule {
public:
    char gap_000[0x100];
    MainDecision* md;           // +100
    int mapXSizeValue;          // +104
    int mapYSizeValue;          // +108
    char gap_10C[0x1C];
    int* importantUnitsValue;   // +128
    int importantUnitsNumber;   // +12C
    int gap_130;
    int importantUnitsMax;      // +134
    int* importantBuildingsValue; // +138
    int importantBuildingsNumber; // +13C
    int gap_140;
    int importantBuildingsMax;  // +144
    int* importantObjectsValue; // +148
    int importantObjectsNumber; // +14C
    int gap_150;
    int importantObjectsMax;    // +154
    char gap_158[0xB0];
    char learnFileName[260];    // +208
    char gap_30C[0x1C4];
    ResourceBlob resources[4];  // ptr +4D0 count +4F0 etc via raw loop

    void storeAttackMemory(int,int,int,int,int,int,int,unsigned long,int,int,int);
    void addObjectMemory(int,int,int,int,int,int,int,int,int,int,int,int,int,void*);
    void loadLearnInfo(char* suffix);
};

#define ADD_UNIQUE(VALUE, NUMBER, MAXIMUM, ID) \
{ \
    int au_i = 0; \
    int au_id = (ID); \
    int au_found = 0; \
    if ((NUMBER) > 0) { \
        do { \
            if (au_i >= (MAXIMUM)) break; \
            if ((VALUE)[au_i] == au_id) { au_found = 1; break; } \
            au_i++; \
        } while (au_i < (NUMBER)); \
    } \
    if (!au_found) { \
        if ((NUMBER) > (MAXIMUM) - 1) { \
            int au_newMax = (NUMBER) + 1; \
            int* au_nv = (int*)operator new(au_newMax * 4); \
            if (au_nv != 0) { \
                int au_j = 0; \
                if ((MAXIMUM) > 0) { \
                    while (au_j < au_newMax && au_j < (MAXIMUM)) { \
                        au_nv[au_j] = (VALUE)[au_j]; \
                        au_j++; \
                    } \
                } \
                operator delete(VALUE); \
                (VALUE) = au_nv; \
                (MAXIMUM) = au_newMax; \
            } \
        } \
        (VALUE)[(NUMBER)] = au_id; \
        (NUMBER)++; \
    } \
}

void TribeInformationAIModule::loadLearnInfo(char* suffix)
{
    int numToLoad;
    int tempInt;
    int local2c;
    char temp[0x24];
    char* learnFileName = this->learnFileName;
    int civ = (int)this->md->civ;

    if (suffix == 0) {
        sprintf(learnFileName, (char*)0x5879A4, civ);
    } else {
        sprintf(learnFileName, (char*)0x587994, suffix, rge_base_game->info->get_current_player_name(), civ);
    }

    int file = rge_open(learnFileName, 0x8000);
    if (file != -1) {
        rge_read(file, &this->mapXSizeValue, 4);
        rge_read(file, &this->mapYSizeValue, 4);
        rge_read(file, &numToLoad, 4);
        int i = 0;
        if (numToLoad > 0) {
            do {
                rge_read(file, temp, 0x18);
                this->storeAttackMemory(*(int*)&temp[0], *(int*)&temp[4], *(int*)&temp[8], *(int*)&temp[12],
                    *(int*)&temp[16], *(int*)&temp[20], *(int*)&temp[22], *(unsigned long*)&temp[13],
                    *(int*)&temp[14], *(int*)&temp[18], *(int*)&temp[20]);
                i++;
            } while (i < numToLoad);
        }

        rge_read(file, &numToLoad, 4);
        i = 0;
        if (numToLoad > 0) {
            do {
                rge_read(file, temp, 0x24);
                this->addObjectMemory(*(int*)&temp[0], *(int*)&temp[4], *(int*)&temp[8], *(int*)&temp[12],
                    *(int*)&temp[13], *(int*)&temp[14], *(int*)&temp[15], *(int*)&temp[16],
                    *(int*)&temp[18], *(int*)&temp[20], *(int*)&temp[24], *(int*)&temp[28], *(int*)&temp[32], 0);
                int id = *(int*)&temp[0];
                ADD_UNIQUE(this->importantUnitsValue, this->importantUnitsNumber, this->importantUnitsMax, id);
                i++;
            } while (i < numToLoad);
        }

        char* p = (char*)this + 0x4F0;
        int k = 4;
        do {
            rge_read(file, p, 4);
            rge_read(file, p - 0x10, 4);
            *(void**)(p - 0x20) = operator new((*(int*)p) * 20);
            rge_read(file, *(void**)(p - 0x20), (*(int*)p) * 20);
            p += 4;
            k--;
        } while (k != 0);

        rge_read(file, &tempInt, 4);
        i = 0;
        if (tempInt > 0) {
            do {
                rge_read(file, &local2c, 4);
                ADD_UNIQUE(this->importantBuildingsValue, this->importantBuildingsNumber, this->importantBuildingsMax, local2c);
                i++;
            } while (i < tempInt);
        }
        rge_read(file, &tempInt, 4);
        i = 0;
        if (tempInt > 0) {
            do {
                rge_read(file, &local2c, 4);
                ADD_UNIQUE(this->importantObjectsValue, this->importantObjectsNumber, this->importantObjectsMax, local2c);
                i++;
            } while (i < tempInt);
        }
        rge_close(file);
    }
}
