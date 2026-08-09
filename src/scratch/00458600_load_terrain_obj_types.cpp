// VA: 00458600 RGE_Map::load_terrain_obj_types
// map.cpp:1916-1942
//
// Binary-supported reconstruction: read the terrain-object table from the
// text stream, retain only loaded terrain sets with fewer than 30 entries,
// then store object type, density, placement flag, and increment the count.
// The first header value is read into a dead four-byte local; VC5 can reuse
// that home for the live object-count value later in the loop.
//
// Attempt log:
// - Initial scaffold only opened a file and stored its descriptor; it was not
//   behaviorally complete and did not represent the fscanf/table loop.
// - Baseline natural fopen/fscanf reconstruction aligned all five calls and
//   the frame but cached a terrain record and emitted only 250 bytes.
// - Repeated direct terrain_types indexing recovered the target's recomputed
//   record-address family (354 bytes, 206 differing bytes).
// - Reusing the dead header long as a count diagnostic reached exact size and
//   134 differing bytes, but is not a canonical source model; rolled back.
// - Final clean source keeps named loaded/object-type/density/placement/count
//   ownership; remaining gap is count spill/register and body block layout.

#include <stdio.h>

class RGE_Tile_Set {
public:
    unsigned char loaded;
    char gap_01[0xFD];
    short obj_types[30];
    short obj_density[30];
    unsigned char obj_placement_flags[30];
    short num_obj_type;
    char gap_196[2];
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[0x88];
    RGE_Tile_Set terrain_types[32];
    char gap_338C[0x5A00];
    void* map_row_offset;

    void load_terrain_obj_types(char* filename);
};

void RGE_Map::load_terrain_obj_types(char* filename)
{
    FILE* file = fopen(filename, "r");

    if (file != 0) {
        long version;
        short placement_flag;
        short density;
        short object_type;
        short terrain_id;

        fscanf(file, "%hd", &version);
        while (fscanf(file, "%hd %hd %hd %hd",
                      &terrain_id, &object_type, &density,
                      &placement_flag) != EOF) {
            if (this->terrain_types[terrain_id].loaded != 0) {
                if (this->terrain_types[terrain_id].num_obj_type < 30) {
                    this->terrain_types[terrain_id].obj_types[
                        this->terrain_types[terrain_id].num_obj_type] = object_type;
                    this->terrain_types[terrain_id].obj_density[
                        this->terrain_types[terrain_id].num_obj_type] = density;
                    this->terrain_types[terrain_id].obj_placement_flags[
                        this->terrain_types[terrain_id].num_obj_type] =
                        (unsigned char)placement_flag;
                    ++this->terrain_types[terrain_id].num_obj_type;
                }
            }
        }
    }

    fclose(file);
}
