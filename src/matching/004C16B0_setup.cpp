// VA: 004C16B0 RGE_Static_Object::setup
// Source: stat_obj.cpp lines 484-567
// Attempt log:
// 1: initial implementation from packet, shaped to original store/call order; wrong first param load/store and create-list vtable offset.
// 2: correct vtable padding to put create_object_list/create_sprite_list at +1E0/+1E4 and store owner before master.
// 3: source order master/type/owner made first param load wrong again; explicit p/m temps no change.
// 4: dead first owner assignment probe no change.
// 5: return to owner/type/master best early load family.
// 6: owner/master/type order probe no codegen change.
// 7: reorder world_y/world_z stores worsened set_position block.
// 8: restore z-before-y best shape.
// 9: local z temp before world/position call; no codegen change.
// 10: /Ot flag probe no change; removed flag.
// Follow-up: the +0x34 virtual is the proven float-returning teleport ABI; an
// ignored result supplies the original fstp st0.  Keeping the position stores
// in source order x/y/z restores VC5's original register schedule.
// Follow-up: source initialization order type/owner/master restores the
// original type-before-owner store while retaining the expected parameter
// preload.  Exact 398-byte match; typed period-plausible source, no asm/hack.

class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Object_Node;
class RGE_Object_List;
class RGE_Active_Sprite_List;
class RGE_Sound { public: void play(int); };

extern int __cdecl debug_rand(char* file, int line);
extern void __cdecl debug_srand(char* file, int line, int seed);
extern int debug_random_on;

class RGE_Game_World {
public:
    char gap_00[0x7C];
    short curr_player;
    long get_next_object_id();
    long get_next_reusable_object_id();
};

class RGE_Player_vtable_pad {
public:
#define PAD(n) virtual void pad##n();
    virtual ~RGE_Player_vtable_pad();
    PAD(01) PAD(02) PAD(03) PAD(04) PAD(05) PAD(06) PAD(07)
    PAD(08) PAD(09) PAD(10) PAD(11) PAD(12) PAD(13) PAD(14) PAD(15)
    PAD(16) PAD(17) PAD(18) PAD(19) PAD(20) PAD(21) PAD(22) PAD(23)
    PAD(24) PAD(25) PAD(26) PAD(27) PAD(28) PAD(29) PAD(30) PAD(31)
    PAD(32) PAD(33) PAD(34) PAD(35) PAD(36) PAD(37) PAD(38) PAD(39)
    PAD(40) PAD(41) PAD(42) PAD(43) PAD(44) PAD(45) PAD(46) PAD(47)
    PAD(48) PAD(49) PAD(50) PAD(51) PAD(52) PAD(53) PAD(54)
#undef PAD
};

class RGE_Player : public RGE_Player_vtable_pad {
public:
    virtual RGE_Object_Node* addObject(RGE_Static_Object* obj, int sleep, int dopple); // +DC
    char gap_04[0x3C - 0x04];
    RGE_Game_World* world;
    RGE_Sound* created_sound; // +40 per setup use
    char gap_44[0x4A - 0x44];
    short id;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;
    char gap_05[0x13];
    void* sprite;
    char gap_1C[0x0A];
    short hp;
    char gap_28[0x18];
    RGE_Sound* created_sound;
    char gap_44[0xA4 - 0x44];
    unsigned char recyclable;
};

class RGE_Static_Object_vtable_pad {
public:
#define VPAD(n) virtual void v##n();
    VPAD(00) VPAD(04) VPAD(08) VPAD(0C) VPAD(10) VPAD(14) VPAD(18) VPAD(1C)
    VPAD(20) VPAD(24) VPAD(28) VPAD(2C) VPAD(30)
#undef VPAD
};

