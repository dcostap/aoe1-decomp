// VA: 004C0C90 RGE_Sprite::hit_test(short, short, long, long)
// sprite.cpp
//
// Attempt log:
// - Established the RGE_Sprite box/draw-list/facet ownership and the
//   binary-observed 16-byte picture-list stride.
// - A nested box-presence guard plus an explicit while scan reproduces the
//   original size, frame, ordered calls, and branch topology.
// - The remaining mismatch is VC5 register/liveness coloring in the scan;
//   raw cross-member cursor experiments improved bytes only marginally and
//   were restored to this typed entry form.
// This pass tested a named draw-list base, a materialized parent facet
// denominator, and a typed pointer-increment scan. The normalized typed walk
// is the living source (137-byte diff); the raw-cursor 124-byte result remains
// diagnostic history only. Remaining drift starts at child-entry coloring.
// Follow-up bounded pass: a top-level byte index restored the original early
// EBX zero and improved the emitted diff to 124 bytes, but all base/member
// cursor spellings remained in the same VC5 basin. Function-scope pointer and
// counter declarations, delayed entry materialization, and a byte-buffer
// cursor were nonproductive or duplicate-codegen probes. A six-variant local
// shape lab found no exact candidate; its best raw indexing form was rejected
// as noncanonical. Restored the typed source below; residual drift is the
// original child-entry register/liveness schedule.
// Main-agent audit confirmed typed 0x10-byte picture-entry traversal and child
// sprite ownership; no byte cursor survives.
// Fresh orch-sprite-02 probe 1 supersedes that paused diagnostic source: retain
// the original base-plus-byte-index form, but load the draw-list base through
// repeated direct member expressions. This matches 230/230 bytes exactly.
// The raw-looking cursor is kept because the oracle proves EBX byte offsets,
// repeated draw_list base loads, and the source decomp uses the same period
// pointer-to-member arithmetic; no asm or compiler-only scaffolding is used.
// Sprite group audit: the standalone owner is exact. With the preceding
// 004C04F0 owner in PDB order, only the child-entry SIB base/index bytes drift;
// the typed calls, stride, and all other bytes remain aligned. Natural address
// and typed-entry variants did not change this context-local pair.

#include "../../include/sprite_context.h"

unsigned char RGE_Sprite::hit_test(short x, short y, long facet, long value) {
    int index = 0;

    if (((this->box_x1 != 0) || (this->box_x2 != 0)) &&
        ((this->box_y1 != 0) || (this->box_y2 != 0))) {
        if ((x >= this->box_x1) && (x <= this->box_x2) &&
            (y >= this->box_y1) && (y <= this->box_y2)) {
            return 1;
        }
    }

    if ((this->draw_list_num > 0) && (this->draw_list != 0)) {
        int i = 0;
        if (this->draw_list_num > 0) {
            while (i < this->draw_list_num) {
                RGE_Sprite* sprite =
                    *(RGE_Sprite**)((char*)&this->draw_list->sprite + index);
                if (sprite->shape_hit_test(
                        x - *(short*)((char*)&this->draw_list->offset_x + index),
                        y - *(short*)((char*)&this->draw_list->offset_y + index),
                        (sprite->facet_num * facet) / (int)this->facet_num,
                        value)) {
                    return 1;
                }
                index += 0x10;
                i++;
            }
        }
        return 0;
    }

    return this->shape_hit_test(x, y, facet, value);
}
