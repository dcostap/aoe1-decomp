// VA: 0053C680 RGE_Visible_Map::recomputeExplored (56B)
// PDB source: visible.cpp lines 483-497
// tried decompiler-style do/while, height-vs-y compare, and row local variants
// best shape keeps prologue/register bank mostly right, but VC5 still uses test ebx,ebx instead of cmp ebx,edi and refuses to save/use ebp for the row base load chain

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

    y = 0;
    this->numberTilesExploredValue = 0;
    if (this->heightValue > y) {
        do {
            int x;

            x = 0;
            if (this->widthValue > 0) {
                unsigned char* row;

                row = *(this->map_offsets + y);
                do {
                    if (row[x] != 0xFF) {
                        this->numberTilesExploredValue = this->numberTilesExploredValue + 1;
                    }
                    x = x + 1;
                } while (x < this->widthValue);
            }
            y = y + 1;
        } while (y < this->heightValue);
    }
}
