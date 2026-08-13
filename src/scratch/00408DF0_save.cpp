// 00408DF0 BuildAIModule::save - direct reconstruction
// Attempts:
// - Direct write helpers outlined repeated string and write bodies, producing a much smaller function.
// - Expanded the writes and corrected the BuildAIModule and BuildItem offsets.
// - Recomputed strlen for each string data write. This restored the repeated scan shape and exact code size.
// - Used direct integer homes for integer getters and float homes for coordinate getters.
// - Removed the decompiler-shaped tempString self store. VC5 then matched size, calls, CFG, and 1200 of 1266 bytes.
// - Modeled the embedded BuildItem sentinel and typed next link from the original +0x15C read; codegen stayed unchanged.
// - Remaining drift is local scratch scheduling: saved-this and sentinel displacements, float FSTP placement, and integer homes.
// - Best source reconstruction: 1266 bytes, 90 differing bytes, 94.79% edit similarity. Leave in scratch.
#include <string.h>
extern "C" void __cdecl rge_write(int, void*, int);
class BaseItem { public: virtual ~BaseItem(); char gap04[0x68]; char* name(); int typeID() const; int gameID() const; int uniqueID() const; float x() const; float y() const; float z() const; float xSize() const; float ySize() const; float zSize() const; int skip() const; };
class BuildItem: public BaseItem { public: BuildItem* next; int buildCategory() const; int inProgress() const; int built() const; int buildAttempts() const; int buildFrom() const; int terrainSet() const; int terrainAdjacency(int) const; int placeOnElevation() const; int numberBuilds() const; int buildCap() const; int skipCycles() const; unsigned char permanentSkip() const; };
class BuildAIModule { public: char gap0[0xf0]; BuildItem buildList; char gap160[0x40]; int buildListLengthValue; char buildListNameValue[0x101]; char lastBuildItemRequestedValue[0x101]; char currentBuildItemRequestedValue[0x101]; char nextBuildItemRequestedValue[0x101]; int numberItemsIntoBuildListValue; int save(int); };
#define WRITE_STRING(SRC) { strcpy(tempString, (SRC)); tempInt = strlen(tempString); rge_write(file, &tempInt, 4); rge_write(file, tempString, strlen(tempString)); }
#define WRITE_I(EXPR) { tempInt = (EXPR); rge_write(file, &tempInt, 4); }
#define WRITE_I_TO(VAR, EXPR) { VAR = (EXPR); rge_write(file, &VAR, 4); }
#define WRITE_FF(EXPR) { tempFloat = (EXPR); rge_write(file, &tempFloat, 4); }
int BuildAIModule::save(int file) {
    char tempString[257];
    int tempInt; float tempFloat; int tempBOOL; unsigned char tempBYTE;
    rge_write(file, &this->buildListLengthValue, 4);
    WRITE_STRING(this->buildListNameValue);
    WRITE_STRING(this->lastBuildItemRequestedValue);
    WRITE_STRING(this->currentBuildItemRequestedValue);
    WRITE_STRING(this->nextBuildItemRequestedValue);
    rge_write(file, &this->numberItemsIntoBuildListValue, 4);
    BuildItem* item = this->buildList.next;
    BuildItem* end = &this->buildList;
    while (item != end) {
        if (item == 0) return 1;
        WRITE_STRING(item->name());
        WRITE_I(item->typeID());
        WRITE_I(item->gameID());
        WRITE_I(item->uniqueID());
        WRITE_FF(item->x());
        WRITE_FF(item->y());
        WRITE_FF(item->z());
        WRITE_FF(item->xSize());
        WRITE_FF(item->ySize());
        WRITE_FF(item->zSize());
        WRITE_I_TO(tempBOOL, item->skip());
        WRITE_I(item->buildCategory());
        WRITE_I(item->inProgress());
        WRITE_I(item->built());
        WRITE_I(item->buildAttempts());
        WRITE_I(item->buildFrom());
        WRITE_I(item->terrainSet());
        WRITE_I(item->terrainAdjacency(1));
        WRITE_I(item->terrainAdjacency(2));
        WRITE_I(item->placeOnElevation());
        WRITE_I(item->numberBuilds());
        WRITE_I(item->buildCap());
        WRITE_I(item->skipCycles());
        tempBYTE = item->permanentSkip();
        rge_write(file, &tempBYTE, 1);
        item = (BuildItem*)item->next;
    }
    return 1;
}
