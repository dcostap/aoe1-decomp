#ifndef OBJLIST_SHARED_CONTEXT
class RGE_Master_Static_Object;
class RGE_Player;
class TDrawArea;
class RGE_Color_Table;

class RGE_Static_Object {
public:
    virtual void destroy(int);
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, unsigned char);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook(void);
};

struct RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    char gap_00[4];
    RGE_Object_Node* list;

    void rehook_list();
};
#endif

void RGE_Object_List::rehook_list() {
    RGE_Object_Node* node;

    node = this->list;
    while (node != 0) {
        node->node->rehook();
        node = node->next;
    }
}
