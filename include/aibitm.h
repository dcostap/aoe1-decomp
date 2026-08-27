#ifndef AOE1_AIBITM_H
#define AOE1_AIBITM_H

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
