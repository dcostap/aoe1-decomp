// VA: 00470940 RGE_Player::modify_tobj_delta
// PDB source: player.cpp, lines 1571-1598
//
// Baseline reconstruction: apply a delta modification to one master object,
// or to every master in the requested group, walking the live object list
// before modifying the master itself.
//
// Attempt log:
// - Reused the exact modify_tobj source shape and same-TU typed ABI; only the
//   delta virtual method at object/master slots 0x4c/0x0c differs.

class RGE_Player;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);

    char gap_04[0x10];
    short object_group;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(void*, short, short, void*);
    virtual void shadow_draw(void*, short, short, unsigned char);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(void*);
    virtual void add_overlay_sprite(void*, unsigned char);
    virtual void remove_overlay_sprite(void*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);

    char gap_04[4];
    RGE_Master_Static_Object* master_obj;
};

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    char gap_00[4];
    RGE_Object_Node* list;
};

class RGE_Player {
public:
    virtual ~RGE_Player();

    char gap_04[0x1E];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;

    void modify_tobj_delta(short, short, float, unsigned char);
};

void RGE_Player::modify_tobj_delta(short object_num, short object_group,
                                   float amount, unsigned char amount_type)
{
    if (object_num >= 0) {
        short i = object_num;
        if (master_objects[i] != 0) {
            if (objects != 0) {
                RGE_Object_Node* node = objects->list;
                while (node != 0) {
                    if (node->node->master_obj == master_objects[i]) {
                        node->node->modify_delta(amount, amount_type);
                    }
                    node = node->next;
                }
            }
            master_objects[i]->modify_delta(amount, amount_type);
        }
    } else if (object_group >= 0) {
        short i = 0;
        if (master_object_num > 0) {
            do {
                if (master_objects[i] != 0 &&
                    master_objects[i]->object_group == object_group) {
                    if (objects != 0) {
                        RGE_Object_Node* node = objects->list;
                        while (node != 0) {
                            if (node->node->master_obj == master_objects[i]) {
                                node->node->modify_delta(amount, amount_type);
                            }
                            node = node->next;
                        }
                    }
                    master_objects[i]->modify_delta(amount, amount_type);
                }
                ++i;
            } while (i < master_object_num);
        }
    }
}
