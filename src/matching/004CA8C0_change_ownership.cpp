// VA: 004CA8C0 TRIBE_Combat_Object::change_ownership
// PDB source: t_c_obj.cpp lines 368-424
//
// Attempt log:
// - baseline: canonical combat-object ownership with the nine visible-unit
//   records, old-owner removal/new-owner insertion, master cloning, and the
//   natural typed virtual notification calls.

class RGE_Static_Object;
class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Object_Node;
class RGE_World;

struct VISIBLE_UNIT_REC {
    int object_id;
    unsigned char distance;
    unsigned char player;
    unsigned char pos_x;
    unsigned char pos_y;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player,
                                             float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();

    char gap_04[0x0C];
    short id;
    short copy_id;
    short object_group;
};

class RGE_Object_Node {
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual RGE_Object_Node* addObject(RGE_Static_Object* object,
                                       int sleep, int dopple);
    virtual void removeObject(RGE_Static_Object* object,
                              int sleep, int dopple, RGE_Object_Node* node);

    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
    char gap_28[0x14];
    RGE_World* world;
    char gap_40[0x0A];
    short id;

    void unselect_one_object(RGE_Static_Object* object);
};

class RGE_World {
public:
    virtual unsigned char data_load_world(void* file);
    unsigned long world_time;
};

class UnitAIModule {
public:
    void purgeNotifyQueue(unsigned long time);
};

class RGE_Action_Object {
public:
    void change_ownership(RGE_Player* player);
};

class RGE_Static_Object {
public:
    void take_attribute_from_owner();
    void give_attribute_to_owner();
};

class RGE_Combat_Object {
public:
    virtual ~RGE_Combat_Object();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void change_ownership(RGE_Player* player);
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual int explore_terrain(RGE_Player* player, unsigned char flag, int value);
    virtual void unexplore_terrain(RGE_Player* player, unsigned char flag, int value);
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual void vfF0();
    virtual void vfF4();
    virtual void vfF8();
    virtual void vfFC();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10C();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11C();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12C();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13C();
    virtual void vf140();
    virtual void vf144();
    virtual void notify(int first, int second, int third,
                        long fourth, long fifth, long sixth);
    virtual void vf14C();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15C();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16C();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17C();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18C();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19C();
    virtual void vf1A0();
    virtual void vf1A4();
    virtual void vf1A8();
    virtual void vf1AC();
    virtual void vf1B0();
    virtual void vf1B4();
    virtual void vf1B8();
    virtual void vf1BC();
    virtual void vf1C0();
    virtual void vf1C4();
    virtual void vf1C8();
    virtual void vf1CC();
    virtual void vf1D0();
    virtual void vf1D4();
    virtual void vf1D8();
    virtual void vf1DC();
    virtual void vf1E0();
    virtual void vf1E4();
    virtual void vf1E8();
    virtual void vf1EC();
    virtual void vf1F0();
    virtual void vf1F4();
    virtual void vf1F8();
    virtual void vf1FC();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x26];
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
    char gap_54[0x20];
    UnitAIModule* unitAIValue;
    char gap_78[0x11C];
    VISIBLE_UNIT_REC* VUR_Ptrs[9];
    unsigned long Unified_Map_Value;
    float attack_timer;
    unsigned char capture_flag;
    char gap_1C1[3];
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    unsigned char own_master;

    void change_ownership(RGE_Player* player);
};

void TRIBE_Combat_Object::change_ownership(RGE_Player* player)
{
    if (this->id >= 0) {
        for (int i = 0; i < 9; ++i) {
            if (this->VUR_Ptrs[i] != 0) {
                this->VUR_Ptrs[i]->player = (unsigned char)player->id;
            }
        }
    }

    if (this->master_obj->object_group == 1) {
        ((RGE_Action_Object*)this)->change_ownership(player);
        return;
    }

    if (player->master_objects[this->master_obj->id] != 0) {
        if ((this->selected & 1) != 0) {
            this->owner->unselect_one_object((RGE_Static_Object*)this);
        }

        ((RGE_Static_Object*)this)->take_attribute_from_owner();

        this->owner->removeObject((RGE_Static_Object*)this,
                                  this->sleep_flag,
                                  this->dopple_flag,
                                  this->player_object_node);
        this->player_object_node = player->addObject((RGE_Static_Object*)this,
                                                       this->sleep_flag,
                                                       this->dopple_flag);

        if (this->object_state == 2) {
            this->unexplore_terrain(this->owner, 0, -1);
        }

        this->owner = player;

        if (this->own_master == 0) {
            this->master_obj = this->master_obj->make_new_master();
            this->own_master = 1;
        }

        if (this->object_state == 2) {
            this->explore_terrain(this->owner, 0, -1);
        }

        ((RGE_Static_Object*)this)->give_attribute_to_owner();

        if (this->unitAIValue != 0) {
            this->unitAIValue->purgeNotifyQueue(this->owner->world->world_time);
        }

        this->notify(this->id, this->id, 0x20B, player->id, 0, 0);
    }
}
