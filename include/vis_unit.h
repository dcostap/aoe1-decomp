#ifndef AOE1_VIS_UNIT_H
#define AOE1_VIS_UNIT_H


class RGE_Player;
class RGE_Static_Object;
class RGE_Tile_List;
struct VISIBLE_UNIT_REC;

struct VISIBLE_UNIT_REC {
    int object_id;
    unsigned char distance;
    unsigned char player;
    unsigned char pos_x;
    unsigned char pos_y;
};

typedef char aoe1_visible_unit_rec_size_check[
    (sizeof(VISIBLE_UNIT_REC) == 0x08) ? 1 : -1];

struct VISIBLE_UNIT_PTR {
    VISIBLE_UNIT_REC* unit_list;
    short list_size;
    short used;
};

typedef char aoe1_visible_unit_ptr_size_check[
    (sizeof(VISIBLE_UNIT_PTR) == 0x08) ? 1 : -1];

class Visible_Unit_Manager {
public:
    VISIBLE_UNIT_PTR** PlayerDataPtrs;
    VISIBLE_UNIT_REC* Return_Buffer[5];
    int Player_Count;
    int Category_Count;

protected:
    unsigned char* distanceTable;

public:
    Visible_Unit_Manager(int Num_Players, int Num_Categories);
    ~Visible_Unit_Manager();
    void Build_Distance_Table();
    void Update_Unit_Info(int Object_Id, int player_id, int Xpos, int Ypos, int Category,
                          unsigned long PriorUnifiedMap, unsigned long NewUnifiedMap,
                          VISIBLE_UNIT_REC** ObjectPtrs);
    int GetVisibleUnits(int Xpos, int Ypos, int LOS, int player, int* DesiredTypes,
                        int DesiredCount, int* PlayerListMap);
};

typedef char aoe1_visible_unit_manager_size_check[
    (sizeof(Visible_Unit_Manager) == 0x24) ? 1 : -1];

struct VISIBLE_RESOURCE_REC {
public:
    int object_id;
    unsigned char distance;
    unsigned char zone;
    unsigned char pos_x;
    unsigned char pos_y;
};

typedef char aoe1_visible_resource_rec_size_check[
    (sizeof(VISIBLE_RESOURCE_REC) == 0x08) ? 1 : -1];

class Visible_Resource_Manager {
public:
    VISIBLE_RESOURCE_REC** VR_List;
    int* VR_ListSize;
    int* VR_ListUsed;
    RGE_Player* owner;
    int num_visible_resource_lists;

    Visible_Resource_Manager(RGE_Player* list_owner, int num_lists);
    Visible_Resource_Manager(int infile, RGE_Player* list_owner);
    ~Visible_Resource_Manager();
    void save(int outfile);
    void Process_New_Tiles(RGE_Tile_List* tile_list);
    void AddResource(int Obj_Id, int ObjGroup);
    int Remove_Resource(int Obj_Id, int ObjGroup);
    VISIBLE_RESOURCE_REC* Get_Closest_Resource(int Xpos, int Ypos, int Zone,
                                                int ResType, int* excList,
                                                int elSize);
};

typedef char aoe1_visible_resource_manager_size_check[
    (sizeof(Visible_Resource_Manager) == 0x14) ? 1 : -1];

#endif
