#ifndef AOE1_TECH_H
#define AOE1_TECH_H

class RGE_Player;
class Tech_Player_Tree;
class Tech_Tree;
class TRIBE_Tech;
class TRIBE_World;

class TRIBE_Tech {
public:
    Tech_Tree* tech_tree;
    short tech_tree_num;
    TRIBE_World* world;
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

    unsigned char research(short, float);
    unsigned char start_research(short, unsigned char, short*);
    unsigned char cancel_research(short, unsigned char);
    unsigned char check_for_new_tech();
    short get_tech_state(short);
    short get_progress(short);
    char* get_name(short);
    void disable(short);
    void enable(short);
    unsigned char do_tech(short);
    unsigned char undo_tech(short);
};

typedef char tribe_player_tech_size_check[
    (sizeof(TRIBE_Player_Tech) == 0x10) ? 1 : -1];

#endif
