#pragma once
#include "common.h"

class RGE_Check_List {
public:
    RGE_Check_Node* list;                    // 0x0

    RGE_Check_List();
    ~RGE_Check_List();
    void add_node(RGE_Static_Object* param_1, float param_2, float param_3, uchar param_4);
};

static_assert(sizeof(RGE_Check_List) == 0x4, "RGE_Check_List Size Mismatch");

class RGE_Static_Object {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
    long id;                                 // 0x4
    RGE_Master_Static_Object* master_obj;    // 0x8
    RGE_Player* owner;                       // 0xC
    RGE_Sprite* sprite;                      // 0x10
    RGE_Sprite* old_sprite;                  // 0x14
    RGE_Active_Sprite_List* sprite_list;     // 0x18
    RGE_Tile* tile;                          // 0x1C
    RGE_Static_Object* inside_obj;           // 0x20
    RGE_Object_List* objects;                // 0x24
    short screen_x_offset;                   // 0x28
    short screen_y_offset;                   // 0x2A
    short shadow_x_offset;                   // 0x2C
    short shadow_y_offset;                   // 0x2E
    float hp;                                // 0x30
    uchar curr_damage_percent;               // 0x34
    uchar facet;                             // 0x35
    uchar selected;                          // 0x36
    uchar selected_group;                    // 0x37
    float world_x;                           // 0x38
    float world_y;                           // 0x3C
    float world_z;                           // 0x40
    float attribute_amount_held;             // 0x44
    uchar object_state;                      // 0x48
    uchar sleep_flag;                        // 0x49
    uchar dopple_flag;                       // 0x4A
    uchar goto_sleep_flag;                   // 0x4B
    short attribute_type_held;               // 0x4C
    uchar type;                              // 0x4E
    uchar worker_num;                        // 0x4F
    RGE_Object_Node* player_object_node;     // 0x50
    ManagedArray<int> pathingGroupMembers;   // 0x54
    ManagedArray<int> groupMembers;          // 0x64
    UnitAIModule* unitAIValue;               // 0x74
    int groupCommanderValue;                 // 0x78
    int zoneMapIndex;                        // 0x7C
    float groupRangeValue;                   // 0x80
    uchar inObstructionMapValue;             // 0x84
    uchar lastInObstructionMapValue;         // 0x85
    uchar underAttackValue;                  // 0x86

