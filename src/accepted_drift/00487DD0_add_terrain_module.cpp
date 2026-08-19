// VA: 00487DD0, TRIBE_RMM_Database_Controller::add_terrain_module, 461 bytes
// Source: rmm_tdbc.cpp lines 321-385
// Attempt log:
// - Baseline: natural reconstruction of the map-info land-tile calculation, base
//   call, scaled terrain loop, random adjustment branches, and final debug log.
// - ABI probes: replacing the free log shim with the PDB-backed variadic
//   TDebuggingLog::Log member restored the direct call target and exact ordered
//   call multiset. The absolute L receiver macro is retained from same-TU donors.
// - Expression probes: split and one-expression forms of the land-tile product,
//   nested versus named final debug_rand, and corrected inherited width/height
//   names all emitted the same basin. The remaining early hunk is the reversed
//   `imul [esi+18]`/`imul [esi+14]` operand order.
// - Layout probe: a reference-backed full RGE_Terrain_Info/RGE_Terrain_Info_Line
//   reconstruction was binary-plausible but moved to 364 differing bytes and
//   71.08% shape; restored. The proven line size is 0x20 and terrain array base
//   is +0x1474, while the raw anchored cursor remains the closest VC5 basin.
// - Control-flow probe: moving flag stores into a post-adjustment selection
//   changed the CFG/prologue and reached 432 differing bytes; restored.
// - Alias probe: equivalent byte-cursor/int-lvalue spelling was a codegen
//   duplicate; restored. No productive hypothesis remained in the 10-probe
//   assignment.
// - Final validated basin: 462 rebuilt bytes versus 461 original, 158/158
//   instructions, 96.20% shape, exact saved registers and ordered 5-call set,
//   88 strict differing bytes (60 raw edit cost), first mismatch +0x1f. The
//   unresolved structural stage is the multiply order plus late independent
//   store scheduling/receiver evaluation. No inline asm.
// - Fresh hypothesis: swapped the natural land-tile product to height then
//   width, matching the binary operand order. VC5 canonicalized it back to
//   the same output; restored the clean raw-cursor reconstruction.
// - Call-order probe: split the final debug_rand result into a named value
//   before the typed log call. VC5 emitted the same 462-byte basin; restored.
// - Fresh structural probes: the canonical first terrain-line type improved
//   the basin to 86 differing bytes and 96.84% shape; full typed adjustment
//   loops regressed broadly and were restored. A volatile flag cursor was a
//   diagnostic only: it improved to 77 bytes but is not plausible source.
// - Final clean source uses named terrain-line ownership throughout. The raw
//   adjustment cursors were diagnostic only. Remaining mismatch is store
//   scheduling in the type-0d arm, multiply order, and variadic cleanup.
// - Fresh worker pass: the clean source rebuilt to 461 bytes with 219 strict
//   differing bytes and 82.39% shape. Reviewed absolute constants and strings
//   improved relocation context but did not improve positional bytes.
// - A typed member-address cursor for clumps and avoid_hot_spots reached the
//   closest natural codegen basin: 462 bytes, 158/158 instructions, 99.37%
//   shape, 438 equal bytes, and 43 strict differing bytes. It kept exact call
//   order and saved-register sets. This probe used derived member pointers and
//   was restored because the clean source must not retain raw cursor plumbing.
// - The remaining basin differs at the type-6 EAX/EDX result color, the
//   fallback cursor/type register roles, and the final variadic receiver load.
//   Static-member, local-receiver, declaration-order, and typed-alias probes
//   did not improve the basin. The source is restored to the clean model.
// - Revisit: replaced the terrain and map stubs with the proven 0x1298
//   RGE_Terrain_Info and 0x48-byte RGE_Map_Data_Entry layouts. The named
//   aggregate source kept the 461-byte boundary and all ordered calls.
// - Revisit: typed field-address cursors and separate scan counters preserve
//   the original loop blocks without byte cursors or raw addresses.
// - Revisit: `terrain_size += terrain_size` emits the original EDX load and
//   shift. Shift and named-temporary forms kept EAX and were not retained.
// - Final revisit validation: 461/461 bytes, 158/158 instructions, 100%
//   exact blocks, and 5/5 ordered calls. Ten bytes remain in the fallback
//   loop's consistent register recolor: original EAX cursor/ECX type versus
//   rebuilt ECX cursor/EAX type. No exact policy-valid source was found.
// ACCEPTED DRIFT: All ten changed bytes form that one consistent EAX/ECX
// exchange. Instruction order, memory addresses, branches, flags, and calls
// remain equal under the map. Both values have the same live ranges, and the
// registers are caller-saved. Every instruction shape and basic block matches;
// no write, cleanup action, or fault order changes.

