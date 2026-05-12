// VA: 00430680 RGE_Combat_Object::update
// Source: com_obj.cpp lines 589-711
// Attempt log:
// 1: natural reconstruction from packet and nearby enter_obj/destructor patterns; initial layout had an extra world field and shifted post-owner offsets by 4.
// 2: model owner/player as field +0x0C with world at owner+0x3C; codegen within 2 bytes but player pointer was preserved instead of index offset.
// 3: use `> 0` mask test and reload world->players[local_4] at vf44 site.

typedef unsigned long ulong;

#define unified_map_offsets ((unsigned long**)0x00886808)

class RGE_Player;
class RGE_Static_Object;
class UnitAIModule;
class Visible_Unit_Manager;

extern "C" Visible_Unit_Manager* VisibleUnitManager;

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
    char gap_3E[0x40 - 0x3E];
    RGE_Player** players;
    char gap_44[0x84 - 0x44];
    float frame_delta;

    int is_player_turn(int player_id);
    unsigned long get_accum_time_delta(int player_id);
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x14];
    short object_group;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    char gap_40[0x4A - 0x40];
    short id;

    int computerPlayer(void);
};

class RGE_Action_Object {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(RGE_Player* player);

    unsigned char update(void);
};

class Visible_Unit_Manager {
public:
    void Update_Unit_Info(int object_id, int player_id, int world_x, int world_y, int object_group, unsigned long old_value, unsigned long new_value, void* vur_ptrs);
};

class UnitAIModule {
public:
    int update(unsigned long delta);
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x20 - 0x10];
    int inside_obj;
    char gap_24[0x38 - 0x24];
    float world_x;
    float world_y;
    char gap_40[0x74 - 0x40];
    UnitAIModule* aiModule;
    char gap_78[0x194 - 0x78];
    void* VUR_Ptrs[9];
    unsigned long Unified_Map_Value;
    float attack_timer;
    unsigned char capture_flag;

    unsigned char update(void);
};

unsigned char RGE_Combat_Object::update(void)
{
    long local_4 = -1;

    if (this->attack_timer > 0.0f) {
        this->attack_timer = this->attack_timer - this->owner->world->frame_delta;
        if (this->attack_timer < 0.0f) {
            this->attack_timer = 0.0f;
        }
    }

    unsigned char result = RGE_Action_Object::update();

    int object_id = this->id;
    if (object_id >= 0 && this->inside_obj == 0) {
        int x = (int)this->world_x;
        int y = (int)this->world_y;
        unsigned long new_value = unified_map_offsets[y][x];
        unsigned long old_value = this->Unified_Map_Value;
        this->Unified_Map_Value = new_value;
        if (new_value != old_value) {
            VisibleUnitManager->Update_Unit_Info(object_id,
                                                 (int)this->owner->id,
                                                 x,
                                                 y,
                                                 (int)this->master_obj->object_group,
                                                 old_value,
                                                 new_value,
                                                 this->VUR_Ptrs);
            if (this->capture_flag) {
                RGE_Game_World* world = this->owner->world;
                int player = 1;
                int player_num = world->player_num;
                if (player_num > 1) {
                    int owner_id = this->owner->id;
                    do {
                        if (player != owner_id) {
                            unsigned long mask = 1 << player;
                            if ((new_value & mask) > 0) {
                                local_4 = player;
                                break;
                            }
                        }
                        ++player;
                    } while (player < player_num);
                }
                if (local_4 >= 0) {
                    if (world->players[local_4]->computerPlayer() == 0) {
                        this->vf44(this->owner->world->players[local_4]);
                        if (this->capture_flag == 1) {
                            this->capture_flag = 0;
                        }
                    }
                }
            }
        }
    }

    if (this->aiModule != 0) {
        if (this->owner->world->is_player_turn((int)this->owner->id)) {
            this->aiModule->update(this->owner->world->get_accum_time_delta((int)this->owner->id));
        }
    }

    return result;
}
