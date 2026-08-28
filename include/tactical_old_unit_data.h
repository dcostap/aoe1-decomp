#ifndef AOE1_TACTICAL_OLD_UNIT_DATA_H
#define AOE1_TACTICAL_OLD_UNIT_DATA_H

class OldUnitData {
public:
    int id;
    int data1;
    int data2;
    int data3;
};

typedef char tactical_old_unit_data_size_check[
    (sizeof(OldUnitData) == 0x10) ? 1 : -1];

#endif
