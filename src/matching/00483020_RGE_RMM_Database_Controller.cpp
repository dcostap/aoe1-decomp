// VA: 00483020 RGE_RMM_Database_Controller(int) (466B)
// rmm_dbct.cpp, EH-framed constructor (/GX)
//
// Baseline reconstruction: invoke the real random-map base constructor, read
// the map table, then allocate and read each owned land/terrain/object/elevation
// record block. The aggregate layouts are named and exact-sized; ownership is
// expressed with typed records rather than decompiler offsets.
// Attempt log:
// - The typed baseline established the real /GX base-constructor and all
//   sixteen calls, but missed the original local frame and map-record stride.
// - A diagnostic byte-offset record cursor recovered the 0x10 frame and exact
//   size; splitting the map load and reversing the tail updates reached a
//   32-byte emitted-code mismatch. It is not a valid living source surface.
// - The living source uses ordinary typed map-entry iteration. A shared map-entry
//   local left a localized 45-byte register/tail gap.
// - Direct typed member expressions for each map subrecord remove that gap and
//   produce the exact 466-byte function without raw cursor source.
// - A local RGE_Map_Data owner widened the gap to 130 bytes; rolled back.
// - For-loop spelling and a named land-size temporary produced unchanged code.
// - Reversing the map-count comparison made a 46-byte mismatch; the original
//   map_index < map_num spelling is retained.
// - Making the base destructor virtual to match the same-TU donor did not
//   change emitted code; the EH frame and first prologue hunk remain open.
// - Adding the derived virtual-destructor declaration to the same fresh TU
//   also left emitted code unchanged; no EH handler or frame appeared.
// - Naming a local RGE_Map_Data* for the aggregate moved 336 bytes and made
//   the size three bytes shorter, so the member-based clean form is restored.
// - Pointer induction and raw byte-cursor forms are diagnostic evidence only.
// Exact-finish:
// - A fresh /GX rebuild matches 466 bytes, the 0x10 frame, all 16 ordered
//   calls, the EH owner symbol, and the original boundary.
// - Reverting the direct typed subrecord expressions to one shared map-entry
//   local restores a 45-byte mismatch at the loop tail. The direct expressions
//   are required. The exact source was restored after this walkback.
// Context audit: this owner now uses the canonical rmm_dbct/rmm_obj random-map
// base surface. Its PDB module is rmm_dbct.cpp and its address precedes the
// target and all later dbct owners.

#include <stdlib.h>
#include "..\..\include\rmm_dbct_context.h"

extern void __cdecl rge_read(int file, void* data, int size);

RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(int file)
    : RGE_Random_Map_Module(0, 0, 0)
{
    this->world = 0;
    this->map_type = -1;
    this->number_of_players = 0;

    rge_read(file, &this->map_info, 8);
    if (this->map_info.map_num > 0) {
        this->map_info.maps = (RGE_Map_Data_Entry*)calloc(
            this->map_info.map_num, sizeof(RGE_Map_Data_Entry));
        rge_read(file, this->map_info.maps,
                 this->map_info.map_num * sizeof(RGE_Map_Data_Entry));

        for (int map_index = 0;
             map_index < this->map_info.map_num;
             ++map_index) {
            RGE_Land_Data* land_info =
                &this->map_info.maps[map_index].land_info;
            RGE_Terrain_Data* terrain_info =
                &this->map_info.maps[map_index].terrain_info;
            RGE_Object_Data* object_info =
                &this->map_info.maps[map_index].object_info;
            RGE_Elevation_Data* elevation_info =
                &this->map_info.maps[map_index].elevation_info;

            rge_read(file, land_info, sizeof(RGE_Land_Data));
            if (land_info->land_num > 0) {
                land_info->land = (RGE_Land_Data_Entry*)calloc(
                    land_info->land_num, sizeof(RGE_Land_Data_Entry));
                rge_read(file, land_info->land,
                         land_info->land_num * sizeof(RGE_Land_Data_Entry));
            }

            rge_read(file, terrain_info, sizeof(RGE_Terrain_Data));
            if (terrain_info->terrain_num > 0) {
                terrain_info->terrain = (RGE_Terrain_Data_Entry*)calloc(
                    terrain_info->terrain_num, sizeof(RGE_Terrain_Data_Entry));
                rge_read(file, terrain_info->terrain,
                         terrain_info->terrain_num * sizeof(RGE_Terrain_Data_Entry));
            }

            rge_read(file, object_info, sizeof(RGE_Object_Data));
            if (object_info->object_num > 0) {
                object_info->objects = (RGE_Object_Data_Entry*)calloc(
                    object_info->object_num, sizeof(RGE_Object_Data_Entry));
                rge_read(file, object_info->objects,
                         object_info->object_num * sizeof(RGE_Object_Data_Entry));
            }

            rge_read(file, elevation_info, sizeof(RGE_Elevation_Data));
            if (elevation_info->elevation_num > 0) {
                elevation_info->elevation = (RGE_Elevation_Data_Entry*)calloc(
                    elevation_info->elevation_num, sizeof(RGE_Elevation_Data_Entry));
                rge_read(file, elevation_info->elevation,
                         elevation_info->elevation_num * sizeof(RGE_Elevation_Data_Entry));
            }
        }
    }
}
