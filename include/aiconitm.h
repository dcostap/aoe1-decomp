#ifndef AOE1_AICONITM_H
#define AOE1_AICONITM_H

class BaseItem {
public:
    virtual ~BaseItem();

    int typeIDValue;
    int gameIDValue;
    int uniqueIDValue;
    char nameValue[64];
    float xValue;
    float yValue;
    float zValue;
    float xSizeValue;
    float ySizeValue;
    float zSizeValue;
    int skipValue;

    BaseItem();
    BaseItem(int typeID, int gameID, int uniqueID, char* name,
             float x, float y, float z, float xSize, float ySize, float zSize);
    BaseItem(BaseItem* other);
    BaseItem(const BaseItem& other);
};

typedef char aiconitm_baseitem_size[(sizeof(BaseItem) == 0x6c) ? 1 : -1];

class ConstructionItem : public BaseItem {
public:
    ConstructionItem();
    ConstructionItem(float x, float y, float z, float xSize, float ySize,
                     float zSize, int typeID, char* name);
    ConstructionItem(ConstructionItem* other);
    ConstructionItem(const ConstructionItem& other);
    virtual ~ConstructionItem();

    ConstructionItem* next;      // +0x6c
    ConstructionItem* prev;      // +0x70
    int inProgressValue;         // +0x74
    int builtValue;              // +0x78
    int buildAttemptsValue;      // +0x7c

    int inProgress() const;
    int built() const;
    int buildAttempts() const;
    void setInProgress(int value);
    void setBuilt(int value);
    void incrementBuildAttempts();
    void decrementBuildAttempts();
    void setBuildAttempts(int value);
};

typedef char aiconitm_constructionitem_size[
    (sizeof(ConstructionItem) == 0x80) ? 1 : -1];
typedef char aiconitm_inprogress_offset[
    ((char*)&((ConstructionItem*)0)->inProgressValue - (char*)0 == 0x74) ? 1 : -1];
typedef char aiconitm_built_offset[
    ((char*)&((ConstructionItem*)0)->builtValue - (char*)0 == 0x78) ? 1 : -1];
typedef char aiconitm_build_attempts_offset[
    ((char*)&((ConstructionItem*)0)->buildAttemptsValue - (char*)0 == 0x7c) ? 1 : -1];

int __cdecl operator==(const ConstructionItem& left, const ConstructionItem& right);
int __cdecl operator!=(const ConstructionItem& left, const ConstructionItem& right);
int __cdecl operator<(const ConstructionItem& left, const ConstructionItem& right);
int __cdecl operator>(const ConstructionItem& left, const ConstructionItem& right);

#endif
