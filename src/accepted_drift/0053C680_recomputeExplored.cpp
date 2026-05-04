// VA: 0053C680 RGE_Visible_Map::recomputeExplored (56B)
// PDB source: visible.cpp lines 483-497
// ACCEPTED_DRIFT: 1-byte SIB encoding difference only.
//   [eax+ebp] (3 bytes, original) vs [ebp+eax+0] (4 bytes, rebuilt).
//   Equivalent address encoding — same byte is read before the same inc/loop.
//   VC5's C++ reference forces the LEA+MOV+EBP pattern (matching prologue +
//   row loading), but also forces ebp-as-base in the SIB (adding a disp8=0).
//   All 49 other bytes match perfectly; the 7 positional-diff bytes are all
//   cascading consequences of this 1-byte SIB size difference (offset shifts).
//
//   Repeated attempts to get [eax+ebp] from a reference-based load: tried
//   x[ref], *(x+*row_ptr), row_ptr[0][x], all produce same [ebp+eax+0] SIB.
//   Without the reference (plain pointer), VC5 optimizes away the two-step
//   LEA+MOV and produces direct mov, losing push ebp and cmp ebx,edi.

class RGE_Visible_Map {
public:
    unsigned char** map_offsets;
    void* world;
    void* player;
    void* map;
    unsigned char* visible_map;
    int widthValue;
    int heightValue;
    int numberTilesExploredValue;

    void recomputeExplored(void);
};

void RGE_Visible_Map::recomputeExplored(void) {
    int y;
    int x;

    y = 0;
    this->numberTilesExploredValue = 0;
    if (this->heightValue > y) {
        do {
            x = 0;
            if (this->widthValue > 0) {
                unsigned char** row_ptr = this->map_offsets + y;
                do {
                    if (row_ptr[0][x] != 0xFF) {
                        this->numberTilesExploredValue = this->numberTilesExploredValue + 1;
                    }
                    x = x + 1;
                } while (x < this->widthValue);
            }
            y = y + 1;
        } while (y < this->heightValue);
    }
}
