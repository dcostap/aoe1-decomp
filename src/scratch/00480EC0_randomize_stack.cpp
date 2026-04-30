// 00480EC0 RGE_Random_Map_Module::randomize_stack (rmm_base.cpp:473-506)
// PARKED after 6 attempts - multiple compound VC5 codegen issues

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
    Map_Stack sub_stacks[100];
    char _pad[4];

    // Phase 1: Initialize all 100 sub_stacks
    for (int i = 0; i < 100; i++) {
        init_stack(&sub_stacks[i]);
    }

    // Phase 2-3: Outer loop (2 iterations)
    for (int outer = 2; outer != 0; outer--) {
        // Phase 2: Distribute param_1's linked list into random sub_stacks
        while (param_1->next != 0) {
            int r = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_base.cpp", 0x1E8);
            r = (r * 100) / 0x7FFF;
            {
                Map_Stack* node = param_1->next;
                add_stack_node(&sub_stacks[r], node);
            }
        }

        // Phase 3: Collect sub_stacks back into param_1's list
        int offset = 0x18;
        Map_Stack** ebp = &sub_stacks[0].next;

        while (offset < 0x978) {
            Map_Stack** edi = (Map_Stack**)((char*)&sub_stacks[0].next + offset);

check_pair:
            if (*ebp != 0)
                goto handle_pp;
            if (*edi == 0)
                goto advance_pair;

check_pp2:
            if (*edi != 0) {
                add_stack_node(param_1, *edi);
            }
            goto check_pair;

handle_pp:
            add_stack_node(param_1, *ebp);
            goto check_pp2;

advance_pair:
            ebp = (Map_Stack**)((char*)ebp + 0x30);
            offset += 0x30;
        }
    }
}
