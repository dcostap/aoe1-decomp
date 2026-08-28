#ifndef AOE1_TECH_H
#define AOE1_TECH_H

class RGE_Player;
class TRIBE_World;

// CodeView record: class Tech_Tree, size 0x3C.
class Tech_Tree {
public:
    char* name;
    short pre_reqs[4];
    short pre_reqs_required;
    short attribute[3];
    short attribute_cost[3];
    unsigned char attribute_used[3];
    short research;
    short effect;
    short track;
    short icon;
    unsigned char button_location;
    short build_obj_id;
    short string_id;
    short string_id2;
    long help_string_id;
    long help_page_id;
    long hotkey_id;
};

typedef char tech_tree_size_check[(sizeof(Tech_Tree) == 0x3C) ? 1 : -1];

// CodeView record: class Tech_Player_Tree, size 0x08.
class Tech_Player_Tree {
public:
    float research_done;
    short state;
};

typedef char tech_player_tree_size_check[
    (sizeof(Tech_Player_Tree) == 0x08) ? 1 : -1];

class TRIBE_Tech {
public:
    Tech_Tree* tech_tree;
    short tech_tree_num;
    TRIBE_World* world;

    TRIBE_Tech(int, TRIBE_World*);
    TRIBE_Tech(char*);
    ~TRIBE_Tech();

    unsigned char do_tech(short, RGE_Player*);
    void save(int);
    long get_help_message(short);
    long get_help_page(short);
    long get_hotkey(short);
};

typedef char tribe_tech_size_check[(sizeof(TRIBE_Tech) == 0x0C) ? 1 : -1];

class TRIBE_Player_Tech {
public:
    Tech_Player_Tree* tech_player_tree;
    short tech_player_tree_num;
    TRIBE_Tech* base_tech;
    RGE_Player* owner;

    TRIBE_Player_Tech(int, TRIBE_Tech*, RGE_Player*, unsigned char);
    TRIBE_Player_Tech(TRIBE_Tech*, RGE_Player*, unsigned char);
    ~TRIBE_Player_Tech();

    short get_tech_state(short);
    unsigned char undo_tech(short);
    unsigned char do_tech(short);
    unsigned char research(short, float);
    void tech_cost(short, short*, short*, short*, short*, short*, short*);
    unsigned char check_tech_cost(short, short*);
    unsigned char start_research(short, unsigned char, short*);
    unsigned char cancel_research(short, unsigned char);
    unsigned char check_for_new_tech();
    void save(int);
    short get_progress(short);
    char* get_name(short);
    short get_string_id(short);
    short get_string_id2(short);
    unsigned char get_button_location(short);
    void do_rev_tech(short);
    unsigned char rev_tech(short);
    void disable(short);
    void enable(short);
    long get_help_message(short);
    long get_help_page(short);
    long get_hotkey(short);
};

typedef char tribe_player_tech_size_check[
    (sizeof(TRIBE_Player_Tech) == 0x10) ? 1 : -1];

#endif
