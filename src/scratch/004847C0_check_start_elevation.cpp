// VA: 004847C0 RGE_RMM_Elevation_Generator::check_start_elevation (224 bytes)
// Source: rmm_elev.cpp lines 64-95
//
// Checks that every 24-byte cell in the rectangle [x-range..x+range] x
// [y-range..y+range] (clamped to the map) has terrain bits matching `terrain`
// and elevation bits >= `elevation`. Returns 0 on the first mismatch.
//
// Attempt log:
// 1: natural indexed access this->tiles[row][col*24+5]; this spilled to ebp, tiles[row] recomputed per cell (201B).
//    -> switched to per-row cell pointer with 24-byte stride (count_map_tiles idiom).
// 2: pointer idiom; first hunk is y1/x1 compute order (orig computes y1 before x1, reusing edi=y).
// 3: y1-before-x1 fixed; still homes y1 in arg1 (orig: arg5) and loop setup lands after the
//    guard (orig hoists first-row setup before guard, short jg).
// 4: named `long offset = x0*24` local: worse (saved this early to [esp+10h], ecx stolen for x1).
// 5: named `char* row_base` local: shifted all register roles (x0=edi etc.), worse prologue.
// 6: explicit while loops with row_ptr + cell pointer (next-row base loaded at loop bottom).
//    -> exact 224B size, clean natural baseline (diff 148B / 66.07%, 170 equal bytes).
// 7: declare x1 before y1 (y1 last) but assign y1 before x1: identical codegen (0 bytes changed).
// 8: focused loop-shape lab (while/do/direct-row-base/preloaded-cell forms): no exact variant;
//    the best family used an inner nonempty-row guard (diff 144B, 160 equal bytes).
// 9: direct dword access to the proven dead `range` home improved stack-slot coloring but
//    emitted the same 144B family; volatile access added 3 bytes and was rolled back.
// 10: top-declared offset/row/row_ptr plus the natural inner guard reproduced the same 144B
//     family; preloading a named row base is the current natural source (diff 142B / 163 equal).
//
// Left in scratch: remaining drift is localized.
//  - +0025: y1 homed in arg1 [esp+18h]; original homes it in arg5 [esp+28h] (the dead `range`
//    param slot). Same-TU exact donor remove_area_from_lists (00484C80) needed explicit
//    `x = end; radius = start_y;` param reassignment to recover param-slot homes; this
//    function's range param is uchar, so a dword y1 store cannot reuse it via assignment.
//  - +0045..: loop shape: original peels first rowBase load before the outer guard and carries
//    rowBase+offset in eax (loaded via `add eax,[edi]` in the row_inc); rebuilt loads rowBase
//    at the outer-loop top and keeps rowPtr homed in a slot. y1 slot choice drives the other
//    slot rotations (row arg1->arg2, rowPtr arg2->arg5).
// Paused: exact matching budget exhausted. Current source keeps canonical named row-base
// ownership; remaining drift is the y1/row/row_ptr stack-home rotation and first-row setup.
// Subsequent claim evidence: restoring the exact sibling inherited map/TILE declaration
// surface was codegen-identical; using y0 directly, typed tile bitfields, predicate byte
// locals, and alternate natural declaration orders were either worse or duplicate.
// Keep this clean row-base source. The original keeps x1 in EBX/uses CL for the tile mask,
// while this basin spills x1 and uses BL; its y1/row/row_ptr home rotation remains unresolved.
// Main-agent audit retained canonical elevation-map ownership and replaced the
// residual char casts with a typed byte-row traversal.
// Continuation (sa-ab4dd300-r1): the exact rmm_base/rmm_elev/rmm_terr base and
// 24-byte tile declaration surface was restored; emitted code was identical.
// Deriving the initial row-table pointer from the named row counter was also
// identical. Reusing the now-dead x parameter as the outer row counter is a
// binary-supported stack-home hypothesis: it moves the row counter to arg[0]
// and improves the current reconstruction to 141 differing bytes / 84.38%
// shape. Reversing bound declaration/assignment order and late-declaring y1
// were neutral or worse; naming the tile byte regressed to 191 bytes.
// Keep the readable x-row-counter source; y1/row-pointer home rotation and
// the original CL-vs-BL predicate coloring remain unresolved.
// Current claim: x1-before-y1 initialization moved the first mismatch earlier
// and was rolled back; declaring bounds before row locals was codegen-identical.
// Inverting the natural all-good tile predicate was also identical, while an
// explicit initial empty-range return plus do/while row loop broadened the CFG.
// A four-variant bound-declaration lab reproduced only the 141-byte or worse
// 146-byte families; no y1 range-home rotation was found.
// Continuation (orch-rmmelev-01):
// 11: reusing x as clipped x1 with a separate row counter worsened to 214 bytes.
// 12: a for-header row increment improved late edit alignment but worsened strict
//     bytes to 172; the outer empty-range do/while reproduced the prior 169-byte
//     family and was rolled back.
// 13: the exact rmm_elev class/TU declarations and full tile/info surface were
//     restored; codegen was identical. Comma-grouped bound declarations were also
//     identical.
// 14: a typed row-pointer seed/base/cell surface lab found no new basin; the clean
//     141-byte row-base source remains best. Restore it before final validation.
// Left unresolved: original y1 uses the dead range home, x1 remains in EBX, and
// row_ptr is homed in the y parameter slot so ECX can mask the tile byte; current
// natural VC5 allocation rotates those homes/registers despite exact size, CFG
// counts, and canonical map-row ownership.
// Continuation (wave21-rmmelev-01):
// 15: an explicit initial empty-range return plus infinite outer loop with a
//     bottom success return broadened to 169 bytes; rolled back.
// 16: carrying the row-table pointer in the dead y parameter home was binary-
//     motivated but codegen-identical to the clean basin; rolled back.
// 17: a scoped col_end copy of x1 and 18: separate nested tile-failure guards
//     were both codegen-identical; no liveness/CFG change.
// 19: swapped the natural inner induction statements to `++col` then
//     `cell += 24`, matching the oracle's inc-before-add order. Strict diff
//     stayed 141, but shape improved 84.38% -> 85.42% and edit diff 95 -> 94;
//     retain this period-plausible source order.
// 20: an explicit next_row compare before writing the reused x home broadened
//     to 174 bytes / 73.00% shape; rolled back.
// 21: an address-taken y-home alias was codegen-identical to the clean basin;
//     rolled back. A nine-variant row-pointer type/expression lab (22) found
//     only the typed duplicate basin; dword/byte cross-type variants did not
//     compile. Remaining blocker is the original y1/range-home, row_ptr/y-home,
//     x1/EBX, and CL-vs-BL allocation rotation, not tile/map ownership.

