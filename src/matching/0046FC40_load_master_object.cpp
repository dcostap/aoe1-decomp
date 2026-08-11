// VA: 0046FC40 RGE_Player::load_master_object (617B)
// PDB source: player.cpp, lines 1077-1106
// FLAGS: config/flags/0046FC40_load_master_object.rsp (/GX for the EH/new basin)
//
// Attempt log:
// - Baseline: restored the period typed RGE_Player master_objects field at +0x24,
//   the seven concrete master-object sizes, and the player.cpp switch/case order.
// - Exact: /GX plus natural typed new expressions reproduces all EH state stores,
//   constructor calls, shared null stores, and the 617-byte function.

void* __cdecl operator new(unsigned int size);
class RGE_Sprite;
class RGE_Sound;

class RGE_Master_Static_Object {
public:
    char pad[0xB8];
    RGE_Master_Static_Object(int, RGE_Sprite**, RGE_Sound**, int);
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    char pad2[4];
    RGE_Master_Animated_Object(int, RGE_Sprite**, RGE_Sound**, int);
};

class RGE_Master_Moving_Object : public RGE_Master_Static_Object {
public:
    char pad2[0x20];
    RGE_Master_Moving_Object(int, RGE_Sprite**, RGE_Sound**, int);
};

class RGE_Master_Missile_Object : public RGE_Master_Static_Object {
public:
    char pad2[0x9C];
    RGE_Master_Missile_Object(int, RGE_Sprite**, RGE_Sound**, int);
};

class RGE_Master_Action_Object : public RGE_Master_Static_Object {
public:
    char pad2[0x44];
    RGE_Master_Action_Object(int, RGE_Sprite**, RGE_Sound**, int);
};

class RGE_Master_Combat_Object : public RGE_Master_Static_Object {
public:
    char pad2[0x90];
    RGE_Master_Combat_Object(int, RGE_Sprite**, RGE_Sound**, int);
};

class RGE_Master_Doppleganger_Object : public RGE_Master_Static_Object {
public:
    char pad2[4];
    RGE_Master_Doppleganger_Object(int, RGE_Sprite**, RGE_Sound**, int);
};

class RGE_Player {
public:
    char gap[0x24];
    RGE_Master_Static_Object** master_objects;

    void load_master_object(int file, short index, unsigned char type,
                            RGE_Sprite** sprites, RGE_Sound** sounds);
};

void RGE_Player::load_master_object(int file, short index, unsigned char type,
                                     RGE_Sprite** sprites, RGE_Sound** sounds)
{
    RGE_Master_Static_Object* object;

    switch (type) {
    case 10:
        object = new RGE_Master_Static_Object(file, sprites, sounds, 1);
        break;
    case 20:
        object = new RGE_Master_Animated_Object(file, sprites, sounds, 1);
        this->master_objects[index] = object;
        return;
    case 30:
        object = new RGE_Master_Moving_Object(file, sprites, sounds, 1);
        break;
    case 60:
        object = new RGE_Master_Missile_Object(file, sprites, sounds, 1);
        this->master_objects[index] = object;
        return;
    case 40:
        object = new RGE_Master_Action_Object(file, sprites, sounds, 1);
        break;
    case 50:
        object = new RGE_Master_Combat_Object(file, sprites, sounds, 1);
        this->master_objects[index] = object;
        return;
    case 25:
        object = new RGE_Master_Doppleganger_Object(file, sprites, sounds, 1);
        break;
    default:
        return;
    }

    this->master_objects[index] = object;
}
