// VA: 0046FA60 RGE_Player::load (475B)
// PDB source: player.cpp, lines 1020-1072
// FLAGS: config/flags/0046FA60_load.rsp (/GX for the original EH/new basin)
//
// Attempt log:
// - Replaced the old partial scaffold with the complete player load sequence:
//   master-object table, visible/resource objects, three object lists, and the
//   save-version-gated doppelganger list.
// - Baseline mirrors the exact same-TU TRIBE_Player::load source family while
//   retaining RGE_Player's proven field ownership and constructor surfaces.
// - Moved the sleeping-list load after construction of the doppelganger list;
//   PDB line bands/original call order prove the two allocations precede that
//   load. This recovered the exact 475-byte body.

#ifdef PLAYER_GROUPED_TU
#include "../../include/player_context.h"
#endif

#ifndef PLAYER_GROUPED_TU
extern "C" void __cdecl rge_read(int file, void* buffer, int size);
#else
void rge_read(int file, void* buffer, int size);
#endif
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern float save_game_version;
extern float DAT_00570ec0;

#ifndef PLAYER_GROUPED_TU
class RGE_Sprite;
class RGE_Sound;
class RGE_Master_Static_Object;
class RGE_Game_World;

class RGE_Visible_Map {
public:
    char pad[0x38];
    RGE_Visible_Map(int file, RGE_Game_World* world);
};

class Visible_Resource_Manager {
public:
    char pad[0x14];
    Visible_Resource_Manager(int file, class RGE_Player* player);
};

class RGE_Object_List {
public:
    virtual void vf00();
    char pad[0x08];
    RGE_Object_List();
    void load_list(int file, RGE_Game_World* world);
};

class RGE_Game_World {
public:
    char gap_00[0x30];
    RGE_Sound** sounds;
    char gap_34[0x04];
    RGE_Sprite** sprites;
};

class RGE_Player {
public:
    virtual void load(int file);

    char gap_04[0x1E];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    char gap_34[0x04];
    RGE_Visible_Map* visible;
    RGE_Game_World* world;
    char gap_40[0xD0];
    Visible_Resource_Manager* VR_List;

    void load_master_object(int file, short index, unsigned char type,
                            RGE_Sprite** sprites, RGE_Sound** sounds);
};
#endif

void RGE_Player::load(int file)
{
    rge_read(file, &this->master_object_num, 2);

    if (this->master_object_num > 0) {
        this->master_objects = (RGE_Master_Static_Object**)calloc(
            (int)this->master_object_num, 4);
        rge_read(file, this->master_objects,
                 (int)this->master_object_num * 4);

        for (short i = 0; i < this->master_object_num; ++i) {
            if (this->master_objects[i] != 0) {
                unsigned char type;
                rge_read(file, &type, 1);
                this->load_master_object(file, i, type,
                                         this->world->sprites,
                                         this->world->sounds);
            }
        }
    } else {
        this->master_objects = 0;
    }

    this->visible = new RGE_Visible_Map(file, this->world);
    this->VR_List = new Visible_Resource_Manager(file, this);
    this->objects = new RGE_Object_List;
    this->objects->load_list(file, this->world);
    this->sleeping_objects = new RGE_Object_List;
    this->doppleganger_objects = new RGE_Object_List;
    this->sleeping_objects->load_list(file, this->world);

    if (!(save_game_version < DAT_00570ec0)) {
        this->doppleganger_objects->load_list(file, this->world);
    }
}
