// 005128A0 TRIBE_Player::load
// Attempt log:
// 1: Natural reconstruction from packet and neighboring save/load_master_object.
// FLAGS: config/flags/005128A0_load.rsp

extern "C" void __cdecl rge_read(int file, void* dst, int size);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern float g_58EBCC;
extern float g_576858;

class RGE_Sprite;
class RGE_Sound;
#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Game_World { public: char pad_00[0x30]; RGE_Sprite** pad_30; char pad_34[4]; RGE_Sound** pad_38; };

class RGE_Player {
public:
    virtual void vf00();
    void load_master_object(int file, short index, unsigned char type, RGE_Sprite** sprites, RGE_Sound** sounds);
};

class RGE_Visible_Map {
public:
    char pad[0x38];
    RGE_Visible_Map(int file, RGE_Game_World* world);
};

class Visible_Resource_Manager {
public:
    char pad[0x14];
    Visible_Resource_Manager(int file, void* player);
};

class RGE_Object_List {
public:
    virtual void vf00();
    char pad[0x08];
    RGE_Object_List();
    void load_list(int file, RGE_Game_World* world);
};

class TRIBE_Object_List : public RGE_Object_List {
public:
    virtual void vf00();
};

class TRIBE_Player : public RGE_Player {
public:
    char pad_04[0x22 - 4];
    short master_object_count; // +22
    void** master_objects; // +24
    TRIBE_Object_List* list_28;
    TRIBE_Object_List* list_2c;
    RGE_Object_List* list_30;
    char pad_34[0x38 - 0x34];
    RGE_Visible_Map* visible_map; // +38
    RGE_Game_World* world; // +3c
    char pad_40[0x110 - 0x40];
    Visible_Resource_Manager* visible_resources; // +110

    void load_master_object(int file, short index, unsigned char type, RGE_Sprite** sprites, RGE_Sound** sounds);
    void load(int file);
};
#endif

void TRIBE_Player::load(int file)
{
    rge_read(file, &this->master_object_count, 2);
    short count = this->master_object_count;
    if (count > 0) {
        this->master_objects = (RGE_Master_Static_Object**)calloc(count, 4);
        rge_read(file, this->master_objects, this->master_object_count * 4);
        for (short i = 0; i < this->master_object_count; ++i) {
            if (this->master_objects[i] != 0) {
                unsigned char type;
                rge_read(file, &type, 1);
                this->load_master_object(file, i, type, (RGE_Sprite**)this->world->pad_38, (RGE_Sound**)this->world->pad_30);
            }
        }
    } else {
        this->master_objects = 0;
    }

    this->visible_map = new RGE_Visible_Map(file, this->world);
    this->visible_resources = new Visible_Resource_Manager(file, this);
    this->list_28 = new TRIBE_Object_List;
    this->list_28->load_list(file, this->world);
    this->list_2c = new TRIBE_Object_List;
    this->list_2c->load_list(file, this->world);
    this->list_30 = new RGE_Object_List;

    if (!(g_58EBCC < g_576858)) {
        this->list_30->load_list(file, this->world);
    }
}
