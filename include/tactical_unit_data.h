#ifndef AOE1_TACTICAL_UNIT_DATA_H
#define AOE1_TACTICAL_UNIT_DATA_H

struct UnitData {
    int id;
    int data1;
    int data2;
    int data3;
    int target;
    unsigned long lastTaskTime;
};

typedef char tactical_unit_data_size_check[
    (sizeof(UnitData) == 0x18) ? 1 : -1];

#endif
