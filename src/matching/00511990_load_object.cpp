// 00511990 TRIBE_Master_Player::load_object
// Source: tmplayer.cpp lines 61-81
// Size: 365 bytes, EH-framed
// FLAGS: config/flags/00511990_load_object.rsp (/GX required by EH/new paths)
//
// Attempt log:
// Probe 1 (baseline, default flags): natural typed switch/new form with the
// complete polymorphic master-object hierarchy, 267 bytes; missed EH state
// tracking around the allocation/constructor blocks.
// Probe 2 (flags): restored the donor-supported /GX response file; exact at
// 365 bytes, including all EH state stores and seven direct calls.

class RGE_Sprite;
class RGE_Sound;
class RGE_Master_Static_Object;
struct _iobuf;

class RGE_Master_Player {
public:
    virtual ~RGE_Master_Player();
    virtual void finish_init(int, RGE_Sprite**, RGE_Sound**);
    virtual void load_master_object(int, unsigned char, RGE_Sprite**, RGE_Sound**, short);
    virtual void create_master_object_space(short);
    virtual void load_object(_iobuf*, unsigned char, RGE_Sprite**, RGE_Sound**, short);
    virtual void save(int);

    char name[20];
    short master_object_num;
    unsigned char pad_1A[2];
    RGE_Master_Static_Object** master_objects;
    short attribute_num;
    unsigned char pad_22[2];
    float* attributes;
    unsigned char culture;
    unsigned char type;
    short tribe_effect;
};

class RGE_Master_Static_Object {
public:
    char pad[0xB8 - 4];
    virtual ~RGE_Master_Static_Object();
    RGE_Master_Static_Object(_iobuf*, RGE_Sprite**, RGE_Sound**, short, int);
};

class RGE_Master_Action_Object : public RGE_Master_Static_Object {
public:
    char pad_action[0x44];
    virtual ~RGE_Master_Action_Object();
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    char pad_combat[0x4C];
    virtual ~RGE_Master_Combat_Object();
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    char pad_tribe_combat[0x1C];
    virtual ~TRIBE_Master_Combat_Object();
    TRIBE_Master_Combat_Object(_iobuf*, RGE_Sprite**, RGE_Sound**, short, int);
};

class TRIBE_Master_Tree_Object : public RGE_Master_Static_Object {
public:
    TRIBE_Master_Tree_Object(_iobuf*, RGE_Sprite**, RGE_Sound**, short, int);
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
public:
    char pad_building[0x18];
    virtual ~TRIBE_Master_Building_Object();
    TRIBE_Master_Building_Object(_iobuf*, RGE_Sprite**, RGE_Sound**, short, int);
};

class TRIBE_Master_Player : public RGE_Master_Player {
public:
    virtual void load_object(_iobuf*, unsigned char, RGE_Sprite**, RGE_Sound**, short);
};

void TRIBE_Master_Player::load_object(_iobuf* file, unsigned char object_type,
                                      RGE_Sprite** sprites, RGE_Sound** sounds,
                                      short index)
{
    RGE_Master_Static_Object* object;

    switch (object_type) {
    case 'F':
        object = new TRIBE_Master_Combat_Object(file, sprites, sounds, index, 1);
        break;
    case 'P':
        object = new TRIBE_Master_Building_Object(file, sprites, sounds, index, 1);
        this->master_objects[index] = object;
        return;
    case 'Z':
        object = new TRIBE_Master_Tree_Object(file, sprites, sounds, index, 1);
        break;
    default:
        RGE_Master_Player::load_object(file, object_type, sprites, sounds, index);
        return;
    }

    this->master_objects[index] = object;
}
