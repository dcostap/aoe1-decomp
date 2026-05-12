// VA: 004C1420 RGE_Static_Object::recycle_in_to_game
// Source: stat_obj.cpp lines 336-398
// Attempt log:
// initial natural implementation from packet with local class/vtable surfaces.
// using this->master_obj for later sprite/sound reloads (not the parameter) fixed early EBp/master preservation; first 0xFD bytes now exact.
// corrected master layout so set_sprite uses sprite at +0x18 and created_sound remains +0x40.
// tried named hp_value local and assignment-in-condition forms for hp/sleep_flag: worsened first mismatch to the FPU compare area; rolled back.
// tried double compare and volatile hp store: no improvement/worse early compare; rolled back.
// tried dummy hp local before addObject: optimized away, no change.
// best remaining mismatch: rebuilt omits original `fstp st0` immediately before owner->addObject vcall; this shifts debug_rand/tail by 2 bytes.
// left in scratch because the missing FPU-stack pop is not a safe accepted-drift candidate without deeper review.

class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Object_Node;
class RGE_Sound { public: void play(int); };

extern int __cdecl debug_rand(char* file, int line);
extern void __cdecl debug_srand(char* file, int line, int seed);
extern int debug_random_on;

class RGE_Player_vtable_pad {
public:
#define PAD(n) virtual void pad##n();
    PAD(0) PAD(1) PAD(2) PAD(3) PAD(4) PAD(5) PAD(6) PAD(7)
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
    char gap_00[0x3C];
    void* world; // +0x3C
};

class RGE_Master_Static_Object {
public:
    void* vtable_ptr;              // +00
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
    virtual void set_position(float x, float y, float z); // +34
    virtual void set_sprite(void* sprite);                // +38

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

    this->set_sprite(this->master_obj->sprite);
    this->world_x = x;
    this->world_y = y;
    this->world_z = z;
    this->old_sprite = 0;
    this->set_position(x, y, z);

    this->player_object_node = this->owner->addObject(this, this->sleep_flag, this->dopple_flag);

    int seed = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0x183);
    int old_debug = debug_random_on;
    debug_random_on = 0;

    RGE_Sound* sound = this->master_obj->created_sound;
    if (sound != 0 && *(short*)((char*)this->owner + 0x4A) == *(short*)(*(char**)((char*)this->owner + 0x3C) + 0x7C)) {
        sound->play(1);
    }

    debug_random_on = old_debug;
    debug_srand((char*)"C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0x18D, seed);
}