// Continuation (sa-1b774ae7-r1):
// 23: moving the column initializer before the inner guard broadened to 185 bytes;
// rolled back. A natural row-base-before-counter update improved late alignment
// but broadened to 172 bytes; rolled back.
// 24: a focused 20-variant declaration/predicate lab found no exact group; the
// closest valid direct-predicate family remained 141 bytes. Invalid nested
// predicate forms that skip the required terrain==FF failure were not retained.
// 25: `register long x1` was codegen-identical. A natural long radius promotion
// worsened to 142 bytes; rolled back. A counted inner for-loop was same-size but
// no closer. Address-taking row_ptr through a typed pointer alias was duplicate.
// 26: function-scope column lifetime likewise broadened to 185 bytes; rolled back.
// Final blocker remains a VC5 allocation basin: original homes y1 in dead range,
// spills row_ptr to the y home, keeps x1 in EBX, and uses CL for the tile mask;
// the clean typed row-base source homes y1/x1 oppositely, keeps row_ptr in ECX,
// and uses BL. Exact size/CFG/canonical map ownership remain stable.
// Continuation (follow-4847C0-r1):
// 27: assigning the offset after the row seed worsened to 143 bytes; rolled back.
// 28: declaring the inner column before cell worsened to 144 bytes; rolled back.
// 29: carrying a typed RGE_Tile row base worsened to 146 bytes; rolled back.
// 30: an if-plus-do outer loop broadened to 169 bytes; rolled back.
// 31: carrying cell across rows worsened to 163 bytes and changed the prologue;
//     rolled back. 32: seeding row_ptr from y0 directly is codegen-identical.
// Clean source retained: natural typed byte-row ownership and while/do scan.
// Validation remains 224 bytes, 141 differing bytes, 85.42% shape. The blocker
// remains the original y1/range-home and row-pointer/byte-register allocation.
// Continuation (shardE-4847C0): promoting the uchar range parameter to long
// with an explicit 0xFF mask duplicated an earlier ABI probe and worsened the
// strict diff to 142 bytes; rolled back.

// Fresh reassessment: spelling the initial row seed with x0 * 24 instead of
// the named offset, and swapping the row-base/table local declarations, both
// rebuilt to the same 224-byte/141-difference code. Both were rolled back.

