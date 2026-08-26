// VA: 0053CCF0 RGE_Visible_Map::unexplore_terrain_sq
// Source: visible.cpp lines 891-975
// Attempt log:
// baseline candidate: canonical visible-map/world/player/map layout and the natural
// paired unexplore loop; tile advances are unconditional as in the executable.
// self alias plus absolute global surfaces improved relocation/edit alignment but
// did not change the default emitted structure.
// /Oy- reproduced the 381-byte size and moved the frame/register basin closer,
// but still lacked the original two-slot frame and was rolled back as a flag crutch.
// Named width/height and negative-return/control-flow variants were nonproductive.
// Typed unified_map_offsets[256] and full visible.cpp world/player/map/tile record
// surfaces were emitted identically to the clean candidate. A separate typed
// checksum accumulator was likewise optimized to the same code.
// A natural start-column local reached exact size but retained the wrong register
// basin (339 positional bytes); a start-row local improved edit/resync similarity
// to 59.06% and 354 positional bytes, yet still omitted the original EBP frame and
// parameter-home topology. Delaying the self owner made no further change.
// Those source-shape experiments were diagnostic only and were restored.
// This session: hoisted row cursors, reused a function-scope inner count, and
// added string.h context; each emitted the clean 356-byte code unchanged.
// An ordinary self/reference alias for the late mask reload was likewise
// optimized away. A contiguous typed self/tile local aggregate forced an 8-byte
// stack allocation and a 363-byte result but not the oracle's EBP frame, and
// reversing its member order plus old-TU top-level scan locals was unchanged;
// those layout probes were restored.
// Direct this-member ownership in the coordinate loop, guided by the binary's
// saved this while EBX is reused for tile access, was codegen-identical and
// restored; the persistent alias is not the EBP/local-home cause.
// This claim tested post-call self setup, a pointer-to-pointer self home,
// visible.cpp LOS declarations, inverted suppression nesting, a y1 reference,
// x1 register qualification, and local declaration order. All natural probes
// were codegen duplicates; the row-cursor probe changed structure but not the
// frame basin and was restored. A volatile p6 home was diagnostic only and was
// also restored. The next useful evidence is a donor-level VC5 TU or ABI
// context that explains the original EBP/local-home allocation.
// Revisit claim: restoring the proven RGE_Map prefix, splitting the tile zero
// declaration, using a typed owner reference, typed row indexing, and normal
// C++ linkage for log_map_call all emitted the clean 356-byte basin unchanged.
// An explicit outer while loop reached 360 bytes but changed the CFG and still
// lacked the oracle frame, so it was restored. Typed map ownership and the
// natural paired row/column traversal remain authoritative.
// Left in scratch: default code is 25 bytes short with broad prologue/register
// drift; canonical behavior and field ownership are stable, but source/ABI context
// still needs a donor-level explanation for the original EBP/local topology.
// Current claim: assignment-then-decrement upper clamps and a stdio include were
// codegen duplicates. The original EBP frame and separate self/tile homes remain.
// Authentic TU context gate (proved unless marked otherwise): PDB module is
// C:\\msdev\\work\\age1_x1\\visible.cpp. This owner occupies source lines
// 891-975, with the ordered bands 891, 902, 905, 909, 913-924, 927, 931-940,
// 943-975. Its address sequence is 0053CCF0-0053CE6A; the next visible.cpp
// owner begins at 0053CE70. The class owner is RGE_Visible_Map and the exact
// symbol is ?unexplore_terrain_sq@RGE_Visible_Map@@QAEXHHHHHH@Z with __thiscall
// cleanup ret 18h. Anchors are the visible_tu.cpp include at this address,
// visible_tu_context.h's RGE_Visible_Map layout, direct log_map_call at
// 0053CD30 -> 0053D150, and the observed accesses to this+04/+08/+0C/+14/
// +18/+34 plus map_offsets, unified_map_offsets, and map_row_offset. The
// neighboring address order 0053C6F0, 0053C920, 0053CAC0, 0053CCF0, 0053CE70
// proves one contiguous visible.cpp source band. Any source-order explanation
// for the EBP/local-home difference remains unknown; no dummy context is used.
// Resume probes: splitting self/tile declaration from assignment was a codegen
// duplicate (356 bytes, 361 strict differences, no frame). A const-qualified
// self pointer was also a codegen duplicate with the same metrics. Both failed
// experiments were restored to the pinned natural source.
// Accepted-drift audit: do not promote this candidate. The original has an
// 0x08 local frame at log_map_call, while the rebuild has none. The logger
// therefore receives a different stack and exception context before any map
// checksum or visibility update.

#include "../../include/visible_context.h"

void RGE_Visible_Map::unexplore_terrain_sq(int x1, int y1, int x2, int y2,
                                           int update_tiles, int p6)
{
    RGE_Visible_Map* self = this;
    RGE_Tile* tile = 0;

    log_map_call(self->world->world_time, (int)self->player->id, 4, p6,
                 x1, y1, x2, y2, Map_Update_Suppresion);

    if (Map_Update_Suppresion == 0) {
        p6 = self->input_csum;
        p6 = _rotl(p6, 3);
        p6 ^= 0x56565656;
        p6 = _rotl(p6, 2);
        p6 ^= x1;
        p6 = _rotl(p6, 4);
        p6 ^= y1;
        p6 = _rotl(p6, 3);
        p6 ^= x2;
        p6 = _rotl(p6, 3);
        p6 ^= y2;
        self->input_csum = p6;

        if ((x1 >= self->widthValue) || (x2 < 0) ||
            (y1 >= self->heightValue) || (y2 < 0)) {
            return;
        }
        if (x1 < 0) {
            x1 = 0;
        }
        if (x2 >= self->widthValue) {
            x2 = self->widthValue - 1;
        }
        if (y1 < 0) {
            y1 = 0;
        }
        if (y2 >= self->heightValue) {
            y2 = self->heightValue - 1;
        }

        for (; y1 <= y2; ++y1) {
                unsigned char* visible = self->map_offsets[y1] + x1;
                unsigned long* explored = unified_map_offsets[y1] + x1;

                if (update_tiles != 0) {
                    tile = self->map->map_row_offset[y1] + x1;
                }

            if (x1 <= x2) {
                int count = x2 - x1 + 1;
                do {
                    unsigned char value = *visible;
                    --value;
                    if (value == 0xff) {
                        value = 0;
                    }
                    if (value == 0) {
                        if (update_tiles != 0) {
                            tile->flags_09 = 0x80;
                        }
                        *explored &= self->PlayerVisibleMaskInvertValue;
                    }
                    *visible = value;
                    ++visible;
                    ++explored;
                    ++tile;
                    --count;
                } while (count != 0);
        }
    }
}
}
