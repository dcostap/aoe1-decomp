// 00437EC0 RGE_Diamond_Map::draw_visible_object (diam_map.cpp:1021-1112)
// Attempt log (sa-d55a5d35-draw_visible_object, bounded 10-probe pass):
// - Reconstructed the typed object/master/player/map and doppleganger surfaces, coordinate
//   ftol results, visibility masks, and the vslot +0xEC draw_object call surface.
// - Corrected master fog/map field offsets; all bytes remain exact-size and the direct ftol
//   sequence is stable. The natural candidate remains broad (340 differing bytes) because
//   this/player callee-save coloring, shared visibility tails, global map-offset relocation,
//   and case-1/case-3 versus case-2 virtual-call topology are unresolved.
// - Explicit shared-label and common-tail switch experiments were diagnostic only and rolled
//   back; retain ordinary nested visibility and switch source in scratch for the next worker.
// - Fresh pass: testing an int draw-level local. The original zero-extends map_draw_level into
//   a callee-save register before its jump table, while the prior unsigned-char source lowered
//   the dispatch into a decrement chain and lost one draw_object call.
// - int level plus an explicit case 0 produced the closest clean dispatch basin (339 differing
//   bytes, 384 emitted bytes), but VC5 still folded case 2 into the case-3 draw_object site.
// - Switch-arm order, case-zero/default exit spelling, and an inline case-3 color assignment
//   did not change that basin. Int working-color locals and a common call tail added a frame or
//   widened the function, so those diagnostics were rolled back.
// - Final validated candidate keeps the ordinary typed switch and separate case-two return;
//   remaining structural gaps are this/player register coloring and the folded virtual call.

extern unsigned long* unified_map_offsets[];

class RGE_Visible_Map;
class RGE_Tile;

class RGE_Master_Static_Object {
public:
    char gap_00[0x65];
    unsigned char fog_flag;
    char gap_66[0x28];
    unsigned char map_draw_level;
    unsigned char map_color;
};

class RGE_Player {
public:
    char gap_00[0x38];
    RGE_Visible_Map* visible;
    char gap_3C[0x0E];
    short id;
    char gap_4C[0x60];
    int mutualAlly[9];
    unsigned long mutualExploredMask;
    unsigned long mutualVisibleMask;
};

class RGE_Map {
public:
    char gap_00[0x8DB8];
    unsigned char map_visible_flag;
    unsigned char fog_flag;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    RGE_Tile* tile;
    RGE_Static_Object* inside_obj;
    void* objects;
    char gap_28[0x10];
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
    char gap_50[0x38];
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    char gap_88[4];
};

class RGE_Doppleganger_Object : public RGE_Animated_Object {
public:
    RGE_Static_Object* doppled_object;
    void* draw_color;
    RGE_Master_Static_Object* doppled_master_obj;
    int doppled_player;
    unsigned long* MapAddress;
    unsigned long LastMapValue;
    unsigned long CantSeeBits;
    unsigned char map_draw_level;
    unsigned char map_color;
    unsigned char gap_AA[2];
    int doppledObjectID;
};

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;

class TPanel {
public:
    virtual ~TPanel();
    virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30();
    virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48();
    virtual void v4C(); virtual void v50(); virtual void v54();
    virtual void v58(); virtual void v5C(); virtual void v60();
    virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78();
    virtual void v7C(); virtual void v80(); virtual void v84();
    virtual void v88(); virtual void v8C(); virtual void v90();
    virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4(); virtual void vA8();
    virtual void vAC(); virtual void vB0(); virtual void vB4();
    virtual void vB8(); virtual void vBC(); virtual void vC0();
    virtual void vC4(); virtual void vC8(); virtual void vCC();
    virtual void vD0(); virtual void vD4(); virtual void vD8();
    virtual void vDC();

    TPanel* previous_panel;
    TPanel* previous_modal_panel;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
    TDrawArea* render_area;
    tagRECT clip_rect;
    char gap_34[0xB8];
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    unsigned char panel_type;
    unsigned char color;
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;
};

class RGE_Diamond_Map : public TPanel {
public:
    virtual void draw_selected_area();
    virtual void draw_objects();
    virtual void draw_visible_object(RGE_Static_Object* object,
                                     unsigned char color1,
                                     unsigned char color2);
    virtual void draw_object(short x, short y, unsigned char color,
                             short mode, RGE_Static_Object* object);
    virtual void draw_view_rect();

    void* world;
    RGE_Player* player;
    RGE_Map* map;
    char gap_100[0x60];
    unsigned long cur_player_bit;
};

void RGE_Diamond_Map::draw_visible_object(RGE_Static_Object* object,
                                          unsigned char color1,
                                          unsigned char color2)
{
    RGE_Player* player;
    if (object->tile == 0)
        return;

    short col = (short)object->world_x;
    int row = (int)object->world_y;
    player = this->player;
    unsigned char visibility;

    if (player->visible == 0) {
        visibility = 0x0F;
    } else {
        RGE_Map* map = this->map;
        if (map->map_visible_flag != 0 && map->fog_flag == 0) {
            visibility = 0x0F;
        } else {
            visibility = 0;
            unsigned long mask = unified_map_offsets[(short)row][(short)col];
            if ((player->mutualExploredMask & mask) != 0)
                visibility = 0x80;
            if ((player->mutualVisibleMask & mask) != 0)
                visibility = 0x0F;
            if (map->map_visible_flag != 0 && visibility == 0)
                visibility = 0x80;
            if (map->fog_flag == 0 && visibility == 0x80)
                visibility = 0x0F;
        }
    }

    if (visibility != 0x0F &&
        (visibility != 0x80 || object->master_obj->fog_flag == 0))
        return;

    int level;
    if (object->type == 0x19) {
        if (visibility == 0x0F)
            return;

        RGE_Doppleganger_Object* dopple =
            (RGE_Doppleganger_Object*)object;
        if (player->mutualAlly[object->owner->id] == 1 &&
            (this->cur_player_bit & dopple->CantSeeBits) == 0) {
            level = dopple->map_draw_level;
            color1 = dopple->map_color;
            color2 = color1;
        } else {
            level = 0;
            color1 = 0xFF;
            color2 = 0xFF;
        }
    } else {
        level = object->master_obj->map_draw_level;
        if (level == 3)
            color1 = object->master_obj->map_color;
    }

    switch (level) {
    case 0:
        return;
    case 2:
        this->draw_object(col, (short)row, color1, 2, object);
        return;
    case 1:
        this->draw_object(col, (short)row, color2, 1, object);
        break;
    case 3:
        color2 = color1;
        this->draw_object(col, (short)row, color2, 2, object);
        break;
    default:
        return;
    }
}
