// 0040B1A0 ConstructionAIModule::save
// Attempt log:
// 1: behavior reconstruction from packet/Ghidra: write construction-plan fields, then serialize construction lots and second list items.
// 2: first version used a static helper for item serialization; check compared only the helper-shortened main body (text 896), so expanded as macro/inlined body.
// 3: inlined version reaches exact 1263-byte size but has 0x124 frame vs original 0x118 and broad mismatch; removing unused tempInt did not alter frame.
// 4: key mismatch is source shape/local packing and duplicated item-serialization scheduling. Original uses tempString at esp+24 with this stored in first dword, repeated compiler strcpy/strlen loops, tempFloat/tempBOOL/local_110 slots at esp+10/14/18, and two near-identical hand-inlined list loops. Current macro source preserves behavior but VC5 allocates different locals and emits different loop/call choreography. Not accepted_drift-safe.

#include <string.h>

extern "C" void rge_write(int fd, void* src, int size);

typedef unsigned char uchar;

class BaseItem {
public:
    char* name();
    int typeID();
    int gameID();
    int uniqueID();
    float x(); float y(); float z();
    float xSize(); float ySize(); float zSize();
    int skip();
};
class ConstructionItem : public BaseItem {
public:
    char gap[0x6c];
    ConstructionItem* next;
    ConstructionItem* prev;
    int inProgress();
    int built();
    int buildAttempts();
};
class ConstructionAIModule {
public:
    char gap0[0xF0];
    int numberConstructionLotsValue; // +F0
    ConstructionItem constructionLots; // +F4 sentinel
    int numberSomething; // +174
    ConstructionItem secondList; // +178 sentinel
    char gap1e8[0x1F8-0x1E8];
    char constructionPlanNameValue[0x104]; // +1F8
    int xReferencePointValue; // +2FC
    int yReferencePointValue; // +300
    int zReferencePointValue; // +304
    int mapXSizeValue; // +308
    int mapYSizeValue; // +30C
    int save(int fd) const;
};

#define WRITE_ITEM(item) do {     strcpy(tempString + 4, (item)->name());     tempFloat = (float)strlen(tempString + 4);     rge_write(fd, &tempFloat, 4);     rge_write(fd, tempString + 4, (int)tempFloat);     tempFloat = (float)(item)->typeID(); rge_write(fd, &tempFloat, 4);     tempFloat = (float)(item)->gameID(); rge_write(fd, &tempFloat, 4);     tempFloat = (float)(item)->uniqueID(); rge_write(fd, &tempFloat, 4);     tempBOOL = (int)(item)->x(); rge_write(fd, &tempBOOL, 4);     tempBOOL = (int)(item)->y(); rge_write(fd, &tempBOOL, 4);     tempBOOL = (int)(item)->z(); rge_write(fd, &tempBOOL, 4);     tempBOOL = (int)(item)->xSize(); rge_write(fd, &tempBOOL, 4);     tempBOOL = (int)(item)->ySize(); rge_write(fd, &tempBOOL, 4);     tempBOOL = (int)(item)->zSize(); rge_write(fd, &tempBOOL, 4);     local_110 = (item)->skip(); rge_write(fd, &local_110, 4);     local_110 = (item)->inProgress(); rge_write(fd, &local_110, 4);     local_110 = (item)->built(); rge_write(fd, &local_110, 4);     tempFloat = (float)(item)->buildAttempts(); rge_write(fd, &tempFloat, 4); } while(0)

int ConstructionAIModule::save(int fd) const
{
    float tempFloat;
    int tempBOOL;
    int local_110;
    ConstructionItem* local_10c;
    char tempString[257];

    *(const ConstructionAIModule**)tempString = this;
    rge_write(fd, (void*)&this->numberConstructionLotsValue, 4);
    strcpy(tempString + 4, this->constructionPlanNameValue);
    tempFloat = (float)strlen(tempString + 4);
    rge_write(fd, &tempFloat, 4);
    rge_write(fd, tempString + 4, (int)tempFloat);
    rge_write(fd, (void*)&this->xReferencePointValue, 4);
    rge_write(fd, (void*)&this->yReferencePointValue, 4);
    rge_write(fd, (void*)&this->zReferencePointValue, 4);
    rge_write(fd, (void*)&this->mapXSizeValue, 4);
    rge_write(fd, (void*)&this->mapYSizeValue, 4);

    ConstructionItem* item = this->constructionLots.next;
    local_10c = (ConstructionItem*)((char*)this + 0xF4);
    if (item != local_10c) {
        do {
            if (item == 0) break;
            WRITE_ITEM(item);
            item = item->next;
        } while (item != local_10c);
    }

    rge_write(fd, (void*)((char*)this + 0x174), 4);
    item = *(ConstructionItem**)((char*)this + 0x1E4);
    local_10c = (ConstructionItem*)((char*)this + 0x178);
    if (item != local_10c) {
        do {
            if (item == 0) return 1;
            WRITE_ITEM(item);
            item = item->next;
        } while (item != local_10c);
    }
    return 1;
}
