// 00482B70 RGE_RMM_Database_Controller(char*,char*,char*,char*)
// Clean reconstruction: load the map database and its three owned record tables.
// The map records use the period RGE data layouts proved by the executable.
// Attempt log:
// - Replaced guessed aggregate offsets with the proven RGE map-data layouts.
// - Positive count guards restored the executable's zero-compare CFG and most
//   ordered call alignment.
// - Land, terrain, and object records use their named fields and owned arrays.
// - Remaining drift is register coloring, stack-home reuse, and map-load CFG
//   and size after the bounded hypotheses.
// - Independent positive-load and nonpositive-fallback guards restore all 28
//   ordered calls, including both map-file fclose sites; the extra predicate
//   leaves a 13-byte size overrun and one CFG edge mismatch.
// - Structural probes inverted the initial fopen guard and moved the positive
//   map-load jump before the fallback reset/close. This aligns the first map
//   CFG and all 28 calls; residual drift starts in register coloring and later
//   loop scheduling.
// - Reused one offset local across all record scans; this was codegen-neutral.
// - Kept the map pointer reset in the nonpositive count arm; this moved the
//   mismatch from 840 to 835 bytes and restored the two map fallback blocks.
// - Integer and FILE-pointer CRT surfaces were codegen-neutral; keep the
//   period _iobuf pointer form as the clean source.
// - Replaced persistent record-entry pointer locals with direct typed array
//   members. The original reloads each record base before its stores.
// - Moved record-count increments after the named field stores. This restores
//   the original 395-instruction topology, 97.22% shape, and +8-byte size.
// - A separate map handle, virtual declaration surface, and counter reset
//   were codegen-neutral or worse; the direct typed-array form is retained.
// - Fresh claim: twenty evidence-led probes tested declaration order, scalar
//   widths, register hints, counter lifetimes, typed cursor and owner aliases,
//   map-entry locals, CRT headers, and equivalent member lvalues. The clean
//   code stayed at 1193 bytes with 28 aligned calls and a 0x34 frame; cursor
//   and owner aliases worsened the frame or code shape. The remaining blocker
//   is VC5 register coloring: the original starts the zero/index path in ESI
//   and the clean source starts it in EBX, then the original has an 8-byte
//   shorter fallback/record-tail layout. The pinned clean source is restored.
// - Fresh probes tested nonpositive allocation guards, a counter-fed zero
//   store, a separate map stream, a proven byte-stride land cursor, and the
//   neighboring controller class surface. The guard form reached the target
//   size but inverted two branch tails. Other forms were neutral or worse.
//   The clean typed source is restored; no source drift is accepted.
// - Continuation probes kept the canonical dbct source owner. Replacing its
//   declarations with the protected rmm_cntr context did not change output.
//   Period stdio/stdlib headers, register hints, declaration initializers,
//   count-guard lvalues, and narrow local4 spelling did not improve the
//   1193-byte / 790-byte mismatch. A scoped typed land-entry alias improved
//   structural similarity but changed the proven direct-store topology and
//   was restored.
// Context audit: this unresolved owner now uses the canonical rmm_dbct base,
// controller, and map-record declarations. The complete prefix wrapper keeps
// its 8-byte boundary overrun isolated and preserves all later exact anchors.
// Continuation boundary pass:
// - Reversing the terrain and object guards to `count <= 0` first reduced the
//   code to the original 1185-byte boundary, but it reversed the PDB-supported
//   source tail order and changed two CFG edges. The natural positive guards
//   remain authoritative.
// - The canonical group boundary is therefore 00482B70-00483010 for this
//   unresolved owner. Later exact anchors remain valid in the complete wrapper.
// Captain context pass: PDB module, source bands, class ownership, address
// order, boundaries, and exact anchors are recorded in the captain packet.
// Captain probe: the PDB-shaped declaration order for record pointers,
// counters, and FILE was codegen-neutral at 1193 bytes and 790 diff bytes.
// Captain probe: a controller self-alias reduced size to 1187 bytes, but
// worsened the strict diff to 1074 bytes and lost an exact block. It was
// restored.
// BLOCKER: The remaining basin is the EBX/ESI register swap and an 8-byte
// fallback/record-tail size difference. The target keeps 28 ordered calls and
// an exact 0x34 frame, but no current source form proves the target coloring.

