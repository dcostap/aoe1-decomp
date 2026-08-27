#ifndef TECH_CONTEXT_H
#define TECH_CONTEXT_H

#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4035 4805)

extern "C" void* __cdecl fopen(const char* filename, const char* mode);
extern "C" int __cdecl fclose(void* file);
extern "C" int __cdecl fscanf(void* file, const char* format, ...);
void __cdecl getstring(char** destination, char* source);

struct Tech_Entry {
    char* name;
    short pre_reqs[4];
    short pre_reqs_required;
    short attribute[3];
    short attribute_cost[3];
    unsigned char attribute_used[3];
    char gap_1D;
    short research;
    short effect;
    short civilization;
    short full_tech_mode;
    unsigned char button_location;
    char gap_27;
    short button_id;
    short string_id;
    short string_id2;
    char gap_2E[2];
    long help_string_id;
    long help_page_id;
    long hotkey_id;
};

struct Tech_Player_Tree {
    float research_done;
    short state;
    char gap_06[2];
};

struct Player_Attributes {
    float attributes[0x40];
};

class RGE_Player {
public:
    char gap_00[0x50];
    Player_Attributes* player_attributes;
};

class RGE_Effects {
public:
    void* effects;
    long effect_num;
    virtual ~RGE_Effects();
    virtual void save(int fd);
    virtual void do_effect(short effect_id, RGE_Player* player);
};

struct TRIBE_World {
    char gap_00[0x4C];
    RGE_Effects* effects;
};

class TRIBE_Tech {
public:
    Tech_Entry* tech_tree;
    short tech_tree_num;
    char gap_06[2];
    union {
        TRIBE_World* world;
        TRIBE_World* field_08;
    };

    TRIBE_Tech(int fd, TRIBE_World* world_arg);
    TRIBE_Tech(char* filename);
    ~TRIBE_Tech();
    unsigned char do_tech(short tech_id, RGE_Player* player);
    void save(int fd);
    long get_help_message(short tech_id);
    long get_help_page(short tech_id);
    long get_hotkey(short tech_id);
};

struct Tech_Cost_Temps {
    Tech_Entry* tech;
    short total;
    char gap_06[2];
    unsigned char can_use_carry;
};

struct TRIBE_Tech_Helper {
    unsigned char do_tech(short tech_id, RGE_Player* player);
};

struct TRIBE_History_Info_Helper {
    void add_history_event(unsigned char event_id);
};

class TRIBE_Player_Tech {
public:
    Tech_Player_Tree* tech_player_tree;
    short tech_player_tree_num;
    char gap_06[2];
    union {
        TRIBE_Tech* base_tech;
        TRIBE_Tech* base;
        TRIBE_Tech* field_08;
    };
    RGE_Player* owner;

    TRIBE_Player_Tech(int fd, TRIBE_Tech* tech, RGE_Player* player, unsigned char load);
    TRIBE_Player_Tech(TRIBE_Tech* tech, RGE_Player* player, unsigned char load);
    ~TRIBE_Player_Tech();
    short get_tech_state(short tech_id);
    unsigned char undo_tech(short tech_id);
    unsigned char do_tech(short tech_id);
    unsigned char research(short tech_id, float amount);
    void tech_cost(short tech_id, short* attr1, short* cost1, short* attr2, short* cost2, short* attr3, short* cost3);
    unsigned char check_tech_cost(short tech_id, short* missing_attribute);
    unsigned char start_research(short tech_id, unsigned char charge, short* missing_attribute);
    unsigned char cancel_research(short tech_id, unsigned char refund);
    unsigned char check_for_new_tech();
    void save(int fd);
    short get_progress(short tech_id);
    char* get_name(short tech_id);
    short get_string_id(short tech_id);
    short get_string_id2(short tech_id);
    unsigned char get_button_location(short tech_id);
    void do_rev_tech(short tech_id);
    unsigned char rev_tech(short tech_id);
    void disable(short tech_id);
    void enable(short tech_id);
    long get_help_message(short tech_id);
    long get_help_page(short tech_id);
    long get_hotkey(short tech_id);
};

extern float save_game_version;
extern double DAT_005766d8;
void __cdecl rge_read(int fd, void* data, int size);
void __cdecl rge_write(int fd, void* data, int size);
long __cdecl __ftol(double value);

#endif
