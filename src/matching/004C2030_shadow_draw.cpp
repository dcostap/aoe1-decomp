class RGE_Color_Table;
class TDrawArea;
class RGE_Player {
public:
    char gap_00[0x108];
    RGE_Color_Table* color_table;
};
class RGE_Master_Static_Object;

class RGE_Active_Sprite_List {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void shadow_draw(short param_1, short param_2, short param_3, RGE_Color_Table* param_4, TDrawArea* param_5, unsigned char param_6);
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x8];
    RGE_Active_Sprite_List* sprite_list;
    void* tile;
    char gap_20[0xC];
    short shadow_x_offset;
    short shadow_y_offset;
    char gap_30[0x5];
    unsigned char facet;
    char gap_36[0x12];
    unsigned char object_state;

    void shadow_draw(TDrawArea* param_1, short param_2, short param_3, unsigned char param_4);
};

void RGE_Static_Object::shadow_draw(TDrawArea* param_1, short param_2, short param_3, unsigned char param_4) {
    if (this->tile != 0 && this->object_state < 7) {
        this->sprite_list->shadow_draw(this->facet, this->shadow_x_offset + param_2, this->shadow_y_offset + param_3, this->owner->color_table, param_1, param_4);
    }
}
