#ifndef AOE1_TIMELINE_H
#define AOE1_TIMELINE_H

// Declarations for the original Timeline.cpp source module.

class RGE_Game_World;
class RGE_Static_Object;

struct RGE_Time_Entry {
    float time;
    unsigned char command;
    short obj_type;
    unsigned char player;
    float x;
    float y;
    float z;
    short task;
    RGE_Static_Object* this_obj;
    short this_obj_id;
    RGE_Static_Object* target_obj;
    short target_obj_id;
    RGE_Time_Entry* next;
};

typedef char timeline_entry_layout[
    (sizeof(RGE_Time_Entry) == 0x30) ? 1 : -1];
typedef char timeline_entry_next_offset[
    ((char*)&((RGE_Time_Entry*)0)->next - (char*)0 == 0x2c) ? 1 : -1];

class RGE_Timeline {
public:
    RGE_Timeline(RGE_Game_World* world);
    RGE_Timeline(int fd, RGE_Game_World* world);
    virtual ~RGE_Timeline();

    void update();
    void mock_update(float time);
    void save(int fd);

    RGE_Time_Entry* add(float time);
    RGE_Time_Entry* add_attack(float time, RGE_Static_Object* this_obj,
                               RGE_Static_Object* target_obj);
    RGE_Time_Entry* add_create(float time, short obj_type,
                               unsigned char player, float x, float y,
                               float z);
    RGE_Time_Entry* add_move(float time, RGE_Static_Object* this_obj,
                             float x, float y, float z);
    RGE_Time_Entry* add_delete(float time, RGE_Static_Object* this_obj);
    void sub(RGE_Time_Entry* entry);

    RGE_Game_World* world;
    RGE_Time_Entry* time_list;
    short list_num;
    short avail_id;
    float old_time;

private:
    short find_id(RGE_Static_Object* obj);
};

typedef char timeline_object_layout[
    (sizeof(RGE_Timeline) == 0x14) ? 1 : -1];
typedef char timeline_world_offset[
    ((char*)&((RGE_Timeline*)0)->world - (char*)0 == 0x04) ? 1 : -1];
typedef char timeline_list_offset[
    ((char*)&((RGE_Timeline*)0)->time_list - (char*)0 == 0x08) ? 1 : -1];

#endif
