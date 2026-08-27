#ifndef AOE1_ASP_LIST_H
#define AOE1_ASP_LIST_H

// Compiler-facing declarations for the original asp_list.cpp module.
// Layouts and virtual slots follow the reviewed PDB and binary evidence.

class RGE_Color_Table;
class TDrawArea;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Active_Sprite;
struct RGE_Active_Sprite_Node;

class RGE_Active_Sprite {
public:
    virtual ~RGE_Active_Sprite();
    virtual void set_offset(long param_1, long param_2);
    virtual void save(int param_1);
    virtual void update(float param_1, float param_2);
    virtual void draw(short param_1, long param_2, long param_3, long param_4,
                       long param_5, RGE_Color_Table* param_6, TDrawArea* param_7);
    virtual void normal_draw(short param_1, long param_2, long param_3,
                             RGE_Color_Table* param_4, TDrawArea* param_5);
    virtual void shadow_draw(short param_1, long param_2, long param_3,
                             RGE_Color_Table* param_4, TDrawArea* param_5,
                             unsigned char param_6);
    virtual short frame();
    virtual unsigned char is_animating();
    virtual void set_frame(short param_1);
    virtual unsigned char frame_passed(short param_1);
    virtual unsigned char looped();
    virtual short get_facetindex(short param_1);
    virtual unsigned char get_frame(short* param_1, short* param_2, short* param_3,
                                    short* param_4, long param_5);
    virtual void setToFirstFrame();
    void destroy(int flags);
    RGE_Sprite* sprite;
    unsigned char type;
    char gap_09[0x3];
    long offset_x;
    long offset_y;

    int check_for_shadows();
    unsigned char get_lowest_draw_level();

    RGE_Active_Sprite(int param_1, RGE_Sprite** param_2);
};

class RGE_Active_Animated_Sprite : public RGE_Active_Sprite {
public:
    short frame;
    char gap_16[0x2];
    long animate_interval;
    long animate_last;
    short last_frame;
    unsigned char frame_changed;
    unsigned char frame_looped;
    unsigned char animate_flag;
    char gap_25[0x3];

    RGE_Active_Animated_Sprite(int param_1, RGE_Sprite** param_2);
};

class RGE_Sprite {
public:
    int check_for_shadows();
    RGE_Active_Sprite* make_active_sprite();
};

class RGE_Static_Object {
public:
    void remove_shadows();
};

struct RGE_Active_Sprite_Node {
public:
    RGE_Active_Sprite* node;
    unsigned char order;
    unsigned char count;
    char gap_06[0x2];
    RGE_Active_Sprite_Node* next;
};

class RGE_Active_Sprite_List {
public:
    virtual ~RGE_Active_Sprite_List();
    virtual short frame(RGE_Sprite* param_1);
    virtual void update(float param_1, float param_2);
    virtual void draw(short param_1, short param_2, short param_3, short param_4,
                       short param_5, RGE_Color_Table* param_6, TDrawArea* param_7);
    virtual void normal_draw(short param_1, short param_2, short param_3,
                             RGE_Color_Table* param_4, TDrawArea* param_5);
    virtual void shadow_draw(short param_1, short param_2, short param_3,
                             RGE_Color_Table* param_4, TDrawArea* param_5,
                             unsigned char param_6);
    virtual unsigned char is_animating(RGE_Sprite* param_1);
    virtual void set_frame(RGE_Sprite* param_1, short param_2);
    virtual unsigned char frame_passed(RGE_Sprite* param_1, short param_2);
    virtual unsigned char looped(RGE_Sprite* param_1);
    virtual short get_facetindex(RGE_Sprite* param_1, short param_2);

protected:
    // BINARY NOTE: FPO identifies load_node as protected (MAE), not public (UAE).
    virtual unsigned char load_node(int param_1, unsigned char param_2,
                                    RGE_Sprite** param_3);

public:
    RGE_Active_Sprite_Node* list;
    RGE_Static_Object* owner;

    RGE_Active_Sprite_List(RGE_Static_Object* owner);
    void load(int param_1, RGE_Sprite** param_2);
    void save(int file);
    void delete_list();
    RGE_Active_Sprite_Node* copy_sprite_list();
    void use_sprite_list(RGE_Active_Sprite_Node* list);
    void add_sprite(RGE_Sprite* sprite, unsigned char order, long offset_x, long offset_y);
    void remove_sprite(RGE_Sprite* sprite);
    int check_for_shadows();
    unsigned char get_lowest_draw_level();
    unsigned char get_frame(short& param_1, short& param_2, short& param_3,
                            short& param_4, RGE_Sprite* param_5, long param_6);
};

#endif
