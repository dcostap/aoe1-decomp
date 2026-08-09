// VA: 004C4C50 | RGE_Static_Object::change_ownership | stat_obj.cpp:2406-2447
//
// Attempt log:
// baseline: natural typed ownership transfer reconstructed from the original
// call order, the proven RGE_Static_Object/RGE_Master_Static_Object layouts,
// and the executable's virtual slots.
// behavior: the replacement sprite falls back to the new master's default
// sprite when the old sprite is neither the default, death, nor undead sprite.
// liveness: a named new-node temporary preserves the observed old-master load
// before the player-node store; VC5 still chooses a different volatile color.
// probes: declaration order, separate old-sprite, comma sequencing, and
// register hints were unchanged or less plausible; the remaining drift is the
// localized old-master/sprite register coloring and its branch-span fallout.
// Main-agent audit restored canonical master/player/static-object destructor
// slots in place of raw vptr/slot-zero placeholders; emitted code is unchanged.
// fresh worker: direct this->master_obj lookup before naming old_master widened
// to 136B/45.2%; restored canonical old-master local.
// fresh worker: distinct old_sprite declared after old_master preserved 301B/134
// basin; restored existing clean source.

class RGE_Sprite;
class RGE_Active_Sprite_List;
class RGE_Tile;
class RGE_Object_List;
class RGE_Object_Node;
class RGE_Static_Object;
class RGE_Master_Static_Object;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;
    unsigned char gap_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    unsigned char gap_16[2];
    RGE_Sprite* sprite;
    RGE_Sprite* death_sprite;
    RGE_Sprite* undead_sprite;
    unsigned char undead_flag;
    unsigned char gap_25[1];
    short hp;
};

class RGE_Player {
public:
#define PLAYER_PAD(n) virtual void player_pad##n();
    virtual ~RGE_Player();
    PLAYER_PAD(1)  PLAYER_PAD(2)  PLAYER_PAD(3)
    PLAYER_PAD(4)  PLAYER_PAD(5)  PLAYER_PAD(6)  PLAYER_PAD(7)
    PLAYER_PAD(8)  PLAYER_PAD(9)  PLAYER_PAD(10) PLAYER_PAD(11)
    PLAYER_PAD(12) PLAYER_PAD(13) PLAYER_PAD(14) PLAYER_PAD(15)
    PLAYER_PAD(16) PLAYER_PAD(17) PLAYER_PAD(18) PLAYER_PAD(19)
    PLAYER_PAD(20) PLAYER_PAD(21) PLAYER_PAD(22) PLAYER_PAD(23)
    PLAYER_PAD(24) PLAYER_PAD(25) PLAYER_PAD(26) PLAYER_PAD(27)
    PLAYER_PAD(28) PLAYER_PAD(29) PLAYER_PAD(30) PLAYER_PAD(31)
    PLAYER_PAD(32) PLAYER_PAD(33) PLAYER_PAD(34) PLAYER_PAD(35)
    PLAYER_PAD(36) PLAYER_PAD(37) PLAYER_PAD(38) PLAYER_PAD(39)
    PLAYER_PAD(40) PLAYER_PAD(41) PLAYER_PAD(42) PLAYER_PAD(43)
    PLAYER_PAD(44) PLAYER_PAD(45) PLAYER_PAD(46) PLAYER_PAD(47)
    PLAYER_PAD(48) PLAYER_PAD(49) PLAYER_PAD(50) PLAYER_PAD(51)
    PLAYER_PAD(52) PLAYER_PAD(53) PLAYER_PAD(54)
    virtual RGE_Object_Node* add_object(RGE_Static_Object*, int, int);
    virtual void remove_object(RGE_Static_Object*, int, int, RGE_Object_Node*);

    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;
    unsigned char gap_21[1];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    void* victory_conditions;
    void* visible;
    void* world;
    void* doppleganger_creator;
    char* name;
    unsigned char type;
    unsigned char gap_49[1];
    short id;

    void unselect_one_object(RGE_Static_Object*);
};