typedef unsigned char uchar;

extern "C" int __cdecl debug_rand(char* file, int line);

class TDebuggingLog {};
extern TDebuggingLog* L;
extern void __cdecl Log(TDebuggingLog* log, char* fmt, ...);

struct RGE_Land_Data {
    int map_edge_buffer[4];
    int map_edge_fade;
    int land_placement_edge;
    int base_terrain;
    int grown_land_percent;
    int id;
    int land_num;
    void* land;
};

struct RGE_Map_Data_Entry {
    int map_id;
    RGE_Land_Data land_info;
    char terrain_info[8];
    char object_info[8];
    char elevation_info[8];
};

struct RGE_Map_Data {
    int map_num;
    RGE_Map_Data_Entry* maps;
};

struct RGE_Terrain_Info_Line {
    int terrain_size;
    int terrain_generated;
    int terrain_type;
    int clumps;
    int spacing;
    int base_terrain_type;
    int clumpiness_factor;
    int avoid_hot_spots;
};

struct RGE_Terrain_Hot_Spots {
    int x;
    int y;
    int radius;
    int fade;
};

struct RGE_Terrain_Info {
    RGE_Terrain_Info_Line terrain[99];
    int terrain_num;
    RGE_Terrain_Hot_Spots hot_spots[99];
    int hot_spot_num;
};

class RGE_RMM_Database_Controller {
public:
    virtual void generate();
    virtual void add_land_module(uchar x);
    virtual void add_terrain_module();
};

class TRIBE_RMM_Database_Controller : public RGE_RMM_Database_Controller {
public:
    char gap_04[0x10];
    int map_width;          // +0x14 (RGE_Random_Map_Module::map_width)
    int map_height;         // +0x18 (RGE_Random_Map_Module::map_height)
    char gap_1c[0x18];
    int map_type;           // +0x34
    char gap_38[0x1474 - 0x38];
    RGE_Terrain_Info terrain_info; // +0x1474
    char gap_after2[0x4f54 - 0x270c];
    RGE_Map_Data map_info; // +0x4f54

    virtual void add_terrain_module();
};

void TRIBE_RMM_Database_Controller::add_terrain_module()
{
    long land_tile_num =
        this->map_info.maps[this->map_type].land_info.grown_land_percent * this->map_width *
        this->map_height / 100;

    RGE_RMM_Database_Controller::add_terrain_module();

    float scale = (float)land_tile_num * 0.00005f;
    int scale_index = 0;
    if (this->terrain_info.terrain_num > 0) {
        RGE_Terrain_Info_Line* line = this->terrain_info.terrain;
        do {
            if (line->terrain_type != 6 && scale > 1.0) {
                line->clumps = (long)((float)line->clumps * scale);
            }
            scale_index++;
            ++line;
        } while (scale_index < this->terrain_info.terrain_num);
    }

    if (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0x154) < 0x1fff) {
        int adjust_index = 0;
        if (this->terrain_info.terrain_num > 0) {
            int* clumps = &this->terrain_info.terrain[0].clumps;
            do {
                int type = clumps[-1];
                int* terrain_size = clumps - 3;
                int* clump_count = clumps;
                int* avoid = clumps + 4;
                if (type == 0x0d) {
                    *terrain_size *= 3;
                    *clump_count *= 3;
                    *avoid = 2;
                } else if (type == 0x14) {
                    *terrain_size /= 2;
                    *clump_count /= 2;
                } else if (type == 0x13) {
                    *terrain_size /= 2;
                    *clump_count /= 2;
                } else if (type == 0x0a) {
                    *terrain_size /= 2;
                    *clump_count /= 2;
                    *avoid = 2;
                } else if (type == 6) {
                    *terrain_size = *terrain_size + *terrain_size;
                    *avoid = 0;
                }
                adjust_index++;
                clumps += 8;
            } while (adjust_index < this->terrain_info.terrain_num);
        }
    } else {
        int fallback_index = 0;
        if (this->terrain_info.terrain_num > 0) {
            RGE_Terrain_Info_Line* line = this->terrain_info.terrain;
            int* avoid_hot_spots =
                &line->avoid_hot_spots;
            do {
                int type = avoid_hot_spots[-5];
                if (type == 6) {
                    avoid_hot_spots[0] = 0;
                } else if (type == 0x0a || type == 0x0d) {
                    avoid_hot_spots[0] = 2;
                }
                fallback_index++;
                avoid_hot_spots += 8;
            } while (fallback_index < this->terrain_info.terrain_num);
        }
    }

    int final_rand = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0x180);
    Log(L, "Random Map terrain initilization, rand: %d", final_rand);
}
