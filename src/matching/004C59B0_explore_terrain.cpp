// VA: 004C59B0 RGE_Static_Object::explore_terrain (234B)
// PDB source: stat_obj.cpp lines 2941-3015
// Attempt log:
// - baseline candidate: canonical ownership from the exact stat_obj.cpp
//   unexplore_terrain donor; player->visible/world/id, world->curr_player,
//   master_obj->los/radius_x/radius_y, and this->world_x/world_y; natural
//   mode==0 versus radius-bounded explore_terrain_sq dispatch.
// - Main-agent audit restored donor-backed polymorphic ownership for the
//   master, world, and player surfaces; emitted code remains exact.

extern "C" long __cdecl _ftol(void);

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x24];
    float los;              // +0x28
    char gap_2C[0x30 - 0x2C];
    float radius_x;         // +0x30
    float radius_y;         // +0x34
};

class RGE_Game_World {
public:
    virtual void data_load_world();
    char gap_04[0x78];
    short curr_player;      // +0x7C
};

class RGE_Visible_Map {
public:
    char gap_00[0x38];

    int explore_terrain(int x, int y, int range, int square, int update_tiles, int p6);
    int explore_terrain_sq(int x1, int y1, int x2, int y2, int update_tiles, int p6);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x34];
    RGE_Visible_Map* visible; // +0x38
    RGE_Game_World* world;    // +0x3C
    char gap_40[0x4A - 0x40];
    short id;                  // +0x4A
};

class RGE_Static_Object {
public:
    virtual void v00();
    long id;                              // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    char gap_0C[0x38 - 0x0C];
    float world_x;                        // +0x38
    float world_y;                        // +0x3C

    int explore_terrain(RGE_Player* player, unsigned char mode, int range);
};
#endif

int RGE_Static_Object::explore_terrain(RGE_Player* player, unsigned char mode, int range)
{
    if (player != 0) {
        if (range == -1) {
            range = (int)this->master_obj->los;
        }
        if (range > 0) {
            RGE_Visible_Map* visible = player->visible;
            long current = (player->id == player->world->curr_player);
            if (mode == 0) {
                return visible->explore_terrain(
                    (long)this->world_x, (long)this->world_y, range, 0, current, this->id);
            } else {
                if (this->master_obj->radius_x > 0.0 && this->master_obj->radius_y > 0.0) {
                    return visible->explore_terrain_sq(
                        (long)(this->world_x - this->master_obj->radius_x),
                        (long)(this->world_y - this->master_obj->radius_y),
                        (long)(this->world_x + this->master_obj->radius_x - 0.01f),
                        (long)(this->world_y + this->master_obj->radius_y - 0.01f),
                        current, this->id);
                }
            }
        }
    }
    return 0;
}
