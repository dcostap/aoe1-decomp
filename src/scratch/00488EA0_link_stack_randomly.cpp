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
