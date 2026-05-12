// VA: 004418A0 RGE_Doppleganger_Object::RGE_Doppleganger_Object
// Source: dpl_obj.cpp lines 52-115
// Attempt log:
// 1: initial natural constructor with /GX, shared layout from nearby doppleganger constructor.
// FLAGS: config/flags/004418A0_RGE_Doppleganger_Object.rsp

class RGE_Master_Doppleganger_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Static_Object;
class RGE_Active_Sprite_Node;

class RGE_Color_Table { public: char gap_00[0x25]; unsigned char map_color; };
class RGE_Active_Sprite_List { public: RGE_Active_Sprite_Node* copy_sprite_list(); void use_sprite_list(RGE_Active_Sprite_Node* node); };

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x04];
    RGE_Master_Static_Object* master_obj; // +08
    RGE_Player* owner;                    // +0C
    void* sprite;                         // +10
    char gap_14[4];
    RGE_Active_Sprite_List* sprite_list;  // +18
    char gap_1C[0x35 - 0x1C];
    unsigned char facet;                  // +35
    char gap_36[0x48 - 0x36];
    unsigned char object_state;           // +48
    char gap_49[0x8C - 0x49];
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x8E];
    unsigned char map_draw_level; // +8E
    char gap_8F[1];
    unsigned char map_color;      // +90
};

class RGE_Player {
public:
    char gap_00[0x4A];
    short id;                     // +4A
    char gap_4C[0x108 - 0x4C];
    RGE_Color_Table* color_table; // +108
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    RGE_Animated_Object(RGE_Master_Doppleganger_Object* master, RGE_Player* player, float x, float y, float z, int doSetup);
};

class RGE_Doppleganger_Object : public RGE_Animated_Object {
public:
    RGE_Doppleganger_Object(RGE_Master_Doppleganger_Object* master, RGE_Player* player, float x, float y, float z, int doSetup, RGE_Static_Object* doppled);
    int setup(RGE_Master_Doppleganger_Object* master, RGE_Player* player, float x, float y, float z);
    void destroy_obj();
    void validate();

    RGE_Static_Object* doppled_object;      // +8C
    RGE_Color_Table* draw_color;            // +90
    RGE_Master_Static_Object* doppled_master_obj; // +94
    int doppled_player;                     // +98
    unsigned long* MapAddress;              // +9C
    int LastMapValue;                       // +A0
    int CantSeeBits;                        // +A4
    unsigned char map_draw_level;           // +A8
    unsigned char map_color;                // +A9
    char gap_AA[2];
    int doppledObjectID;                    // +AC
};

RGE_Doppleganger_Object::RGE_Doppleganger_Object(RGE_Master_Doppleganger_Object* master, RGE_Player* player, float x, float y, float z, int doSetup, RGE_Static_Object* doppled)
    : RGE_Animated_Object(master, player, x, y, z, 0)
{
    *(void**)this = (void*)0x00570220;
    this->doppled_object = 0;
    this->draw_color = 0;
    this->doppled_master_obj = 0;
    this->doppled_player = 0;
    this->MapAddress = 0;
    this->LastMapValue = 0;
    this->CantSeeBits = 0;
    this->map_draw_level = 0;
    this->map_color = 0;
    this->doppledObjectID = -1;

    if (doSetup != 0) {
        this->setup(master, player, x, y, z);
    }

    this->doppled_object = doppled;
    if (doppled != 0) {
        this->doppled_master_obj = doppled->master_obj;
        this->doppled_player = doppled->owner->id;
        this->doppledObjectID = *(int*)((char*)doppled + 4);
        this->sprite = doppled->sprite;
        this->sprite->copy_sprite_list();
        this->sprite_list->use_sprite_list(doppled->sprite_list->copy_sprite_list());
        this->facet = doppled->facet;
        this->draw_color = doppled->owner->color_table;
        this->map_draw_level = doppled->master_obj->map_draw_level;
        if (this->map_draw_level == 3) {
            this->map_color = doppled->master_obj->map_color;
        } else {
            this->map_color = doppled->owner->color_table->map_color;
        }
        if (doppled->object_state >= 7) {
            this->doppled_object = 0;
            this->doppledObjectID = -1;
        }
    } else {
        this->doppledObjectID = -1;
        this->doppled_master_obj = 0;
        this->doppled_player = 0;
        this->destroy_obj();
    }
    this->validate();
}