    virtual void recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5); // vt0[1]+0x4=0x4C1420
    virtual void recycle_out_of_game();                     // vt0[2]+0x8=0x4C1590
    virtual void draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4); // vt0[3]+0xC=0x4C1F30
    virtual void shadow_draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4); // vt0[4]+0x10=0x4C2030
    virtual void normal_draw(TDrawArea* param_1, short param_2, short param_3); // vt0[5]+0x14=0x4C2080
    virtual void draw_front_frame(TDrawArea* param_1, short param_2, short param_3); // vt0[6]+0x18=0x4C2110
    virtual void draw_back_frame(TDrawArea* param_1, short param_2, short param_3); // vt0[7]+0x1C=0x4C21A0
    virtual void draw_frame(TDrawArea* param_1, short param_2, short param_3); // vt0[8]+0x20=0x4C3B30
    virtual uchar update();                                 // vt0[9]+0x24=0x4C3C70
    virtual void check_damage_sprites();                    // vt0[10]+0x28=0x4C3F90
    virtual void rehook();                                  // vt0[11]+0x2C=0x4C4210
    virtual void save(int param_1);                         // vt0[12]+0x30=0x4C4360
    virtual float teleport(float param_1, float param_2, float param_3); // vt0[13]+0x34=0x4C4680
    virtual void new_sprite(RGE_Sprite* param_1);           // vt0[14]+0x38=0x4C4BD0
    virtual void add_overlay_sprite(RGE_Sprite* param_1, uchar param_2); // vt0[15]+0x3C=0x4C4C20
    virtual void remove_overlay_sprite(RGE_Sprite* param_1); // vt0[16]+0x40=0x4C4C40
    virtual void change_ownership(RGE_Player* param_1);     // vt0[17]+0x44=0x4C4C50
    virtual void modify(float param_1, uchar param_2);      // vt0[18]+0x48=0x4C4D80
    virtual void modify_delta(float param_1, uchar param_2); // vt0[19]+0x4C=0x4C4E00
    virtual void modify_percent(float param_1, uchar param_2); // vt0[20]+0x50=0x4C4E90
    virtual void transform(RGE_Master_Static_Object* param_1); // vt0[21]+0x54=0x4C4F10
    virtual void copy_obj(RGE_Master_Static_Object* param_1); // vt0[22]+0x58=0x4C4FB0
    virtual void set_object_state(uchar param_1);           // vt0[23]+0x5C=0x4C52F0
    virtual void remove_visible_resource();                 // vt0[24]+0x60=0x4C50F0
    virtual void create_doppleganger_when_dying();          // vt0[25]+0x64=0x4C5210
    virtual void destroy_obj();                             // vt0[26]+0x68=0x4C5080
    virtual void die_die_die();                             // vt0[27]+0x6C=0x4C50C0
    virtual void damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5); // vt0[28]+0x70=0x4C5B90
    virtual float calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5); // vt0[29]+0x74=0x4C5BE0
    virtual void rotate(long param_1);                      // vt0[30]+0x78=0x4C5C10
    virtual uchar can_attack();                             // vt0[31]+0x7C=0x405D00
    virtual void set_attribute(short param_1, float param_2); // vt0[32]+0x80=0x4C5C40
    virtual void set_attribute_amount(float param_1, uchar param_2, uchar param_3); // vt0[33]+0x84=0x4C5C60
    virtual int heal(int param_1, int param_2);             // vt0[34]+0x88=0x405EA0
    virtual uchar heal(float param_1);                      // vt0[35]+0x8C=0x4C5CB0
    virtual int canRepair();                                // vt0[36]+0x90=0x405D10
    virtual void notify_of_relation(long param_1, uchar param_2); // vt0[37]+0x94=0x4C5D10
    virtual void do_command(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[38]+0x98=0x41A450
    virtual void move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[39]+0x9C=0x41A460
    virtual void work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[40]+0xA0=0x41A470
    virtual void stop();                                    // vt0[41]+0xA4=0x41A480
    virtual void set_attack(RGE_Static_Object* param_1);    // vt0[42]+0xA8=0x41A490
    virtual void play_command_sound();                      // vt0[43]+0xAC=0x41A4A0
    virtual void play_move_sound();                         // vt0[44]+0xB0=0x41A4B0
    virtual void new_angle(float param_1);                  // vt0[45]+0xB4=0x4C6260
    virtual RGE_Static_Object* spawn_death_obj();           // vt0[46]+0xB8=0x4C41D0
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[47]+0xBC=0x41A4C0
    virtual void set_being_worked_on(RGE_Action_Object* param_1, short param_2, uchar param_3); // vt0[48]+0xC0=0x4C5D20
    virtual void release_being_worked_on(RGE_Static_Object* param_1); // vt0[49]+0xC4=0x4C5D40
    virtual uchar is_moving();                              // vt0[50]+0xC8=0x4C5850
    virtual RGE_Static_Object* get_target_obj();            // vt0[51]+0xCC=0x41A4D0
    virtual void enter_obj(RGE_Static_Object* param_1);     // vt0[52]+0xD0=0x4C58E0
    virtual void exit_obj();                                // vt0[53]+0xD4=0x4C5960
    virtual int explore_terrain(RGE_Player* param_1, uchar param_2, int param_3); // vt0[54]+0xD8=0x4C59B0
    virtual void unexplore_terrain(RGE_Player* param_1, uchar param_2, int param_3); // vt0[55]+0xDC=0x4C5AA0
    virtual LOSTBL* get_los_table();                        // vt0[56]+0xE0=0x4C5980
    virtual int inAttackRange(RGE_Static_Object* param_1);  // vt0[57]+0xE4=0x405D20
    virtual uchar underAttack();                            // vt0[58]+0xE8=0x4C6B60
    virtual void setUnderAttack(uchar param_1);             // vt0[59]+0xEC=0x4C6B70
    virtual float calc_attack_modifier(RGE_Static_Object* param_1); // vt0[60]+0xF0=0x405D30
    virtual float getSpeed();                               // vt0[61]+0xF4=0x4C1CE0
    virtual float getAngle();                               // vt0[62]+0xF8=0x41A4E0
    virtual float maximumSpeed();                           // vt0[63]+0xFC=0x41A4F0
    virtual float rateOfFire();                             // vt0[64]+0x100=0x405D40
    virtual float damageCapability(RGE_Static_Object* param_1); // vt0[65]+0x104=0x405D60
    virtual float damageCapability();                       // vt0[66]+0x108=0x405D50
    virtual float weaponRange();                            // vt0[67]+0x10C=0x405D70
    virtual float minimumWeaponRange();                     // vt0[68]+0x110=0x405D80
    virtual int passableTile(float param_1, float param_2, int param_3); // vt0[69]+0x114=0x41A500
    virtual uchar facetToNextWaypoint();                    // vt0[70]+0x118=0x41A510
    virtual int currentTargetID();                          // vt0[71]+0x11C=0x405D90
    virtual float currentTargetX();                         // vt0[72]+0x120=0x405DA0
    virtual float currentTargetY();                         // vt0[73]+0x124=0x405DB0
    virtual float currentTargetZ();                         // vt0[74]+0x128=0x405DC0
    virtual void setWaitingToMove(uchar param_1);           // vt0[75]+0x12C=0x41A520
    virtual uchar waitingToMove();                          // vt0[76]+0x130=0x41A530
    virtual uchar actionState();                            // vt0[77]+0x134=0x41A540
    virtual uchar keepGatheringWhenObjectIsOut(int param_1); // vt0[78]+0x138=0x405DD0
    virtual uchar produceWhenKilledBy(int param_1);         // vt0[79]+0x13C=0x405DE0
    virtual uchar useSameZoneDropsite();                    // vt0[80]+0x140=0x405DF0
    virtual void logDebug(char* param_1);                   // vt0[81]+0x144=0x4C7340
    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6); // vt0[82]+0x148=0x405E00
    virtual int attack(float param_1, float param_2, float param_3, int param_4); // vt0[83]+0x14C=0x405E20
    virtual int attack(int param_1, int param_2);           // vt0[84]+0x150=0x405E10
    virtual int moveTo(float param_1, float param_2, float param_3, float param_4, int param_5); // vt0[85]+0x154=0x405E50
    virtual int moveTo(int param_1, float param_2, int param_3); // vt0[86]+0x158=0x405E40
    virtual int moveTo(int param_1, int param_2);           // vt0[87]+0x15C=0x405E30
    virtual int moveAwayFrom(int param_1, int param_2);     // vt0[88]+0x160=0x405E60
    virtual int hunt(int param_1, int param_2);             // vt0[89]+0x164=0x405E70
    virtual int gather(int param_1, int param_2);           // vt0[90]+0x168=0x405E80
    virtual int convert(int param_1, int param_2);          // vt0[91]+0x16C=0x405E90
    virtual int repair(int param_1, int param_2);           // vt0[92]+0x170=0x405EB0
    virtual int build(int param_1, int param_2);            // vt0[93]+0x174=0x405EC0
    virtual int trade(int param_1, int param_2);            // vt0[94]+0x178=0x405ED0
    virtual int explore(int param_1, int param_2, int param_3); // vt0[95]+0x17C=0x405EE0
    virtual int enter(int param_1, int param_2);            // vt0[96]+0x180=0x405EF0
    virtual int unload(int param_1, float param_2, float param_3, float param_4); // vt0[97]+0x184=0x405F00
    virtual int transport(float param_1, float param_2, float param_3, int param_4); // vt0[98]+0x188=0x405F10
    virtual int stopAction();                               // vt0[99]+0x18C=0x405F20
    virtual int pause();                                    // vt0[100]+0x190=0x405F30
    virtual int canPath(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6); // vt0[101]+0x194=0x41A560
    virtual int canPath(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7); // vt0[102]+0x198=0x41A550
    virtual int canBidirectionPath(int param_1, int param_2, float param_3, float* param_4, int param_5, int param_6, int param_7); // vt0[103]+0x19C=0x41A570
    virtual int canPathWithObstructions(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6, ManagedArray<int>* param_7); // vt0[104]+0x1A0=0x41A580
    virtual int canPathWithAdditionalPassability(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7, int param_8, int param_9); // vt0[105]+0x1A4=0x41A590
    virtual int findFirstTerrainAlongExceptionPath(int param_1, float* param_2, float* param_3); // vt0[106]+0x1A8=0x41A5A0
    virtual int canLinePath(int param_1, int param_2, int param_3, int param_4, float param_5, int param_6); // vt0[107]+0x1AC=0x41A5C0
    virtual int canLinePath(XYPoint* param_1, XYPoint* param_2, float param_3, XYPoint* param_4, int param_5); // vt0[108]+0x1B0=0x41A5B0
    virtual int firstTileAlongLine(XYPoint* param_1, XYPoint* param_2, XYPoint* param_3, int param_4, int param_5, int param_6); // vt0[109]+0x1B4=0x41A5D0
    virtual XYZBYTEPoint* userDefinedWaypoint(int param_1); // vt0[110]+0x1B8=0x41A5E0
    virtual int addUserDefinedWaypoint(XYZBYTEPoint* param_1, int param_2); // vt0[111]+0x1BC=0x41A5F0
    virtual void removeAllUserDefinedWaypoints(int param_1); // vt0[112]+0x1C0=0x41A600
    virtual void removeUserDefinedWaypoint(int param_1);    // vt0[113]+0x1C4=0x41A610
    virtual int numberUserDefinedWaypoints();               // vt0[114]+0x1C8=0x41A620
    virtual Path* findAvoidancePath(XYZPoint* param_1, float param_2, int param_3); // vt0[115]+0x1CC=0x41A630
    virtual long get_action_checksum();                     // vt0[116]+0x1D0=0x4C7F30
    virtual long get_waypoint_checksum();                   // vt0[117]+0x1D4=0x4C7F40
    virtual int setup(int param_1, RGE_Game_World* param_2); // vt0[118]+0x1D8=0x4C1840
    virtual int setup(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5); // vt0[119]+0x1DC=0x4C16B0
    virtual RGE_Object_List* create_object_list();          // vt0[120]+0x1E0=0x4C1D60
    virtual RGE_Active_Sprite_List* create_sprite_list();   // vt0[121]+0x1E4=0x4C1DC0
    RGE_Static_Object(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    RGE_Static_Object(int param_1, RGE_Game_World* param_2, int param_3);
    ~RGE_Static_Object();
    void change_unique_id();
    void get_starting_attribute();
    void give_attribute_to_owner();
    void take_attribute_from_owner();
    void capture_frame(TDrawArea* param_1, short param_2, short param_3);
    void capture_square_frame(TDrawArea* param_1, short param_2, short param_3);
    void capture_frame_3d_cube(TDrawArea* param_1, short param_2, short param_3);
    void capture_frame_3d_square(TDrawArea* param_1, short param_2, short param_3);
    void draw_frame_3d_square_back(TDrawArea* param_1, short param_2, short param_3);
    void draw_frame_3d_square_front(TDrawArea* param_1, short param_2, short param_3);
    void draw_frame_3d_cube_back(TDrawArea* param_1, short param_2, short param_3);
    void draw_frame_3d_cube_front(TDrawArea* param_1, short param_2, short param_3);
    RGE_Static_Object* get_object_pointer(long param_1);
    RGE_Sprite* get_sprite_pointer(short param_1);
    RGE_Static_Object* check_object_bounds();
    float get_terrain_speed(uchar param_1);
    uchar is_dying();
    int get_frame(short* param_1, short* param_2, short* param_3, short* param_4);
    uchar more_room();
    int inRange(RGE_Static_Object* param_1, float param_2);
    float distance_to_object(RGE_Static_Object* param_1);
    float distance_to_position(float param_1, float param_2, float param_3);
    uchar hit_test(short param_1, short param_2, short param_3, short param_4, short param_5);
    uchar box_hit_test(short param_1, short param_2, short param_3, short param_4, short param_5, short param_6);
    void set_location(float param_1, float param_2, float param_3);
    uchar drop_held_objects(int param_1);
    uchar find_drop_location(int param_1, float* param_2, float* param_3, RGE_Master_Static_Object* param_4, RGE_Static_Object* param_5, float param_6, float param_7, float param_8, float param_9);
    RGE_Check_List* make_object_bounds_list(float param_1);
    int boundToFacet(float param_1, float param_2, int param_3);
    int numberFacets();
    int addToObstructionMap(int param_1);
    int removeFromObstructionMap(int param_1);
    void changeInfluenceMap(InfluenceMap* param_1, int param_2, int param_3, int param_4);
    RGE_Check_List* objectCollisionList(float param_1);
    UnitAIModule* unitAI();
    uchar lookupZone(XYPoint param_1);
    uchar lookupZone(int param_1, int param_2);
    uchar currentZone();
    int withinRangeOfZoneAtPoint(uchar param_1, float param_2, XYPoint* param_3);
    int withinRangeOfZone(uchar param_1, float param_2);
    int findClosestPointInTerrainType(XYPoint param_1, XYPoint* param_2, int param_3, int param_4, int param_5);
    int isGroupCommander();
    int inGroup();
    int unitIsInGroup(int param_1);
    int createGroup(int* param_1, int param_2, int param_3, float param_4);
    int commanderCreateGroup(int* param_1, int param_2, int param_3, float param_4);
    int addToGroup(int param_1, float param_2);
    int commanderAddToGroup(int param_1, float param_2);
    int removeFromGroup(int param_1);
    int commanderRemoveFromGroup(int param_1);
    int destroyGroup();
    int commanderDestroyGroup();
    void addToPathingGroup(int param_1);
    void removeAllFromPathingGroup();
    void remove_shadows();
    void set_sleep_flag(uchar param_1);
};

static_assert(sizeof(RGE_Static_Object) == 0x88, "RGE_Static_Object Size Mismatch");

