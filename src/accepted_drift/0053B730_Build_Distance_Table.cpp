// vis_unit.cpp target: Visible_Unit_Manager::Build_Distance_Table
// ACCEPTED_DRIFT 2026-05-21 (Boss approved): exact-size, behavior-equivalent, localized inner-loop addressing drift.
// Best validation: 173B, 5.2023% positional / 4.0462% edit, first mismatch at inner table write hunk.
// Drift is confined to the distance-table byte test/store in the innermost loop: original materializes
// `table + index` in ECX (`mov ecx,[ebp+20]; add ecx,eax; cmp byte [ecx],ff; mov [ecx],bl`), while
// rebuilt keeps the same base and index separate (`mov ecx,[ebp+20]; cmp byte [ecx+eax],ff; mov [ecx+eax],bl`).
// The allocation/free, memset-to-FF, outer offset-table walk, clipping, counts, loop exits, and register/stack cleanup
// otherwise resync. Tried pointer-temp, unsigned/signed table surfaces, register entry, entry-loop do/while, fill-loop
// spelling, unsigned row predicate, inner pointer lvalue/cast variants, count while/do variants, and flags /Ob0,
// /O2-no-/Oy, /Oa, /O1, /G5. Pointer-temp variants force worse ESI/EDI allocation; this is the tightest basin.

void operator_delete(void* ptr);
extern "C" void* __cdecl malloc(unsigned int size);

extern int* NormalLOS;
extern int* PTR_Edge_Offsets_N16;

class Visible_Unit_Manager {
public:
    char gap_00[0x20];
    unsigned char* distanceTable;

    void Build_Distance_Table();
};

void Visible_Unit_Manager::Build_Distance_Table()
{
    if (this->distanceTable != 0) {
        operator_delete(this->distanceTable);
    }

    unsigned char* table = (unsigned char*)malloc(0x100);
    this->distanceTable = table;
    for (int i = 0; i < 0x100; i++) {
        table[i] = 0xff;
    }

    int distance = 0;
    int** offsets = &NormalLOS;
    do {
        register int* entry = *offsets;
        int row = entry[0];
        while (row != 999) {
            int first = entry[1];
            int last = entry[2];
            if (row >= 0 && row <= 15) {
                if (first < 0) {
                    first = 0;
                }
                if (last > 15) {
                    last = 15;
                }
                int index = (row << 4) + first;
                if (first <= last) {
                    int count = last - first + 1;
                    do {
                        unsigned char* t = this->distanceTable;
                        if (t[index] == 0xff) {
                            t[index] = (unsigned char)distance;
                        }
                        index++;
                        count--;
                    } while (count);
                }
            }
            entry += 3;
            row = entry[0];
        }
        offsets++;
        distance++;
    } while ((int)offsets <= (int)&PTR_Edge_Offsets_N16);
}
