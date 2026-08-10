// 00488EA0 RGE_RMM_Terrain_Generator::link_stack_randomly
// PDB source: rmm_terr.cpp:245-275
// Attempt log:
// - Baseline: natural stack-array linking and random row/column links; all three
//   direct calls aligned, but the compiler used an 8-byte frame (241 vs 239).
// - Removing the list alias produced an exact-size/frame basin but swapped the
//   saved-this/parameter register roles and worsened resync; repeated unchanged
//   forms were discarded.
// - Explicit parameter-home reuse plus a saved list reached 239 bytes, exact
//   frame/saved-register counts, and 88.5% shape, but retained a setup/register
//   hunk at +0008; declaration-order tuning reached 88.4% and did not close it.
// - Restored the clean-source baseline after the 10-hypothesis budget: remaining
//   drift is VC5 local liveness/register coloring, not call set, layout, or CFG.
// - New worker baseline: same-TU check_terrain recovery confirms the full random-module base surface; next probe names those proven base fields instead of a gap-only prefix.
// - Full base surface emitted identically to the gap-only donor; no new structural lead. Keep the named canonical base and pause rather than repeat the prior liveness basin.
// - New claim: direct width-minus-one spelling reached exact size/frame but moved to a different register/CFG basin (216-byte diff, 73.9% shape); restored.
// - Register-qualified list/width, named height/width temporaries, split list initialization, and const width-bound probes were unchanged or worse; restored.
// - Fresh pass: height*width operand reversal was compiler-canonicalized with no emitted change; restored.
// - C89-shaped top declarations reached 240 bytes but degraded block/resync shape; split bound initialization reached 239 bytes but worsened to 228 diff; restored.
// - Late saved-list declaration plus parameter-home count reached the best fresh basin (239 bytes, no frame, 94.2% shape, first mismatch +8), but emitted code duplicated the prior basin: VC5 kept the list in ESI and count in EBX instead of target EBX/parameter-home roles. const/register list, separate cursor, and decompiler local-order variants were unchanged; restored.
// - Fresh bounded pass exhausted; clean natural source retained. Remaining gap is early saved-register/parameter-home coloring, with calls, layout, and CFG aligned.
// - New claim: parameter-home count reuse with late list/max-bound declaration combinations reached a 218-byte, exact-size/frame basin (94.2% shape) but still saved the list through ESI/its home and kept the count in EBX; the register-qualified parameter was codegen-identical.
// - A 16-variant lab over list placement, cached/direct dimensions, cursor shape, and parameter-home count found no exact match; all size/frame/call-eligible groups retained the same early list/register hunk. The best lab groups are diagnostic only and were not promoted over the clean source.
// - A narrow volatile reference to the proven parameter home worsened the function to 259 bytes; rolled back. Remaining binary lead is the target's early EBX=list, EBP=(width-1), push-ecx=max_y, parameter-home count coloring; canonical ownership and behavior are otherwise aligned.

extern "C" int __cdecl debug_rand(char* file, int line);

class RGE_Map;
class RGE_Random_Map_Module_List;

struct Map_Stack {
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

class RGE_Random_Map_Module {
public:
    virtual unsigned char generate() = 0;

    RGE_Random_Map_Module* parent;
    RGE_Random_Map_Module_List* list;
    RGE_Map* map;
    void* map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;

    void add_stack_node(Map_Stack* target, Map_Stack* node);
};

class RGE_RMM_Terrain_Generator : public RGE_Random_Map_Module {
public:
    void link_stack_randomly(Map_Stack* param_1, unsigned char param_2);
};

void RGE_RMM_Terrain_Generator::link_stack_randomly(Map_Stack* param_1, unsigned char param_2)
{
    Map_Stack* list = param_1;
    long max_y = this->map_height - 1;
    long max_x = this->map_width - 1;
    Map_Stack* first = this->stack_array;
    Map_Stack* last = first + this->map_width * this->map_height - 1;

    first->prev = param_1;
    first->next = first + 1;
    param_1->next = first;
    last->next = 0;
    last->prev = last - 1;

    first = first + 1;
    while (first < last) {
        first->next = first + 1;
        first->prev = first - 1;
        first = first + 1;
    }

    long count = (this->map_width * this->map_height
                  + ((this->map_width * this->map_height >> 31) & 7)) >> 3;
    if (count > 0) {
        do {
            long x = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 0x10F)
                      * max_x) / 0x7FFF;
            long y = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 0x110)
                      * max_y) / 0x7FFF;
            this->add_stack_node(list, this->stack_offsets[y] + x);
            --count;
        } while (count != 0);
    }
}
