#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Map {
public:
    void request_redraw(int col0, int row0, int col1, int row1, unsigned char attr);
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Static_Object {
public:
    char gap_00[0x0C];
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;

    void remove_shadows(void);
};
#endif

void RGE_Static_Object::remove_shadows(void) {
    int x0 = (int)this->world_x;
    int y0 = (int)this->world_y;
    this->owner->world->map->request_redraw(x0 - 2, y0 - 2, x0 + 1, y0 + 1, 0);
}
