#ifndef AOE1_M_S_OBJ_H
#define AOE1_M_S_OBJ_H

// RGE_Master_Static_Object::master_type values, set by each master-object class constructor.
// Numeric macros preserve VC5 output; the values order the class hierarchy (see move_obj/tplayer range checks).
#define RGE_MASTER_TYPE_STATIC 0x0A
#define RGE_MASTER_TYPE_ANIMATED 0x14
#define RGE_MASTER_TYPE_DOPPLEGANGER 0x19
#define RGE_MASTER_TYPE_MOVING 0x1E
#define RGE_MASTER_TYPE_ACTION 0x28
#define RGE_MASTER_TYPE_COMBAT 0x32
#define RGE_MASTER_TYPE_MISSILE 0x3C
#define TRIBE_MASTER_TYPE_COMBAT 0x46
#define TRIBE_MASTER_TYPE_BUILDING 0x50
#define TRIBE_MASTER_TYPE_TREE 0x5A

// Master-object groups, not master-object IDs or tactical-group types.
// Keep the short object_group field and existing integer parameter types.
// The names are cleanup labels taken from the empires.dat members of each group, not developer names.
// Group 11 (missiles, rubble, corpses, smoke) and the memberless groups 0x11, 0x1F, 0x21, and 0x26 stay
// numeric. See workflow/decomp_notes/object_groups.md.
#define OBJECT_GROUP_ARCHER          0
#define OBJECT_GROUP_ARTIFACT        1
#define OBJECT_GROUP_TRADE_BOAT      2
#define OBJECT_GROUP_BUILDING        3
#define OBJECT_GROUP_CIVILIAN        4
#define OBJECT_GROUP_FISH            5
#define OBJECT_GROUP_INFANTRY        6
#define OBJECT_GROUP_FORAGE          7
#define OBJECT_GROUP_STONE_SOURCE    8
#define OBJECT_GROUP_HUNTED_ANIMAL   9
#define OBJECT_GROUP_PREDATOR        10
#define OBJECT_GROUP_CAVALRY         0x0C
#define OBJECT_GROUP_SIEGE_WEAPON    0x0D
#define OBJECT_GROUP_TERRAIN         0x0E
#define OBJECT_GROUP_TREE            0x0F
#define OBJECT_GROUP_TREE_STUMP      0x10
#define OBJECT_GROUP_PRIEST          0x12
#define OBJECT_GROUP_TRANSPORT_BOAT  0x14
#define OBJECT_GROUP_FISHING_BOAT    0x15
#define OBJECT_GROUP_WAR_BOAT        0x16
#define OBJECT_GROUP_CHARIOT_ARCHER  0x17
#define OBJECT_GROUP_WAR_ELEPHANT    0x18
#define OBJECT_GROUP_HERO            0x19
#define OBJECT_GROUP_ELEPHANT_ARCHER 0x1A
#define OBJECT_GROUP_WALL            0x1B
#define OBJECT_GROUP_PHALANX         0x1C
#define OBJECT_GROUP_TRAINED_LION    0x1D
#define OBJECT_GROUP_FLAG            0x1E
#define OBJECT_GROUP_GOLD_SOURCE     0x20
#define OBJECT_GROUP_CLIFF           0x22
#define OBJECT_GROUP_CHARIOT         0x23
#define OBJECT_GROUP_HORSE_ARCHER    0x24
#define OBJECT_GROUP_DOPPLEGANGER    0x25
#define OBJECT_GROUP_SLINGER         0x27

