// Authentic vis_unit.cpp recovery wrapper.
//
// Source module: C:\\msdev\\work\\age1_x1\\vis_unit.cpp
// PDB owner order:
//   0053B5A0 Visible_Unit_Manager::Visible_Unit_Manager (49-88)
//   0053B670 Visible_Unit_Manager::~Visible_Unit_Manager (91-125)
//   0053B730 Visible_Unit_Manager::Build_Distance_Table (129-168)
//   0053B7E0 Visible_Unit_Manager::Update_Unit_Info (172-258)
//   0053B9A0 Visible_Unit_Manager::GetVisibleUnits (265-434)
//   0053BB30 Visible_Resource_Manager::Visible_Resource_Manager (445-474)
//   0053BBE0 Visible_Resource_Manager::Visible_Resource_Manager (477-518)
//   0053BD10 Visible_Resource_Manager::~Visible_Resource_Manager (521-533)
//   0053BD70 Visible_Resource_Manager::save (537-554)
//   0053BE00 Visible_Resource_Manager::Process_New_Tiles (559-611)
//   0053BED0 Visible_Resource_Manager::AddResource (616-665)
//   0053BFD0 Visible_Resource_Manager::Remove_Resource (669-703)
//   0053C050 Visible_Resource_Manager::Get_Closest_Resource (708-792)
//
// This proposal owns each normal VA once through the included owner source.
// Natural C++ owns the scan, allocation cursor, and destructor. The narrow
// layout carriers below use executable offsets; no dispatch table is written.

#include <stdlib.h>
#include <string.h>

struct VisibleUnitRec {
    int object_id;
    unsigned char distance;
    unsigned char player;
    unsigned char pos_x;
    unsigned char pos_y;
};

typedef struct VisibleUnitPtr {
    VisibleUnitRec* unit_list;
    union {
        short allocated;
        short list_size;
    };
    short used;
} VisibleUnitPtr;

struct VisibleResourceRec {
    int object_id;
    unsigned char distance;
    unsigned char zone;
    unsigned char pos_x;
    unsigned char pos_y;
};

typedef VisibleResourceRec VisibleResourceRecord;

class Visible_Unit_Manager {
public:
    VisibleUnitPtr** PlayerDataPtrs;
    VisibleUnitRec* Return_Buffer[5];
    int Player_Count;
    int Category_Count;
    unsigned char* distanceTable;

    Visible_Unit_Manager(int player_count, int category_count);
    ~Visible_Unit_Manager();
    void Build_Distance_Table();
    void Update_Unit_Info(int object_id, int player, int x, int y, int category,
                          unsigned long old_mask, unsigned long new_mask,
                          VisibleUnitRec** refs);
    int GetVisibleUnits(int x, int y, int distance, int player,
                        int* categories, int category_count, int* player_map);
};

class RGE_Object_Master {
public:
    unsigned char reserved_00[0xA5];
    unsigned char track_as_resource;
    unsigned char reserved_A6;
    unsigned char resource_group;
};

struct RGE_Object_Node {
    class RGE_Static_Object* node;
    RGE_Object_Node* next;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Object_Master* master_obj;
    unsigned char reserved_0C[0x2C];
    float x;
    float y;
};

// BINARY NOTE: Update_Unit_Info writes the combat-object VUR_Ptrs array at
// the proven derived offset +0x194. This is a real base/derived boundary.
class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    unsigned char reserved_04[0x190];
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    VisibleUnitRec* VUR_Ptrs[9];
};

class RGE_Player;

struct RGE_Tile_List_Node {
    int x;
    int y;
};

class RGE_Tile_List {
public:
    void get_list_info(RGE_Tile_List_Node** list, int* size);
};

struct TileObjects {
    unsigned char reserved_00[0x10];
    RGE_Object_Node* list;
    short number_of_objects;
};

struct RGE_Tile {
    TileObjects objects;
};

struct RGE_Map {
    unsigned char reserved_00[0x8D8C];
    RGE_Tile** map_row_offset;
};

struct RGE_World2 {
    unsigned char reserved_00[0x28];
    RGE_Map* map;
};

class RGE_Player {
public:
    unsigned char reserved_00[0x3C];
    RGE_World2* world2;
};

class Visible_Resource_Manager {
public:
    VisibleResourceRec** VR_List;
    int* VR_ListSize;
    int* VR_ListUsed;
    RGE_Player* owner;
    int num_visible_resource_lists;

    Visible_Resource_Manager(RGE_Player* owner, int count);
    Visible_Resource_Manager(int handle, RGE_Player* owner);
    ~Visible_Resource_Manager();
    void save(int handle);
    void Process_New_Tiles(RGE_Tile_List* list);
    void AddResource(int object_id, int type);
    int Remove_Resource(int object_id, int type);
    VisibleResourceRec* Get_Closest_Resource(int x, int y, int param3,
                                             int type, int* reject_list,
                                             int reject_count);
};

extern VisibleUnitRec* VisibleUnitList[5];
extern int VisibleUnitList_Size[5];
extern void* VisibleUnitManager;
extern int* NormalLOS;
extern int* PTR_Edge_Offsets_N16;
extern RGE_Static_Object** VIS_UNIT_objectsValue;
extern float save_game_version;
extern float DAT_005776c8;
extern double DAT_005776D0;
extern double DAT_005776D8;
extern void rge_read(int handle, void* buffer, int size);
extern void rge_write(int handle, void* buffer, int size);

#define VIS_UNIT_TU_CONTEXT 1
#include "matching/0053B5A0_Visible_Unit_Manager.cpp"
#include "matching/0053B670_Visible_Unit_Manager.cpp"
#include "accepted_drift/0053B730_Build_Distance_Table.cpp"
#include "scratch/0053B7E0_Update_Unit_Info.cpp"
#include "matching/0053B9A0_GetVisibleUnits.cpp"
#include "matching/0053BB30_Visible_Resource_Manager.cpp"
#include "matching/0053BBE0_Visible_Resource_Manager.cpp"
#include "matching/0053BD10_Visible_Resource_Manager.cpp"
#include "matching/0053BD70_save.cpp"
#include "matching/0053BE00_Process_New_Tiles.cpp"
#include "matching/0053BED0_AddResource.cpp"
#include "matching/0053BFD0_Remove_Resource.cpp"
#include "scratch/0053C050_Get_Closest_Resource.cpp"
#undef VIS_UNIT_TU_CONTEXT
