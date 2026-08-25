// 004DFD60 TribeInformationAIModule::findObjectMemoryLimits
// Attempt log:
// - Baseline: the prior source had the right call set but a 0x44 frame and broad
//   mismatch from blanket ObjectMemory initialization.
// - Reconstructed canonical 0x24-byte ObjectMemory ownership, the same-TU
//   polymorphic md/Tribe surfaces, direct byte-offset scan, typed visible-map
//   access, and the nested weapon-range/zone check.  Frame became 0x3c and the
//   best diagnostic build reached 734 bytes, 224 instructions, and 83.93% shape.
// - Binary ABI correction: vslot +0x10c is the no-argument weaponRange(), not a
//   point-taking helper; this removed the extra pre-call push and aligned the
//   range-check block.
// - The oracle retains a localized result-initialization/return-slot packing
//   hunk and a later field/induction schedule gap.  A raw aggregate-zero alias
//   reproduced one prologue store diagnostically (510-byte diff) but is not kept
//   in the living source because it is compiler-steering rather than canonical
//   source.  The prior worker paused after the ten-hypothesis budget.
// - Rechecked the first result hunk: the returned max-distance field is also
//   initialized to zero before the scan.
// - This pass removed unused type/group result initialization, restored direct
//   coordinate-expression order, and named signed group temporaries. It then
//   reversed equivalent max comparisons to recover the original compare and
//   x87 block shapes.
// - The byte-cursor exact candidate was not promoted. The living source keeps
//   named ObjectMemory ownership. It needs a later typed codegen pass.
// - This pass tested loop form, local order, typed point ownership, pointer
//   lifetime, and reviewed object ABI surfaces. Most variants stayed in one
//   basin. A typed moving entry pointer improved shape but did not match.
// - The exact natural form removes the entry alias and repeats typed
//   importantObjectMemory[i].field expressions. It also uses reviewed
//   RGE_Static_Object, RGE_Player, and XYPoint ownership. Check: MATCH,
//   731/731 bytes, 224/224 instructions, 0.0000%.

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
typedef unsigned char uchar;

struct XYPoint {
    int x;
    int y;
};

struct ObjectMemory {
    int id;              // +00 also used as max distance result in return struct
    short type;          // +04
    short group;         // +06
    uchar x;             // +08
    uchar y;             // +09
    uchar z;             // +0A
    uchar owner;         // +0B
    short hitPoints;     // +0C
    short pad0e;         // +0E
    int attackAttempts;  // +10
    uchar kills;         // +14
    char pad15[3];
    float damageCapability; // +18
    float rateOfFire;       // +1C
    float range;            // +20
};

struct RGE_Static_Object;
struct RGE_Visible_Map { uchar get_visible(int x, int y); };
struct TDrawArea;
struct RGE_Color_Table;
struct RGE_Master_Static_Object;
struct RGE_Armor_Weapon_Info;
struct RGE_Action_Object;
struct LOSTBL;
struct RGE_Sprite;
struct RGE_Active_Sprite_List;
struct RGE_Tile;
struct RGE_Object_List;
struct RGE_Object_Node;
struct RGE_Player {
    virtual ~RGE_Player();
    char gap_04[0x34];
    RGE_Visible_Map* visible;
};
struct MainDecisionAIModule {
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;
    RGE_Static_Object* object(int id);
};

struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, uchar);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual uchar update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, uchar);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(uchar);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object* = 0);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object* = 0);
    virtual void rotate(long);
    virtual uchar can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, uchar, uchar);
    virtual int heal(int, int);
    virtual uchar heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, uchar);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop();
    virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(RGE_Action_Object*, short, uchar);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual uchar is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, uchar, int);
    virtual void unexplore_terrain(RGE_Player*, uchar, int);
    virtual LOSTBL* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual uchar underAttack();
    virtual void setUnderAttack(uchar);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability();
    virtual float weaponRange();
    long id; // +04
    RGE_Master_Static_Object* master_obj; // +08
    RGE_Player* owner; // +0c
    RGE_Sprite* sprite; // +10
    RGE_Sprite* old_sprite; // +14
    RGE_Active_Sprite_List* sprite_list; // +18
    RGE_Tile* tile; // +1c
    RGE_Static_Object* inside_obj; // +20
    RGE_Object_List* objects; // +24
    short screen_x_offset; // +28
    short screen_y_offset; // +2a
    short shadow_x_offset; // +2c
    short shadow_y_offset; // +2e
    float hp; // +30
    uchar curr_damage_percent; // +34
    uchar facet; // +35
    uchar selected; // +36
    uchar selected_group; // +37
    float world_x; // +38
    float world_y; // +3c
    float world_z; // +40
    float attribute_amount_held; // +44
    uchar object_state; // +48
    uchar currentZone();
    int withinRangeOfZoneAtPoint(uchar zone, float dist, XYPoint* pt);
    float distance_to_position(float x, float y, float z);
};

