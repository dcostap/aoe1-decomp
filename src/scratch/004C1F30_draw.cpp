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

class TDrawArea;
class RGE_Color_Table;
class RGE_Sprite;
class RGE_Tile;
class RGE_Object_List;
class RGE_Master_Static_Object;
class RGE_Static_Object;

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
    char gap_50[0x38];

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
extern int SDI_Object_ID;
extern int SDI_Draw_Line;

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
