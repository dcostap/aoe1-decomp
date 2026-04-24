// first pass: bounds-check tile coordinates, walk the per-tile object list, and delete each static object node with flag 1
// tried direct bounds checks, reordered early returns, and explicit tile_x/tile_y locals; the remaining mismatch stayed at the opening x-load register choice (eax vs edx)

class RGE_Static_Object {
public:
    virtual void delete_object(int flag);
};

class RGE_Object_Node {
public:
    RGE_Static_Object* object;
    RGE_Object_Node* next;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[0x4];
    int map_width;
    int map_height;
    char gap_10[0x8D78];
    RGE_Object_Node*** tile_rows;

    void delete_all_objects_on_tile(int x, int y);
};

void RGE_Map::delete_all_objects_on_tile(int x, int y) {
    int tile_x = x;
    int tile_y = y;

    if (tile_x < 0) {
        return;
    }
    if (tile_x >= this->map_width) {
        return;
    }
    if (tile_y < 0) {
        return;
    }
    if (tile_y >= this->map_height) {
        return;
    }

    RGE_Object_Node* node = this->tile_rows[tile_y][tile_x];
    while (node != 0) {
        RGE_Object_Node* next = node->next;
        if (node->object != 0) {
            node->object->delete_object(1);
        }
        node = next;
    }
}
