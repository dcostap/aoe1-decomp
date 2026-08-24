// probe: tile stores objects.list directly at +0x10 and object count at +0x14

#ifndef MAP_CONTEXT_H
class RGE_Static_Object {
public:
    virtual void delete_object(int flag);
};

class RGE_Object_Node {
public:
    RGE_Static_Object* object;
    RGE_Object_Node* next;
};

class RGE_Tile {
public:
    char gap_00[0x10];
    RGE_Object_Node* list;
    short number_of_objects;
    char gap_16[2];
};

class RGE_Map {
public:
    void* vtable;
    void* map;
    int map_width;
    int map_height;
    char gap_10[0x8D7C];
    RGE_Tile** map_row_offset;

    void delete_all_objects_on_tile(int x, int y);
};

#endif

void RGE_Map::delete_all_objects_on_tile(int x, int y) {
    if (x < 0 || x >= this->map_width) {
        return;
    }
    if (y < 0 || y >= this->map_height) {
        return;
    }

    RGE_Object_Node* node = this->map_row_offset[y][x].list;
    while (node != 0) {
        RGE_Object_Node* next = node->next;
        RGE_Static_Object* object = node->object;
        if (object != 0) {
            object->delete_object(1);
        }
        node = next;
    }
}
