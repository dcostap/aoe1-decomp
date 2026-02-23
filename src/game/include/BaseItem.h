#pragma once
#include "common.h"

class BaseItem {
public:
    BaseItem();
    BaseItem(int param_1, int param_2, int param_3, char* param_4, float param_5, float param_6, float param_7, float param_8, float param_9, float param_10);
    BaseItem(BaseItem* param_1);
    BaseItem(const BaseItem& param_1);

    // Virtuals (best-effort)
    virtual ~BaseItem(); // vt[0] (0x0)

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
    void setTypeID(int param_1);
    void setGameID(int param_1);
    void setUniqueID(int param_1);
    void setName(char* param_1);
    void setX(float param_1);
    void setY(float param_1);
    void setZ(float param_1);
    void setXSize(float param_1);
    void setYSize(float param_1);
    void setZSize(float param_1);
    void setSkip(int param_1);

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
};

int operator==(const BaseItem& param_1, const BaseItem& param_2);
int operator!=(const BaseItem& param_1, const BaseItem& param_2);
int operator<(const BaseItem& param_1, const BaseItem& param_2);
int operator>(const BaseItem& param_1, const BaseItem& param_2);

static_assert(sizeof(BaseItem) == 0x6C, "Size mismatch");
