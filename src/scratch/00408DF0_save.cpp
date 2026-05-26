// 00408DF0 BuildAIModule::save - direct reconstruction
// Attempts:
// - Direct helper-based write_string/write_i/write_fi compiled far too small (.text 816 vs original 1266) because repeated string/write bodies were outlined.
// - Expanded string/int/float writes as macros, restoring the original 0x118 stack frame and broad repeated rep-scan/copy shape.
// - Corrected BuildAIModule offsets: list length +0x1A0, strings +0x1A4/+0x2A5/+0x3A6/+0x4A7, item count +0x5A8, list first +0x15C, sentinel +0xF0, BuildItem next +0x6C.
// - Delayed sentinel/end initialization to remove one extra early self store; first mismatch remains local stack slot for tempString/self store ([esp+20] vs original [esp+2C] under pushed args), with broad downstream stack-slot drift.
// - Best comparable run: same size 1266, ~71.1% positional / ~91.5% edit; not accepted-drift quality.
#include <string.h>
extern "C" void __cdecl rge_write(int, void*, int);
class BaseItem { public: virtual ~BaseItem(); char gap04[0x68]; BaseItem* next; char* name(); int typeID() const; int gameID() const; int uniqueID() const; float x() const; float y() const; float z() const; float xSize() const; float ySize() const; float zSize() const; int skip() const; };
class BuildItem: public BaseItem { public: int buildCategory() const; int inProgress() const; int built() const; int buildAttempts() const; int buildFrom() const; int terrainSet() const; int terrainAdjacency(int) const; int placeOnElevation() const; int numberBuilds() const; int buildCap() const; int skipCycles() const; unsigned char permanentSkip() const; };
class BuildAIModule { public: char gap0[0x15c]; BuildItem* first; char gap160[0x40]; int buildListLengthValue; char buildListNameValue[0x101]; char lastBuildItemRequestedValue[0x101]; char currentBuildItemRequestedValue[0x101]; char nextBuildItemRequestedValue[0x101]; int numberItemsIntoBuildListValue; int save(int); };
#define WRITE_STRING(SRC) { strcpy(tempString, (SRC)); tempInt = strlen(tempString); rge_write(file, &tempInt, 4); rge_write(file, tempString, tempInt); }
#define WRITE_I(EXPR) { tempInt = (EXPR); rge_write(file, &tempInt, 4); }
#define WRITE_FI(EXPR) { tempFloat = (float)(EXPR); rge_write(file, &tempFloat, 4); }
#define WRITE_FF(EXPR) { tempFloat = (EXPR); rge_write(file, &tempFloat, 4); }
int BuildAIModule::save(int file) {
    char tempString[257];
    int tempInt; float tempFloat; unsigned char tempBYTE;
    rge_write(file, &this->buildListLengthValue, 4);
    WRITE_STRING(this->buildListNameValue);
    WRITE_STRING(this->lastBuildItemRequestedValue);
    WRITE_STRING(this->currentBuildItemRequestedValue);
    WRITE_STRING(this->nextBuildItemRequestedValue);
    rge_write(file, &this->numberItemsIntoBuildListValue, 4);
    *(int*)tempString = (int)this;
    BuildItem* item = this->first;
    BuildItem* end = (BuildItem*)((char*)this + 0xF0);
    while (item != end) {
        if (item == 0) return 1;
        WRITE_STRING(item->name());
        WRITE_FI(item->typeID());
        WRITE_FI(item->gameID());
        WRITE_FI(item->uniqueID());
        WRITE_I((int)item->x());
        WRITE_I((int)item->y());
        WRITE_I((int)item->z());
        WRITE_I((int)item->xSize());
        WRITE_I((int)item->ySize());
        WRITE_I((int)item->zSize());
        WRITE_I(item->skip());
        WRITE_FI(item->buildCategory());
        WRITE_I(item->inProgress());
        WRITE_I(item->built());
        WRITE_FI(item->buildAttempts());
        WRITE_FI(item->buildFrom());
        WRITE_FI(item->terrainSet());
        WRITE_FI(item->terrainAdjacency(1));
        WRITE_FI(item->terrainAdjacency(2));
        WRITE_I(item->placeOnElevation());
        WRITE_FI(item->numberBuilds());
        WRITE_FI(item->buildCap());
        WRITE_FI(item->skipCycles());
        tempBYTE = item->permanentSkip();
        rge_write(file, &tempBYTE, 1);
        item = (BuildItem*)item->next;
    }
    return 1;
}
