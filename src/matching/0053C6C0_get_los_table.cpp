struct LOSTBL;

extern LOSTBL* Edge_Offsets_T16[17];
extern LOSTBL* Edge_Offsets_N16[17];

class RGE_Visible_Map {
public:
    LOSTBL* get_los_table(int distance, int diagonal);
};

LOSTBL* RGE_Visible_Map::get_los_table(int distance, int diagonal) {
    if (distance > 0x10) {
        distance = 0x10;
    }
    if (distance < 0) {
        distance = 0;
    }
    if (diagonal != 0) {
        return Edge_Offsets_T16[distance];
    }
    return Edge_Offsets_N16[distance];
}