struct _iobuf;
extern "C" _iobuf* __cdecl fopen(const char*, const char*);
extern "C" int __cdecl fclose(_iobuf*);
extern "C" int __cdecl fscanf(_iobuf*, const char*, ...);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);

#include "..\..\include\rmm_dbct_context.h"

RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(
    char* terrain_file, char* object_file, char* terrain_type_file, char* map_file)
    : RGE_Random_Map_Module(0, 0, 0)
{
    int index;
    index = 0;
    _iobuf* infile;
    RGE_Land_Data* land_info;
    RGE_Terrain_Data* terrain_info;
    RGE_Object_Data* object_info;
    int local_30;
    int land_index;
    long terrain_num;
    long object_num;
    long temp_terrain_type;
    long temp_zone;
    long temp_placement_type;
    long temp_amount_of_land_used_percent;
    long temp_by_player_flag;
    long temp_group_flag;
    long temp_scale_flag;
    unsigned char local_4[4];
    int offset;

    this->world = 0;
    this->map_type = -1;
    this->number_of_players = 0;
    infile = fopen(map_file, "r");
    if (infile != 0) {
        fscanf(infile, " %d", &this->map_info);
        if (this->map_info.map_num > 0) {
            this->map_info.maps = (RGE_Map_Data_Entry*)calloc(this->map_info.map_num, 0x48);
            if (this->map_info.map_num > 0) {
                index = 0;
                offset = 0;
                do {
                    fscanf(infile, "%d", (char*)this->map_info.maps + offset);
                    ++index;
                    offset += 0x48;
                } while (index < this->map_info.map_num);
                index = 0;
                fclose(infile);
                goto map_database_loaded;
            }
        } else {
            this->map_info.maps = 0;
        }
        fclose(infile);
    } else {
        this->map_info.maps = 0;
        this->map_info.map_num = 0;
    }

map_database_loaded:
    if (this->map_info.map_num > 0) {
        infile = fopen(terrain_file, "r");
        if (infile != 0) {
            fscanf(infile, "%d", &terrain_num);
            index = 0;
            if (terrain_num > 0) {
                do {
                    fscanf(infile, "%d", &local_30);
                    land_info = &this->map_info.maps[local_30].land_info;
                    fscanf(infile, "%d %d %d %d %d %d %d %d %d",
                           &land_info->land_num,
                           &land_info->map_edge_buffer[0],
                           &land_info->map_edge_buffer[1],
                           &land_info->map_edge_buffer[2],
                           &land_info->map_edge_buffer[3],
                           &land_info->map_edge_fade,
                           &land_info->land_placement_edge,
                           &land_info->base_terrain,
                           &land_info->grown_land_percent);
                    if (land_info->land_num > 0) {
                        land_info->land = (RGE_Land_Data_Entry*)calloc(land_info->land_num, 0x2c);
                        land_index = 0;
                        if (land_info->land_num > 0) {
                            do {
                                fscanf(infile,
                                       "%d %d %d %d %d %d %d %d %d %d %d %d",
                                       &land_info->land[land_index].land_id,
                                       &temp_zone,
                                       &land_info->land[land_index].land_avoidance_tiles,
                                       &land_info->land[land_index].base_square_radius,
                                       &temp_placement_type,
                                       &temp_amount_of_land_used_percent,
                                       &land_info->land[land_index].x,
                                       &land_info->land[land_index].y,
                                       &temp_by_player_flag,
                                       &temp_group_flag,
                                       &land_info->land[land_index].radius,
                                       &land_info->land[land_index].fade);
                                land_info->land[land_index].terrain_type = (unsigned char)temp_zone;
                                land_info->land[land_index].zone = (unsigned char)temp_placement_type;
                                land_info->land[land_index].placement_type =
                                    (unsigned char)temp_amount_of_land_used_percent;
                                land_info->land[land_index].amount_of_land_used_percent =
                                    (unsigned char)temp_by_player_flag;
                                land_info->land[land_index].by_player_flag = (unsigned char)temp_group_flag;
                                land_info->land[land_index].clumpiness_factor = 8;
                                ++land_index;
                            } while (land_index < land_info->land_num);
                        }
                    } else {
                        land_info->land = 0;
                    }
                    ++index;
                } while (index < terrain_num);
            }
            fclose(infile);
        }

        infile = fopen(object_file, "r");
        if (infile != 0) {
            fscanf(infile, "%d", &object_num);
            index = 0;
            if (object_num > 0) {
                do {
                    fscanf(infile, "%d", &local_30);
                    terrain_info = &this->map_info.maps[local_30].terrain_info;
                    fscanf(infile, "%d", terrain_info);
                    land_index = 0;
                    if (terrain_info->terrain_num > 0) {
                        terrain_info->terrain =
                            (RGE_Terrain_Data_Entry*)calloc(terrain_info->terrain_num, 0x18);
                        if (terrain_info->terrain_num > 0) {
                            do {
                                fscanf(infile, "%d %d %d %d %d",
                                       &terrain_info->terrain[land_index].terrain_percent,
                                       &terrain_info->terrain[land_index].terrain_type,
                                       &terrain_info->terrain[land_index].clumps,
                                       &terrain_info->terrain[land_index].spacing,
                                       &terrain_info->terrain[land_index].base_terrain_type);
                                terrain_info->terrain[land_index].clumpiness_factor = 0x14;
                                ++land_index;
                            } while (land_index < terrain_info->terrain_num);
                        }
                    } else {
                        terrain_info->terrain = 0;
                    }
                    ++index;
                } while (index < object_num);
            }
            fclose(infile);
        }

        infile = fopen(terrain_type_file, "r");
        if (infile != 0) {
            fscanf(infile, "%d", &temp_terrain_type);
            index = 0;
            if (temp_terrain_type > 0) {
                do {
                    fscanf(infile, "%d", &local_30);
                    object_info = &this->map_info.maps[local_30].object_info;
                    fscanf(infile, "%d", object_info);
                    land_index = 0;
                    if (object_info->object_num > 0) {
                        object_info->objects =
                            (RGE_Object_Data_Entry*)calloc(object_info->object_num, 0x2c);
                        if (object_info->object_num > 0) {
                            do {
                                fscanf(infile,
                                       "%d %d %d %d %d %d %d %d %d %d %d %d",
                                       &object_info->objects[land_index].obj_id,
                                       &object_info->objects[land_index].terrain,
                                       &temp_scale_flag,
                                       local_4,
                                       &object_info->objects[land_index].object_number_per_group,
                                       &object_info->objects[land_index].object_number_varience,
                                       &object_info->objects[land_index].number_of_groups,
                                       &object_info->objects[land_index].group_area,
                                       &object_info->objects[land_index].player_id,
                                       &object_info->objects[land_index].land_id,
                                       &object_info->objects[land_index].land_inner_radius,
                                       &object_info->objects[land_index].land_outer_radius);
                                object_info->objects[land_index].group_flag = (unsigned char)temp_scale_flag;
                                object_info->objects[land_index].scale_flag = local_4[0];
                                ++land_index;
                            } while (land_index < object_info->object_num);
                        }
                    } else {
                        object_info->objects = 0;
                    }
                    ++index;
                } while (index < temp_terrain_type);
            }
            fclose(infile);
        }
    } else {
        this->map_info.map_num = 0;
        this->map_info.maps = 0;
    }
}
