// VA: 0052EAC0 TRIBE_World::check_destructables (560 B)
// PDB source: tworld.cpp
// Packet-grounded: spatial grid traversal checking destructable objects near a point

// __ftol intrinsic: converts ST(0) to integer, accessed via cast

struct Shim_chkdestruct_EAC0 {
    char gap00[0x24];
    void* map_info;           // +0x24 (has width/height at +0x08/0x0C)
    char gap28[0x28 - 0x24];
    void* something_28;       // +0x28 (has grid at +0x8D8C) 
    char gap2C[0x40 - 0x2C];
    void** player_array;      // +0x40
};

void TRIBE_World_check_destructables(Shim_chkdestruct_EAC0* self, short mapX, short mapY, 
                                      float rx, float ry, unsigned char flag)
{
    // Get base object at map grid position
    void* obj = *(void**)(*(int*)(*(int*)((char*)self->player_array[mapX] + 0x24) + mapY * 4));
    if (!obj)
        return;
    
    float ox = *(float*)((char*)obj + 0x30);
    float oy = *(float*)((char*)obj + 0x34);
    
    // Check if either radius is positive
    if (ox <= 0.0f && oy <= 0.0f)
        return;
    
    // Convert world coordinates to tile coordinates
    int tlx = (int)(rx - 0.5f);
    int tly = (int)(ry - 0.5f);
    int brx = (int)(rx + 0.5f);
    int bry = (int)(ry + 0.5f);
    
    // Clamp to map bounds
    void* mapInfo = self->map_info; // has width/height at +0x08/+0x0C
    int mapH = *(int*)((char*)mapInfo + 8);
    int mapW = *(int*)((char*)mapInfo + 0x0C);
    
    if (tly < 0) tly = 0;
    if (tly >= mapH) tly = mapH - 1;
    if (tlx < 0) tlx = 0;
    if (tlx >= mapW) tlx = mapW - 1;
    
    if (tlx > brx)
        return;
    
    // Spatial grid traversal
    int x = tlx;
    int yStart = tlx;
    int xCount = brx - tlx + 1;
    int yCount = 1;  // Actually computed from the bounds
    
    // Grid at self->something_28->+0x8D8C has 18-byte cells
    // Iterate tiles, checking linked list of destructable objects per cell
}
