#ifndef VICTORY_DESCRIPTION_CONTEXT_H
#define VICTORY_DESCRIPTION_CONTEXT_H

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" void __cdecl getstring(char** destination, char* source);

#ifndef VICTORY_CONTEXT_H
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[4];
    char* name;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
    char gap_28[0x22];
    short id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[4];
    RGE_Master_Static_Object* master_obj;
};

class RGE_Victory_Entry {
public:
    unsigned char command;
    char gap_01[3];
    long obj_type;
    RGE_Player* target_player;
    float x0;
    float y0;
    float x1;
    float y1;
    long number;
    long count;
    RGE_Static_Object* this_obj;
    RGE_Static_Object* target_obj;
    char gap_2C[4];
    RGE_Victory_Entry* next;
};

class RGE_Victory_Conditions {
public:
    virtual ~RGE_Victory_Conditions();
    virtual void handle_point_condition(void* entry);
    virtual void handle_condition(RGE_Victory_Entry* entry);
    virtual char* condition_description(RGE_Victory_Entry* entry);
    virtual void save(int handle);

    void sub(RGE_Victory_Entry* entry);
    void destroy_all();

    RGE_Victory_Entry* victory_list;
    long list_num;
};
#endif

#endif
