// tried the straightforward time-threshold/toggle shape first
// current hypothesis: any remaining mismatch would be in the shared layout or base-call basin

unsigned long debug_timeGetTime(char* param_1, int param_2);

class RGE_Diamond_Map {
public:
    void draw_objects();
};

class TRIBE_Diamond_Map_View : public RGE_Diamond_Map {
public:
    char gap_000[0x16C];
    unsigned long last_attack_time;
    int flash_on;

    void draw_objects();
};

void TRIBE_Diamond_Map_View::draw_objects() {
    unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tvw_dmap.cpp", 0x40);
    if (0x14D <= now - this->last_attack_time) {
        this->flash_on = (this->flash_on == 0);
        this->last_attack_time = now;
    }
    RGE_Diamond_Map::draw_objects();
}
