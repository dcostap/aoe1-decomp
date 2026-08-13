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

typedef unsigned char uchar;

extern "C" int __cdecl debug_rand(char* file, int line);

class TDebuggingLog {
public:
    void Log(char* fmt, ...);
};
#define L (*(TDebuggingLog**)0x62C4FC)

static char s_file[] = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp";
static char s_log[] = "Random Map terrain initilization, rand: %d";

class MapInfoTable {
public:
    char gap_00[0x20];
    int vals[1];
};

class RGE_Terrain_Info_Line {
public:
    int terrain_size;
    int terrain_generated;
    int terrain_type;
    int clumps;
    int spacing;
    int base_terrain_type;
    int clumpiness_factor;
    int avoid_hot_spots;
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
    char gap_38[0x20d4 - 0x38];
    int mod_count;          // +0x20d4
    char gap_after2[0x4f58 - 0x20d8];
    MapInfoTable* map_infos; // +0x4f58

    void add_terrain_module();
};

void TRIBE_RMM_Database_Controller::add_terrain_module()
{
    int land_tile_num =
        this->map_infos->vals[this->map_type * 18] * this->map_width *
        this->map_height / 100;

    RGE_RMM_Database_Controller::add_terrain_module();

    float scale = (float)land_tile_num * 0.00005f;
    int i = 0;
    if (this->mod_count > 0) {
        RGE_Terrain_Info_Line* line =
            (RGE_Terrain_Info_Line*)((char*)this + 0x1474);
        do {
            if (line->terrain_type != 6 && scale > 1.0) {
                line->clumps = (long)((float)line->clumps * scale);
            }
            i++;
            ++line;
        } while (i < this->mod_count);
    }

    if (debug_rand(s_file, 0x154) < 0x1fff) {
        i = 0;
        if (this->mod_count > 0) {
            RGE_Terrain_Info_Line* line =
                (RGE_Terrain_Info_Line*)((char*)this + 0x1474);
            do {
                int type = line->terrain_type;
                if (type == 0x0d) {
                    line->terrain_size = line->terrain_size * 3;
                    line->clumps = line->clumps * 3;
                    line->avoid_hot_spots = 2;
                } else if (type == 0x14) {
                    line->terrain_size = line->terrain_size / 2;
                    line->clumps = line->clumps / 2;
                } else if (type == 0x13) {
                    line->terrain_size = line->terrain_size / 2;
                    line->clumps = line->clumps / 2;
                } else if (type == 0x0a) {
                    line->terrain_size = line->terrain_size / 2;
                    line->clumps = line->clumps / 2;
                    line->avoid_hot_spots = 2;
                } else if (type == 6) {
                    line->terrain_size = line->terrain_size << 1;
                    line->avoid_hot_spots = 0;
                }
                i++;
                ++line;
            } while (i < this->mod_count);
        }
    } else {
        i = 0;
        if (this->mod_count > 0) {
            RGE_Terrain_Info_Line* line =
                (RGE_Terrain_Info_Line*)((char*)this + 0x1474);
            do {
                int type = line->terrain_type;
                if (type == 6) {
                    line->avoid_hot_spots = 0;
                } else if (type == 0x0a || type == 0x0d) {
                    line->avoid_hot_spots = 2;
                }
                i++;
                ++line;
            } while (i < this->mod_count);
        }
    }

    L->Log(s_log, debug_rand(s_file, 0x180));
}
