// VA: 00487DD0, TRIBE_RMM_Database_Controller::add_terrain_module, 461 bytes
// Source: rmm_tdbc.cpp lines 321-385
// Attempt log:
// - v1: natural reconstruction from packet/decompiler with local layout and terrain-line stride 0x20.
// - v2: modeled initial land_tile_num percent calculation using /100 idiom and base-class call.
// - v3: modeled both debug_rand branches and final TDebuggingLog::Log call.
// - v4: fixed class gaps after vptr so mod_count/map_infos land at +0x20d4/+0x4f58.
// - v5: split percent multiply statements to try to force imul +0x18 before +0x14; no change.
// - v6: changed final log to cdecl helper surface to match push log, push fmt, push rand cleanup.
// - v7: introduced local w for +0x18 multiply order probe; no change.
// - v8: used raw offset casts for +0x18 then +0x14 multiply; no change.
// - v9: introduced local log pointer before final cdecl log call; no change.
// - v10: declared g_debug_log as int and cast in call to probe final global load register; no change.
// - v11: paused in scratch. Best check: 461/461 bytes, positional diff 16.4859%, edit diff 10.6291%, first mismatch +0x1f.
//   Blocker: stubborn but localized codegen/register ordering. Main behavior and most bytes match; remaining early diff is
//   multiply order for +0x14/+0x18 operands (`imul [esi+14]` vs original `imul [esi+18]`) despite expression/order/raw-offset
//   probes. Final log call is behaviorally right but loads the global through ECX before pushes rather than original EAX after
//   pushing rand. No inline asm.

typedef unsigned char uchar;

extern "C" int __cdecl debug_rand(char* file, int line);

class TDebuggingLog;
extern "C" void __cdecl DebugLog_Log(TDebuggingLog* log, char* fmt, int value);
extern int g_debug_log;

static char s_file[] = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp";
static char s_log[] = "Random Map terrain initilization, rand: %d";

class TRIBE_History_Info;

struct TerrainLine {
    int field_00;    // -0x10 from pointer used in second loop? unused
};

struct TerrainMod {
    char gap_00[0x14];
    int chance;       // +0x14 relative to start, ecx-0xc
    int type;         // +0x1c relative, ecx-4
    int amount;       // +0x20 relative, ecx
    char gap_24[0x0c];
    int flag;         // +0x30 relative, ecx+0x10
};

class MapInfoTable {
public:
    char gap_00[0x20];
    int vals[1];
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
    int map_height;         // +0x14
    int map_width;          // +0x18
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
    int land_tile_num;
    int percent = this->map_infos->vals[this->map_type * 18];
    int w = *(int*)((char*)this + 0x18);
    percent *= w;
    percent *= *(int*)((char*)this + 0x14);
    percent /= 100;
    land_tile_num = percent;

    RGE_RMM_Database_Controller::add_terrain_module();

    float scale = (float)land_tile_num * 0.00005f;
    int i = 0;
    if (this->mod_count > 0) {
        int* p = (int*)((char*)this + 0x1480);
        do {
            if (*(p - 1) != 6 && scale > 1.0) {
                *p = (long)((float)*p * scale);
            }
            i++;
            p += 8;
        } while (i < this->mod_count);
    }

    if (debug_rand(s_file, 0x154) < 0x1fff) {
        i = 0;
        if (this->mod_count > 0) {
            int* p = (int*)((char*)this + 0x1480);
            do {
                int type = *(p - 1);
                if (type == 0x0d) {
                    *(p - 3) = *(p - 3) * 3;
                    *p = *p * 3;
                    p[4] = 2;
                } else if (type == 0x14) {
                    *(p - 3) = *(p - 3) / 2;
                    *p = *p / 2;
                } else if (type == 0x13) {
                    *(p - 3) = *(p - 3) / 2;
                    *p = *p / 2;
                } else if (type == 0x0a) {
                    *(p - 3) = *(p - 3) / 2;
                    *p = *p / 2;
                    p[4] = 2;
                } else if (type == 6) {
                    *(p - 3) = *(p - 3) << 1;
                    p[4] = 0;
                }
                i++;
                p += 8;
            } while (i < this->mod_count);
        }
    } else {
        i = 0;
        if (this->mod_count > 0) {
            int* p = (int*)((char*)this + 0x1490);
            do {
                int type = *(p - 5);
                if (type == 6) {
                    *p = 0;
                } else if (type == 0x0a || type == 0x0d) {
                    *p = 2;
                }
                i++;
                p += 8;
            } while (i < this->mod_count);
        }
    }

    int r = debug_rand(s_file, 0x180);
    DebugLog_Log((TDebuggingLog*)g_debug_log, s_log, r);
}