#ifndef TAIINFMD_PREFIX_CONTEXT
struct TribeInformationAIModule {
    virtual ~TribeInformationAIModule();
    char pad004[0xFC];
    MainDecisionAIModule* md;
    char pad104[0x0c];
    int maxImportantObjectMemory;
    ObjectMemory* importantObjectMemory;
    ObjectMemory findObjectMemoryLimits(int owner, int object_id, int& a, int& b);
};
#endif
#endif

#endif
ObjectMemory TribeInformationAIModule::findObjectMemoryLimits(int owner, int object_id, int& c1, int& c2)
{
    ObjectMemory rVal;
    RGE_Static_Object* target;
    RGE_Static_Object* obj;
    int i;
    uchar zone;
    XYPoint pt;
    int dx;
    int dy;
    int group;
    float dist;

    c1 = 0;
    c2 = 0;
    rVal.id = 0;
    rVal.hitPoints = 0;
    rVal.attackAttempts = 0;
    rVal.kills = 0;
    rVal.damageCapability = 0.0f;
    rVal.rateOfFire = 0.0f;
    rVal.range = 0.0f;

    target = this->md->object(object_id);
    if (target != 0) {
        zone = target->currentZone();
        i = 0;
        if (this->maxImportantObjectMemory > 0) {
            do {
                if ((int)this->importantObjectMemory[i].owner == owner) {
                    obj = this->md->object(this->importantObjectMemory[i].id);
                    if (obj != 0) {
                        if (zone != obj->currentZone()) {
                            pt.x = (int)obj->world_x;
                            pt.y = (int)obj->world_y;
                            if (target->withinRangeOfZoneAtPoint(
                                    zone, target->weaponRange(), &pt) != 1)
                                goto next;
                        }
                        obj = this->md->object(this->importantObjectMemory[i].id);
                        if (obj != 0) {
                            dx = (int)this->importantObjectMemory[i].x - (int)obj->world_x;
                            if (dx < 0) dx = -dx;
                            dy = (int)this->importantObjectMemory[i].y - (int)obj->world_y;
                            if (dy < 0) dy = -dy;
                            if ((dx > 5 || dy > 5) &&
                                this->md->player->visible->get_visible(
                                    (int)obj->world_x, (int)obj->world_y) != 0x0F)
                                goto skip_visible;
                            group = this->importantObjectMemory[i].group;
                            if (group != 3 && group != 0x1B)
                                c1++;
                            group = this->importantObjectMemory[i].group;
                            if (group != 2 &&
                                group != 0x15 &&
                                group != 0x16 &&
                                group != 0x14 &&
                                this->importantObjectMemory[i].type != 0x2D)
                                c2++;
                            dist = target->distance_to_position(
                                (float)this->importantObjectMemory[i].x,
                                (float)this->importantObjectMemory[i].y,
                                (float)this->importantObjectMemory[i].z);
                            if (dist > (float)rVal.id) rVal.id = (int)dist;
                            if (this->importantObjectMemory[i].hitPoints > rVal.hitPoints)
                                rVal.hitPoints = this->importantObjectMemory[i].hitPoints;
                            if (this->importantObjectMemory[i].attackAttempts > 0)
                                rVal.hitPoints =
                                    (short)this->importantObjectMemory[i].attackAttempts;
                            if (this->importantObjectMemory[i].kills > 0)
                                rVal.hitPoints =
                                    (unsigned short)this->importantObjectMemory[i].kills;
                            if (this->importantObjectMemory[i].damageCapability > rVal.damageCapability)
                                rVal.damageCapability = this->importantObjectMemory[i].damageCapability;
                            if (this->importantObjectMemory[i].rateOfFire > rVal.rateOfFire)
                                rVal.rateOfFire = this->importantObjectMemory[i].rateOfFire;
                            if (this->importantObjectMemory[i].range > rVal.range)
                                rVal.range = this->importantObjectMemory[i].range;
                        }
                    }
                }
skip_visible:
next:
                i++;
            } while (i < this->maxImportantObjectMemory);
        }
    }
    return rVal;
}
