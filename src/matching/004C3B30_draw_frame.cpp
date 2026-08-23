// VA: 004C3B30 RGE_Static_Object::draw_frame
// PDB source: stat_obj.cpp lines 1624-1676
// Qualified owner: RGE_Static_Object, symbol ?draw_frame@RGE_Static_Object@@UAEXPAVTDrawArea@@FF@Z.
// Qualified boundary: 004C3B30 through 004C3C6C; next symbol 004C3C70 is update.
// Exact finish (2026-08-24):
// - Fresh baseline and restore checks are MATCH at 313 bytes, 0.0000%, with
//   the 0x8 frame, four saved registers, six conditional branches, and one return.
// - All seven ordered calls align: facet dispatch, get_frame, DrawRect, __ftol,
//   DrawRect, and the two FillRect calls. The owner symbol and boundary match.
// - Walkback of separate health-bar updates changed 11 bytes at 004C3C27;
//   restoring pre-increment and compound-assignment arguments restored MATCH.
// BINARY NOTE: Keep the sprite and sprite-list guards, facet dispatch, frame
// query, health checks, GDI call order, and signed __ftol conversion in this order.
// No publication or global write occurs in this target. No inline assembly or
// fake volatility is needed. The default VC5 flags are sufficient.

#include <stdlib.h>

class TDrawArea {
public:
    void DrawRect(long x1, long y1, long x2, long y2, unsigned char color);
    void FillRect(long x1, long y1, long x2, long y2, unsigned char color);
};

class RGE_Sprite;
class RGE_Color_Table;
class RGE_Player;
class RGE_Tile;
class RGE_Object_List;
class RGE_Object_Node;
class UnitAIModule;

class RGE_Active_Sprite_List {
public:
    virtual ~RGE_Active_Sprite_List();
    virtual short frame(RGE_Sprite* sprite);
    virtual void update(float param_1, float param_2);
    virtual void draw(short facet, short x, short y, short shadow_x,
                      short shadow_y, RGE_Color_Table* color_table,
                      TDrawArea* area);
    virtual void normal_draw(short facet, short x, short y,
                             RGE_Color_Table* color_table, TDrawArea* area);
    virtual void shadow_draw(short facet, short x, short y,
                             RGE_Color_Table* color_table, TDrawArea* area,
                             unsigned char param_6);
    virtual unsigned char is_animating(RGE_Sprite* sprite);
    virtual void set_frame(RGE_Sprite* sprite, short frame_number);
    virtual unsigned char frame_passed(RGE_Sprite* sprite, short frame_number);
    virtual unsigned char looped(RGE_Sprite* sprite);
    virtual short get_facetindex(RGE_Sprite* sprite, short facet);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x22];
    short hp;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object* master,
                                    RGE_Player* player, float x, float y,
                                    float z);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea* area, short x, short y,
                      RGE_Color_Table* color_table);
    virtual void shadow_draw(TDrawArea* area, short x, short y,
                             unsigned char shadow);
    virtual void normal_draw(TDrawArea* area, short x, short y);
    virtual void draw_front_frame(TDrawArea* area, short x, short y);
    virtual void draw_back_frame(TDrawArea* area, short x, short y);
    virtual void draw_frame(TDrawArea* area, short x, short y);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int file);
    virtual float teleport(float x, float y, float z);
    virtual void new_sprite(RGE_Sprite* sprite);

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    RGE_Tile* tile;
    char gap_20[0x8];
    short screen_x_offset;
    short screen_y_offset;
    char gap_2c[0x4];
    float hp;
    char gap_34;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
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
    RGE_Object_Node* player_object_node;
    char gap_54[0x20];
    UnitAIModule* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    unsigned char inObstructionMapValue;
    unsigned char lastInObstructionMapValue;
    unsigned char underAttackValue;
    unsigned char gap_87;

    int get_frame(short& min_x, short& min_y, short& max_x, short& max_y);
};

void RGE_Static_Object::draw_frame(TDrawArea* area, short x, short y)
{
    short min_x;
    short min_y;
    short max_y;
    short max_x;
    int x1;
    int y1;
    int x2;
    int y2;

    if (this->sprite != 0 && this->sprite_list != 0) {
        this->sprite_list->get_facetindex(this->sprite, this->facet);

        if (this->get_frame(min_x, min_y, max_x, max_y) != 0) {
            x1 = x + min_x + this->screen_x_offset - 1;
            y1 = y + min_y + this->screen_y_offset - 1;
            x2 = x + max_x + this->screen_x_offset + 1;
            y2 = y + max_y + this->screen_y_offset + 1;

            area->DrawRect(x1, y1, x2, y2, 0xff);

            if (this->object_state <= 2) {
                int health = (int)this->hp;
                if (health < 1) {
                    health = 0;
                }

                int max_health = (int)this->master_obj->hp;
                if (max_health > 0) {
                    y1 -= 6;
                    x2 = x1 + 26;
                    y2 = y1 + 5;
                    area->DrawRect(x1, y1, x2, y2, 0xff);

                    area->FillRect(++x1, ++y1, x2 -= 2, y2 -= 2, 0x55);
                    area->FillRect(x1, y1,
                                   (health * 25) / max_health + x1 - 1,
                                   y1 + 3, 0x25);
                }
            }
        }
    }
}
