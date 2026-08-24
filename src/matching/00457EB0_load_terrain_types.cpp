// 00457EB0 RGE_Map::load_terrain_types(RGE_Sound**)
// PDB source: map.cpp lines 1659-1678
// Attempt log:
// 1: natural reverse-order RGE_Tile_Set cursor; size/calls matched, but VC5 anchored
//    the cursor at the object start instead of the binary's resource_id field.
// 2-4: indexed and pointer-loop/control-flow variants; positive sound-index guard
//    recovered the late zero arm, but the field anchor remained wrong.
// 5: anchored the typed tile-set view at resource_id with the proven 0x198 stride;
//    exact 205-byte match.
// 6: changed the proven -0x1c owner conversion to typed long-pointer arithmetic;
//    emitted code unchanged and retained.
// FLAGS: config/flags/00457EB0_load_terrain_types.rsp (/GX required by TShape new)

extern "C" void __cdecl addstring(char** dst, char* base, char* ext);
extern void __cdecl free(void* block);

#ifndef MAP_CONTEXT_H
class RGE_Sound;

class TShape {
public:
    char data[0x20];

    TShape(char* filename, long resource_id);
    int is_loaded();
};

class RGE_Tile_Set {
public:
    unsigned char loaded;             // +0x00
    unsigned char random;             // +0x01
    char name[13];                    // +0x02
    char pict_name[13];               // +0x0F
    long resource_id;                 // +0x1C
    TShape* shape;                    // +0x20
    RGE_Sound* sound;                 // +0x24
    char rest[0x198 - 0x28];
};

class RGE_Map {
public:
    char gap_00[0x8C];
    RGE_Tile_Set terrain_types[32];

    void load_terrain_types(RGE_Sound** sounds);
};

#endif

void RGE_Map::load_terrain_types(RGE_Sound** sounds)
{
    char* filename2 = 0;
    long* resource_id = &this->terrain_types[31].resource_id;
    int count = 0x20;

    do {
        RGE_Tile_Set* tile_set = (RGE_Tile_Set*)(resource_id - 7);
        if (tile_set->loaded != 0) {
            addstring(&filename2, tile_set->pict_name, (char*)".shp");
            tile_set->shape = new TShape(filename2, *resource_id);
            if (tile_set->shape->is_loaded() == 0) {
                tile_set->loaded = 0;
            }
            if ((long)tile_set->sound >= 0) {
                tile_set->sound = sounds[(long)tile_set->sound];
            } else {
                tile_set->sound = 0;
            }
        }
        resource_id -= 0x66;
        --count;
    } while (count != 0);

    if (filename2 != 0) {
        free(filename2);
    }
}
