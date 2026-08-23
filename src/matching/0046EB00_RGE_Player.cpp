// VA: 0046EB00 ~RGE_Player (380B)
// PDB source: player.cpp, lines 279-325
//
// Canonical reconstruction: destroy owned object lists and auxiliary objects,
// release the master-object table and raw allocations, then let the two
// embedded tile lists unwind in reverse declaration order.
//
// Attempt log:
// - Initial scratch scaffold only covered the three object-list fields; it was
//   replaced with the complete period-plausible ownership reconstruction.
// - Ordered vptr-write probe was neutral; compiler-generated polymorphic
//   initialization is the exact relocation-bearing form.
// - Saved each owned heap pointer in a local before its destructor/delete pair;
//   this restored the original EDI lifetime and exact 380-byte layout.
// - Natural delete expressions for the nonvirtual owned classes emitted the
//   same direct destructor/operator-delete calls as the explicit diagnostic
//   spelling; retained the natural form.

// FLAGS: config/flags/0046EB00_RGE_Player.rsp (/GX for the EH-framed dtor)

#include <stdlib.h>
#ifdef PLAYER_GROUPED_TU
#include "../../include/player_context.h"
#endif

#ifndef PLAYER_GROUPED_TU
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
};

class RGE_Object_List {
public:
    ~RGE_Object_List();
};

class RGE_Victory_Conditions {
public:
    ~RGE_Victory_Conditions();
};

class RGE_Visible_Map {
public:
    ~RGE_Visible_Map();
};

class RGE_Doppleganger_Creator {
public:
    ~RGE_Doppleganger_Creator();
};

class Visible_Resource_Manager {
public:
    ~Visible_Resource_Manager();
};

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    void* list;

    ~RGE_Tile_List();
};

class RGE_Player {
public:
    virtual ~RGE_Player();

    char gap_04[0x1E];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    RGE_Victory_Conditions* victory_conditions;
    RGE_Visible_Map* visible;
    char gap_3C[0x4];
    RGE_Doppleganger_Creator* doppleganger_creator;
    char* name;
    unsigned char gap_48[0x4];
    short attribute_num;
    unsigned char gap_4E[0x2];
    float* attributes;
    unsigned char gap_54[0x4];
    RGE_Tile_List tile_list;
    RGE_Tile_List diam_tile_list;
    char gap_80[0x4];
    unsigned char* relations;
    char gap_88[0x88];
    Visible_Resource_Manager* VR_List;

};
#endif

RGE_Player::~RGE_Player() {
    RGE_Object_List* object_list;
    RGE_Victory_Conditions* victory_conditions;
    RGE_Visible_Map* visible_map;
    RGE_Doppleganger_Creator* doppleganger_creator;
    Visible_Resource_Manager* resource_manager;

    object_list = this->objects;
    if (object_list != 0) {
        delete object_list;
    }
    object_list = this->sleeping_objects;
    if (object_list != 0) {
        delete object_list;
    }
    object_list = this->doppleganger_objects;
    if (object_list != 0) {
        delete object_list;
    }
    victory_conditions = this->victory_conditions;
    if (victory_conditions != 0) {
        delete victory_conditions;
    }

    free(this->relations);
    this->relations = 0;

    if (this->master_object_num > 0) {
        for (short i = 0; i < this->master_object_num; ++i) {
            if (this->master_objects[i] != 0) {
                delete this->master_objects[i];
            }
        }
        free(this->master_objects);
        this->master_objects = 0;
        this->master_object_num = 0;
    }

    visible_map = this->visible;
    if (visible_map != 0) {
        delete visible_map;
    }
    doppleganger_creator = this->doppleganger_creator;
    if (doppleganger_creator != 0) {
        delete doppleganger_creator;
    }
    resource_manager = this->VR_List;
    if (resource_manager != 0) {
        delete resource_manager;
    }
    if (this->name != 0) {
        free(this->name);
        this->name = 0;
    }
    if (this->attribute_num > 0) {
        free(this->attributes);
        this->attribute_num = 0;
    }
}
