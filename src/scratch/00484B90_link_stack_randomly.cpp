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

struct Map_Stack {
    long x;                 // +0x00
    long y;                 // +0x04
    long cost;              // +0x08
    long tot_cost;          // +0x0C
    Map_Stack* next;        // +0x10
    Map_Stack* prev;        // +0x14
};

int __cdecl debug_rand(char* file, int line);

class RGE_RMM_Elevation_Generator {
public:
    void* vftable;                  // +0x00
    char gap_04[0x10];              // +0x04..+0x13
    long map_width;                 // +0x14
    long map_height;                // +0x18
    char gap_1C[0x28 - 0x1C];       // +0x1C..+0x27
    Map_Stack* stack_array;         // +0x28
    Map_Stack** stack_offsets;      // +0x2C

    void add_stack_node(Map_Stack* target, Map_Stack* node);
    void link_stack_randomly(Map_Stack* param_1);
};

void RGE_RMM_Elevation_Generator::link_stack_randomly(Map_Stack* param_1) {
    Map_Stack* stack = this->stack_array;
    stack->prev = param_1;
    stack->next = &stack[1];

    Map_Stack* last = &stack[this->map_height * this->map_width - 1];
    last->next = 0;
    last->prev = &last[-1];

    for (Map_Stack* node = &stack[1]; node < last; node++) {
        node->next = &node[1];
        node->prev = &node[-1];
    }

    for (long count = this->map_height * this->map_width / 16; count > 0; count--) {
        long x = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_elev.cpp", 0xFA) * (this->map_width - 1) / 0x7FFF;
        long y = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_elev.cpp", 0xFB) * (this->map_height - 1) / 0x7FFF;
        this->add_stack_node(param_1, &this->stack_offsets[y][x]);
    }
}
