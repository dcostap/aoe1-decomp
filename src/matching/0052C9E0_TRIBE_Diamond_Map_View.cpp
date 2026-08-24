#ifndef TVW_DMAP_SHARED_CONTEXT
class RGE_Diamond_Map_View {
public:
    virtual ~RGE_Diamond_Map_View();
    char gap_04[0x168];
    unsigned long last_attack_time;
    int flash_on;

    RGE_Diamond_Map_View();
};

class TRIBE_Diamond_Map_View : public RGE_Diamond_Map_View {
public:
    TRIBE_Diamond_Map_View();
};
#endif

TRIBE_Diamond_Map_View::TRIBE_Diamond_Map_View() : RGE_Diamond_Map_View() {
    this->last_attack_time = 0;
    this->flash_on = 0;
}
