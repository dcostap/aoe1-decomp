// 0040B1A0 ConstructionAIModule::save
// Attempt log:
// 1: reconstructed the two serialized sentinel-list walks from the packet, preserving the original
//    null/sentinel exits and duplicated name/field write sequence.
// 2: corrected the item ABI/layout to a full 0x80-byte ConstructionItem and restored the +174/+178/+1F8
//    field ownership; the reference addresses and all 67 direct calls now align.
// 3: serialized strlen/type/state values through integer homes and float accessors through a float home;
//    this removes all spurious __ftol calls and reaches the original 0x118 frame and 1263-byte size.
// 4: removing the explicit tempString self overlay is the cleaner source shape and leaves one natural
//    self home, but VC5 still places tempString+4 at esp+28 (original esp+24) and shifts the first
//    scratch home by four bytes. Explicit overlay, declaration order, and 261-byte-buffer probes were
//    diagnostic and did not produce a compliant exact source. Remaining drift is stack/local topology,
//    not behavior or call set; leave this typed reconstruction in scratch.

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
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;
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
    char constructionPlanNameValue[0x104]; // +1F8
    int xReferencePointValue; // +2FC
    int yReferencePointValue; // +300
    int zReferencePointValue; // +304
    int mapXSizeValue; // +308
    int mapYSizeValue; // +30C
    int save(int fd);
};

#define WRITE_ITEM(item) do {     strcpy(tempString + 4, (item)->name());     tempInt = strlen(tempString + 4);     rge_write(fd, &tempInt, 4);     rge_write(fd, tempString + 4, tempInt);     tempInt = (item)->typeID(); rge_write(fd, &tempInt, 4);     tempInt = (item)->gameID(); rge_write(fd, &tempInt, 4);     tempInt = (item)->uniqueID(); rge_write(fd, &tempInt, 4);     tempFloat = (item)->x(); rge_write(fd, &tempFloat, 4);     tempFloat = (item)->y(); rge_write(fd, &tempFloat, 4);     tempFloat = (item)->z(); rge_write(fd, &tempFloat, 4);     tempFloat = (item)->xSize(); rge_write(fd, &tempFloat, 4);     tempFloat = (item)->ySize(); rge_write(fd, &tempFloat, 4);     tempFloat = (item)->zSize(); rge_write(fd, &tempFloat, 4);     status_value = (item)->skip(); rge_write(fd, &status_value, 4);     status_value = (item)->inProgress(); rge_write(fd, &status_value, 4);     status_value = (item)->built(); rge_write(fd, &status_value, 4);     status_value = (item)->buildAttempts(); rge_write(fd, &status_value, 4); } while(0)

int ConstructionAIModule::save(int fd)
{
    float tempFloat;
    int tempInt;
    int status_value;
    ConstructionItem* sentinel;
    char tempString[257];

    rge_write(fd, (void*)&this->numberConstructionLotsValue, 4);
    strcpy(tempString + 4, this->constructionPlanNameValue);
    tempInt = strlen(tempString + 4);
    rge_write(fd, &tempInt, 4);
    rge_write(fd, tempString + 4, tempInt);
    rge_write(fd, (void*)&this->xReferencePointValue, 4);
    rge_write(fd, (void*)&this->yReferencePointValue, 4);
    rge_write(fd, (void*)&this->zReferencePointValue, 4);
    rge_write(fd, (void*)&this->mapXSizeValue, 4);
    rge_write(fd, (void*)&this->mapYSizeValue, 4);

    ConstructionItem* item = this->constructionLots.next;
    sentinel = &this->constructionLots;
    if (item != sentinel) {
        do {
            if (item == 0) break;
            WRITE_ITEM(item);
            item = item->next;
        } while (item != sentinel);
    }

    rge_write(fd, (void*)&this->numberSomething, 4);
    item = this->secondList.next;
    sentinel = &this->secondList;
    if (item != sentinel) {
        do {
            if (item == 0) return 1;
            WRITE_ITEM(item);
            item = item->next;
        } while (item != sentinel);
    }
    return 1;
}
