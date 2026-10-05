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
    BaseItem(int tid, int gid, int uid, char* n, float x, float y, float z, float xs, float ys, float zs);
    BaseItem(BaseItem* bi);
    BaseItem(const BaseItem& bi);

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

    void setTypeID(int v);
    void setGameID(int v);
    void setUniqueID(int v);
    void setName(char* n);
    void setX(float v);
    void setY(float v);
    void setZ(float v);
    void setXSize(float v);
    void setYSize(float v);
    void setZSize(float v);
    void setSkip(int v);
};

int __cdecl operator==(const BaseItem& one, const BaseItem& two);
int __cdecl operator!=(const BaseItem& one, const BaseItem& two);
int __cdecl operator<(const BaseItem& one, const BaseItem& two);
int __cdecl operator>(const BaseItem& one, const BaseItem& two);

typedef char aibitm_base_item_size[(sizeof(BaseItem) == 0x6C) ? 1 : -1];

#endif
