#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    char gap_00[0x66];
    short terrain;
};

class RGE_Game_World {
public:
    char gap_00[0x54];
    float** terrains;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;

    float get_terrain_speed(unsigned char terrain_type);
};
#endif

float RGE_Static_Object::get_terrain_speed(unsigned char terrain_type) {
    return owner->world->terrains[master_obj->terrain][terrain_type];
}
