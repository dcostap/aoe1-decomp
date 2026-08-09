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

struct Map_Stack {
    long x;                 // +0x00
    long y;                 // +0x04
    long cost;              // +0x08
    long tot_cost;          // +0x0C
    Map_Stack* next;        // +0x10
    Map_Stack* prev;        // +0x14
};

int __cdecl debug_rand(char* file, int line);

class RGE_Random_Map_Module {
public:
    virtual unsigned char generate() = 0;
    RGE_Random_Map_Module* parent;  // +0x04
    void* list;                     // +0x08
    void* map;                      // +0x0C
    void* map_row_offset;           // +0x10
    long map_width;                 // +0x14
    long map_height;                // +0x18
    float schedule;                 // +0x1C
    void* search_map;               // +0x20
    void* search_map_rows;          // +0x24
    Map_Stack* stack_array;         // +0x28
    Map_Stack** stack_offsets;      // +0x2C

    void add_stack_node(Map_Stack* target, Map_Stack* node);
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
class RGE_RMM_Elevation_Generator : public RGE_Random_Map_Module {
public:
    virtual unsigned char generate();
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

    for (long count = height * width / 16; count > 0; count--) {
        long x = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_elev.cpp", 0xFA) * max_width / 0x7FFF;
        long y = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_elev.cpp", 0xFB) * max_height / 0x7FFF;
        this->add_stack_node(param_1, &this->stack_offsets[y][x]);
    }
}