class RGE_Static_Object {
public:
#define STATIC_PAD(n) virtual void static_pad##n();
    virtual ~RGE_Static_Object();
    STATIC_PAD(1)  STATIC_PAD(2)  STATIC_PAD(3)
    STATIC_PAD(4)  STATIC_PAD(5)  STATIC_PAD(6)  STATIC_PAD(7)
    STATIC_PAD(8)  STATIC_PAD(9)  STATIC_PAD(10) STATIC_PAD(11)
    STATIC_PAD(12) STATIC_PAD(13)
    virtual void new_sprite(RGE_Sprite*);
    STATIC_PAD(15) STATIC_PAD(16) STATIC_PAD(17) STATIC_PAD(18)
    STATIC_PAD(19) STATIC_PAD(20) STATIC_PAD(21) STATIC_PAD(22)
    STATIC_PAD(23) STATIC_PAD(24) STATIC_PAD(25) STATIC_PAD(26)
    STATIC_PAD(27) STATIC_PAD(28) STATIC_PAD(29) STATIC_PAD(30)
    STATIC_PAD(31) STATIC_PAD(32) STATIC_PAD(33) STATIC_PAD(34)
    STATIC_PAD(35) STATIC_PAD(36) STATIC_PAD(37) STATIC_PAD(38)
    STATIC_PAD(39) STATIC_PAD(40) STATIC_PAD(41) STATIC_PAD(42)
    STATIC_PAD(43) STATIC_PAD(44) STATIC_PAD(45) STATIC_PAD(46)
    STATIC_PAD(47) STATIC_PAD(48) STATIC_PAD(49) STATIC_PAD(50)
    STATIC_PAD(51) STATIC_PAD(52) STATIC_PAD(53)
    virtual void add_terrain(RGE_Player*, int, int);
    virtual void remove_terrain(RGE_Player*, int, int);
    virtual void add_object(RGE_Player*, int, int);
    STATIC_PAD(57) STATIC_PAD(58) STATIC_PAD(59) STATIC_PAD(60)
    STATIC_PAD(61) STATIC_PAD(62) STATIC_PAD(63) STATIC_PAD(64)
    STATIC_PAD(65) STATIC_PAD(66) STATIC_PAD(67) STATIC_PAD(68)
    STATIC_PAD(69) STATIC_PAD(70) STATIC_PAD(71) STATIC_PAD(72)
    STATIC_PAD(73) STATIC_PAD(74) STATIC_PAD(75) STATIC_PAD(76)
    STATIC_PAD(77) STATIC_PAD(78) STATIC_PAD(79) STATIC_PAD(80)
    STATIC_PAD(81)
    virtual void dispatch_148(int, int, int, int, int, int);

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    RGE_Tile* tile;
    RGE_Static_Object* inside_obj;
    RGE_Object_List* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
    RGE_Object_Node* player_object_node;

    void take_attribute_from_owner();
    void give_attribute_to_owner();
    void change_ownership(RGE_Player* player);
};

void RGE_Static_Object::change_ownership(RGE_Player* player)
{
    if (player->master_objects[this->master_obj->id] == 0) {
        return;
    }

    if ((this->selected & 1) != 0) {
        this->owner->unselect_one_object(this);
    }

    float hp_num = this->hp / (float)(int)this->master_obj->hp;
    this->take_attribute_from_owner();

    if (this->object_state == 2) {
        this->remove_terrain(this->owner, 0, -1);
    }

    this->owner->remove_object(this, this->sleep_flag, this->dopple_flag,
                               this->player_object_node);
    RGE_Object_Node* new_node =
        player->add_object(this, this->sleep_flag, this->dopple_flag);

    RGE_Master_Static_Object* old_master = this->master_obj;
    this->player_object_node = new_node;
    RGE_Master_Static_Object* new_master =
        player->master_objects[old_master->id];
    RGE_Sprite* new_sprite = this->sprite;
    if (new_sprite != old_master->sprite) {
        if (new_sprite == old_master->death_sprite) {
            new_sprite = new_master->death_sprite;
        } else if (new_sprite == old_master->undead_sprite) {
            new_sprite = new_master->undead_sprite;
        } else {
            new_sprite = new_master->sprite;
        }
    } else {
        new_sprite = new_master->sprite;
    }

    if (new_sprite != 0) {
        this->new_sprite(new_sprite);
    }

    this->owner = player;
    this->master_obj = new_master;
    this->hp = (float)(int)new_master->hp * hp_num;

    if (this->object_state == 2) {
        this->add_terrain(player, 0, -1);
    }

    this->give_attribute_to_owner();
    this->dispatch_148(this->id, this->id, 0x20B, (int)player->id, 0, 0);
}
