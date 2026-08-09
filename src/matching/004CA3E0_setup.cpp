// VA: 004CA3E0 TRIBE_Combat_Object::setup(int, RGE_Game_World*)
// PDB source: t_c_obj.cpp:152-180
//
// Binary-supported ownership used here:
//   RGE_Combat_Object owns master_obj (+0x08), owner (+0x0c), type (+0x4e),
//   and the UnitAIModule pointer (+0x74); TRIBE_Combat_Object adds
//   own_master at +0x1c4.  The vtable padding mirrors the exact sibling
//   setup in this translation unit so initUnitAI remains at +0x250.
//
// Baseline: natural deserialization setup with the original parameter-home
// reuse for the one-byte master kind and final four-byte presence flag.
// Main-agent audit restored canonical player/world/combat destructor ownership
// and renamed the persistent file handle; emitted code remains exact.

class RGE_Game_World;
class RGE_Sprite;
class RGE_Sound;

extern "C" void __cdecl rge_read(int handle, void* buffer, int size);

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int handle);
    virtual void load(int handle);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
};

class TRIBE_Master_Combat_Object : public RGE_Master_Static_Object {
public:
    virtual ~TRIBE_Master_Combat_Object();
    char gap_04[0x160];
    TRIBE_Master_Combat_Object(int handle, RGE_Sprite** sprites,
                               RGE_Sound** sounds, int do_setup);
};

class TRIBE_Master_Building_Object : public RGE_Master_Static_Object {
public:
    virtual ~TRIBE_Master_Building_Object();
    char gap_04[0x178];
    TRIBE_Master_Building_Object(int handle, RGE_Sprite** sprites,
                                 RGE_Sound** sounds, int do_setup);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    char gap_04[0x2c];
    RGE_Sound** sounds;
    char gap_34[0x4];
    RGE_Sprite** sprites;
};

#define V(n) virtual void v_##n();
#define V10(p) V(p##0) V(p##1) V(p##2) V(p##3) V(p##4) V(p##5) V(p##6) V(p##7) V(p##8) V(p##9)
#define V3(p) V(p##0) V(p##1) V(p##2)
#define V4TAIL(p) V(p##4) V(p##5) V(p##6) V(p##7)

class RGE_Combat_Object {
public:
    virtual ~RGE_Combat_Object();
    V(01) V(02) V(03) V(04) V(05) V(06) V(07) V(08) V(09)
    V10(1)
    V10(2)
    V10(3)
    V10(4)
    V10(5)
    V10(6)
    V10(7)
    V10(8)
    V10(9)
    V10(10)
    V10(11)
    V10(12)
    V10(13)
    V3(14)
    virtual int setup(int handle, RGE_Game_World* world);
    V4TAIL(14)

    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x3e];
    unsigned char type;
    char gap_4f[0x25];
    UnitAIModule* unit_ai;
    char gap_78[0x148];
    unsigned char capture_flag;
    char gap_1c1[0x3];
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    virtual void initUnitAI();
    virtual int setup(int handle, RGE_Game_World* world);

    unsigned char own_master;
};

int TRIBE_Combat_Object::setup(int param_1, RGE_Game_World* param_2)
{
    int handle = param_1;

    RGE_Combat_Object::setup(handle, param_2);
    this->type = 0x46;
    rge_read(handle, &this->own_master, 1);

    if (this->own_master != 0) {
        rge_read(handle, &param_2, 1);
        if ((char)param_2 == 'F') {
            this->master_obj = new TRIBE_Master_Combat_Object(
                handle, this->owner->world->sprites,
                this->owner->world->sounds, 1);
        } else if ((char)param_2 == 'P') {
            this->master_obj = new TRIBE_Master_Building_Object(
                handle, this->owner->world->sprites,
                this->owner->world->sounds, 1);
        }
    }

    rge_read(handle, &param_1, 4);
    if (param_1 == 1) {
        this->initUnitAI();
        if (this->unit_ai != 0) {
            this->unit_ai->load(handle);
        }
    }
    return 1;
}

#undef V4TAIL
#undef V3
#undef V10
#undef V
