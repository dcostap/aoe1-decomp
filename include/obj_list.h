#ifndef OBJ_LIST_H
#define OBJ_LIST_H

class RGE_Game_World;
class RGE_Static_Object;
class TDrawArea;

struct RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    unsigned char centered;
};

class RGE_Object_List {
public:
    RGE_Object_Node* list;
    short number_of_objects;

protected:
    virtual void load(unsigned char object_type, int infile, RGE_Game_World* world);
    void invert();

public:
    RGE_Object_List();
    ~RGE_Object_List();
    void removeAllObjects();
    RGE_Object_Node* add_node(RGE_Static_Object* obj);
    void remove_node(RGE_Static_Object* obj, RGE_Object_Node* node);
    void draw(TDrawArea* render_area, short x, short y, unsigned char fogged_tile);
    void shadow_draw(TDrawArea* render_area, short x, short y, unsigned char flag, unsigned char fog_flag);
    void normal_draw(TDrawArea* render_area, short x, short y, unsigned char fog_flag);
    void update();
    RGE_Object_Node* sort();
    RGE_Static_Object* find_by_group(long id);
    RGE_Static_Object* find_by_group(long id, float x, float y,
                                     unsigned char certain_state,
                                     unsigned char object_state,
                                     RGE_Static_Object* zone_obj);
    RGE_Static_Object* find_by_id(long id);
    RGE_Static_Object* find_by_master_id(long id, float x, float y,
                                         unsigned char certain_state,
                                         unsigned char object_state,
                                         RGE_Static_Object* zone_obj);
    RGE_Static_Object* find_by_master_ids(long id1, long id2, float x, float y,
                                          unsigned char certain_state,
                                          unsigned char object_state,
                                          RGE_Static_Object* zone_obj);
    RGE_Static_Object* find_by_type(unsigned char type, float x, float y,
                                    unsigned char certain_state,
                                    unsigned char object_state);
    void save(int outfile);
    void load_list(int infile, RGE_Game_World* world);
    void rehook_list();
};

typedef char object_node_size_check[
    (sizeof(RGE_Object_Node) == 0x10) ? 1 : -1];
typedef char object_list_size_check[
    (sizeof(RGE_Object_List) == 0x0C) ? 1 : -1];

#endif
