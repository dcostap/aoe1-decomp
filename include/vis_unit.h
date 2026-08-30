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
    Visible_Unit_Manager(int player_count, int category_count);
    ~Visible_Unit_Manager();
    void Build_Distance_Table();
    void Update_Unit_Info(int object_id, int player, int x, int y, int category,
                          unsigned long old_mask, unsigned long new_mask,
                          VISIBLE_UNIT_REC** refs);
    int GetVisibleUnits(int x, int y, int distance, int player,
                        int* categories, int category_count, int* player_map);
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

    Visible_Resource_Manager(RGE_Player* owner, int count);
    Visible_Resource_Manager(int handle, RGE_Player* owner);
    ~Visible_Resource_Manager();
    void save(int handle);
    void Process_New_Tiles(RGE_Tile_List* list);
    void AddResource(int object_id, int type);
    int Remove_Resource(int object_id, int type);
    VISIBLE_RESOURCE_REC* Get_Closest_Resource(int x, int y, int param3,
                                                int type, int* reject_list,
                                                int reject_count);
};

typedef char aoe1_visible_resource_manager_size_check[
    (sizeof(Visible_Resource_Manager) == 0x14) ? 1 : -1];

#endif
