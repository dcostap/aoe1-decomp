// vis_unit.cpp target: Visible_Resource_Manager::Process_New_Tiles
// walks newly visible tiles and adds objects whose master marks them as resources.

struct RGE_Object_Master {
    char gap_00[0xA5];
    unsigned char track_as_resource;
    unsigned char gap_A6;
    unsigned char resource_group;
};

struct RGE_Static_Object {
    char gap_00[0x4];
    int id;
    RGE_Object_Master* master_obj;
};

struct RGE_Object_Node {
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

struct TileObjects {
    char gap_00[0x10];
    RGE_Object_Node* list;
    short number_of_objects;
};

struct RGE_Tile {
    TileObjects objects;
};

class RGE_Tile_List {
public:
    int x;
    int y;
    void get_list_info(RGE_Tile_List** list, int* size);
};

struct RGE_Map {
    char gap_00[0x8D8C];
    RGE_Tile** map_row_offset;
};

struct RGE_World2 { char gap_00[0x28]; RGE_Map* map; };
struct RGE_Player { char gap_00[0x3C]; RGE_World2* world2; };

class Visible_Resource_Manager {
public:
    void** VR_List;
    int* VR_ListSize;
    int* VR_ListUsed;
    RGE_Player* owner;
    int num_visible_resource_lists;

    void Process_New_Tiles(RGE_Tile_List* list);
    void AddResource(int id, unsigned char type);
};

void Visible_Resource_Manager::Process_New_Tiles(RGE_Tile_List* list) {
    int size;
    RGE_Tile_List* tileList;
    list->get_list_info(&tileList, &size);
    if (size > 0 && this->num_visible_resource_lists != 0) {
        RGE_Tile** rows = this->owner->world2->map->map_row_offset;
        int i = 0;
        if (size > 0) {
            do {
                RGE_Tile_List* cur = tileList;
                RGE_Tile* tile = &rows[cur->y][cur->x];
                int count = tile->objects.number_of_objects;
                if (count > 0) {
                    RGE_Object_Node* node = tile->objects.list;
                    if (node != 0) {
                        do {
                            if (count <= 0) {
                                break;
                            }
                            RGE_Static_Object* obj = node->node;
                            if (obj != 0) {
                                RGE_Object_Master* master = obj->master_obj;
                                if (master->track_as_resource) {
                                    this->AddResource(obj->id, master->resource_group);
                                }
                            }
                            node = node->next;
                            count--;
                        } while (node != 0);
                    }
                }
                i++;
                tileList++;
            } while (i < size);
        }
    }
}