class RGE_Static_Object : public RGE_Static_Object_vtable_pad {
public:
    virtual float teleport(float x, float y, float z);    // +34
    virtual void new_sprite(void* sprite);                // +38
#define VPAD2(n) virtual void v##n();
    VPAD2(000) VPAD2(001) VPAD2(002) VPAD2(003) VPAD2(004) VPAD2(005) VPAD2(006) VPAD2(007)
    VPAD2(008) VPAD2(009) VPAD2(010) VPAD2(011) VPAD2(012) VPAD2(013) VPAD2(014) VPAD2(015)
    VPAD2(016) VPAD2(017) VPAD2(018) VPAD2(019) VPAD2(020) VPAD2(021) VPAD2(022) VPAD2(023)
    VPAD2(024) VPAD2(025) VPAD2(026) VPAD2(027) VPAD2(028) VPAD2(029) VPAD2(030) VPAD2(031)
    VPAD2(032) VPAD2(033) VPAD2(034) VPAD2(035) VPAD2(036) VPAD2(037) VPAD2(038) VPAD2(039)
    VPAD2(040) VPAD2(041) VPAD2(042) VPAD2(043) VPAD2(044) VPAD2(045) VPAD2(046) VPAD2(047)
    VPAD2(048) VPAD2(049) VPAD2(050) VPAD2(051) VPAD2(052) VPAD2(053) VPAD2(054) VPAD2(055)
    VPAD2(056) VPAD2(057) VPAD2(058) VPAD2(059) VPAD2(060) VPAD2(061) VPAD2(062) VPAD2(063)
    VPAD2(064) VPAD2(065) VPAD2(066) VPAD2(067) VPAD2(068) VPAD2(069) VPAD2(070) VPAD2(071)
    VPAD2(072) VPAD2(073) VPAD2(074) VPAD2(075) VPAD2(076) VPAD2(077) VPAD2(078) VPAD2(079)
    VPAD2(080) VPAD2(081) VPAD2(082) VPAD2(083) VPAD2(084) VPAD2(085) VPAD2(086) VPAD2(087)
    VPAD2(088) VPAD2(089) VPAD2(090) VPAD2(091) VPAD2(092) VPAD2(093) VPAD2(094) VPAD2(095)
    VPAD2(096) VPAD2(097) VPAD2(098) VPAD2(099) VPAD2(100) VPAD2(101) VPAD2(102) VPAD2(103)
    VPAD2(104)
#undef VPAD2
    virtual RGE_Object_List* create_object_list();        // +1E0
    virtual RGE_Active_Sprite_List* create_sprite_list(); // +1E4

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    void* sprite;
    void* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    void* tile;
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

    void get_starting_attribute();
    void give_attribute_to_owner();
    int setup(RGE_Master_Static_Object* master, RGE_Player* player, float x, float y, float z);
};

int RGE_Static_Object::setup(RGE_Master_Static_Object* master, RGE_Player* player, float x, float y, float z)
{
    int old_debug;
    int seed;
    this->type = 10;
    this->owner = player;
    this->master_obj = master;
    this->tile = 0;
    this->inside_obj = 0;
    this->objects = this->create_object_list();

    this->hp = (float)(int)this->master_obj->hp;
    this->sleep_flag = (this->hp > 0.0f);
    this->dopple_flag = (this->master_obj->master_type == 0x19);

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
    this->get_starting_attribute();
    this->give_attribute_to_owner();

    if (this->master_obj->recyclable != 0) {
        this->id = this->owner->world->get_next_reusable_object_id();
    } else {
        this->id = this->owner->world->get_next_object_id();
    }
    this->sprite_list = this->create_sprite_list();
    this->new_sprite(this->master_obj->sprite);

    this->world_x = x;
    this->world_y = y;
    this->world_z = z;
    this->old_sprite = 0;
    this->teleport(x, y, z);

    this->player_object_node = this->owner->addObject(this, this->sleep_flag, this->dopple_flag);

    seed = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0x22A);
    old_debug = debug_random_on;
    debug_random_on = 0;
    if (this->master_obj->created_sound != 0 && this->owner->id == this->owner->world->curr_player) {
        this->master_obj->created_sound->play(1);
    }
    debug_random_on = old_debug;
    debug_srand((char*)"C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0x235, seed);
    return 1;
}
