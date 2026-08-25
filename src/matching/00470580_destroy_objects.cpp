#ifndef PLAYER_GROUPED_TU
class RGE_Object {
public:
    virtual ~RGE_Object();
    virtual void recycle_in_to_game();
    virtual void recycle_out_of_game();
    virtual void draw();
    virtual void shadow_draw();
    virtual void normal_draw();
    virtual void draw_front_frame();
    virtual void draw_back_frame();
    virtual void draw_frame();
    virtual void update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save();
    virtual void teleport();
    virtual void new_sprite();
    virtual void add_overlay_sprite();
    virtual void remove_overlay_sprite();
    virtual void change_ownership();
    virtual void modify();
    virtual void modify_delta();
    virtual void modify_percent();
    virtual void transform();
    virtual void copy_obj();
    virtual void set_object_state();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
};

class RGE_Object_Node {
public:
    RGE_Object* node;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    RGE_Object_Node* list;
};

class RGE_Player {
public:
    char gap_00[0x28];
    RGE_Object_List* objects;

    void destroy_objects();
};

#endif

void RGE_Player::destroy_objects() {
    RGE_Object_Node* node;

    node = this->objects->list;
    while (node != 0) {
        node->node->destroy_obj();
        node = node->next;
    }
}