// Master-object IDs, the index into RGE_Player::master_objects. Each name is the internal name that
// the pinned XPack/data2/empires.dat gives that ID, spelled as a macro. 158, 159, and 163 use the
// civilization spelling, not the Gaia list's "_Gaia" suffix. IDs with no record in that file have no
// name. See workflow/decomp_notes/master_object_ids.md.
#define MASTER_OBJECT_ACADEMY                  0
#define MASTER_OBJECT_ALLIGATOR                1
#define MASTER_OBJECT_SOLDIER_ARCHER1          4
#define MASTER_OBJECT_SOLDIER_ARCHER2          5
#define MASTER_OBJECT_SOLDIER_ARCHER3          6
#define MASTER_OBJECT_MISSLE_ARROW             9
#define MASTER_OBJECT_ARTIFACT_DISCOVERY1      10
#define MASTER_OBJECT_SOLDIER_BALISTA          11
#define MASTER_OBJECT_BARRACKS1                12
#define MASTER_OBJECT_BOAT_FISHING1            13
#define MASTER_OBJECT_BOAT_FISHING2            14
#define MASTER_OBJECT_BOAT_TRADE1              15
#define MASTER_OBJECT_BOAT_TRADE2              16
#define MASTER_OBJECT_BOAT_TRANSPORT1          17
#define MASTER_OBJECT_BOAT_TRANSPORT2          18
#define MASTER_OBJECT_BOAT_WAR1                19
#define MASTER_OBJECT_BOAT_WAR2                20
#define MASTER_OBJECT_BOAT_WAR3                21
#define MASTER_OBJECT_RUBBLE_1X1               22
#define MASTER_OBJECT_RUBBLE_2X2               23
#define MASTER_OBJECT_RUBBLE_3X3               24
#define MASTER_OBJECT_SOLDIER_EL_ARCHER        25
#define MASTER_OBJECT_TERRAIN_PATH_STNG5       26
#define MASTER_OBJECT_TERRAIN_PATH_STNG6       27
#define MASTER_OBJECT_TERRAIN_PATH_STNG2       28
#define MASTER_OBJECT_TERRAIN_PATH_DRT1        29
#define MASTER_OBJECT_TERRAIN_PATH_DRT2        30
#define MASTER_OBJECT_TERRAIN_PATH_DRT4        31
#define MASTER_OBJECT_TERRAIN_PATH_DRT5        32
#define MASTER_OBJECT_MISSLE_CATAPULT_STONE    34
#define MASTER_OBJECT_SOLDIER_CATAPULT1        35
#define MASTER_OBJECT_SOLDIER_CATAPULT2        36
#define MASTER_OBJECT_SOLDIER_CAVALRY1         37
#define MASTER_OBJECT_SOLDIER_CAVALRY2         38
#define MASTER_OBJECT_SOLDIER_CAVALRY3_ARCH    39
#define MASTER_OBJECT_SOLDIER_CHARIOT1         40
#define MASTER_OBJECT_SOLDIER_CHARIOT2         41
#define MASTER_OBJECT_DEAD_MAN                 43
#define MASTER_OBJECT_DOCK_1                   45
#define MASTER_OBJECT_SOLDIER_ELEPHANT         46
#define MASTER_OBJECT_TERRAIN_PATH_DRT6        47
#define MASTER_OBJECT_ELEPHANT                 48
#define MASTER_OBJECT_SIEGE_WORKSHOP           49
#define MASTER_OBJECT_FARM                     50
#define MASTER_OBJECT_FENCE_WOOD               51
#define MASTER_OBJECT_FISH_TUNA                52
#define MASTER_OBJECT_FISH_SALMON              53
#define MASTER_OBJECT_TERRAIN_PATH_STNG3       54
#define MASTER_OBJECT_TERRAIN_PATH_STNG4       55
#define MASTER_OBJECT_TREE94                   56
#define MASTER_OBJECT_HERO_PERSEUS             58
#define MASTER_OBJECT_FORAGE_FRUIT             59
#define MASTER_OBJECT_LION_TRAINED             60
#define MASTER_OBJECT_SMOKE                    61
#define MASTER_OBJECT_HERO_ALEXANDER           62
#define MASTER_OBJECT_HERO_XERXES              63
#define MASTER_OBJECT_GAZELLE                  65
#define MASTER_OBJECT_MINE_GOLD                66
#define MASTER_OBJECT_GRANARY                  68
#define MASTER_OBJECT_GUARD_TOWER              69
#define MASTER_OBJECT_HOUSE                    70
#define MASTER_OBJECT_TOWN_CENTER2             71
#define MASTER_OBJECT_WALL_SMALL               72
#define MASTER_OBJECT_SOLDIER_INF1             73
#define MASTER_OBJECT_SOLDIER_INF2             74
#define MASTER_OBJECT_SOLDIER_INF3             75
#define MASTER_OBJECT_SOLDIER_INF4             76
#define MASTER_OBJECT_SOLDIER_INF5             77
#define MASTER_OBJECT_HERO_TIBERIUS            78
#define MASTER_OBJECT_WATCH_TOWER              79
#define MASTER_OBJECT_SHALLOWS                 80
#define MASTER_OBJECT_HERO_AMON_RA             81
#define MASTER_OBJECT_GOVERNMENT_CENTER        82
#define MASTER_OBJECT_MAN                      83
#define MASTER_OBJECT_MARKET1                  84
#define MASTER_OBJECT_DEAD_ALLIGATOR           85
#define MASTER_OBJECT_STABLE1                  86
#define MASTER_OBJECT_RANGE1                   87
#define MASTER_OBJECT_LION_KING                89
#define MASTER_OBJECT_ELEPHANT_KING            90
#define MASTER_OBJECT_SOLDIER_PHAL1            93
#define MASTER_OBJECT_SOLDIER_PHAL2            94
#define MASTER_OBJECT_MISSLE_SPEAR             100
#define MASTER_OBJECT_STABLE                   101
#define MASTER_OBJECT_MINE_STONE               102
#define MASTER_OBJECT_STORAGE_PIT1             103
#define MASTER_OBJECT_TEMPLE1                  104
#define MASTER_OBJECT_STORAGE_PIT2             105
#define MASTER_OBJECT_TERRAIN_BONES            106
#define MASTER_OBJECT_ARTIFACT_WAR_CHEST       108
#define MASTER_OBJECT_TOWN_CENTER1             109
#define MASTER_OBJECT_TRADE_WKSHOP             110
#define MASTER_OBJECT_FLARE                    112
#define MASTER_OBJECT_TREE_FOREST_J1           113
#define MASTER_OBJECT_TREE_FOREST_J2           114
#define MASTER_OBJECT_TREE_STUMP1              115
#define MASTER_OBJECT_MARKET2                  116
#define MASTER_OBJECT_WALL_MED                 117
#define MASTER_OBJECT_BUILDER                  118
#define MASTER_OBJECT_FISHERMAN                119
#define MASTER_OBJECT_FORAGER                  120
#define MASTER_OBJECT_TREE_FOREST_J3           121
#define MASTER_OBJECT_HUNTER                   122
#define MASTER_OBJECT_LUMBERJACK               123
#define MASTER_OBJECT_MINER_STONE              124
#define MASTER_OBJECT_PRIEST                   125
#define MASTER_OBJECT_LION                     126
#define MASTER_OBJECT_EXPLORER                 127
#define MASTER_OBJECT_TREE_FOREST_J4           129
#define MASTER_OBJECT_TREE_STUMP2              130
#define MASTER_OBJECT_TREE_STUMP3              131
#define MASTER_OBJECT_BARRACKS2                132
#define MASTER_OBJECT_DOCK_2                   133
#define MASTER_OBJECT_TREE01                   134
#define MASTER_OBJECT_TREE02                   135
#define MASTER_OBJECT_TREE03                   136
#define MASTER_OBJECT_TREE04                   137
#define MASTER_OBJECT_TREE05                   138
#define MASTER_OBJECT_TREE06                   139
#define MASTER_OBJECT_TREE07                   140
#define MASTER_OBJECT_TREE08                   141
#define MASTER_OBJECT_TREE09                   142
#define MASTER_OBJECT_TREE10                   143
#define MASTER_OBJECT_TREE11                   144
#define MASTER_OBJECT_TREE12                   145
#define MASTER_OBJECT_TREE13                   146
#define MASTER_OBJECT_TREE14                   147
#define MASTER_OBJECT_TREE15                   148
#define MASTER_OBJECT_TREE16                   149
#define MASTER_OBJECT_TREE17                   150
#define MASTER_OBJECT_TREE18                   151
#define MASTER_OBJECT_TREE19                   152
#define MASTER_OBJECT_TREE20                   153
#define MASTER_OBJECT_HOUSE1                   154
#define MASTER_OBJECT_WALL_LARGE               155
#define MASTER_OBJECT_REPAIR_MAN               156
#define MASTER_OBJECT_HORSE                    157
#define MASTER_OBJECT_ARTIFACT_RUINS1          158
#define MASTER_OBJECT_ARTIFACT1                159
#define MASTER_OBJECT_TREE_FOREST_P1           161
#define MASTER_OBJECT_FLAG                     162
#define MASTER_OBJECT_ARTIFACT_RUINS2          163
#define MASTER_OBJECT_CACTUS1                  164
#define MASTER_OBJECT_CACTUS2                  165
#define MASTER_OBJECT_CACTUS3                  166
#define MASTER_OBJECT_GRASS_CLUMP2             167
#define MASTER_OBJECT_GRASS_CLUMP1             168
#define MASTER_OBJECT_CACTUS4                  169
#define MASTER_OBJECT_GRASS_CLUMP3             170
#define MASTER_OBJECT_GRASS_CLUMP4             171
#define MASTER_OBJECT_GRASS_CLUMP5             172
#define MASTER_OBJECT_GRASS_CLUMP6             173
#define MASTER_OBJECT_GRASS_CLUMP7             174
#define MASTER_OBJECT_GRASS_CLUMP8             175
#define MASTER_OBJECT_GRASS_CLUMP9             176
#define MASTER_OBJECT_GRASS_CLUMP10            177
#define MASTER_OBJECT_DESSERT_CLUMP1           178
#define MASTER_OBJECT_DESSERT_CLUMP2           179
#define MASTER_OBJECT_DESSERT_CLUMP3           180
#define MASTER_OBJECT_BONES1                   181
#define MASTER_OBJECT_BONES2                   182
#define MASTER_OBJECT_BONES3                   183
#define MASTER_OBJECT_TERRAIN_ROCK_G2          184
#define MASTER_OBJECT_TERRAIN_ROCK_S2          185
#define MASTER_OBJECT_TERRAIN_ROCK_D1          186
#define MASTER_OBJECT_TERRAIN_CRACK2           187
#define MASTER_OBJECT_TERRAIN_CRACK3           188
#define MASTER_OBJECT_TERRAIN_CRACK4           189
#define MASTER_OBJECT_TERRAIN_CRACK5           190
#define MASTER_OBJECT_TERRAIN_CRACK1           191
#define MASTER_OBJECT_TREE21                   192
#define MASTER_OBJECT_TREE22                   193
#define MASTER_OBJECT_TREE23                   194
#define MASTER_OBJECT_TREE90                   195
#define MASTER_OBJECT_TREE24                   197
#define MASTER_OBJECT_TREE_FOREST_P2           198
#define MASTER_OBJECT_SENTRY_TOWER             199
#define MASTER_OBJECT_TREE_FOREST_P3           203
#define MASTER_OBJECT_MISSLE_BOLT              204
#define MASTER_OBJECT_MISSLE_BOLT_FIRE         205
#define MASTER_OBJECT_MISSLE_ARROW_FIRE        206
#define MASTER_OBJECT_DEAD_ARCH_1              207
#define MASTER_OBJECT_DEAD_ARCH_2              208
#define MASTER_OBJECT_DEAD_AXEMAN              209
#define MASTER_OBJECT_DEAD_B_SWD               210
#define MASTER_OBJECT_DEAD_BALISTA             211
#define MASTER_OBJECT_DEAD_CATAPULT            212
#define MASTER_OBJECT_DEAD_CHARIOT             213
#define MASTER_OBJECT_DEAD_H_CAVALRY           214
#define MASTER_OBJECT_DEAD_INFANTRY            215
#define MASTER_OBJECT_DEAD_L_SWD               216
#define MASTER_OBJECT_DEAD_L_CAVALRY           217
#define MASTER_OBJECT_DEAD_LEGION              218
#define MASTER_OBJECT_DEAD_LONG_BOW            219
#define MASTER_OBJECT_DEAD_PHALNX              221
#define MASTER_OBJECT_DEAD_PRIEST              222
#define MASTER_OBJECT_DEAD_S_SWD               223
#define MASTER_OBJECT_DEAD_WAR_ELE             224
#define MASTER_OBJECT_TREE_FOREST_P4           226
#define MASTER_OBJECT_HERO_JASON               227
#define MASTER_OBJECT_HERO_BLIND_LAME_PRIEST   228
#define MASTER_OBJECT_HERO_DEMON               229
#define MASTER_OBJECT_HERO_HERSIFON            230
#define MASTER_OBJECT_HERO_CORLIS              231
#define MASTER_OBJECT_HERO_HECTOR              233
#define MASTER_OBJECT_HERO_SPY                 234
#define MASTER_OBJECT_HERO_CATAPULT            235
#define MASTER_OBJECT_HERO_TOWER               236
#define MASTER_OBJECT_HERO_HORSE_ARCHER        237
#define MASTER_OBJECT_DOCK_DESTRUCTION         238
#define MASTER_OBJECT_HERO12                   239
#define MASTER_OBJECT_HERO_MERCENARY01         240
#define MASTER_OBJECT_HERO_TRAITOR_01          241
#define MASTER_OBJECT_WALL_L_RUBBLE            242
#define MASTER_OBJECT_DOPPLEGANGER             243
#define MASTER_OBJECT_DEAD_FARM                244
#define MASTER_OBJECT_HERO_MOR_HAVOC           245
#define MASTER_OBJECT_MISSILE_LASER            246
#define MASTER_OBJECT_LASER_TRAIL              247
#define MASTER_OBJECT_SOLDIER_NUKER            248
#define MASTER_OBJECT_MISSILE_NUKE             249
#define MASTER_OBJECT_BOAT_WAR4                250
#define MASTER_OBJECT_MINER_GOLD               251
#define MASTER_OBJECT_DEAD_LUMBER              252
#define MASTER_OBJECT_DEAD_FISHER              253
#define MASTER_OBJECT_DEAD_MINER               254
#define MASTER_OBJECT_DEAD_HUNTER              255
#define MASTER_OBJECT_DEAD_BUILDER             256
#define MASTER_OBJECT_DEAD_FARMER              257
#define MASTER_OBJECT_DEAD_FORAGER             258
#define MASTER_OBJECT_FARMER                   259
#define MASTER_OBJECT_FISH_SHORE_JUMP          260
#define MASTER_OBJECT_DEAD_CHARIOT_2           261
#define MASTER_OBJECT_DEAD_GAZELLE             262
#define MASTER_OBJECT_FISH_SHORE_SWIM          263
#define MASTER_OBJECT_CLIFFS_1                 264
#define MASTER_OBJECT_CLIFFS_2                 265
#define MASTER_OBJECT_CLIFFS_3                 266
#define MASTER_OBJECT_CLIFFS_4                 267
#define MASTER_OBJECT_CLIFFS_5                 268
#define MASTER_OBJECT_CLIFFS_6                 269
#define MASTER_OBJECT_CLIFFS_7                 270
#define MASTER_OBJECT_CLIFFS_8                 271
#define MASTER_OBJECT_CLIFFS_9                 272
#define MASTER_OBJECT_CLIFFS_10                273
#define MASTER_OBJECT_SOLDIER_LASER            274
#define MASTER_OBJECT_MISSLE_CATAPULT_MAN      275
#define MASTER_OBJECT_WONDER                   276
#define MASTER_OBJECT_BOAT_WAR5                277
#define MASTER_OBJECT_GUARD_TOWER2             278
#define MASTER_OBJECT_SOLDIER_BALISTA2         279
#define MASTER_OBJECT_SOLDIER_CATAPULT3        280
#define MASTER_OBJECT_SOLDIER_CAVALRY4         281
#define MASTER_OBJECT_SOLDIER_INF6             282
#define MASTER_OBJECT_SOLDIER_CAVALRY3         283
#define MASTER_OBJECT_SOLDIER_PHAL3            291
#define MASTER_OBJECT_RAFT                     292
#define MASTER_OBJECT_MAN2                     293
#define MASTER_OBJECT_WALL_M_RUBBLE            294
#define MASTER_OBJECT_WALL_S_RUBBLE            295
#define MASTER_OBJECT_CLIFF_WATERFALL          296
#define MASTER_OBJECT_HERO_JUGGERNAUT          297
#define MASTER_OBJECT_HERO_MEDUSA              298
#define MASTER_OBJECT_SOLDIER_SCOUT            299
#define MASTER_OBJECT_MISSLE_ALIGATOR          300
#define MASTER_OBJECT_FENCE_STONE              301
#define MASTER_OBJECT_FIRE                     302
#define MASTER_OBJECT_DEAD_A_CAVALRY           303
#define MASTER_OBJECT_TERRAIN_ROCK_D2          304
#define MASTER_OBJECT_TERRAIN_ROCK_D3          305
#define MASTER_OBJECT_TERRAIN_ROCK_D4          306
#define MASTER_OBJECT_TERRAIN_ROCK_G1          307
#define MASTER_OBJECT_TERRAIN_ROCK_G3          308
#define MASTER_OBJECT_TERRAIN_ROCK_G4          309
#define MASTER_OBJECT_TERRAIN_ROCK_G5          310
#define MASTER_OBJECT_TERRAIN_ROCK_G6          311
#define MASTER_OBJECT_TERRAIN_ROCK_G7          312
#define MASTER_OBJECT_TERRAIN_ROCK_G8          313
#define MASTER_OBJECT_TERRAIN_ROCK_S1          314
#define MASTER_OBJECT_TERRAIN_ROCK_S10         315
#define MASTER_OBJECT_TERRAIN_ROCK_S11         316
#define MASTER_OBJECT_TERRAIN_ROCK_S12         317
#define MASTER_OBJECT_TERRAIN_ROCK_S3          318
#define MASTER_OBJECT_TERRAIN_ROCK_S4          319
#define MASTER_OBJECT_TERRAIN_ROCK_S5          320
#define MASTER_OBJECT_TERRAIN_ROCK_S6          321
#define MASTER_OBJECT_TERRAIN_ROCK_S7          322
#define MASTER_OBJECT_TERRAIN_ROCK_S8          323
#define MASTER_OBJECT_TERRAIN_ROCK_S9          324
#define MASTER_OBJECT_SMOKE_BATTLEX1           326
#define MASTER_OBJECT_SMOKE_BATTLEX2           327
#define MASTER_OBJECT_SMOKE_BATTLEX3           328
#define MASTER_OBJECT_MISSLE_CATAPULT_STONE_F  329
#define MASTER_OBJECT_FLAG_B                   330
#define MASTER_OBJECT_RUBBLESMOKEX3            331
#define MASTER_OBJECT_TERRAIN_ROCK_M1          332
#define MASTER_OBJECT_TERRAIN_ROCK_M2          333
#define MASTER_OBJECT_TERRAIN_ROCK_M3          334
#define MASTER_OBJECT_DEAD_ELEPHANT            335
#define MASTER_OBJECT_DEAD_ELARCH              336
#define MASTER_OBJECT_SPACE_SHIP               337
#define MASTER_OBJECT_SOLDIER_CAMEL            338
#define MASTER_OBJECT_SOLDIER_HVY_CHARIOT      339
#define MASTER_OBJECT_TERRAIN_PATH_STNG1       340
#define MASTER_OBJECT_DEAD_SCOUT               341
#define MASTER_OBJECT_DEAD_CAT2                342
#define MASTER_OBJECT_TERRAIN_DEAD_TREE        343
#define MASTER_OBJECT_TERRAIN_PATH_DRT3        344
#define MASTER_OBJECT_SOLDIER_ARMOR_ELEPHANT   345
#define MASTER_OBJECT_MISSILE_WARBOAT_6        346
#define MASTER_OBJECT_SOLDIER_SLINGER          347
#define MASTER_OBJECT_TERRAIN_PATH_GRS1        348
#define MASTER_OBJECT_TERRAIN_PATH_GRS2        349
#define MASTER_OBJECT_TERRAIN_PATH_GRS3        350
#define MASTER_OBJECT_TERRAIN_PATH_GRS4        351
#define MASTER_OBJECT_TERRAIN_PATH_GRS5        352
#define MASTER_OBJECT_TERRAIN_PATH_GRS6        353
#define MASTER_OBJECT_TERRAIN_PATH_STND1       354
#define MASTER_OBJECT_TERRAIN_PATH_STND2       355
#define MASTER_OBJECT_TERRAIN_PATH_STND3       356
#define MASTER_OBJECT_TERRAIN_PATH_STND4       357
#define MASTER_OBJECT_TERRAIN_PATH_STND5       358
#define MASTER_OBJECT_TERRAIN_PATH_STND6       359
#define MASTER_OBJECT_BOAT_WAR6                360
#define MASTER_OBJECT_MISSILE_SLING_BULLET     361
#define MASTER_OBJECT_ALLIGATOR_KING           362
#define MASTER_OBJECT_DEAD_SLINGER             363
#define MASTER_OBJECT_TREE91                   365
#define MASTER_OBJECT_TREE92                   366
#define MASTER_OBJECT_TREE93                   367
#define MASTER_OBJECT_MISSLE_BOAT_STONE        368
#define MASTER_OBJECT_DEAD_LION                369
#define MASTER_OBJECT_FISH_WHALE               370
#define MASTER_OBJECT_WINSETT_S_Z              372
#define MASTER_OBJECT_Z_ROCKET                 373
#define MASTER_OBJECT_DEAD_CAMEL               374
#define MASTER_OBJECT_HERO_HANNIBAL            375
#define MASTER_OBJECT_HERO_CAESAR              376
#define MASTER_OBJECT_HERO_CLEOPATRA           377
#define MASTER_OBJECT_HERO_MARK_ANTONY         378
#define MASTER_OBJECT_HERO_SCIPIO              379
#define MASTER_OBJECT_HERO_ZENOBIA_S_TOWER     380
#define MASTER_OBJECT_HERO_VERCINGETORIX       381
#define MASTER_OBJECT_HERO_ARCHIMEDES          382
#define MASTER_OBJECT_MIRROR_TOWER             383
#define MASTER_OBJECT_GAZELLE_KING             384
#define MASTER_OBJECT_TERRAIN_BEACH_ROCK       385
#define MASTER_OBJECT_SOLDIER_MECH             386
#define MASTER_OBJECT_DEAD_MECH                387
#define MASTER_OBJECT_MISSILE_MECH_GUN         388
#define MASTER_OBJECT_DEAD_H_CHARIOT           389
#define MASTER_OBJECT_DEAD_ARMORED_ELEPHANT    390
#define MASTER_OBJECT_TREE_PINE_10             391
#define MASTER_OBJECT_TREE_PINE_9              392
#define MASTER_OBJECT_TREE_PINE_IMP            393
#define MASTER_OBJECT_SAINT_FRANCIS            394
#define MASTER_OBJECT_LIGHTNING_BOLT           395
#define MASTER_OBJECT_WINSETT_S_MOM_S_Z        397

