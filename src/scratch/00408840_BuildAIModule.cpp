// 00408840 BuildAIModule::BuildAIModule
// FLAGS: config/flags/00408840_BuildAIModule.rsp (/GX for constructor EH)
// Attempt log:
// 1: reconstructed constructor/load from packet Ghidra: base AIModule, sentinel BuildItem, strings, item loop, BuildItem ctor/setters and list insertion.
// 2: added /GX and placement-new helper; reached exact 1240-byte size.
// 3: removed accidental ManagedArray ctor surface that inserted a non-original member ctor call.
// 4: corrected BuildItem local/member size to 0xB0 so buildListLength/string offsets align with original (+1A0/+1A4/+2A5/+3A6/+4A7/+5A8).
// 5: adjusted local name buffer to recover original 0x16C EH frame; first mismatch moved after base/sentinel construction.
// 6: tried staging fd into a local after header initialization; VC5 still schedules fd load before zero/vptr/list-link stores.
// 7: remaining mismatch is broad constructor scheduling/EH-state and local-slot order: original zeroes list fields before loading fd, then writes vptr/list links and calls rge_read; rebuilt hoists fd/load/read setup earlier and interleaves differently despite exact size. Not accepted_drift-safe.
// 8: added the same-TU AIModule base layout, virtual BuildItem/BuildAIModule destructors, destructible ManagedArray<int>, and natural BuildItem allocation; corrected virtual padding back to the proven 0xB0 object size. Diff improved, but frame and five float conversions remain.
// Main review removed the old manual derived-vptr store and kept compiler-owned
// constructor setup. ManagedArray now uses its natural array-delete form.

#include <string.h>
#include <stdlib.h>

typedef unsigned char uchar;
void* __cdecl operator new(unsigned int);
extern "C" void rge_read(int fd, void* dst, int size);
extern "C" float save_game_version;
extern "C" float version_3_1;
extern "C" float version_2_2;

class AIModule {
public:
    virtual ~AIModule();
    AIModule(const char*, int, int, void*);
    char gap_04[0xEC];
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ManagedArray() {}
    ~ManagedArray() {
        if (value != 0) {
            delete[] value;
            value = 0;
        }
        numberValue = 0;
        desiredNumberValue = 0;
        maximumSizeValue = 0;
    }
};

class BuildItem {
public:
    char pad[0x68]; // vptr at +0, next/prev remain at +0x6C/+0x70
    BuildItem* next;
    BuildItem* prev;
    char pad_tail[0x3C];
    BuildItem();
    virtual ~BuildItem();
    BuildItem(int z, uchar permanentSkip, int y, int a, int b, int local, char* name, float x, float nskip, float gameID, int place, int skip, int num, int from);
    void setBuilt(int); void setInProgress(int); void setBuildAttempts(int); void setNumberBuilds(int); void setBuildCap(int); void setSkipCycles(int); void setPermanentSkip(uchar);
    void setSkip(int); void setGameID(int); void setX(float); void setY(float); void setZ(float);
};

class BuildAIModule : public AIModule {
public:
    BuildItem buildList; // +F0
    int buildListLengthValue; // +1A0
    char buildListNameValue[0x101]; // +1A4
    char lastBuildItemRequestedValue[0x101]; // +2A5
    char currentBuildItemRequestedValue[0x101]; // +3A6
    char nextBuildItemRequestedValue[0x101]; // +4A7
    int numberItemsIntoBuildListValue; // +5A8
    ManagedArray<int> typesToIgnore; // +5AC-ish
    BuildAIModule(int p1, int fd);
    virtual ~BuildAIModule();
};

