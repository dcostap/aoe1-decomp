#ifndef VICTORY_CONTEXT_H
#define VICTORY_CONTEXT_H

// Shared period-shaped declarations for the victory.cpp owner set.
//
// The PDB identifies one RGE_Victory_Conditions class for the complete
// victory.cpp source module.  Keep the proven field offsets and virtual slots
// in one declaration.  Individual owner files still define only their own
// function body.

extern "C" void rge_read(int handle, void* data, int size);
extern "C" void rge_write(int handle, void* data, int size);
extern "C" void* calloc(unsigned int count, unsigned int size);

class RGE_Game_World;
class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Static_Object;
class RGE_Object_List;
class RGE_Victory_Entry;
class RGE_Victory_Point_Entry;

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    class RGE_Object_Node* list; // +0x04
    RGE_Static_Object* find_by_id(long id);
};

class RGE_Object_Node {
public:
    RGE_Static_Object* node; // +0x00
    RGE_Object_Node* next; // +0x04
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    char gap_04[0x38];
    short player_num; // +0x3C
    char gap_3E[2];
    RGE_Player** players; // +0x40
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x24];
    RGE_Object_List* objects; // +0x28
    char gap_2C[0x10];
    RGE_Game_World* world; // +0x3C
    char gap_40[0x0A];
    short id; // +0x4A
    char gap_4C[4];
    float* attributes; // +0x50
    char gap_54[0x30];
    unsigned char* relations; // +0x84
    char gap_88[0x7C];
    unsigned char allied_victory; // +0x104
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0E];
    short copy_id; // +0x12
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id; // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner; // +0x0C
    char gap_10[0x28];
    float world_x; // +0x38
    float world_y; // +0x3C
    char gap_40[8];
    unsigned char object_state; // +0x48
};

class RGE_Victory_Entry {
public:
    unsigned char command; // +0x00
    char gap_01[3];
    long obj_type; // +0x04
    RGE_Player* target_player; // +0x08
    float x0; // +0x0C
    float y0; // +0x10
    float x1; // +0x14
    float y1; // +0x18
    long number; // +0x1C
    long count; // +0x20
    RGE_Static_Object* this_obj; // +0x24
    RGE_Static_Object* target_obj; // +0x28
    unsigned char victory_group; // +0x2C
    unsigned char ally_flag; // +0x2D
    unsigned char state; // +0x2E
    unsigned char checked_flag; // +0x2F
    RGE_Victory_Entry* next; // +0x30
};

class RGE_Victory_Point_Entry {
public:
    unsigned char command; // +0x00
    unsigned char state; // +0x01
    unsigned char id; // +0x02
    unsigned char group; // +0x03
    long attribute; // +0x04
    long amount; // +0x08
    long points; // +0x0C
    long curr_points; // +0x10
    float curr_attribute_amount; // +0x14
    RGE_Victory_Point_Entry* next; // +0x18
};

class RGE_Victory_Conditions {
public:
    virtual void handle_point_condition(RGE_Victory_Point_Entry* entry);
    virtual void handle_condition(RGE_Victory_Entry* entry);
    virtual char* condition_description(RGE_Victory_Entry* entry);
    virtual void save(int handle);

    RGE_Victory_Conditions(RGE_Player* player);
    RGE_Victory_Conditions(RGE_Player* player, int handle, long* version_map,
                           unsigned char version_flag);
    ~RGE_Victory_Conditions();

    RGE_Victory_Entry* add(unsigned char group, unsigned char id);
    unsigned char add_attributes(unsigned char group, long attribute, long amount,
                                 unsigned char state);
    unsigned char add_bring(unsigned char group, RGE_Static_Object* this_obj,
                            RGE_Static_Object* target_obj);
    unsigned char add_bring(unsigned char group, RGE_Static_Object* this_obj,
                            float x0, float y0, float x1, float y1);
    unsigned char add_capture(unsigned char group, RGE_Static_Object* this_obj,
                              unsigned char ally_flag);
    unsigned char add_create(unsigned char group, long obj_type, long number,
                             unsigned char ally_flag);
    unsigned char add_create(unsigned char group, long obj_type, long number,
                             float x0, float y0, float x1, float y1,
                             unsigned char ally_flag);
    unsigned char add_destroy(unsigned char group, RGE_Static_Object* this_obj);
    unsigned char add_destroy(unsigned char group, long obj_type, long number,
                              RGE_Player* target_player);
    unsigned char add_destroy(unsigned char group, long obj_type,
                              RGE_Player* target_player);
    unsigned char add_destroy(unsigned char group, RGE_Player* target_player);
    unsigned char add_explore(unsigned char group, long percent,
                              unsigned char ally_flag);
    RGE_Victory_Point_Entry* add_point(unsigned char group, unsigned char id);
    unsigned char add_points_attribute_amount(unsigned char group, unsigned char id,
                                              long attribute, long amount, long points);
    unsigned char add_points_attribute_first(unsigned char group, unsigned char id,
                                             long attribute, long amount, long points);
    unsigned char add_points_high_attribute_amount(unsigned char group, unsigned char id,
                                                    long attribute, long amount, long points);
    unsigned char add_points_high_attribute_once(unsigned char group, unsigned char id,
                                                 long attribute, long amount, long points);
    unsigned char add_points_highest_attribute(unsigned char group, unsigned char id,
                                               long attribute, long amount, long points);
    unsigned char add_victory_points(unsigned char group, long points,
                                     unsigned char id);

    void check_for_victory();
    unsigned char condition_info(long index, char** out_entry,
                                 unsigned char* out_command);
    long condition_number(long index);
    RGE_Victory_Entry* condition_raw_info(long index);
    void destroy_all();
    long get_attribute_id(unsigned char id);
    long get_victory_points();
    long get_victory_points_group(unsigned char group);
    long get_victory_points_id(unsigned char id);
    void handle_attribute(RGE_Victory_Entry* entry);
    void handle_bring_area(RGE_Victory_Entry* entry);
    void handle_bring_object(RGE_Victory_Entry* entry);
    void handle_capture(RGE_Victory_Entry* entry);
    void handle_create(RGE_Victory_Entry* entry);
    void handle_create_in_area(RGE_Victory_Entry* entry);
    void handle_destroy(RGE_Victory_Entry* entry);
    void handle_destroy_all(RGE_Victory_Entry* entry);
    void handle_destroy_multiple(RGE_Victory_Entry* entry);
    void handle_destroy_player(RGE_Victory_Entry* entry);
    void handle_explore(RGE_Victory_Entry* entry);
    void handle_points_attribute_amount(RGE_Victory_Point_Entry* entry);
    void handle_points_attribute_first(RGE_Victory_Point_Entry* entry);
    void handle_points_high_attribute_amount(RGE_Victory_Point_Entry* entry);
    void handle_points_high_attribute_once(RGE_Victory_Point_Entry* entry);
    void handle_victory_points(RGE_Victory_Entry* entry);
    unsigned char remove_condition(long index);
    void sub(RGE_Victory_Entry* entry);
    void sub_point(RGE_Victory_Point_Entry* entry);
    unsigned char update();
    void update_for_object(RGE_Static_Object* object);
    unsigned char victory_achieved();

protected:
    void handle_points_highest_attribute(RGE_Victory_Point_Entry* entry);

public:
    RGE_Victory_Entry* victory_list; // +0x04
    long list_num; // +0x08
    RGE_Player* player; // +0x0C
    unsigned char victory; // +0x10
    char gap_11[3];
    RGE_Victory_Point_Entry* victory_point_list; // +0x14
    long point_list_num; // +0x18
    long tot_victory_points; // +0x1C
};

#endif
