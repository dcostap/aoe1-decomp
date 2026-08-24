// VA: 004C5AA0 RGE_Static_Object::unexplore_terrain (226B)
// PDB source: stat_obj.cpp lines 3019-3088
// Attempt log:
// - baseline: canonical ownership (stat_obj.cpp donor layout) — player->visible
//   (+0x38) / player->world (+0x3C) / player->id (+0x4A short), world->curr_player
//   (+0x7C short), this->id (+0x4) / master_obj (+0x8), master_obj->los (+0x28),
//   radius_x (+0x30) / radius_y (+0x34), this->world_x (+0x38) / world_y (+0x3C);
//   natural if/else with mode==0 plain unexplore vs radius-bounded unexplore_terrain_sq;
//   constants DAT_00574718 (0.0 double) and DAT_00574750 (0.01f) per original bytes.

extern "C" long __cdecl _ftol(void);

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    char gap_00[0x28];
    float los;              // +0x28
    char gap_2C[0x30 - 0x2C];
    float radius_x;         // +0x30
    float radius_y;         // +0x34
};

class RGE_Game_World {
public:
    char gap_00[0x7C];
    short curr_player; // +0x7C
};

class RGE_Visible_Map {
public:
    char gap_00[0x38];

    void unexplore_terrain(int x, int y, int range, int square, int update_tiles, int p6);
    void unexplore_terrain_sq(int x1, int y1, int x2, int y2, int update_tiles, int p6);
};

class RGE_Player {
public:
    char gap_00[0x38];
    RGE_Visible_Map* visible; // +0x38
    RGE_Game_World* world;    // +0x3C
    char gap_40[0x4A - 0x40];
    short id;                 // +0x4A
};

class RGE_Static_Object {
public:
    virtual void v00();
    long id;                              // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    char gap_0C[0x38 - 0x0C];
    float world_x;                        // +0x38
    float world_y;                        // +0x3C

    void unexplore_terrain(RGE_Player* player, unsigned char mode, int range);
};
#endif

void RGE_Static_Object::unexplore_terrain(RGE_Player* player, unsigned char mode, int range)
{
    if (player != 0) {
        if (range == -1) {
            range = (int)this->master_obj->los;
        }
        if (range > 0) {
            RGE_Visible_Map* visible = player->visible;
            long current = (player->id == player->world->curr_player);
            if (mode == 0) {
                visible->unexplore_terrain(
                    (long)this->world_x, (long)this->world_y, range, 0, current, this->id);
            } else {
                if (this->master_obj->radius_x > 0.0 && this->master_obj->radius_y > 0.0) {
                    visible->unexplore_terrain_sq(
                        (long)(this->world_x - this->master_obj->radius_x),
                        (long)(this->world_y - this->master_obj->radius_y),
                        (long)(this->world_x + this->master_obj->radius_x - 0.01f),
                        (long)(this->world_y + this->master_obj->radius_y - 0.01f),
                        current, this->id);
                }
            }
        }
    }
}
