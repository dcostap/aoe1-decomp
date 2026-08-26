#ifndef AICONITM_CONTEXT_H
#define AICONITM_CONTEXT_H

// Authentic local declaration surface for C:\\msdev\\work\\age1_x1\\aiconitm.cpp.
//
// The PDB order is four ConstructionItem constructors, its virtual destructor,
// four free comparison operators, and the eight small member methods.  The
// BaseItem prefix is 0x6c bytes; ConstructionItem adds its list links and
// three state fields at offsets 0x6c through 0x7c.

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
    BaseItem(int typeID, int gameID, int uniqueID, const char* name,
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

    ConstructionItem* next;
    ConstructionItem* prev;
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;

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
