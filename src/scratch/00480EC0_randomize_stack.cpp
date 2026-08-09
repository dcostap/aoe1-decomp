// 00480EC0 RGE_Random_Map_Module::randomize_stack (rmm_base.cpp:473-506)
// Attempt log:
// - Baseline retained the natural linked-list phases, but all local-node
//   addresses were one Map_Stack field below the original and the frame was
//   four bytes short.
// - Offset-view experiments using the y/prev fields improved byte metrics but
//   were compiler-steering artifacts, not plausible owning source; main-agent
//   audit restored ordinary Map_Stack elements and named collection cursors.
// - Directly passing param_1->next, a named/register init counter, an unused
//   volatile pad, and a 9-variant counter/outer-loop lab were codegen-neutral.
// - Final normalized source remains exact-size with all five calls aligned,
//   but returns to structural reconstruction (147-byte diff, 73.33% shape);
//   the frame is still 0x964 versus 0x968. Next work should recover the real
//   local declaration/layout context rather than reintroduce offset views.

extern "C" int __cdecl debug_rand(char* file, int line);

struct Map_Stack {
    long x;           // +0x00
    long y;           // +0x04
    float cost;       // +0x08
    float tot_cost;   // +0x0C
    Map_Stack* next;  // +0x10
    Map_Stack* prev;  // +0x14
};

class RGE_Random_Map_Module {
public:
    void init_stack(Map_Stack* stack);
    void add_stack_node(Map_Stack* stack, Map_Stack* node);
    void randomize_stack(Map_Stack* param_1);
};

void RGE_Random_Map_Module::randomize_stack(Map_Stack* param_1)
{
    int i;
    Map_Stack sub_stacks[100];

    // Phase 1: Initialize all 100 sub_stacks
    for (i = 0; i < 100; i++) {
        init_stack(&sub_stacks[i]);
    }

    // Phase 2-3: Outer loop (2 iterations)
    for (int outer = 2; outer != 0; outer--) {
        // Phase 2: Distribute param_1's linked list into random sub_stacks
        while (param_1->next != 0) {
            int r = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_base.cpp", 0x1E8);
            r = (r * 100) / 0x7FFF;
            add_stack_node(&sub_stacks[r], param_1->next);
        }

        // Phase 3: Collect sub_stacks back into param_1's list
        int offset = 0x18;
        Map_Stack** first = &sub_stacks[0].next;

        while (offset < 0x978) {
            Map_Stack** second = (Map_Stack**)((char*)&sub_stacks[0].next + offset);

            while (*first != 0 || *second != 0) {
                if (*first != 0) {
                    add_stack_node(param_1, *first);
                }
                if (*second != 0) {
                    add_stack_node(param_1, *second);
                }
            }

            first = (Map_Stack**)((char*)first + 0x30);
            offset += 0x30;
        }
    }
}