#include <stdio.h>
#include "rge_damage_sprite_info.h"

class DClipInfo_List;
class RGE_Color_Table;
class RGE_Game_World;
class RGE_Master_Combat_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Sound;
class RGE_Sprite;
class RGE_Static_Object;
class TDrawArea;

class RGE_Master_Static_Object {
  public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float amount, unsigned char flag);
    virtual void modify_delta(float amount, unsigned char flag);
    virtual void modify_percent(float amount, unsigned char flag);
    virtual void save(int outfile);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* owner, float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(
        RGE_Player* player, float col, float row, int* obstructionObject, unsigned char check_vis,
        unsigned char check_flat, unsigned char check_overlay, unsigned char construction_radius_flag,
        unsigned char can_be_built_on_flag, unsigned char check_objects
    );
    virtual unsigned char alignment(float& col, float& row, RGE_Game_World* world, unsigned char center_flag);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* attacker);
    virtual void play_command_sound() {
    }
    virtual void play_move_sound() {
    }
    virtual void draw(
        TDrawArea* render_area, short x, short y, RGE_Color_Table* player_color, long facet, long frame, int draw_frame,
        unsigned char frame_color
    );

    RGE_Master_Static_Object(RGE_Master_Static_Object* other_object, int do_setup);
    RGE_Master_Static_Object(int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup);
    RGE_Master_Static_Object(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id, int do_setup);

  protected:
    int setup(RGE_Master_Static_Object* other_object);
    int setup(int infile, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id);

  public:
    void make_available(unsigned char on_off_flag);
    unsigned char alignment_box(
        RGE_Game_World* world, float col, float row, short& x1, short& y1, short& x2, short& y2, short& x3, short& y3,
        short& x4, short& y4
    );
    long get_help_message();
    long get_help_page();
    long get_hotkey();

    unsigned char master_type;
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    RGE_Sprite* sprite;
    RGE_Sprite* death_sprite;
    RGE_Sprite* undead_sprite;
    unsigned char undead_flag;
    short hp;
    float los;
    unsigned char obj_max;
    float radius_x;
    float radius_y;
    float radius_z;
    RGE_Sound* selected_sound;
    RGE_Sound* created_sound;
    RGE_Sound* death_sound;
    short death_spawn_obj_id;
    unsigned char sort_number;
    unsigned char can_be_built_on;
    short button_pict;
    unsigned char hide_in_scenario_editor;
    short portrait_pict;
    unsigned char available;
    short tile_req1;
    short tile_req2;
    short center_tile_req1;
    short center_tile_req2;
    float construction_radius_x;
    float construction_radius_y;
    unsigned char elevation_flag;
    unsigned char fog_flag;
    short terrain;
    unsigned char movement_type;
    short attribute_type_held[3];
    float attribute_amount_held[3];
    short attribute_max_amount;
    float attribute_rot;
    float multiple_attribute_mod;
    unsigned char attribute_flag[3];
    unsigned char area_effect_object_level;
    unsigned char combat_level;
    unsigned char select_level;
    unsigned char map_draw_level;
    unsigned char unit_level;
    unsigned char map_color;
    unsigned char attack_reaction;
    unsigned char convert_terrain_flag;
    unsigned char damage_sprite_num;
    RGE_Damage_Sprite_Info* damage_sprites;
    int help_string_id;
    int help_page_id;
    int hotkey_id;
    unsigned char recyclable;
    unsigned char track_as_resource;
    unsigned char create_doppleganger_on_death;
    unsigned char resource_group;
    unsigned char draw_flag;
    unsigned char draw_color;
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;
};

typedef char m_s_obj_master_size_check[(sizeof(RGE_Master_Static_Object) == 0xB8) ? 1 : -1];

#endif
