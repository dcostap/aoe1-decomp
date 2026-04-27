// VA: 0045A500 update (462B)
// map.cpp

extern int game_tick_count;

class RGE_Map {
public:
    char gap4[0x4];
    int field_8;
    
    void update(int a1);
};

int game_tick_count = 0;

void RGE_Map::update(int a1) {
    int diff = a1 - game_tick_count;
    if (diff > 100) {
        field_8 = diff;
    }
}
