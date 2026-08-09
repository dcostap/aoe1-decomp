// VA: 004C1420 RGE_Static_Object::recycle_in_to_game
// Source: stat_obj.cpp lines 336-398
// Attempt log:
// Attempt log:
// - natural typed initialization matched the first 0xFD bytes and all eight
//   calls, leaving only the ignored float result of the +0x34 virtual call;
// - ABI query and the original FPU sequence identified +0x34 as the real
//   float-returning teleport method, so its ignored result naturally emits the
//   required fstp st0 before addObject;
// - replacing owner/world offset casts with the proven RGE_Player::id/world
//   and RGE_Game_World::curr_player fields preserved the exact output;
// - exact 361-byte match; source is typed, period-plausible, and has no asm or
//   compiler-only scaffolding.

class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Object_Node;
class RGE_Sound { public: void play(int); };
class RGE_Game_World {
public:
    char gap_00[0x7C];
    short curr_player;
};

extern int __cdecl debug_rand(char* file, int line);
extern void __cdecl debug_srand(char* file, int line, int seed);
extern int debug_random_on;

class RGE_Player_vtable_pad {
public:
#define PAD(n) virtual void pad##n();
    virtual ~RGE_Player_vtable_pad();
    PAD(1) PAD(2) PAD(3) PAD(4) PAD(5) PAD(6) PAD(7)
    PAD(8) PAD(9) PAD(10) PAD(11) PAD(12) PAD(13) PAD(14) PAD(15)
    PAD(16) PAD(17) PAD(18) PAD(19) PAD(20) PAD(21) PAD(22) PAD(23)
    PAD(24) PAD(25) PAD(26) PAD(27) PAD(28) PAD(29) PAD(30) PAD(31)
    PAD(32) PAD(33) PAD(34) PAD(35) PAD(36) PAD(37) PAD(38) PAD(39)
    PAD(40) PAD(41) PAD(42) PAD(43) PAD(44) PAD(45) PAD(46) PAD(47)
    PAD(48) PAD(49) PAD(50) PAD(51) PAD(52) PAD(53) PAD(54)
#undef PAD
};

class RGE_Player : public RGE_Player_vtable_pad {
public:
    virtual RGE_Object_Node* addObject(RGE_Static_Object* obj, int sleep, int dopple);
    int computerPlayerValue;              // +0x04
    int pathingAttemptCapValue;           // +0x08
    int pathingDelayCapValue;             // +0x0C
    int currentUpdatePathingAttemptsValue;// +0x10
    long checksum;                        // +0x14
    long position_checksum;               // +0x18
    long action_checksum;                 // +0x1C
    unsigned char checksum_created_this_update; // +0x20
    unsigned char gap_21;
    short master_object_num;              // +0x22
    void* master_objects;                 // +0x24
    void* objects;                        // +0x28
    void* sleeping_objects;               // +0x2C
    void* doppleganger_objects;           // +0x30
    void* victory_conditions;             // +0x34
    void* visible;                        // +0x38
    RGE_Game_World* world;                 // +0x3C
    void* doppleganger_creator;           // +0x40
    char* name;                           // +0x44
    unsigned char type;                   // +0x48
    unsigned char gap_49;
    short id;                             // +0x4A
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object(); // +00
    unsigned char master_type;     // +04
    unsigned char gap_05[0x13];
    void* sprite;                  // +18
    unsigned char gap_1C[0x0A];
    short hp;                      // +26
    char gap_28[0x18];
    RGE_Sound* created_sound;      // +40
};

class RGE_Static_Object_vtable_pad {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
};

class RGE_Static_Object : public RGE_Static_Object_vtable_pad {
public:
    virtual float teleport(float x, float y, float z); // +34
    virtual void new_sprite(void* sprite);             // +38

    long id;                         // +04
    RGE_Master_Static_Object* master_obj; // +08
    RGE_Player* owner;               // +0C
    void* sprite;                    // +10
    void* old_sprite;                // +14
    void* sprite_list;               // +18
    void* tile;                      // +1C
    RGE_Static_Object* inside_obj;   // +20
    void* objects;                   // +24
    short screen_x_offset;           // +28
    short screen_y_offset;           // +2A
    short shadow_x_offset;           // +2C
    short shadow_y_offset;           // +2E
    float hp;                        // +30
    unsigned char curr_damage_percent; // +34
    unsigned char facet;             // +35
    unsigned char selected;          // +36
    unsigned char selected_group;    // +37
    float world_x;                   // +38
    float world_y;                   // +3C
    float world_z;                   // +40
    float attribute_amount_held;     // +44
    unsigned char object_state;      // +48
    unsigned char sleep_flag;        // +49
    unsigned char dopple_flag;       // +4A
    unsigned char goto_sleep_flag;   // +4B
    short attribute_type_held;       // +4C
    unsigned char type;              // +4E
    unsigned char worker_num;        // +4F
    RGE_Object_Node* player_object_node; // +50
    char gap_54[0x74 - 0x54];
    void* unitAIValue;               // +74
    int groupCommanderValue;         // +78
    int zoneMapIndex;                // +7C
    float groupRangeValue;           // +80
    unsigned char inObstructionMapValue; // +84
    unsigned char lastInObstructionMapValue; // +85
    unsigned char underAttackValue;  // +86

    void get_starting_attribute();
    void give_attribute_to_owner();
    void recycle_in_to_game(RGE_Master_Static_Object* master, RGE_Player* player, float x, float y, float z);
};

void RGE_Static_Object::recycle_in_to_game(RGE_Master_Static_Object* master, RGE_Player* player, float x, float y, float z)
{
    this->old_sprite = 0;
    this->unitAIValue = 0;
    this->underAttackValue = 0;
    this->sprite = 0;
    this->groupCommanderValue = -1;
    this->groupRangeValue = 5.0f;
    this->owner = player;
    this->master_obj = master;
    this->tile = 0;
    this->inside_obj = 0;

    this->hp = (float)(int)master->hp;
    this->sleep_flag = (this->hp > 0.0f);
    this->dopple_flag = (master->master_type == 0x19);

    this->facet = 0;
    this->world_x = -999.0f;
    this->world_y = -999.0f;
    this->world_z = 0.0f;
    this->screen_x_offset = 0;
    this->screen_y_offset = 0;
    this->shadow_x_offset = 0;
    this->shadow_y_offset = 0;
    this->selected = 0;
    this->selected_group = 0;
    this->worker_num = 0;
    this->object_state = 2;
    this->curr_damage_percent = 0;
    this->goto_sleep_flag = 0;
    this->player_object_node = 0;

    this->get_starting_attribute();
    this->give_attribute_to_owner();

    this->new_sprite(this->master_obj->sprite);
    this->world_x = x;
    this->world_y = y;
    this->world_z = z;
    this->old_sprite = 0;
    this->teleport(x, y, z);

    this->player_object_node = this->owner->addObject(this, this->sleep_flag, this->dopple_flag);

    int seed = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0x183);
    int old_debug = debug_random_on;
    debug_random_on = 0;

    RGE_Sound* sound = this->master_obj->created_sound;
    if (sound != 0 && this->owner->id == this->owner->world->curr_player) {
        sound->play(1);
    }

    debug_random_on = old_debug;
    debug_srand((char*)"C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0x18D, seed);
}
