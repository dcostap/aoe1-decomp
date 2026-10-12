#ifndef AOE1_TECH_H
#define AOE1_TECH_H

// Technology IDs, the index into TRIBE_Tech::tech_tree and the research IDs in AI build lists. Each name is
// the name that the pinned XPack/data2/empires.dat gives that record, spelled as a macro. Records with an
// empty name have no macro. See workflow/decomp_notes/technology_ids.md.
#define TECH_DOCK                          0
#define TECH_LIGHT_TRANSPORT               1
#define TECH_CATAPULT_TOWER                2
#define TECH_SMALL_WAR_SHIP                3
#define TECH_FISHING_SHIP                  4
#define TECH_MEDIUM_WAR_SHIP               5
#define TECH_MERCHANT_SHIP                 6
#define TECH_TRIREME                       7
#define TECH_HEAVY_TRANSPORT               8
#define TECH_TRIREME_WITH_CATAPULT         9
#define TECH_GRANARY                       10
#define TECH_STONE_WALL                    11
#define TECH_SENTRY_TOWER                  12
#define TECH_MEDIUM_WALL                   13
#define TECH_FORTIFICATIONS                14
#define TECH_GUARD_TOWER                   15
#define TECH_WATCH_TOWER                   16
#define TECH_TEMPLE                        17
#define TECH_AFTERLIFE                     18
#define TECH_MONOTHEISM                    19
#define TECH_FANATICISM                    20
#define TECH_MYSTICISM                     21
#define TECH_ASTROLOGY                     22
#define TECH_JIHAD                         23
#define TECH_POLYTHEISM                    24
#define TECH_JUGGERNAUGHT                  25
#define TECH_MARKET                        26
#define TECH_HELEPOLIS                     27
#define TECH_WHEEL                         28
#define TECH_COINAGE                       30
#define TECH_PLOW                          31
#define TECH_ARTISANSHIP                   32
#define TECH_GOVERNMENT                    33
#define TECH_NOBILITY                      34
#define TECH_ENGINEERING                   35
#define TECH_MASSIVE_CATAPULT              36
#define TECH_ALCHEMY                       37
#define TECH_ADVANCED_HORSE_ARCHER         38
#define TECH_STORAGE_PIT                   39
#define TECH_LEATHER_ARMOR_SOLDIERS        40
#define TECH_LEATHER_ARMOR_ARCHERS         41
#define TECH_LEATHER_ARMOR_MOUNTED         42
#define TECH_SCALE_ARMOR_SOLDIERS          43
#define TECH_SCALE_ARMOR_ARCHERS           44
#define TECH_SCALE_ARMOR_CAVALRY           45
#define TECH_TOOL_WORKING                  46
#define TECH_BRONZE_SHIELD                 47
#define TECH_CHAIN_MAIL_SOLDIERS           48
#define TECH_CHAIN_MAIL_ARCHERS            49
#define TECH_CHAIN_MAIL_CAVALRY            50
#define TECH_METAL_WORKING                 51
#define TECH_METALURGY                     52
#define TECH_SIEGE_WORKSHOP                53
#define TECH_HEAVY_CATAPULT                54
#define TECH_ARCHERY_RANGE                 55
#define TECH_IMPROVED_BOW                  56
#define TECH_COMPOSIT_BOW                  57
#define TECH_BALISTA                       58
#define TECH_CHARIOT_ARCHER                59
#define TECH_HORSE_ARCHER                  60
#define TECH_ELEPHANT_ARCHER               61
#define TECH_BARRACKS                      62
#define TECH_AXE                           63
#define TECH_SHORT_SWORD                   64
#define TECH_BROAD_SWORD                   65
#define TECH_LONG_SWORD                    66
#define TECH_STABLE                        67
#define TECH_CHARIOT                       68
#define TECH_CAVALRY                       69
#define TECH_WAR_ELEPHANT                  70
#define TECH_HEAVY_CAVALRY                 71
#define TECH_ACADEMY                       72
#define TECH_PHALANX                       73
#define TECH_A01_B01_F01_I01_TOOL_AGE      74
#define TECH_D01_H01_J01_BRONZE_AGE        75
#define TECH_B3_C1_D1_IRON_AGE             76
#define TECH_LEGION                        77
#define TECH_CATAPHRACTS                   78
#define TECH_CENTURION                     79
#define TECH_IRRIGATION                    80
#define TECH_DOMESTICATION                 81
#define TECH_TC_GRANARY                    88
#define TECH_TC_STORAGE_PIT                89
#define TECH_TC_DOCK                       90
#define TECH_TC_BARRACKS                   91
#define TECH_STABLE_BRONZE_AGE_ACADEMY     92
#define TECH_MARKET_BRONZE_AGE_GOVT        93
#define TECH_GRANARY_TOOL_AGE_MARKET       94
#define TECH_BARRACKS_TOOL_AGE_RANGE       95
#define TECH_RANGE_BRONZE_AGE_SIEGE_WKSHP  96
#define TECH_BARRACKS_TOOL_AGE_STABLE      97
#define TECH_MARKET_BRONZE_AGE_TEMPLE      98
#define TECH_STONE_AGE                     100
#define TECH_TOOL_AGE                      101
#define TECH_BRONZE_AGE                    102
#define TECH_IRON_AGE                      103
#define TECH_GRANARY_STORAGE_PIT_BARRACKS  105
#define TECH_BALISTICS                     106
#define TECH_WOOD_WORKING                  107
#define TECH_GOLD_MINING                   108
#define TECH_STONE_MINING                  109
#define TECH_CRAFTMANSHIP                  110
#define TECH_SIEGE_CRAFT                   111
#define TECH_ARCHITECTURE                  112
#define TECH_ARISTOCRACY                   113
#define TECH_WRITING                       114
#define TECH_SHADOW_GB_TC                  115
#define TECH_SHADOW_GB_WONDER              116
#define TECH_IRON_SHIELD                   117
#define TECH_NAVAL_RAM                     118
#define TECH_MEDICINE                      119
#define TECH_MARTYRDOM                     120
#define TECH_LOGISTICS                     121
#define TECH_TOWER_SHIELD                  122
#define TECH_SLINGER                       123
#define TECH_CAMEL                         124
#define TECH_ARMORED_ELEPHANTS             125
#define TECH_HEAVY_CHARIOTS                126

class RGE_Player;
class TRIBE_World;

// CodeView record: struct Tech_Tree, size 0x3C.
struct Tech_Tree {
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

// CodeView record: struct Tech_Player_Tree, size 0x08.
struct Tech_Player_Tree {
  public:
    float research_done;
    short state;
};

typedef char tech_player_tree_size_check[(sizeof(Tech_Player_Tree) == 0x08) ? 1 : -1];

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
    void tech_cost(short, short&, short&, short&, short&, short&, short&);
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

typedef char tribe_player_tech_size_check[(sizeof(TRIBE_Player_Tech) == 0x10) ? 1 : -1];

#endif