BuildAIModule::BuildAIModule(int p1, int fd)
    : AIModule((char*)0x57F158, 0x3e9, p1, 0), buildList()
{
    int buildCap;
    int builtValue;
    int inProgressValue;
    int buildAttemptsValue;
    int terrainAdjOne;
    int skipValue;
    float zSize;
    int gameID;
    float xSize;
    float x;
    int uniqueID;
    float y;
    int buildCategory;
    float z;
    int terrainAdjTwo;
    int numberBuilds;
    float ySize;
    int numberSkipCycles;
    int typeID;
    int permanentSkip;
    int terrainSet;
    int placeOnElevation;
    int buildFrom;
    int local_11c;
    char name[261];

    this->numberItemsIntoBuildListValue = 0;
    this->buildListLengthValue = 0;
    this->typesToIgnore.value = 0;
    this->typesToIgnore.numberValue = 0;
    this->typesToIgnore.desiredNumberValue = 0;
    this->typesToIgnore.maximumSizeValue = 0;
    this->buildList.next = &this->buildList;
    this->buildList.prev = &this->buildList;
    int file = fd;

    rge_read(file, &this->buildListLengthValue, 4);
    rge_read(file, &buildCap, 4);
    rge_read(file, this->buildListNameValue, buildCap);
    this->buildListNameValue[buildCap] = 0;
    rge_read(file, &buildCap, 4);
    rge_read(file, this->lastBuildItemRequestedValue, buildCap);
    this->lastBuildItemRequestedValue[buildCap] = 0;
    rge_read(file, &buildCap, 4);
    rge_read(file, this->currentBuildItemRequestedValue, buildCap);
    this->currentBuildItemRequestedValue[buildCap] = 0;
    if (save_game_version < *(float*)0x56E784) {
        strcpy(this->nextBuildItemRequestedValue, (char*)0x57F0BC);
    } else {
        rge_read(file, &buildCap, 4);
        rge_read(file, this->nextBuildItemRequestedValue, buildCap);
        this->nextBuildItemRequestedValue[buildCap] = 0;
    }
    rge_read(file, &this->numberItemsIntoBuildListValue, 4);

    int i = 0;
    if (this->buildListLengthValue > 0) {
        do {
            rge_read(file, &buildCap, 4);
            rge_read(file, name + 4, buildCap);
            name[buildCap + 4] = 0;
            rge_read(file, &permanentSkip, 4);
            rge_read(file, &xSize, 4);
            rge_read(file, &y, 4);
            rge_read(file, &uniqueID, 4);
            rge_read(file, &buildCategory, 4);
            rge_read(file, &terrainAdjTwo, 4);
            rge_read(file, &x, 4);
            rge_read(file, &numberSkipCycles, 4);
            rge_read(file, &gameID, 4);
            rge_read(file, &zSize, 4);
            rge_read(file, &z, 4);
            rge_read(file, &buildAttemptsValue, 4);
            rge_read(file, &inProgressValue, 4);
            rge_read(file, &terrainAdjOne, 4);
            rge_read(file, &local_11c, 4);
            rge_read(file, &placeOnElevation, 4);
            rge_read(file, &skipValue, 4);
            rge_read(file, &numberBuilds, 4);
            rge_read(file, &buildFrom, 4);
            rge_read(file, &ySize, 4);
            builtValue = -1;
            if (save_game_version >= *(float*)0x56E788) {
                rge_read(file, &builtValue, 4);
            }
            rge_read(file, &typeID, 4);
            rge_read(file, &terrainSet, 1);
            BuildItem* item = new BuildItem((int)z, (uchar)permanentSkip, (int)y, 1, 0, local_11c, name + 4, x, (float)numberSkipCycles, (float)gameID, placeOnElevation, skipValue, numberBuilds, buildFrom);
            item->setBuilt(inProgressValue);
            item->setInProgress(buildAttemptsValue);
            item->setBuildAttempts(terrainAdjOne);
            item->setSkip((int)zSize);
            item->setGameID((int)xSize);
            item->setX((float)uniqueID);
            item->setY((float)buildCategory);
            item->setZ((float)terrainAdjTwo);
            item->setNumberBuilds((int)ySize);
            item->setBuildCap(builtValue);
            item->setSkipCycles(typeID);
            item->setPermanentSkip((uchar)terrainSet);
            i++;
            item->next = &this->buildList;
            BuildItem* prev = this->buildList.prev;
            item->prev = prev;
            prev->next = item;
            this->buildList.prev = item;
        } while (i < this->buildListLengthValue);
    }
}
