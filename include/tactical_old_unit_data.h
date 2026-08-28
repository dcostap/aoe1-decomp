#ifndef AOE1_TACTICAL_OLD_UNIT_DATA_H
#define AOE1_TACTICAL_OLD_UNIT_DATA_H

struct OldUnitData {
    int id;
    int data1;
    int data2;
    int data3;
};

struct OldUnitData2 {
    int id;
    int data1;
    int data2;
    int data3;
    int target;
};

typedef char tactical_old_unit_data_size_check[
    (sizeof(OldUnitData) == 0x10) ? 1 : -1];
typedef char tactical_old_unit_data2_size_check[
    (sizeof(OldUnitData2) == 0x14) ? 1 : -1];

#endif
