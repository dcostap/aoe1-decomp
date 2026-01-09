#pragma once
#include "common.h"

class BaseItem {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
    int typeIDValue;                         // 0x4
    int gameIDValue;                         // 0x8
    int uniqueIDValue;                       // 0xC
    char nameValue[64];                      // 0x10
    float xValue;                            // 0x50
    float yValue;                            // 0x54
    float zValue;                            // 0x58
    float xSizeValue;                        // 0x5C
    float ySizeValue;                        // 0x60
    float zSizeValue;                        // 0x64
    int skipValue;                           // 0x68

    BaseItem();
    BaseItem(int param_1, int param_2, int param_3, char* param_4, float param_5, float param_6, float param_7, float param_8, float param_9, float param_10);
    BaseItem(BaseItem* param_1);
    ~BaseItem();
    int typeID();
    int gameID();
    int uniqueID();
    char* name();
    float x();
    float y();
    float z();
    float xSize();
    float ySize();
    float zSize();
    int skip();
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
};

static_assert(sizeof(BaseItem) == 0x6C, "BaseItem Size Mismatch");

