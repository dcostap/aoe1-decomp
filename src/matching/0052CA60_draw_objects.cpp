// tried the straightforward time-threshold/toggle shape first
// current hypothesis: any remaining mismatch would be in the shared layout or base-call basin

#ifndef TVW_DMAP_SHARED_CONTEXT
unsigned long debug_timeGetTime(char* param_1, int param_2);
#endif

#ifndef TVW_DMAP_SHARED_CONTEXT
class RGE_Diamond_Map {
public:
protected:
    virtual void draw_objects();
};

class TRIBE_Diamond_Map_View : public RGE_Diamond_Map {
public:
    char gap_000[0x16C];
    unsigned long last_attack_time;
    int flash_on;

protected:
    virtual void draw_objects();
};
#endif

void TRIBE_Diamond_Map_View::draw_objects() {
    unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tvw_dmap.cpp", 0x40);
    if (0x14D <= now - this->last_attack_time) {
        this->flash_on = (this->flash_on == 0);
        this->last_attack_time = now;
    }
    RGE_Diamond_Map::draw_objects();
}
