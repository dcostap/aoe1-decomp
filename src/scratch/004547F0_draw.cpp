// VA: 004547F0 RGE_Master_Static_Object::draw (348 bytes)
// m_s_obj.cpp:1126-1147
//
// Baseline reconstruction: draw the master sprite, then project the four
// outline corners into the clipping list when outline capture is requested.
// Attempt log:
// - Baseline reaches exact size/frame and all six ordered direct calls; the
//   remaining 314 differing bytes begin in the prologue.
// - Receiver-alias, split-sprite-fetch, scoped-lifetime, early-return, and
//   reduced-virtual-surface probes all emitted the same 348-byte basin (the
//   rebuilt function saves ESI at entry while the oracle homes this and saves
//   ESI only in the outline arm).
// - Formal-home/float-window and donor-shaped screen-local variants widened
//   or broadly disturbed the function and were rolled back.
// - Corrected get_point to (short*, short*, float, float, float, int, int)
//   and AddGDINode to eight short coordinate parameters; all six calls remain
//   aligned, but VC5 moved to a 331-byte, 0x0C-frame codegen basin.
// - Retested a branch-local receiver alias after the ABI correction; emitted
//   code was unchanged and the alias was rolled back.
// - Left in scratch: canonical typed outline/map ownership and exact call
//   set are established; next lead is the original receiver/ESI liveness and
//   local-home topology at 004547F3, not behavior or call discovery.

class TDrawArea;
class RGE_Color_Table;
class RGE_Sprite;
class RGE_Map;
class RGE_Game_World;
class DClipInfo_List;

class RGE_Sprite {
public:
    unsigned char draw(long param_1, long param_2, long param_3, long param_4,
                       long param_5, long param_6, RGE_Color_Table* param_7,
                       TDrawArea* param_8, unsigned char param_9);
};

class RGE_Map {
public:
    void get_point(short* out_x, short* out_y, float param_3, float param_4,
                   float param_5, int param_6, int param_7);
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
};

class RGE_Base_Game {
public:
    char gap_00[0x3F4];
    RGE_Game_World* world;
};

class DClipInfo_List {
public:
    void AddGDINode(int param_1, int param_2, short param_3, short param_4,
                    short param_5, short param_6, short param_7, short param_8,
                    short param_9, short param_10, int param_11, int param_12,
                    int param_13);
};

extern RGE_Base_Game* rge_base_game;
extern DClipInfo_List* SDI_List;
extern int SDI_Object_ID;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* src);
    virtual void modify(float value, unsigned char op);
    virtual void modify_delta(float value, unsigned char op);
    virtual void modify_percent(float value, unsigned char op);
    virtual void save(int file_handle);
    virtual void* make_new_obj(void* player, float x, float y, float z);
    virtual void* make_new_master();
    virtual unsigned char check_placement(void* player, float x, float y,
                                           int* values, unsigned char p5,
                                           unsigned char p6, unsigned char p7,
                                           unsigned char p8, unsigned char p9,
                                           unsigned char p10);
    virtual unsigned char alignment(float& x, float& y, RGE_Game_World* world,
                                    unsigned char mode);

    unsigned char master_type;
    char pad_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    char pad_16[2];
    RGE_Sprite* sprite;
    RGE_Sprite* death_sprite;
    RGE_Sprite* undead_sprite;
    unsigned char undead_flag;
    char pad_25;
    short hp;
    float los;
    unsigned char obj_max;
    char pad_2D[3];
    float radius_x;
    float radius_y;
    float radius_z;
    char gap_3C[0xAC - 0x3C];
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;

    virtual void draw(TDrawArea* draw_area, short x, short y,
                      RGE_Color_Table* color_table, long param_5, long param_6,
                      int param_7, unsigned char param_8);
};

void RGE_Master_Static_Object::draw(TDrawArea* draw_area, short x, short y,
                                    RGE_Color_Table* color_table, long param_5,
                                    long param_6, int param_7,
                                    unsigned char param_8) {
    if (this->sprite != 0) {
        this->sprite->draw(param_5, param_6, (int)x, (int)y, (int)x, (int)y,
                           color_table, draw_area, 10);

        if (param_7 != 0) {
            float rx1 = this->outline_radius_x;
            float ry1 = this->outline_radius_y;
            RGE_Map* map = rge_base_game->world->map;
            short x1;
            short y1;
            short x2;
            short y2;
            short x3;
            short y3;
            short x4;
            short y4;

            map->get_point(&x1, &y1, rx1, -ry1, 0.0f, x, y);
            map->get_point(&x2, &y2, rx1, ry1, 0.0f, x, y);
            rx1 = -rx1;
            map->get_point(&x3, &y3, rx1, ry1, 0.0f, x, y);
            map->get_point(&x4, &y4, rx1, -ry1, 0.0f, x, y);

            SDI_List->AddGDINode(1, (int)y, x1, y1, x2, y2, x3, y3, x4, y4,
                                 10, (int)(param_8 & 0xFF), SDI_Object_ID);
        }
    }
}
