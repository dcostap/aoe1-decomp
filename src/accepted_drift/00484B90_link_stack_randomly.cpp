// 00484B90 RGE_RMM_Elevation_Generator::link_stack_randomly (rmm_elev.cpp:225-260)
// Links the shared stack_array (width*height Map_Stack nodes, 0x18 each) into a
// doubly-linked list, then calls add_stack_node count = w*h/16 times at random
// (x,y) positions selected via debug_rand scaling (magic /0x7FFF division).
// The elevation flavor (vs the terrain twin 00488EA0) does NOT set param_1->next,
// and keeps count in the push-ecx slot with param_1 home reloaded for the call.
//
// ATTEMPT LOG
// probe-001 baseline (diff 216, size 218 vs 234, calls 3/3 aligned): canonical
//   reconstruction above. Rebuilt prologue/init block is 4 instructions short and
//   picks a different this/param register basin (mov ebp,[esp+0Ch]; mov esi,ecx
//   early vs original push ecx/ebx/ebp/esi/edi; mov edi,ecx). Left in scratch:
//   the -16 byte size gap and early-BB shape likely come from the linking-loop
//   source shape (loop rotation / CSE of node=&stack[1] and last computation) or
//   from the hoisted (map_width-1)/(map_height-1) being spilled instead of kept in
//   ebp/ebx. Next leads: (1) try do/while linking loop or comma-chain line 237
//   shape so the last-lea/node-lea land at 237 like the original; (2) check
//   whether `count`/`x`/`y` need to be plain locals rather than loop-scoped;
//   (3) compare with terrain twin 00488EA0 once it is attempted.
// probe-003 abi: restored the proven RGE_Random_Map_Module base and inherited
//   add_stack_node ABI; this changed only one diff byte and worsened shape, so
//   the base surface is retained for canonical ownership, not as a byte win.
// probe-004 layout: named height/width locals; size reached 234 and shape 81%.
// probe-005 control-flow: compute last before the linking stores; resync moved
//   to 65% and diff 194, showing source statement order is material.
// probe-006 liveness: an early list alias was optimized away (duplicate code);
//   rolled back. probe-007 liveness: named max_height/max_width limits exposed
//   the target 85-instruction basin and 55% exact-block coverage.
// probe-008 control-flow: put root prev assignment before last declaration;
//   diff 183, shape 92.9%, and the param load moved to the binary's early band.
// probe-009 liveness: swapped width/height declaration order; field loads and
//   94.1% shape aligned, with diff 182. Direct stack_array and late stack-local
//   variants (probes 010-012) added 2-8 bytes or worsened alignment.
// restored probe-009 as the best natural reconstruction: named dimensions,
//   limits, and stack ownership; remaining drift is register/statement order
//   around stack/param allocation and the first linking block. No inline asm.
// New claim probe: swap max_width/max_height declaration order; this is the
// natural x/y use order that moved the size-preserving output one byte closer.
// Next declaration-order probe: declare the stack pointer before dimensions but
// initialize it at the same source point, testing pointer/parameter coloring
// without changing ownership or statement order.
// Next ownership-expression probe: spell only the root prev store through the
// canonical member, leaving the persistent stack local for the linked-list walk.
// Object audit: PDB names no dimension or product local. FPO, COFF, compiler,
// calls, float field types, and ABI all match. No inline or macro record explains
// the two commutative load bytes, so load-order steering remains unsupported.
// Canonical audit: Map_Stack cost fields use the PDB-proven float types. The
// debug_rand import uses C linkage. The base generate method is concrete, and
// the known helper methods use their protected surfaces. No generic virtual
// slot, raw cursor, volatility, or no-effect expression is present.
// ACCEPTED DRIFT: The only two differing bytes exchange map_width and
// map_height between one MOV and its adjacent signed IMUL. Multiplication is
// commutative. Both ordinary field loads complete before any later operation,
// and the product and IMUL flags are equal. All remaining bytes match.

struct Map_Stack {
    long x;                 // +0x00
    long y;                 // +0x04
    float cost;             // +0x08
    float tot_cost;         // +0x0C
    Map_Stack* next;        // +0x10
    Map_Stack* prev;        // +0x14
};

extern "C" int __cdecl debug_rand(char* file, int line);

class RGE_Map;
class RGE_Random_Map_Module_List;
struct RGE_Tile;

class RGE_Random_Map_Module {
public:
    virtual unsigned char generate();
    RGE_Random_Map_Module* parent;  // +0x04
    RGE_Random_Map_Module_List* list; // +0x08
    RGE_Map* map;                   // +0x0C
    RGE_Tile** map_row_offset;      // +0x10
    long map_width;                 // +0x14
    long map_height;                // +0x18
    float schedule;                 // +0x1C
    unsigned char* search_map;      // +0x20
    unsigned char** search_map_rows; // +0x24
    Map_Stack* stack_array;         // +0x28
    Map_Stack** stack_offsets;      // +0x2C

protected:
    void add_stack_node(Map_Stack* target, Map_Stack* node);
};

