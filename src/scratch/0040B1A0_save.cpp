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
//    diagnostic and did not produce a compliant exact source.
// 5: top-tested while walks reproduce the oracle's bottom sentinel compare followed by the null test;
//    the outer-if/do-while form leaves an extra inverted bottom branch.
// 6: the donor-TU /GX response-file context changed only the frame-family experiment and not emitted
//    code, so the custom flags file was removed.
// 7: the initial plan-name payload recomputes strlen for the data write; reusing the stored length was
//    the major structural mismatch. The natural second strlen reaches exact size/instruction/call/CFG
//    parity and reduces positional drift from 1108 to 58 bytes.
// 9: scoped the initial plan-name length to test natural temporary lifetime reuse; emitted code stayed
//    unchanged, so the localized stack-home drift is not controlled by that lifetime.
// 8: remaining 58 bytes are localized stack displacements: tempString and length/type homes are four
//    bytes high while the float home is four bytes low. Explicit self overlay worsens size by 4; source
//    local declaration order is codegen-neutral. Best readable reconstruction remains in scratch.
// 10: ten local, ABI, header, and control-flow probes stayed in the same 58-byte codegen basin.
// 11: split or scoped length locals, a bit union, and a typed scratch aggregate worsened the frame or body;
//     the natural separate int/float homes remain the supported source model.
// 12: a 64-sample ambient declaration sweep and 768 source/flag variants (/GX, /Ow, /Oi, /Og, /Ot, /Ob0)
//     all emitted one 1263-byte basin. No exact variant was found.
// 13: PDB symbols prove target locals named tempInt, tempBOOL, and tempFloat; exact-name/order,
//     loop scopes, explicit serializer expansion, direct sentinel tests, C++ rge_write linkage,
//     union overlap, and array-subscript spellings all remained in the 58-byte basin.

#include <string.h>

extern "C" void rge_write(int fd, void* src, int size);

typedef unsigned char uchar;

class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[0x68];

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
    ConstructionItem* next;
    ConstructionItem* prev;
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;
    virtual ~ConstructionItem();
    int inProgress();
    int built();
    int buildAttempts();
};
class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};
class ConstructionAIModule : public AIModule {
public:
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
    virtual int save(int fd);
};

#define WRITE_ITEM(item) do {     strcpy(tempString + 4, (item)->name());     tempInt = strlen(tempString + 4);     rge_write(fd, &tempInt, 4);     rge_write(fd, tempString + 4, tempInt);     tempInt = (item)->typeID(); rge_write(fd, &tempInt, 4);     tempInt = (item)->gameID(); rge_write(fd, &tempInt, 4);     tempInt = (item)->uniqueID(); rge_write(fd, &tempInt, 4);     tempFloat = (item)->x(); rge_write(fd, &tempFloat, 4);     tempFloat = (item)->y(); rge_write(fd, &tempFloat, 4);     tempFloat = (item)->z(); rge_write(fd, &tempFloat, 4);     tempFloat = (item)->xSize(); rge_write(fd, &tempFloat, 4);     tempFloat = (item)->ySize(); rge_write(fd, &tempFloat, 4);     tempFloat = (item)->zSize(); rge_write(fd, &tempFloat, 4);     status_value = (item)->skip(); rge_write(fd, &status_value, 4);     status_value = (item)->inProgress(); rge_write(fd, &status_value, 4);     status_value = (item)->built(); rge_write(fd, &status_value, 4);     status_value = (item)->buildAttempts(); rge_write(fd, &status_value, 4); } while(0)

int ConstructionAIModule::save(int fd)
{
    char tempString[257];
    int tempInt;
    float tempFloat;
    int status_value;
    ConstructionItem* sentinel;
    rge_write(fd, (void*)&this->numberConstructionLotsValue, 4);
    strcpy(tempString + 4, this->constructionPlanNameValue);
    tempInt = strlen(tempString + 4);
    rge_write(fd, &tempInt, 4);
    rge_write(fd, tempString + 4, strlen(tempString + 4));
    rge_write(fd, (void*)&this->xReferencePointValue, 4);
    rge_write(fd, (void*)&this->yReferencePointValue, 4);
    rge_write(fd, (void*)&this->zReferencePointValue, 4);
    rge_write(fd, (void*)&this->mapXSizeValue, 4);
    rge_write(fd, (void*)&this->mapYSizeValue, 4);

    ConstructionItem* item = this->constructionLots.next;
    sentinel = &this->constructionLots;
    while (item != sentinel) {
        if (item == 0) break;
        WRITE_ITEM(item);
        item = item->next;
    }

    rge_write(fd, (void*)&this->numberSomething, 4);
    item = this->secondList.next;
    sentinel = &this->secondList;
    while (item != sentinel) {
        if (item == 0) return 1;
        WRITE_ITEM(item);
        item = item->next;
    }
    return 1;
}
