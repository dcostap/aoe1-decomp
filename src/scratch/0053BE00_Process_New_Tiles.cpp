// vis_unit.cpp target: Visible_Resource_Manager::Process_New_Tiles
// walks newly visible tiles and adds objects whose master marks them as resources.
//
// Attempt log:
// - Baseline direct record walk: calls aligned, but VC5 chose EBX for this and
//   omitted the original early EBX/EBP save pair.
// - Reordered guards and loop-index declaration/qualification: no emitted-code
//   change until the inner node walk was normalized.
// - Replaced the decompiler-shaped node do/break loop with the natural
//   `while (node != 0 && count > 0)` form; this recovered the original loop
//   backedge/test topology and the exact object/resource call body.
// - Corrected AddResource's second parameter to int (the binary ABI), and
//   materialized the object id before loading the resource group. This recovered
//   the zero-extension and original id/group load order.
// - Final source keeps the canonical typed tile-record cursor and the natural
//   resource-node walk. Current best check: 161 positional differing bytes,
//   191 rebuilt bytes vs 195 original; calls and frame size match. Remaining
//   drift is the early loop-index initialization/prologue scheduling and the
//   original redundant size guard that VC5 removes from this clean form.

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

struct RGE_Tile_List_Node {
    int x;
    int y;
};

class RGE_Tile_List {
public:
    void get_list_info(RGE_Tile_List_Node** list, int* size);
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
    void AddResource(int id, int type);
};

void Visible_Resource_Manager::Process_New_Tiles(RGE_Tile_List* list) {
    int size;
    RGE_Tile_List_Node* tileList;
    int i = 0;
    list->get_list_info(&tileList, &size);
    if (size > 0 && this->num_visible_resource_lists != 0) {
        if (size > 0) {
            RGE_Tile** rows = this->owner->world2->map->map_row_offset;
            do {
                RGE_Tile_List_Node* cur = tileList;
                RGE_Tile* tile = &rows[cur->y][cur->x];
                int count = tile->objects.number_of_objects;
                if (count > 0) {
                    RGE_Object_Node* node = tile->objects.list;
                    while (node != 0 && count > 0) {
                        RGE_Static_Object* obj = node->node;
                        if (obj != 0) {
                            RGE_Object_Master* master = obj->master_obj;
                            if (master->track_as_resource) {
                                int id = obj->id;
                                this->AddResource(id, master->resource_group);
                            }
                        }
                        node = node->next;
                        count--;
                    }
                }
                i++;
                tileList++;
            } while (i < size);
        }
    }
}
