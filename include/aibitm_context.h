#ifndef AOE1_AIBITM_CONTEXT_H
#define AOE1_AIBITM_CONTEXT_H

// Authentic compiler-facing surface for C:\\msdev\\work\\age1_x1\\aibitm.cpp.
// The PDB source order is recorded by src/aibitm_tu.cpp.

#include <string.h>

extern const char default_item_name[];

class BaseItem {
public:
    virtual ~BaseItem();

    int typeIDValue;              // +0x04
    int gameIDValue;              // +0x08
    int uniqueIDValue;            // +0x0C
    char nameValue[64];           // +0x10
    float xValue;                 // +0x50
    float yValue;                 // +0x54
    float zValue;                 // +0x58
    float xSizeValue;             // +0x5C
    float ySizeValue;             // +0x60
    float zSizeValue;             // +0x64
    int skipValue;                // +0x68

    BaseItem();
    BaseItem(int typeID, int gameID, int uniqueID, char* name,
             float x, float y, float z, float xSize, float ySize, float zSize);
    BaseItem(BaseItem* other);
    BaseItem(const BaseItem& other);

    int typeID() const;
    int gameID() const;
    int uniqueID() const;
    char* name();
    float x() const;
    float y() const;
    float z() const;
    float xSize() const;
    float ySize() const;
    float zSize() const;
    int skip() const;

    void setTypeID(int value);
    void setGameID(int value);
    void setUniqueID(int value);
    void setName(char* value);
    void setX(float value);
    void setY(float value);
    void setZ(float value);
    void setXSize(float value);
    void setYSize(float value);
    void setZSize(float value);
    void setSkip(int value);
};

int __cdecl operator==(const BaseItem& left, const BaseItem& right);
int __cdecl operator!=(const BaseItem& left, const BaseItem& right);
int __cdecl operator<(const BaseItem& left, const BaseItem& right);
int __cdecl operator>(const BaseItem& left, const BaseItem& right);

typedef char aibitm_base_item_size[(sizeof(BaseItem) == 0x6C) ? 1 : -1];

#endif
