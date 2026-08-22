// VA: 00485F10 RGE_RMM_Object_Generator::make_placement_stack
// Attempt log:
// initial natural implementation from packet/decompiler: correct size but broad diff, frame 0x14 due extra locals.
// switched to decompiler-style mutable parameters and explicit local_c/local_8/local_4 topology: exact size but broad scheduling/register diff (401 edit-equal bytes).
// tried pointer signature for stack instead of reference; produced mov-before-sub prologue and same broad family, rolled back to reference.
// tried pstack local alias for &stack; no improvement, same broad family.
// tried early local_c=&stack before stack next/prev stores; fixed initial sub/mov placement but delayed push edi and worsened diff, rolled back.
// tried explicit zero local/casts for null stores and comparisons; no codegen change.
// tried natural row/column implementation first; correct size but worse frame/local pressure (0x14 frame) and broad diff.
// fresh typed rows/stack reconstruction with natural current_y/current_x loops worsened to 494 bytes, 0xC frame, and CFG drift; restored.
// direct zero spelling duplicated the clean 507-byte output; retained the simpler literal form only where it does not alter codegen.
// early local_c initialization worsened resync and added five instructions; restored.
// named search_map_rows/stack_offsets, full 24-byte Map_Stack, and long last bound preserved the 507-byte output; retained as canonical local ownership.
// explicit self alias was neutral in positional bytes but worsened edit resync; restored.
// this-session H1/H2: moving the live tail pointer before stack-link stores,
// then using it for those stores, worsened the first prologue hunk to 480 bytes;
// both forms were rolled back.
// this-session H3: a four-form stack-initialization lab kept the same 507-byte
// size and 446-byte clean-source diff; no form changed the initial parameter load.
// this-session H4: modeled the ABI-proven RGE_Random_Map_Module base with typed
// inherited stack rows and list fields; codegen was unchanged at 446 bytes, so
// restored the clean local surface.
// shardD10 H1: hoisted the typed Map_Stack node local to function scope to
// mirror its binary-persistent value across add_stack_node; codegen was an
// unchanged 507-byte/446-diff duplicate, so restored the clean source.
// luna-r2 H1: hoisted the packet's iVar1/iVar2/iVar3/lVar4/iVar5/pMVar6
// temporaries to function scope to test its local-lifetime and declaration-order
// evidence; codegen was an unchanged 507-byte/446-diff duplicate, so restored
// the clean typed source.
// luna-r3 H1: split the bound copies and arithmetic to mirror the original
// move/sub/sub/add/add line-band order; codegen stayed an unchanged 507-byte/
// 446-diff duplicate, so restored the clean typed source.
// luna-r4 H1: chained next/prev zero initialization was a structural source
// form for the binary's store/compare/store ordering; it was a 507-byte/446-diff
// codegen duplicate, so restored the separate typed stores.
// left in scratch: behavior/calls understood, but source shape for VC5 register allocation in clipping and scan loops is still wrong; not an accepted_drift candidate due broad positional diff from function start.
// this-session: pre-guard y1=x recovers the original inner index/stride shape;
// four typed clipping bounds improve the measured result to 392 positional
// bytes while preserving the 507-byte body. Typed row indexing was rejected
// because it added 20 bytes and a 0x14 frame. Keep the natural ownership model
// below, but retain the binary-proven row/stride lowering in this body.
// Main review removed the manual vptr and raw row/stride lowering. The living
// source now uses a virtual base and typed row indexing.
// this-claim probes: direct max-bound arithmetic worsened to 442/439 bytes;
// same-TU set_search_area arithmetic was a 392-byte duplicate. Explicit base
// vtable, receiver alias, register x, range-home count, zero local, and local
// declaration-order forms were codegen duplicates. A typed row alias or row
// table cursor worsened frame/shape (454 or 500 bytes); restored clean source.

extern "C" int __cdecl debug_rand(char* file, int line);
extern char s_rmm_obj_cpp[];

class RGE_Map;
class RGE_Random_Map_Module_List;
class RGE_Tile;

struct Map_Stack {
    long x;
    long y;
    float cost;
    float total_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

class RGE_Random_Map_Module {
public:
    virtual ~RGE_Random_Map_Module();
    RGE_Random_Map_Module* parent;
    RGE_Random_Map_Module_List* list;
    RGE_Map* map;
    RGE_Tile** map_row_offset;
    long width;
    long height;
    float schedule;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;

    void add_stack_node(Map_Stack* last, Map_Stack* node);
};

class RGE_RMM_Object_Generator : public RGE_Random_Map_Module {
public:
    void make_placement_stack(Map_Stack& stack, long x, long y, long unused, long range);
};

void RGE_RMM_Object_Generator::make_placement_stack(Map_Stack& stack, long x, long y, long unused, long range)
{
    long y1;
    long last;
    Map_Stack* local_c;
    int local_4;

    stack.next = 0;
    stack.prev = 0;

    if (x < 0 || y < 0 || range < 0) {
        x = 0;
        y = 0;
        range = this->width - 1;
        last = this->height - 1;
    } else {
        long min_x = x;
        long min_y = y;
        long max_x = x;
        long max_y = y;
        min_x -= range;
        min_y -= range;
        max_x += range;
        max_y += range;
        x = min_x;
        y = min_y;
        last = max_y;
        range = max_x;
        if (x < 0) x = 0;
        if (y < 0) y = 0;
        if (range >= this->width) range = this->width - 1;
        if (last >= this->height) last = this->height - 1;
    }

    local_c = &stack;
    if (y <= last) {
        local_4 = last + (1 - y);
        long row = y;
        do {
            y1 = x;
            if (x <= range) {
                do {
                    if (this->search_map_rows[row][y1] != 0) {
                        Map_Stack* node = &this->stack_offsets[row][y1];
                        this->add_stack_node(local_c, node);
                        local_c = node;
                    }
                    y1 = y1 + 1;
                } while (y1 <= range);
            }
            row = row + 1;
            local_4 = local_4 - 1;
        } while (local_4 != 0);
    }

    int w = range - x - 1;
    int h = last - y - 1;
    if (w > 1 && h > 1) {
        int count = (h * w) / 4;
        if (count > 0) {
            do {
                int rx = (debug_rand(s_rmm_obj_cpp, 0xaf) * w) / 0x7fff + x;
                int ry = (debug_rand(s_rmm_obj_cpp, 0xb0) * h) / 0x7fff + y;
                if (this->search_map_rows[ry][rx] != 0) {
                    this->add_stack_node(&stack, &this->stack_offsets[ry][rx]);
                }
                count = count - 1;
            } while (count != 0);
        }
    }
}
