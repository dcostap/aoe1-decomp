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
// 9: corrected serialized scalar types from direct int/float call evidence; removed five __ftol calls and three int-to-float conversions. Size and call set now match; +4 frame and constructor topology remain.
// 10: removed the explicit fd local and used the constructor parameter directly; original keeps the file descriptor in the parameter-derived EBP path, and the local may account for the +4 frame.
// 11: matched the Ghidra local declaration char[257] while retaining the name+4 payload offset; frame became exact and diff improved 294 -> 287.
// 12: changed permanentSkip to the Ghidra-proven uchar source type; emitted code was unchanged.
// 13: tested original initial-store order; emitted bytes did not move and edit/resync worsened, so restored the prior natural order.
// 14: moved the loop counter initialization before the numberItems read to match Ghidra's iVar9 placement; emitted code was unchanged, so restored the clean source.
// 15: moved the proven scalar defaults into the member-initializer sequence, following the same-TU constructor donor; diff improved 287 -> 272 and delayed the fd load, but the first mismatch remains in constructor scheduling at +0064.
// 16-28: continued source, lifetime, stack-layout, ABI-global, header-context, and raw-allocation probes. The decisive ABI-context change is using the declared version_2_2 global; it moves the second compare/store sequence into positional parity and reduces the clean diff to 3 bytes. The remaining three bytes are only the name buffer's stack displacement: original name+4 is [esp+78]/name terminator [esp+84], while rebuilt uses [esp+7C]/[esp+88]. Union, scoped-buffer, register, declaration-order, pointer-alias, direct-link, placement-new, and standard-header variants did not reduce this hunk. Current source is the smallest natural 1240-byte reconstruction with 51/51 calls, exact frame, and 3 differing bytes; do not retain raw overlap steering.
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

    ManagedArray()
        : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {}
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
    : AIModule((char*)0x57F158, 0x3e9, p1, 0), buildList(),
      buildListLengthValue(0), numberItemsIntoBuildListValue(0)
{
    int buildCap;
    int builtValue;
    int inProgressValue;
    int buildAttemptsValue;
    int terrainAdjOne;
    int skipValue;
    int zSize;
    float gameID;
    int xSize;
    float x;
    float uniqueID;
    int y;
    float buildCategory;
    int z;
    float terrainAdjTwo;
    int numberBuilds;
    int ySize;
    float numberSkipCycles;
    int typeID;
    uchar permanentSkip;
    int terrainSet;
    int placeOnElevation;
    int buildFrom;
    int local_11c;
    char name[257];

    this->buildList.next = &this->buildList;
    this->buildList.prev = &this->buildList;
    rge_read(fd, &this->buildListLengthValue, 4);
    rge_read(fd, &buildCap, 4);
    rge_read(fd, this->buildListNameValue, buildCap);
    this->buildListNameValue[buildCap] = 0;
    rge_read(fd, &buildCap, 4);
    rge_read(fd, this->lastBuildItemRequestedValue, buildCap);
    this->lastBuildItemRequestedValue[buildCap] = 0;
    rge_read(fd, &buildCap, 4);
    rge_read(fd, this->currentBuildItemRequestedValue, buildCap);
    this->currentBuildItemRequestedValue[buildCap] = 0;
    if (save_game_version >= *(float*)0x56E784) {
        rge_read(fd, &buildCap, 4);
        rge_read(fd, this->nextBuildItemRequestedValue, buildCap);
        this->nextBuildItemRequestedValue[buildCap] = 0;
    } else {
        strcpy(this->nextBuildItemRequestedValue, (char*)0x57F0BC);
    }
    rge_read(fd, &this->numberItemsIntoBuildListValue, 4);

    int i = 0;
    if (this->buildListLengthValue > 0) {
        do {
            rge_read(fd, &buildCap, 4);
            rge_read(fd, name + 4, buildCap);
            name[buildCap + 4] = 0;
            rge_read(fd, &permanentSkip, 4);
            rge_read(fd, &xSize, 4);
            rge_read(fd, &y, 4);
            rge_read(fd, &uniqueID, 4);
            rge_read(fd, &buildCategory, 4);
            rge_read(fd, &terrainAdjTwo, 4);
            rge_read(fd, &x, 4);
            rge_read(fd, &numberSkipCycles, 4);
            rge_read(fd, &gameID, 4);
            rge_read(fd, &zSize, 4);
            rge_read(fd, &z, 4);
            rge_read(fd, &buildAttemptsValue, 4);
            rge_read(fd, &inProgressValue, 4);
            rge_read(fd, &terrainAdjOne, 4);
            rge_read(fd, &local_11c, 4);
            rge_read(fd, &placeOnElevation, 4);
            rge_read(fd, &skipValue, 4);
            rge_read(fd, &numberBuilds, 4);
            rge_read(fd, &buildFrom, 4);
            rge_read(fd, &ySize, 4);
            builtValue = -1;
            if (save_game_version >= version_2_2) {
                rge_read(fd, &builtValue, 4);
            }
            rge_read(fd, &typeID, 4);
            rge_read(fd, &terrainSet, 1);
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
