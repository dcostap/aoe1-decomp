#ifndef OBJ_LIST_TU_CONTEXT_H
#define OBJ_LIST_TU_CONTEXT_H

#include <stdlib.h>

class TDrawArea;
class RGE_Color_Table;
class RGE_Game_World;
class RGE_Player;
class RGE_Object_List;
struct RGE_Object_Node;

// Canonical obj_list.cpp master-object fields used by the list owners.
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;
    unsigned char gap_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    unsigned char gap_16[0x34];
    unsigned char sort_number;
    unsigned char gap_4B[0x1A];
    unsigned char fog_flag;
    unsigned char gap_66[0x52];
};

// The list owners use the proven object virtual slots and fields. The tail
// keeps the complete PDB object size (0x88) without inventing fields.
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
    virtual void rehook();
    virtual void save(int);
    unsigned char lookupZone(int, int);

    long id;
    union {
        RGE_Master_Static_Object* master_obj;
        RGE_Master_Static_Object* master;
    };
    RGE_Player* owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    void* tile;
    void* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    union {
        float world_x;
        float x;
    };
    union {
        float world_y;
        float y;
    };
    float world_z;
    float attribute_amount_held;
    union {
        unsigned char object_state;
        unsigned char player_id;
    };
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
    unsigned char tail[0x38];

    RGE_Static_Object(int, RGE_Game_World*, int);
};

struct RGE_Object_Node {
    union {
        RGE_Static_Object* node;
        RGE_Static_Object* object;
        RGE_Static_Object* obj;
    };
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    unsigned char centered;
    unsigned char pad_0D[3];
};

typedef RGE_Object_Node RGE_Object_List_Node;

// Proven draw-only overlay. Its +0x90 color pointer is used by draw(); the
// normal object type remains the canonical 0x88-byte RGE_Static_Object.
class RGE_Object_Draw_View {
public:
    virtual void destroy(int);
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(void*, short, short, void*);

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    unsigned char gap_10[0x38];
    unsigned char object_state;
    unsigned char gap_49[5];
    unsigned char type;
    unsigned char gap_4F[0x41];
    void* ally_color_table;
};

class RGE_Player {
public:
    unsigned char gap_00[0x3C];
    RGE_Game_World* world;
    unsigned char gap_40[0x0A];
    short id;
    unsigned char gap_4C[0xBC];
    void* color_table;
};

class RGE_Game_World {
public:
    unsigned char gap_00[0x3C];
    short player_num;
    unsigned char gap_3E[2];
    RGE_Player** players;
    unsigned char gap_44[0x38];
    short curr_player;
};

class RGE_Object_List {
public:
    union {
        RGE_Object_Node* list;
        RGE_Object_Node* first;
    };
    short number_of_objects;
    unsigned char pad_0A[2];

protected:
    virtual void load(unsigned char, int, RGE_Game_World*);
    void invert();

public:
    RGE_Object_List();
    ~RGE_Object_List();
    void removeAllObjects();
    RGE_Object_Node* add_node(RGE_Static_Object*);
    void remove_node(RGE_Static_Object*, RGE_Object_Node*);
    void draw(TDrawArea*, short, short, unsigned char);
    void shadow_draw(TDrawArea*, short, short, unsigned char, unsigned char);
    void normal_draw(TDrawArea*, short, short, unsigned char);
    void update();
    RGE_Object_Node* sort();
    RGE_Static_Object* find_by_group(long);
    RGE_Static_Object* find_by_group(long, float, float, unsigned char,
                                     unsigned char, RGE_Static_Object*);
    RGE_Static_Object* find_by_id(long);
    RGE_Static_Object* find_by_master_id(long, float, float, unsigned char,
                                         unsigned char, RGE_Static_Object*);
    RGE_Static_Object* find_by_master_ids(long, long, float, float,
                                          unsigned char, unsigned char,
                                          RGE_Static_Object*);
    RGE_Static_Object* find_by_type(unsigned char, float, float, unsigned char,
                                    unsigned char);
    void save(int);
    void load_list(int, RGE_Game_World*);
    void rehook_list();
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    unsigned char tail[4];
    RGE_Animated_Object(int, RGE_Game_World*, int);
};
class RGE_Doppleganger_Object : public RGE_Static_Object {
public:
    unsigned char tail[0x28];
    RGE_Doppleganger_Object(int, RGE_Game_World*, int);
};
class RGE_Moving_Object : public RGE_Static_Object {
public:
    unsigned char tail[0xF8];
    RGE_Moving_Object(int, RGE_Game_World*, int);
};
class RGE_Missile_Object : public RGE_Static_Object {
public:
    unsigned char tail[0x140];
    RGE_Missile_Object(int, RGE_Game_World*, int);
};
class RGE_Action_Object : public RGE_Static_Object {
public:
    unsigned char tail[0x10C];
    RGE_Action_Object(int, RGE_Game_World*, int);
};
class RGE_Combat_Object : public RGE_Static_Object {
public:
    unsigned char tail[0x13C];
    RGE_Combat_Object(int, RGE_Game_World*, int);
};

#endif
