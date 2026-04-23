// tried the direct decompiler-style do/while shape first; mismatch stayed at the initial height-check compare
// tried local height/width temps and then a for-loop rewrite; codegen moved deeper and got worse
// leaving this in scratch because the remaining gap is control-flow / prolog shape, not call behavior

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
    int y = 0;
    this->numberTilesExploredValue = 0;
    if (this->heightValue > 0) {
        do {
            int x = 0;
            if (this->widthValue > 0) {
                unsigned char* row = this->map_offsets[y];
                do {
                    if (row[x] != 0xFF) {
                        this->numberTilesExploredValue++;
                    }
                    x++;
                } while (x < this->widthValue);
            }
            y++;
        } while (y < this->heightValue);
    }
}
