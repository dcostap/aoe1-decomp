// VA: 00451770 RGE_Master_Missile_Object::make_new_obj (201B)
// PDB source: m_mi_obj.cpp, lines 129-143
// Attempt log:
// baseline: natural recycle-or-allocate factory using the proven master fields,
// the RGE_Static_Object slot-4 recycle call, and a 0x1C8 RGE_Missile_Object.
// FLAGS: /GX retained because the original has VC5 EH registration and ctor state.

class RGE_Master_Static_Object;
class RGE_Master_Combat_Object;
class RGE_Player;
class RGE_Game_World;

class RGE_Static_Object {
public:
    char gap_00[0x84];
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object* master,
                                    RGE_Player* player,
                                    float x, float y, float z);
};

class RGE_Master_Static_Object {
public:
    void* vtable;
    unsigned char master_type;
    char gap_05[0x9F];
    unsigned char recyclable;
    char gap_A5[0x13];
};

class RGE_Master_Combat_Object : public RGE_Master_Static_Object {
public:
    char gap_B8[0x90];
};

class RGE_Master_Missile_Object : public RGE_Master_Combat_Object {
public:
    char gap_148[0x0C];
    RGE_Static_Object* make_new_obj(RGE_Player* player,
                                    float x, float y, float z);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Game_World {
public:
    RGE_Static_Object* recycle_object_in_to_game(unsigned char master_type);
};

class RGE_Combat_Object : public RGE_Static_Object {
public:
    char gap_88[0x13C];
};

class RGE_Missile_Object : public RGE_Combat_Object {
public:
    float max_range;
    RGE_Missile_Object(RGE_Master_Missile_Object* master, RGE_Player* player,
                      float x, float y, float z, int do_setup);
};

RGE_Static_Object* RGE_Master_Missile_Object::make_new_obj(
    RGE_Player* player, float x, float y, float z)
{
    if (this->recyclable != 0) {
        RGE_Static_Object* recycled =
            player->world->recycle_object_in_to_game(this->master_type);
        if (recycled != 0) {
            recycled->recycle_in_to_game(this, player, x, y, z);
            return recycled;
        }
    }

    return new RGE_Missile_Object(this, player, x, y, z, 1);
}
