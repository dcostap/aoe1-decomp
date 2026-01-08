#pragma once
#include "../common.h"

class BaseItem       {
public:
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
    BaseItem(BaseItem* param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~BaseItem() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void loggingHistory();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void setLogHistory();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void toggleLogHistory();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void setHistoryFilename();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void loggingCommonHistory();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void setLogCommonHistory();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void toggleLogCommonHistory();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void loadState();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void saveState();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void gleanState();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void processMessage();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void update();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void setCallbackMessage();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void filterOutMessage();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void displayBuildList();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void loadBuildList();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void numberBuiltOrInProgressItemsOfType();

    // --- Non-Virtual Members ---
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
static_assert(offsetof(BaseItem, skipValue) == 0x68, "BaseItem Offset Mismatch");

