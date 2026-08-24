// 00458FD0 - create_terrain_objects
// Original: map.cpp:2249-2256
// __thiscall, size: 80 bytes

#ifndef MAP_CONTEXT_H
// Local class stubs for matching
class RGE_Player;
class RGE_Game_World;

// RGE_Map stub with needed members (from inventory)
class RGE_Map {
public:
    virtual ~RGE_Map();
    void* map;           // RGE_Tile*
    long map_width;      // offset +0x8
    long map_height;     // offset +0xC
    // ... other members
    
    // Method declarations
    void create_terrain_objects(RGE_Player* player, RGE_Game_World* world);
    void create_terrain_object(RGE_Player* player, RGE_Game_World* world,
        short row, short col, short old_terrain, int remove_now, int min_obj_id, int max_obj_id);
};

#endif

// Attempt log:
// Try 1: Simple nested loops based on Ghidra decompilation
// Try 2: Adjusted to match register usage pattern

void RGE_Map::create_terrain_objects(RGE_Player* player, RGE_Game_World* world) {
    short y = 0;
    short x = 0;
    
    if (this->map_height > 0) {
        do {
            x = 0;
            if (this->map_width > 0) {
                do {
                    this->create_terrain_object(player, world, y, x, -1, 0, -1, -1);
                    x++;
                } while (x < this->map_width);
            }
            y++;
        } while (y < this->map_height);
    }
}
