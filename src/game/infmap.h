#pragma once
#include "../common.h"

class InfluenceMap       {
public:
    int xSizeValue;                          // 0x4
    int ySizeValue;                          // 0x8
    int xReferencePointValue;                // 0xC
    int yReferencePointValue;                // 0x10
    uchar* valueValue;                       // 0x14
    uchar** rowValue;                        // 0x18
    int coverageCountValue;                  // 0x1C
    int connectionCountValue;                // 0x20
    uchar unchangeableLimitValue;            // 0x24

    InfluenceMap(int param_1, int param_2, uchar param_3);
    InfluenceMap(int param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~InfluenceMap() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void copy_obj();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void modify();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void modify_delta();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void modify_percent();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void make_new_obj();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void make_new_master();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void check_placement();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void alignment();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void calc_base_damage_ability();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void play_command_sound();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void play_move_sound();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void create_task_list();

    // --- Non-Virtual Members ---
    int initialize(uchar param_1);
    void save(int param_1);
    void load(int param_1);
    void printToFile(char* param_1);
    void setReferencePoint(int param_1, int param_2);
    int lookupValue(int param_1, int param_2);
    int setValue(int param_1, int param_2, uchar param_3);
    int setValue(int param_1, int param_2, int param_3, int param_4, uchar param_5);
    int incrementValue(int param_1, int param_2, uchar param_3);
    int incrementValue(int param_1, int param_2, int param_3, int param_4, uchar param_5);
    int decrementValue(int param_1, int param_2, uchar param_3);
    int decrementValue(int param_1, int param_2, int param_3, int param_4, uchar param_5);
    int setCoverageCount(XYPoint* param_1, XYPoint* param_2, int param_3);
    int setConnectionCount(XYPoint* param_1, XYPoint* param_2, int param_3, int param_4, int param_5, int param_6);
    int coverageIncluding(XYPoint* param_1, XYPoint* param_2, uchar param_3, uchar param_4);
    int connectionsIncluding(XYPoint* param_1, XYPoint* param_2, uchar param_3, uchar param_4, int param_5, int param_6, int param_7);
    void setUnchangeableLimit(uchar param_1);
    int maxValue();
};

static_assert(sizeof(InfluenceMap) == 0x28, "InfluenceMap Size Mismatch");
static_assert(offsetof(InfluenceMap, unchangeableLimitValue) == 0x24, "InfluenceMap Offset Mismatch");

