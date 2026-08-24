#ifndef RGE_VIEW_SHARED_CONTEXT
class RGE_Map {
public:
    char gap_00[0x8D96];
    short tile_width;
    short tile_height;
    short tile_half_width;
    short tile_half_height;
    short elev_height;

    void coordinate_map(void);
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
};

class RGE_View {
public:
    char gap_00[0xFC];
    RGE_Game_World* world;
    char gap_100[0x04];
    RGE_Map* map;
    short tile_wid;
    short tile_hgt;
    short tile_half_wid;
    short tile_half_hgt;
    short elev_hgt;

    void calc_draw_vars(void);
    void set_world(RGE_Game_World* world);
};
#endif

void RGE_View::set_world(RGE_Game_World* world) {
    this->world = world;
    if (world != 0) {
        map = world->map;
        map->coordinate_map();
        tile_wid = map->tile_width;
        tile_hgt = map->tile_height;
        tile_half_wid = map->tile_half_height;
        tile_half_hgt = map->tile_half_width;
        elev_hgt = map->elev_height;
    } else {
        map = 0;
        tile_wid = 0;
        tile_hgt = 0;
        tile_half_wid = 0;
        tile_half_hgt = 0;
        elev_hgt = 0;
    }
    calc_draw_vars();
}
