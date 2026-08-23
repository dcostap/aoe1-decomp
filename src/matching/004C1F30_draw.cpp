// VA: 004C1F30 RGE_Static_Object::draw
// PDB source: stat_obj.cpp lines 783-828
// Best clean reconstruction: ordinary typed member access, including the
// RGE_Doppleganger_Object extension used when type == 0x19.
// Attempt log:
// - typed baseline initially matched size/frame/call set but used the wrong
//   derived-field layout until the full 0x88-byte static-object tail was
//   restored;
// - changing the doppled-object test to a positive arm reproduced the
//   original je-null block topology and reduced the drift to 7 bytes;
// - direct/temporary/reordered y-shadow and SDI_Draw_Line arithmetic forms,
//   a named line temporary, a shared short y temporary, and a focused
//   y-shadow variant lab all emitted the same localized 7-byte register/order
//   drift; restored here to the clean natural expression form;
// - remaining drift is confined to the SDI line register coloring and the
//   final short y-shadow add order (original: ecx field/eax parameter and
//   mov ax,di; add ax,[this+2e]).
// fresh worker: explicit assignment through a short shadow-y temporary emitted
// the same 255B/7 basin; restored.
// fresh worker: named int promotion of y before SDI_Draw_Line also duplicated
// the 255B/7 basin; restored.
// fresh worker: corrected SDI_Object_ID from int to the binary's long global
// symbol; emitted code stayed in the same 255B/7 basin.
// fresh worker: restored the binary-backed static-object tail and early virtual
// surfaces, then completed the active-sprite-list vtable surface; both were
// codegen-neutral while making the local ownership canonical.
// fresh worker: a 25-variant line/y-shadow expression lab found one emitted
// 255B/7 group for every natural spelling; no variant was retained.
// fresh worker: adding the donor-era <stdlib.h> context used by exact stat_obj
// siblings changed only the localized register/order hunk and produced MATCH.

#include <stdlib.h>

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class TDrawArea;
class RGE_Color_Table;
class RGE_Sprite;
class RGE_Tile;
class RGE_Object_List;
class RGE_Master_Static_Object;
class RGE_Static_Object;
class RGE_Object_Node;
class UnitAIModule;

class RGE_Game_World {
public:
    char gap_00[0x7C];
    short curr_player;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    char gap_40[0xC8];
    RGE_Color_Table* color_table;
};

class RGE_Base_Game {
public:
    char gap_00[0x50];
    unsigned char outline_type;
    char gap_51[0x15F];
    int prog_mode;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0xA8];
    unsigned char draw_flag;
};

class RGE_Active_Sprite_List {
public:
    virtual ~RGE_Active_Sprite_List();
    virtual short frame(RGE_Sprite* sprite);
    virtual void update(float param_1, float param_2);
    virtual void draw(short facet, short x, short y, short shadow_x,
                      short shadow_y, RGE_Color_Table* color_table,
                      TDrawArea* area);
    virtual void normal_draw(short facet, short x, short y,
                             RGE_Color_Table* color_table,
                             TDrawArea* area);
    virtual void shadow_draw(short facet, short x, short y,
                             RGE_Color_Table* color_table,
                             TDrawArea* area, unsigned char shadow);
    virtual unsigned char is_animating(RGE_Sprite* sprite);
    virtual void set_frame(RGE_Sprite* sprite, short frame);
    virtual unsigned char frame_passed(RGE_Sprite* sprite, short frame);
    virtual unsigned char looped(RGE_Sprite* sprite);
    virtual short get_facetindex(RGE_Sprite* sprite, short facet);
    virtual unsigned char load_node(int value, unsigned char flag,
                                    RGE_Sprite** sprite);
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
    RGE_Static_Object* inside_obj;
    RGE_Object_List* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    unsigned char curr_damage_percent;
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

    void capture_frame(TDrawArea* area, short x, short y);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;
};

class RGE_Doppleganger_Object : public RGE_Animated_Object {
public:
    RGE_Static_Object* doppled_object;
    RGE_Color_Table* draw_color;
    RGE_Master_Static_Object* doppled_master_obj;
    int doppled_player;
    unsigned long* MapAddress;
    unsigned long LastMapValue;
    unsigned long CantSeeBits;
};

extern RGE_Base_Game* rge_base_game;
extern long SDI_Object_ID;
extern int SDI_Draw_Line;

#endif

void RGE_Static_Object::draw(TDrawArea* area, short x, short y,
                             RGE_Color_Table* color_table)
{
    SDI_Object_ID = this->id;

    if (this->type == 0x19) {
        RGE_Doppleganger_Object* dopple =
            (RGE_Doppleganger_Object*)this;

        if ((dopple->CantSeeBits & (1 << this->owner->world->curr_player)) != 0) {
            SDI_Object_ID = -1;
            return;
        }

        if (dopple->doppled_object != 0) {
            SDI_Object_ID = dopple->doppled_object->id;
        } else {
            SDI_Object_ID = -1;
        }
    }

    if (this->tile != 0 && this->object_state < 7) {
        if (this->selected != 0 ||
            rge_base_game->outline_type == 3 ||
            ((this->master_obj->draw_flag & 1) == 1 &&
             rge_base_game->prog_mode == 7)) {
            this->capture_frame(area, x, y);
        }

        SDI_Draw_Line = (int)y + (int)this->shadow_y_offset;
        this->sprite_list->draw(
            this->facet,
            this->screen_x_offset + x,
            this->screen_y_offset + y,
            this->shadow_x_offset + x,
            y + this->shadow_y_offset,
            color_table,
            area);
    }

    SDI_Object_ID = -1;
}
