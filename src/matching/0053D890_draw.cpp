#ifndef VW_DIMAP_SHARED_CONTEXT
class RGE_Base_Game {
public:
    void add_to_timing(int index, unsigned long value);
};

extern RGE_Base_Game* rge_base_game;

unsigned long debug_timeGetTime(const char* file, int line);

class RGE_Diamond_Map {
public:
    void draw();
};

class RGE_Diamond_Map_View : public RGE_Diamond_Map {
public:
    void draw();
};
#endif

void RGE_Diamond_Map_View::draw()
{
    unsigned long start;

    start = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_dimap.cpp", 0x10E);
    RGE_Diamond_Map::draw();
    rge_base_game->add_to_timing(7, debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_dimap.cpp", 0x112) - start);
}
