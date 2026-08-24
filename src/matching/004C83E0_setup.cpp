// VA: 004C83E0 TRIBE_Building_Object::setup
// t_b_obj.cpp:176-199
// Retry 2026-05-24: replaced stale stub with packet-derived building setup body.

#ifndef T_B_OBJ_CONTEXT_H
class TRIBE_Master_Building_Object {
public:
    char gap_000[0x10];
    short id;
    char gap_012[0x148];
    short word_15A;
    char gap_15C[0x0C];
    int field_168;
    char gap_16C[0x02];
    unsigned char terrain_restriction;
};

class RGE_Player {
public:
    char gap_00[0x54];
    unsigned char culture;
};

class TRIBE_Destructables {
public:
    void check_destructables(short map_id, short master_id, int tile_y, int tile_x, int zero);
};

class TRIBE_World {
public:
    char gap_00[0x3C];
    class TRIBE_Destructables* destructables;
    char gap_40[0x0A];
    short map_id;
};

class TRIBE_Combat_Object {
public:
    virtual void vf_000();
    virtual void vf_004();
    virtual void vf_008();
    virtual void vf_00C();
    virtual void vf_010();
    virtual void vf_014();
    virtual void vf_018();
    virtual void vf_01C();
    virtual void vf_020();
    virtual void vf_024();
    virtual void vf_028();
    virtual void vf_02C();
    virtual void vf_030();
    virtual void vf_034();
    virtual void set_master_field(int value); // +0x38
    virtual void vf_03C();
    virtual void vf_040();
    virtual void vf_044();
    virtual void vf_048();
    virtual void vf_04C();
    virtual void vf_050();
    virtual void vf_054();
    virtual void vf_058();
    virtual void set_selected(int value);     // +0x5C
    virtual void vf_060();
    virtual void vf_064();
    virtual void vf_068();
    virtual void vf_06C();
    virtual void vf_070();
    virtual void vf_074();
    virtual void vf_078();
    virtual void vf_07C();
    virtual void vf_080();
    virtual void vf_084();
    virtual void vf_088();
    virtual void vf_08C();
    virtual void vf_090();
    virtual void vf_094();
    virtual void vf_098();
    virtual void vf_09C();
    virtual void vf_0A0();
    virtual void vf_0A4();
    virtual void vf_0A8();
    virtual void vf_0AC();
    virtual void vf_0B0();
    virtual void vf_0B4();
    virtual void vf_0B8();
    virtual void vf_0BC();
    virtual void vf_0C0();
    virtual void vf_0C4();
    virtual void vf_0C8();
    virtual void vf_0CC();
    virtual void vf_0D0();
    virtual void vf_0D4();
    virtual void vf_0D8();
    virtual void vf_0DC();
    virtual void vf_0E0();
    virtual void vf_0E4();
    virtual void vf_0E8();
    virtual void vf_0EC();
    virtual void vf_0F0();
    virtual void vf_0F4();
    virtual void vf_0F8();
    virtual void vf_0FC();
    virtual void vf_100();
    virtual void vf_104();
    virtual void vf_108();
    virtual void vf_10C();
    virtual void vf_110();
    virtual void vf_114();
    virtual void vf_118();
    virtual void vf_11C();
    virtual void vf_120();
    virtual void vf_124();
    virtual void vf_128();
    virtual void vf_12C();
    virtual void vf_130();
    virtual void vf_134();
    virtual void vf_138();
    virtual void vf_13C();
    virtual void vf_140();
    virtual void vf_144();
    virtual void vf_148();
    virtual void vf_14C();
    virtual void vf_150();
    virtual void vf_154();
    virtual void vf_158();
    virtual void vf_15C();
    virtual void vf_160();
    virtual void vf_164();
    virtual void vf_168();
    virtual void vf_16C();
    virtual void vf_170();
    virtual void vf_174();
    virtual void vf_178();
    virtual void vf_17C();
    virtual void vf_180();
    virtual void vf_184();
    virtual void vf_188();
    virtual void vf_18C();
    virtual void vf_190();
    virtual void vf_194();
    virtual void vf_198();
    virtual void vf_19C();
    virtual void vf_1A0();
    virtual void vf_1A4();
    virtual void vf_1A8();
    virtual void vf_1AC();
    virtual void vf_1B0();
    virtual void vf_1B4();
    virtual void vf_1B8();
    virtual void vf_1BC();
    virtual void vf_1C0();
    virtual void vf_1C4();
    virtual void vf_1C8();
    virtual void vf_1CC();
    virtual void vf_1D0();
    virtual void vf_1D4();
    virtual void vf_1D8();
    virtual void vf_1DC();
    virtual void vf_1E0();
    virtual void vf_1E4();
    virtual void vf_1E8();
    virtual void vf_1EC();
    virtual void vf_1F0();
    virtual void vf_1F4();
    virtual void vf_1F8();
    virtual void vf_1FC();
    virtual void vf_200();
    virtual void vf_204();
    virtual void vf_208();
    virtual void vf_20C();
    virtual void vf_210();
    virtual void vf_214();
    virtual void* create_action_list();       // +0x218
    virtual void vf_21C();

    char gap_04[0x04];
    TRIBE_Master_Building_Object* master_obj; // +0x08
    TRIBE_World* world;                       // +0x0C
    char gap_10[0x20];
    float field_30;
    char gap_34[0x01];
    unsigned char terrain_restriction;        // +0x35
    char gap_36[0x02];
    int tile_y;                               // +0x38
    int tile_x;                               // +0x3C
    char gap_40[0x0E];
    unsigned char object_type;                // +0x4E
    char gap_4F[0x185];
    void* production_queue_actions;           // +0x1D4
    char gap_1D8[0x04];
    int build_pts;                            // +0x1DC
    char gap_1E0[0x04];
    unsigned char culture;                    // +0x1E4
    unsigned char built;                      // +0x1E5

    int setup(TRIBE_Master_Building_Object* master, RGE_Player* player, float x, float y, float z);
};

class TRIBE_Building_Object : public TRIBE_Combat_Object {
public:
    int setup(TRIBE_Master_Building_Object* master, RGE_Player* player, float x, float y, float z);
};
#endif

int TRIBE_Building_Object::setup(TRIBE_Master_Building_Object* master, RGE_Player* player, float x, float y, float z)
{
    built = 0;
    TRIBE_Combat_Object::setup(master, player, x, y, z);
    object_type = 0x50;
    this->set_selected(0);
    TRIBE_Master_Building_Object* master2 = master_obj;
    if (master2->word_15A > 0) {
        this->set_master_field(master2->field_168);
    }
    master2 = master_obj;
    build_pts = 0;
    field_30 = 1.0f;
    terrain_restriction = master2->terrain_restriction;
    culture = player->culture;
    world->destructables->check_destructables(world->map_id, master2->id, tile_y, tile_x, 0);
    production_queue_actions = this->create_action_list();
    return 1;
}
