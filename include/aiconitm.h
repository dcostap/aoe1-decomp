#ifndef AOE1_AICONITM_H
#define AOE1_AICONITM_H

#include "aibitm.h"

class ConstructionItem : public BaseItem {
  public:
    ConstructionItem();
    ConstructionItem(float x, float y, float z, float xs, float ys, float zs, int ti, char* n);
    ConstructionItem(ConstructionItem* ci);
    ConstructionItem(const ConstructionItem& ci);
    virtual ~ConstructionItem();

    ConstructionItem* next; // +0x6c
    ConstructionItem* prev; // +0x70
    int inProgressValue;    // +0x74
    int builtValue;         // +0x78
    int buildAttemptsValue; // +0x7c

    int inProgress() const;
    int built() const;
    int buildAttempts() const;
    void setInProgress(int p);
    void setBuilt(int b);
    void incrementBuildAttempts();
    void decrementBuildAttempts();
    void setBuildAttempts(int v);
};

typedef char aiconitm_constructionitem_size[(sizeof(ConstructionItem) == 0x80) ? 1 : -1];
typedef char
    aiconitm_inprogress_offset[((char*) &((ConstructionItem*) 0)->inProgressValue - (char*) 0 == 0x74) ? 1 : -1];
typedef char aiconitm_built_offset[((char*) &((ConstructionItem*) 0)->builtValue - (char*) 0 == 0x78) ? 1 : -1];
typedef char
    aiconitm_build_attempts_offset[((char*) &((ConstructionItem*) 0)->buildAttemptsValue - (char*) 0 == 0x7c) ? 1 : -1];

int __cdecl operator==(const ConstructionItem& one, const ConstructionItem& two);
int __cdecl operator!=(const ConstructionItem& one, const ConstructionItem& two);
int __cdecl operator<(const ConstructionItem& one, const ConstructionItem& two);
int __cdecl operator>(const ConstructionItem& one, const ConstructionItem& two);

#endif
