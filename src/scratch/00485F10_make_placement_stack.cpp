// VA: 00485F10 RGE_RMM_Object_Generator::make_placement_stack
// Attempt log:
// initial natural implementation from packet/decompiler: correct size but broad diff, frame 0x14 due extra locals.
// switched to decompiler-style mutable parameters and explicit local_c/local_8/local_4 topology: exact size but broad scheduling/register diff (401 edit-equal bytes).
// tried pointer signature for stack instead of reference; produced mov-before-sub prologue and same broad family, rolled back to reference.
// tried pstack local alias for &stack; no improvement, same broad family.
// tried early local_c=&stack before stack next/prev stores; fixed initial sub/mov placement but delayed push edi and worsened diff, rolled back.
// tried explicit zero local/casts for null stores and comparisons; no codegen change.
// tried natural row/column implementation first; correct size but worse frame/local pressure (0x14 frame) and broad diff.
// left in scratch: behavior/calls understood, but source shape for VC5 register allocation in clipping and scan loops is still wrong; not an accepted_drift candidate due broad positional diff from function start.

extern "C" int __cdecl debug_rand(char* file, int line);
extern char s_rmm_obj_cpp[];

struct Map_Stack {
    char gap_00[0x10];
    Map_Stack* next;
    Map_Stack* prev;
};

class RGE_RMM_Object_Generator {
public:
    char gap_00[0x14];
    long width;
    long height;
    char gap_1c[0x24 - 0x1c];
    char** map;
    char gap_28[4];
    Map_Stack** stack_rows;

    void add_stack_node(Map_Stack* last, Map_Stack* node);
    void make_placement_stack(Map_Stack& stack, long x, long y, long unused, long range);
};

void RGE_RMM_Object_Generator::make_placement_stack(Map_Stack& stack, long x, long y, long unused, long range)
{
    long y1;
    Map_Stack* last;
    Map_Stack* local_c;
    int local_8;
    int local_4;

    int zero = 0;
    stack.next = (Map_Stack*)zero;
    stack.prev = (Map_Stack*)zero;

    if (x < zero || y < zero || range < zero) {
        x = zero;
        y = zero;
        range = this->width - 1;
        last = (Map_Stack*)(this->height - 1);
    } else {
        int iVar5 = x - range;
        int iVar3 = y - range;
        int iVar1 = x + range;
        last = (Map_Stack*)(y + range);
        x = iVar5;
        y = iVar3;
        range = iVar1;
        if (x < zero) x = zero;
        if (y < zero) y = zero;
        if (range >= this->width) range = this->width - 1;
        if ((int)last >= this->height) last = (Map_Stack*)(this->height - 1);
    }

    local_c = &stack;
    if (y <= (int)last) {
        local_8 = y * 4;
        local_4 = (int)last + (1 - y);
        do {
            if (x <= range) {
                int off = x * 0x18;
                y1 = x;
                do {
                    if (*(char*)(*(int*)((char*)this->map + local_8) + y1) != 0) {
                        Map_Stack* node = (Map_Stack*)(*(int*)((char*)this->stack_rows + local_8) + off);
                        this->add_stack_node(local_c, node);
                        local_c = node;
                    }
                    y1 = y1 + 1;
                    off = off + 0x18;
                } while (y1 <= range);
            }
            local_8 = local_8 + 4;
            local_4 = local_4 - 1;
        } while (local_4 != 0);
    }

    int w = range - x - 1;
    int h = (int)last - y - 1;
    if (w > 1 && h > 1) {
        range = (h * w) / 4;
        if (range > 0) {
            do {
                int rx = (debug_rand(s_rmm_obj_cpp, 0xaf) * w) / 0x7fff + x;
                int ry = (debug_rand(s_rmm_obj_cpp, 0xb0) * h) / 0x7fff + y;
                int ry4 = ry * 4;
                if (*(char*)(*(int*)((char*)this->map + ry4) + rx) != 0) {
                    this->add_stack_node(&stack, (Map_Stack*)(*(int*)((char*)this->stack_rows + ry4) + rx * 0x18));
                }
                range = range - 1;
            } while (range != 0);
        }
    }
}