struct RGE_Elevation_Info_Line {
    long elevation_size;
    long elevation;
    long clumps;
    long spacing;
    long base_elevation;
    long base_terrain_type;
};

struct RGE_Elevation_Hot_Spots {
    long x;
    long y;
    long radius;
    long fade;
};

struct RGE_Elevation_Info {
    RGE_Elevation_Info_Line elevation[99];
    long elevation_num;
    RGE_Elevation_Hot_Spots hot_spots[99];
    long hot_spot_num;
};

// Main-agent audit confirmed canonical elevation stack/map ownership and kept
// the natural randomized linking loop.
// Continuation (sa-ab4dd300-r1): rmm_base/rmm_terr/rmm_land donor review
// confirms the inherited random-map base, 0x18-byte Map_Stack stride, and
// stack_offsets[y][x] ownership. A while-form pointer walk, a named root
// alias, using the stack local for the root-prev store, and initializing the
// stack pointer before the dimensions were all codegen-identical. Delaying
// max_width until after the terminal-node product worsened the result to 200
// differing bytes and was rolled back. Keep the natural named-dimension and
// stack-owner source; the remaining 181-byte drift is the param/stack register
// swap and one extra loop-home temporary before the already aligned call tail.
// Current claim: moving the root-prev store ahead of max-limit declarations
// changed the size/CFG and widened the diff to 206 bytes; the clean source was
// restored. The remaining first hunk is the param/stack register swap and the
// product-scale versus max_width scheduling noted above.
// Continuation (orch-rmmelev-02): direct canonical `this->map_height *
// this->map_width / 16` for the post-link count restores the terminal reload
// and collapses the reconstruction from 181 differing bytes to 2, with exact
// size, CFG, call targets, and 90.59% exact-block coverage. VC5 emits the two
// remaining displacement differences in the opposite commutative load order:
// rebuilt `mov [edi+14h]; imul [edi+18h]` versus original `mov [edi+18h];
// imul [edi+14h]`.
// Reversing the product, staged/compound/named-width forms, count-expression
// variant lab, declaration-order changes, volatile/pointer references, a
// decompiler-style signed-shift formula, and a source-lifetime block did not
// produce a new exact basin; the last two-byte basin is retained as the clean
// canonical source. No inline asm or opaque helper was kept.
// wave20-rmmelev-01 baseline: revalidated the canonical source at 2 differing
// bytes; all calls, size, frame, CFG, and 90.59% exact-block coverage match.
// Same-TU typed base context, int/register/top-scoped count forms, stdlib
// context, and a late base-pointer alias were emitted-code duplicates.
// A narrow volatile field load widened the result to 150 bytes; reusing the
// named height/width locals widened it to 181 bytes. A volatile count widened
// it to 143 bytes and 9 extra bytes of code. Restored the clean source; the
// remaining drift is only the commutative count-product memory operand order
// at 00484BE2/00484BE5 (rebuilt width-then-height vs oracle height-then-width).
// close-484B90-r1: exact rmm_elev map_size donor idioms were retested with a
// staged assignment product and a separate map_size local; both were emitted
// identically. The untested height-accumulator assignment and explicit base
// qualification were also emitted identically. The exact terrain loop_count
// guard/do-while tail remains a duplicate. Restored the natural direct-count
// source. Source audit: canonical named Map_Stack fields, inherited map fields,
// direct member calls, and no volatile, raw-address, or codegen-only scaffolding.
// shardE-484B90: declaration-order, standalone-product, and late-width-local
// probes all retained the two-byte terminal product-load mismatch. A direct
// do/while count form widened the block shape and was rolled back. A neutral
// width expression and separate product/division statement were codegen
// duplicates. Restored the canonical for-loop source; no new natural lead
// remains beyond the opposite commutative load order at 00484BE2/00484BE5.
// orch-484B90-a: zero-subtraction, CRT-header-pair, nested-product, comma,
// height-pointer, full-info-layout, and typed-base probes were emitted-code
// duplicates or worse. A typed overlay of the proven adjacent width/height
// fields reached an exact 234-byte match, but it is raw layout plumbing and
// was not retained as living source. A named dimensions aggregate restored
// canonical ownership but returned to the two-byte mismatch. Clean source
// keeps direct named map fields, full typed base context, and the proven
// elevation-info layout; the remaining gap is the commutative product load
// order at 00484BE2/00484BE5.
// orch-484B90-b: re-tested the prior adjacent-field overlay and reproduced an
// exact 234-byte match. A natural local dimensions aggregate returned to the
// same two-byte mismatch. Restored the direct map-field product: the overlay
// remains diagnostic because it is not a plausible source model.
// Claim sa-df973337-r1: fresh donor checks confirm 00488EA0 is an exact
// related stack-link donor, including the height-first product load, while
// this elevation source remains a clean natural reconstruction at 2 bytes.
// Adding the terrain donor's list alias here was codegen-identical; it did not
// recover the target product order. Keep the donor as evidence, not as an
// unsupported elevation-list store or raw layout overlay.
// Claim sa-a1570cfd-r1: staged count accumulation, reversed terminal product,
// terrain donor float cost types, and const dimension locals were all emitted
// duplicates. Restore the natural typed source. The only mismatch remains the
// two operand-displacement bytes at the terminal count product; the exact
// adjacent-field overlay is rejected as raw layout plumbing.
// Claim sa-ce8773f9-r1: declaring only the countdown at function scope and
// using local references to map_height/map_width in the terminal product were
// both emitted-code duplicates. Restore the pinned natural source. The exact
// adjacent-field overlay remains diagnostic only; no supported natural source
// form has changed the height-first product load.
// Claim sa-d177c0ec-r1: read the full target history, the canonical ownership
// evidence, the same-TU callers, and the sibling terrain donor. The original
// line map places the terminal signed product at rmm_elev.cpp:247. The exact
// same-TU generate_modifiers source uses a height accumulator and compound
// width multiply, while count_map_tiles proves that direct field products can
// use the other order. Ten focused source tests covered that accumulator,
// named product and area intermediates, declaration lifetime, the terrain
// do/while shape, signed int count, and constant spelling. They all retained
// the 234-byte, two-byte mismatch. Keep the natural direct product and record
// the final blocker: VC5 selects [this+14] as the initial EAX load and
// [this+18] as the imul memory operand, while the oracle selects the opposite
// register/operand order at 00484BE2 and 00484BE5. The exact adjacent-field
// overlay is raw layout plumbing and is not an allowed source model.
// TU audit (sa-cca4d07f-r1): repository-local context tests did not change the
// two-byte basin. A 512-sample ambient declaration sweep, the exact
// generate_modifiers donor body with its math/string headers, the complete
// elevation method declaration surface, and exact generate plus donor body
// ordering all rebuilt to 234 bytes with the same two displacement bytes.
// A 4096-state VC5 standard-header sweep also produced one 234-byte basin.
// Windows, game_types, and game_globals include contexts were separate no-op
// tests. The exact sibling uchar typedef was also a no-op. The vc5-small flag
// classification kept the default /O2 /Oy basin; /Ow widened it and no flag
// state was exact. These results support the calibrated default flags and the
// current clean direct-field source. No repository-supported TU declaration,
// header, macro, donor-order, type-surface, or flag context selected the
// oracle's height-first commutative load order. Keep the baseline unchanged.
// Claim sa-a51b79c7-r1: 14 focused probes rechecked the two-byte frontier.
// Natural products, map_size temporaries, PDB-like local names, int locals,
// inline base getters, and count lifetimes kept the 234-byte width-first basin.
// Swapped dimension declarations fixed the terminal order but broke the earlier
// PDB-proven height-first load. The terrain donor's do/while changed the whole
// function. The exact adjacent-field overlay remains rejected raw plumbing.
// Restore the canonical float Map_Stack and direct PDB-named base fields.
class RGE_RMM_Elevation_Generator : public RGE_Random_Map_Module {
public:
    RGE_Elevation_Info info;
    virtual unsigned char generate();

protected:
    void link_stack_randomly(Map_Stack* param_1);
};

void RGE_RMM_Elevation_Generator::link_stack_randomly(Map_Stack* param_1) {
    Map_Stack* stack;
    long width = this->map_width;
    long height = this->map_height;
    stack = this->stack_array;
    long max_width = width - 1;
    long max_height = height - 1;
    stack->prev = param_1;
    Map_Stack* last = &stack[height * width - 1];
    stack->next = &stack[1];
    last->next = 0;
    last->prev = &last[-1];

    Map_Stack* node = &stack[1];
    while (node < last) {
        node->next = &node[1];
        node->prev = &node[-1];
        node++;
    }

    for (long count = this->map_height * this->map_width / 16; count > 0; count--) {
        long x = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_elev.cpp", 0xFA) * max_width / 0x7FFF;
        long y = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_elev.cpp", 0xFB) * max_height / 0x7FFF;
        this->add_stack_node(param_1, &this->stack_offsets[y][x]);
    }
}
