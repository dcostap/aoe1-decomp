// Attempt log for 00411B80 ResearchAIModule::loadTechnologyTree
// try 1: natural reconstruction from packet/decompiler, with ResourceItem/TechnologyItem ctor surfaces and /GX; exact size but wrong EH prologue/order due early ResourceItem ctor.
// try 2: move ResourceItem construction into loop only; improved edit diff 18%, but frame 0x1CC vs original 0x1D0 and temp offsets 4 low.
// try 3: add one unused int local to recover original frame/offsets; name[68] fixed frame but shifted name arg 4 low.
// try 4: use name[64] plus address-taken pad after name; optimized out, back to 0x1CC.
// try 5: make temp[260] with name[64] to force frame growth; worse offsets/diff than name[68], rolled back.
// try 6: restore best name[68]/temp[256] layout.
// try 7: use explicit tail local for list insertion to preserve prev pointer through EH-state store; improved to 2.04% positional, remaining name/temp copy offsets 4 low around ctor.
// try 8: enlarge name to 72; worsened to 4.55% and early branch displacement, rolled back.
// try 9: restore name[68] best layout.
// try 10: split allocation result into alloc local; no codegen change.
// try 11: load oldTail after item->next assignment; improved to only 0.63%, remaining ctor spill/copy stack offsets 4 low.
// try 12: name[64] plus explicit pad before name; pad optimized out/frame 0x1CC, worse.
// try 13: name[64] plus temp[260] with pad-before-name layout; worse 1.88%, rolled back.
// try 14: restore best name[68]/temp[256] layout.
// try 15: /GX /Oy- flag probe; too small 608B, rolled back.
// try 16: /GX /O1 flag probe; too small 468B, rolled back.
// try 17: model the observed 4-byte local immediately before the 64-byte name as a typed aggregate; reduced the gap to two bytes, but EH temporaries stayed four bytes low.
// try 18: plain 64-byte name plus top-level allocation pointer shrank the frame to 0x1CC and worsened broad codegen; rolled back.
// try 19: modeling the fifth sscanf integer as rc[4] kept its proven output slot live and restored the plain 64-byte name; exact match.
// Exact result: rc[5] is the natural source model for the five integer destinations, including the formerly apparent rc+4 overflow; it also reproduces the original local reuse in the allocation/constructor EH staging.

#include <stdio.h>
#include <string.h>
#include <io.h>

class ResourceItem {
public:
    char data[0x70];
    ResourceItem(int, int*);
    ResourceItem(ResourceItem const&);
    ~ResourceItem();
};
class TechnologyItem {
public:
    int pad0;
    TechnologyItem* next;
    TechnologyItem* prev;
    char rest[0x48];
    TechnologyItem(int, char*, ResourceItem);
};
class ResearchAIModule {
public:
    char pad0[0xF4];
    TechnologyItem techTree;
    int techTreeLengthValue;
    char techTreeNameValue[260];
    void removeOldTechTree();
    void logCommonHistory(char*, ...);
    int loadTechnologyTree(char*);
};

int ResearchAIModule::loadTechnologyTree(char* filename)
{
    int rc[5];
    char name[64];
    char temp[256];
    FILE* fp;
    TechnologyItem* item;
    TechnologyItem* tail;
    char* id;

    if (this->techTreeLengthValue > 0) {
        this->removeOldTechTree();
    }

    strcpy(this->techTreeNameValue, filename);
    id = this->techTreeNameValue;
    if (strcmp(id, "NONE") != 0) {
        if (id == 0) goto no_tree;
        this->logCommonHistory("Loading tech tree in file '%s'.", filename);
        sprintf(temp, "%s", id);
        fp = fopen(temp, "r");
        if (fp == 0) return 0;
        if (fgets(temp, 0x100, fp) != 0) {
            tail = &this->techTree;
            do {
                sscanf(temp, "%*c%d %s %*d %*d %d %d %d %d %*d %*d %*d %*d", rc, name, rc + 1, rc + 2, rc + 3, rc + 4);
                ResourceItem newRCost2(4, rc + 1);
                TechnologyItem* alloc = new TechnologyItem(rc[0], name, newRCost2);
                item = alloc;
                item->next = tail;
                TechnologyItem* oldTail = this->techTree.prev;
                item->prev = oldTail;
                oldTail->next = item;
                this->techTree.prev = item;
                this->techTreeLengthValue++;
            } while (fgets(temp, 0x100, fp) != 0);
        }
        fclose(fp);
        if (strstr(id, ".tmp") != 0) {
            unlink(id);
        }
    } else {
        if (id == 0) {
no_tree:
            strcpy(0, "NULL");
        }
        this->logCommonHistory("There is no tech tree to load.");
    }
    return 1;
}
