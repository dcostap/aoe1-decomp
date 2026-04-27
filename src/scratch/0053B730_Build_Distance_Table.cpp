// vis_unit.cpp target: Visible_Unit_Manager::Build_Distance_Table
// builds 16x16 byte distance lookup from the NormalLOS offset tables.

void operator_delete(void* ptr);
extern "C" void* __cdecl malloc(unsigned int size);

extern int* NormalLOS;
extern int* PTR_Edge_Offsets_N16;

class Visible_Unit_Manager {
public:
    char gap_00[0x20];
    signed char* distanceTable;

    void Build_Distance_Table();
};

void Visible_Unit_Manager::Build_Distance_Table() {
    if (this->distanceTable != 0) {
        operator_delete(this->distanceTable);
    }

    signed char* table = (signed char*)malloc(0x100);
    this->distanceTable = table;
    for (int i = 0; i < 0x100; i++) {
        table[i] = 0xff;
    }

    int distance = 0;
    int** offsets = &NormalLOS;
    do {
        int* entry;
        entry = *offsets;
        int row = entry[0];
        while (row != 999) {
            int first = entry[1];
            int last = entry[2];
            if (row >= 0 && row <= 0x0f) {
                if (first < 0) {
                    first = 0;
                }
                if (last > 0x0f) {
                    last = 0x0f;
                }
                int index = (row << 4) + first;
                if (first <= last) {
                    int count = last - first + 1;
                    do {
                        if (this->distanceTable[index] == -1) {
                            this->distanceTable[index] = (signed char)distance;
                        }
                        index++;
                        count--;
                    } while (count != 0);
                }
            }
            entry += 3;
            row = entry[0];
        }
        offsets++;
        distance++;
    } while ((int)offsets <= (int)&PTR_Edge_Offsets_N16);
}
