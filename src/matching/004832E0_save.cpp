// VA: 004832E0 save (336B)
//
// Baseline reconstruction: serialize the database header, map table, and each
// map's four owned record blocks through the period rge_write surface.  The
// aggregate layouts are named and sized from the binary-backed map records.
// Attempt log:
// - Typed map-entry iteration was the initial clean source and matched all ten
//   rge_write targets but missed the original local frame.
// - Explicit controller/map-info ownership plus named per-record pointers
//   recovered the 0x10 frame, saved-register set, boundary, and call layout.
// - A diagnostic byte-offset cursor reproduced the remaining stack schedule
//   and reached a 22-byte mismatch, but was rolled back as raw cursor plumbing.
// - The clean source keeps typed map records and the natural counted loop;
//   VC5 emits the original frame and call topology without a byte cursor.
// Fresh pass:
// - Restored the prior byte-offset reconstruction as a diagnostic frontier. It
//   still matches the frame, size, CFG, calls, and 86.51% of exact blocks;
//   drift is 22 bytes in the land and terrain payload arithmetic blocks.
// - Literal and reversed multiplication, pointer locals, compound byte-count
//   assignment, direct member access, first-element address, and void-pointer
//   ABI probes did not change the 22-byte output. Direct member access regressed
//   to a 0x14 frame and 347-byte function.
// - A focused 12-case land/terrain source lab produced one invariant codegen
//   group. No exact candidate appeared. Restored this typed record source.
// - Final blocker is localized VC5 register coloring in map-base setup and the
//   land/terrain payload calls; no source variant moved the 22-byte drift.
// Fresh pass:
// - Dossier, same-TU donors, and ABI evidence confirm the 0x48 map stride,
//   0x2C/0x18 serialized payload records, and all ten ordered rge_write calls.
// - Replaced the controller byte arrays with named fixed-size module
//   aggregates.  VC5 emitted the same typed-iterator basin; raw byte cursors
//   remain excluded from the living source.
// Fresh pass:
// - Replayed the 22-byte frontier, then tested direct member, pointer type,
//   map-add operand, and arithmetic declaration variants. All emitted one
//   invariant group and were rolled back or reduced to this typed source.
// - A gated 24-case land/terrain lab also produced one 336-byte group with
//   10/10 calls and the 0x10 frame. No exact candidate appeared.
// - Fresh claim: named payload locals worsened to 29 bytes; reversed size
//   operands, opaque payload pointers, map-expression operand order, TU
//   stdlib context, and long index type did not change the 22-byte frontier.
//   Using data->maps regressed the frame to 0x0C. Restored this clean source.
// Fresh pass:
// - Original symbol decoration proves save is nonvirtual (QAEEH).  The source
//   now uses that member form; emitted bytes remain unchanged.
// - Reviewed typed base declarations and member order did not change output.
// - A gated 54-case lab varied map addition and payload size forms.  It found
//   two groups, 18 invariant variants, and no exact result.  The clean group
//   remains 336 bytes with a 22-byte mismatch.
// Fresh revisit:
// - Valid commuted pointer arithmetic, typed maps[map_index], map references,
//   full same-TU virtual declarations, and void payload pointers stayed in the
//   same 336-byte group.  No exact candidate appeared.
// Fresh revisit:
// - Direct typed subrecord expressions, without a map-entry local, match the
//   original map-base and payload register colors.  The mismatch is now 10
//   bytes and one pre-loop zero-store/branch schedule hunk.
// - The previous do-while form left the zero store after the map-count branch.
// Exact-finish:
// - Replaced the redundant inner positive-count guard and do-while with a
//   natural counted for loop. The map counter stays separate from the typed
//   map index. This restores the original zero-store order.
// - Moved both counter updates into the for increment list. This is an exact
//   source reduction with no emitted-code change.
// - Fresh authoritative check: MATCH, 336 bytes, 0.0000%, exact owner symbol,
//   0x10 frame, 10 ordered rge_write calls, and the original return boundary.
// - Reverting the counted loop to the prior guarded do-while restores the
//   10-byte mismatch at +004E. The counted loop is required for exactness.
// BINARY NOTE: The private map counter is initialized before the second
// positive-count branch. The shipped exit path does not read its value.

extern "C" {
    void rge_write(int file, void* data, int size);
}

#include "../../include/rmm_dbct_context.h"

unsigned char RGE_RMM_Database_Controller::save(int file)
{
    int file_handle = file;
    RGE_RMM_Database_Controller* controller = this;
    RGE_Map_Data* data = &controller->map_info;
    int local_10;

    rge_write(file_handle, data, 8);

    if (data->map_num > 0) {
        rge_write(file_handle, controller->map_info.maps,
                  data->map_num * sizeof(RGE_Map_Data_Entry));
        local_10 = 0;
        for (int map_index = 0; local_10 < data->map_num;
             ++local_10, ++map_index) {
            RGE_Land_Data* land_info =
                &controller->map_info.maps[map_index].land_info;
            RGE_Terrain_Data* terrain_info =
                &controller->map_info.maps[map_index].terrain_info;
            RGE_Object_Data* object_info =
                &controller->map_info.maps[map_index].object_info;
            RGE_Elevation_Data* elevation_info =
                &controller->map_info.maps[map_index].elevation_info;

            rge_write(file_handle, land_info, sizeof(RGE_Land_Data));
            if (land_info->land_num > 0) {
                rge_write(file_handle, land_info->land,
                          land_info->land_num * sizeof(RGE_Land_Data_Entry));
            }

            rge_write(file_handle, terrain_info, sizeof(RGE_Terrain_Data));
            if (terrain_info->terrain_num > 0) {
                rge_write(file_handle, terrain_info->terrain,
                          terrain_info->terrain_num * sizeof(RGE_Terrain_Data_Entry));
            }

            rge_write(file_handle, object_info, sizeof(RGE_Object_Data));
            if (object_info->object_num > 0) {
                rge_write(file_handle, object_info->objects,
                          object_info->object_num * sizeof(RGE_Object_Data_Entry));
            }

            rge_write(file_handle, elevation_info, sizeof(RGE_Elevation_Data));
            if (elevation_info->elevation_num > 0) {
                rge_write(file_handle, elevation_info->elevation,
                          elevation_info->elevation_num * sizeof(RGE_Elevation_Data_Entry));
            }

        }
    }

    return 1;
}