// Continuation (sa-0667dc43-r1):
// - Direct row indexing, next-row expression updates, a volatile row pointer,
//   and a volatile alias of the row-pointer home all moved away from the clean
//   basin (190, 190, 147/+6 bytes, and 215 differing bytes respectively).
// - Reversing the outer update order and combining the pointer increment with
//   its dereference were codegen-identical to the 141-byte clean basin.
// - Hoisting the column initializer before the inner guard worsened to 185
//   bytes. A 24-variant lab over row-pointer type, bound order, predicate
//   temporary, and update spelling found no exact result; the clean group
//   remained best at 141 differing bytes.
// Keep the pinned clean typed row-base source. The remaining evidence still
// points to the original y1/range-home, row-pointer/y-home, x1/EBX, and
// CL-vs-BL allocation rotation.
// Fresh reassessment (sa-30715b7c-r1):
// - A natural outer `for` with the reused x row counter worsened to 172 bytes.
// - A per-row terrain copy was codegen-identical to the clean source.
// - Direct typed row indexing was 191 bytes; a separate row local with the
//   carried row pointer was 142 bytes in its while form and 172 bytes as a for.
// - Splitting the row base from the offset was 168 bytes. Reordering the
//   initial cursor declaration, joining upper-bound initializers, and copying
//   y1 to an end_y local were all duplicate 141-byte codegen.
// - Typing the row base as RGE_Tile* repeated the 168-byte basin.
// Restore and retain the pinned natural source. The clean result remains
// 224 bytes with 141 differing bytes and 85.42% shape; no natural source
// recovered the y1/range-home and row-pointer/y-home rotation.

// Deeper local/row-ownership reassessment (sa-af6eaad7-r1):
// - Nine row-surface forms (named row table, indexed row pointer, named row,
//   top-scoped cell locals, and typed cell forms) produced the 224-byte/141-
//   difference basin. Typed row/cell ownership entered 190-191-byte basins.
// - Canonical RGE_Tile bitfields, sizeof(RGE_Tile) stride, full bound
//   initialization, register locals, row aliases, nested row scope, and
//   byte/char row-table member types produced no better policy-valid result.
// - An integer row cursor and an explicit y-parameter pointer cursor both
//   normalized to the clean basin. This does not prove a shipped raw cursor;
//   retain the reviewed typed row-table ownership.
// - A const row-table alias changed the prologue and reached 195 differences;
//   the plain typed member remained best. Ten new variant families exhausted
//   local-declaration and row-ownership leads without recovering the original
//   y1/range-home, row-pointer/y-home, x1/EBX, or CL/BL rotation.
// - Object audit confirms the five-parameter ABI, one local FPO word, no SEH,
//   no inline records, the 24-byte tile, and terrain bits at byte 5. PDB names
//   only index1 and y1, so its optimized local records are incomplete. Assembly
//   proves the remaining homes; extra aliases or raw cursors stay unjustified.

// Policy audit:
// - The module owns an RGE_Map and typed RGE_Tile rows.
// - The scan uses typed row and tile pointers, not byte cursors.
// - The named row counter does not reuse an incoming parameter home.

class RGE_Map;
class RGE_Object_Node;

class Map_Stack {
public:
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();

    RGE_Object_Node* list;
    short number_of_objects;
    unsigned char pad_0A[2];
};

class RGE_Tile {
public:
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type;
    unsigned char border_type : 4;
    unsigned char border_shape : 4;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    RGE_Object_List objects;
};

class RGE_Random_Map_Module_List;

class RGE_Random_Map_Module {
public:
    virtual unsigned char generate() = 0;

    RGE_Random_Map_Module* parent;
    RGE_Random_Map_Module_List* list;
    RGE_Map* map;
    RGE_Tile** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;
};

class RGE_RMM_Elevation_Generator : public RGE_Random_Map_Module {
public:

    unsigned char check_start_elevation(long x, long y, unsigned char terrain, unsigned char elevation, unsigned char range);
};

unsigned char RGE_RMM_Elevation_Generator::check_start_elevation(long x, long y, unsigned char terrain, unsigned char elevation, unsigned char range)
{
    long x0 = x - range;
    long y0 = y - range;
    RGE_Tile** row_ptr;
    RGE_Tile* row_base;
    long row;
    long y1;
    long x1;
    y1 = y + range;
    x1 = x + range;

    if (x0 < 0) {
        x0 = 0;
    }
    if (y0 < 0) {
        y0 = 0;
    }
    if (x1 >= this->map_width) {
        x1 = this->map_width - 1;
    }
    if (y1 >= this->map_height) {
        y1 = this->map_height - 1;
    }

    row = y0;
    row_ptr = this->map_row_offset + y0;
    row_base = *row_ptr + x0;
    while (row <= y1) {
        if (x0 <= x1) {
            RGE_Tile* cell = row_base;
            long col = x0;
            do {
                if (terrain == 0xFF
                    || (cell->terrain_type & 0x1F) != terrain
                    || (cell->terrain_type >> 5) < elevation) {
                    return 0;
                }
                col++;
                ++cell;
            } while (col <= x1);
        }
        row_ptr++;
        row++;
        row_base = *row_ptr + x0;
    }
    return 1;
}
