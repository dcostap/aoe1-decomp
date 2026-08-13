// VA: 004C3B30 RGE_Static_Object::draw_frame
// PDB source: stat_obj.cpp lines 1624-1676
// Baseline reconstruction: frame bounds and health-bar drawing follow the
// neighboring capture_square_frame source and the proven object/master layout.
// Attempt log:
// - typed baseline recovered the original 313-byte size, 0x8 frame, saved
//   registers, CFG, and all seven ordered calls;
// - corrected hp to +0x30 and used the proven get_facetindex/get_frame and
//   DrawRect/FillRect surfaces; this restored the complete structural call set;
// - coordinate declaration/order, receiver-local, and top-level-local probes
//   were codegen duplicates or worse and were rolled back;
// - remaining drift is a broad VC5 arithmetic/register and stack-home basin
//   beginning at the lower-left coordinate calculation (219 positional bytes,
//   66.96% instruction-shape similarity). Left in scratch after the bounded
//   ten-hypothesis pass.
// - exact stat_obj draw donors showed that the CRT header and full virtual
//   method surface are codegen-active context; they reduced the gap to 105
//   bytes and raised shape similarity to 77.27% while preserving all calls;
//   the remaining drift is the health-home and callee-saved register basin.
// - swapped coordinate declaration/assignment and health-local declaration
//   orders were codegen duplicates or worse under the donor context.
// - tested exact same-TU box_hit_test-style guard clauses for sprite/frame
//   dispatch and object-state/max-health exits; emitted code was unchanged,
//   so restored the combined natural source form.
// - hoisted outer rectangle coordinates and modeled health-bar bounds as
//   mutable x1/y1/x2/y2 locals; this reproduced the original 313-byte shape.
// - the first mutable update form left an 11-byte hunk before the second
//   FillRect; restoring explicit updates confirmed the hunk was evaluation
//   order, not layout.
// - using pre-increment and compound-assignment arguments in the first health
//   FillRect reproduced the original right-to-left VC5 argument schedule.
//   Current source is an exact 313-byte match with default flags.

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
