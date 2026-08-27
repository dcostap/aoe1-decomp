#ifndef OBJ_LIST_H
#define OBJ_LIST_H

class RGE_Game_World;
class RGE_Static_Object;
class TDrawArea;

struct RGE_Object_Node {
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
    RGE_Static_Object* find_by_type(unsigned char, float, float,
                                    unsigned char, unsigned char);
    void save(int);
    void load_list(int, RGE_Game_World*);
    void rehook_list();
};

typedef char object_node_size_check[
    (sizeof(RGE_Object_Node) == 0x10) ? 1 : -1];
typedef char object_list_size_check[
    (sizeof(RGE_Object_List) == 0x0C) ? 1 : -1];

#endif
