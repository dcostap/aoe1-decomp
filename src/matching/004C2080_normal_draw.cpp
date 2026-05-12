// VA: 004C2080 RGE_Static_Object::normal_draw
// Source: stat_obj.cpp lines 839-854
// 137 bytes, 59 asm instructions
// __thiscall, void (TDrawArea* param_1, short param_2, short param_3)
// Attempt 1: natural reconstruction with proper vtable layout

class TDrawArea;
class RGE_Color_Table;

//////////////////////////////////////////////////////////////////////////////
// RGE_Color_Table — placeholder
//////////////////////////////////////////////////////////////////////////////

struct RGE_Color_Table {
    char _pad[0x100];
};

//////////////////////////////////////////////////////////////////////////////
// RGE_Active_Sprite_List — vtable at known offsets
// vt[0] = 0x00: ~RGE_Active_Sprite_List()
// vt[1] = 0x04: frame(RGE_Sprite*)
// vt[2] = 0x08: update(float, float)
// vt[3] = 0x0C: draw(short, short, short, short, short, RGE_Color_Table*, TDrawArea*)
// vt[4] = 0x10: normal_draw(short, short, short, RGE_Color_Table*, TDrawArea*)
// vt[5] = 0x14: shadow_draw(short, short, short, RGE_Color_Table*, TDrawArea*, unsigned char)
//////////////////////////////////////////////////////////////////////////////

struct RGE_Active_Sprite_List {
    virtual ~RGE_Active_Sprite_List();
    virtual short frame(void* sprite);
    virtual void update(float param_1, float param_2);
    virtual void draw(short param_1, short param_2, short param_3, short param_4, short param_5, RGE_Color_Table* param_6, TDrawArea* param_7);
    virtual void normal_draw(short param_1, short param_2, short param_3, RGE_Color_Table* param_4, TDrawArea* param_5);
    virtual void shadow_draw(short param_1, short param_2, short param_3, RGE_Color_Table* param_4, TDrawArea* param_5, unsigned char param_6);
};

//////////////////////////////////////////////////////////////////////////////
// RGE_Player — partial layout for color_table access
//////////////////////////////////////////////////////////////////////////////

struct RGE_Player {
    char gap_00[0x108];
    RGE_Color_Table* color_table; // +0x108
};

//////////////////////////////////////////////////////////////////////////////
// RGE_Base_Game — global singleton at 0x0062C574
// outline_type at +0x50
//////////////////////////////////////////////////////////////////////////////

struct RGE_Base_Game {
    char gap_00[0x50];
    unsigned char outline_type;  // +0x50
};

#define rge_base_game (*(RGE_Base_Game**)0x62C574)

//////////////////////////////////////////////////////////////////////////////
// RGE_Static_Object — vtable at known offsets
// vt[0] = 0x00: ~RGE_Static_Object()
// vt[1] = 0x04: recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float)
// vt[2] = 0x08: recycle_out_of_game()
// vt[3] = 0x0C: draw(TDrawArea*, short, short, RGE_Color_Table*)
// vt[4] = 0x10: shadow_draw(TDrawArea*, short, short, unsigned char)
// vt[5] = 0x14: normal_draw(TDrawArea*, short, short)  <-- we implement this
// vt[6] = 0x18: draw_front_frame(TDrawArea*, short, short)
// vt[7] = 0x1C: draw_back_frame(TDrawArea*, short, short)
// vt[8] = 0x20: draw_frame(TDrawArea*, short, short)
//////////////////////////////////////////////////////////////////////////////

struct RGE_Static_Object {
    // vt[0]
    virtual ~RGE_Static_Object();
    // vt[1]
    virtual void recycle_in_to_game(void* master_obj, void* player, float x, float y, float z);
    // vt[2]
    virtual void recycle_out_of_game();
    // vt[3]
    virtual void draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4);
    // vt[4]
    virtual void shadow_draw(TDrawArea* param_1, short param_2, short param_3, unsigned char param_4);
    // vt[5] — this function
    virtual void normal_draw(TDrawArea* param_1, short param_2, short param_3);
    // vt[6]
    virtual void draw_front_frame(TDrawArea* param_1, short param_2, short param_3);
    // vt[7]
    virtual void draw_back_frame(TDrawArea* param_1, short param_2, short param_3);
    // vt[8]
    virtual void draw_frame(TDrawArea* param_1, short param_2, short param_3);

    // Data layout (0x88 bytes total)
    long id;                            // +0x04
    void* master_obj;                   // +0x08
    RGE_Player* owner;                  // +0x0C
    char gap_10[0x08];                  // +0x10 sprite, old_sprite
    RGE_Active_Sprite_List* sprite_list; // +0x18
    void* tile;                         // +0x1C
    char gap_20[0x08];                  // +0x20 inside_obj, objects
    short screen_x_offset;              // +0x28
    short screen_y_offset;              // +0x2A
    char gap_2C[0x09];                  // +0x2C shadow offsets, hp, curr_damage
    unsigned char facet;                // +0x35
    unsigned char selected;             // +0x36
    char gap_37[0x11];                  // +0x37 selected_group, world, hp, attributes
    unsigned char object_state;         // +0x48
};

void RGE_Static_Object::normal_draw(TDrawArea* param_1, short param_2, short param_3)
{
    if (this->tile == 0) {
        return;
    }
    if ((unsigned char)this->object_state >= 7) {
        return;
    }

    unsigned char isSelected;
    if (this->selected != 0 || rge_base_game->outline_type == 3) {
        isSelected = 1;
    } else {
        isSelected = 0;
    }

    if (isSelected) {
        this->draw_back_frame(param_1, param_2, param_3);
    }

    this->sprite_list->normal_draw(
        this->facet,
        (short)((int)(short)this->screen_x_offset + (int)param_2),
        (short)((int)(short)this->screen_y_offset + (int)param_3),
        this->owner->color_table,
        param_1
    );

    if (isSelected) {
        this->draw_front_frame(param_1, param_2, param_3);
    }
}
