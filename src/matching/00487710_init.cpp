// VA: 00487710 TRIBE_RMM_Database_Controller::init
// Attempt log:
// Initial natural reconstruction from packet/Ghidra. Uses /GX for EH around new + by-value RGE_Cliffs_Info constructor call.
// try 1: no /GX compiled but wrong frame; kept /GX because original has EH registration and new/ctor local_4 state.
// try 2: made base init a virtual-style call; extra vtable load and pointer adjustment, rolled back to qualified base call.
// try 3: qualified RGE_RMM_Database_Controller::init fixed prologue/base-call sequence through debug_rand.
// try 4: modeled RGE_RMM_Cliffs_Generator size as 0x508; fixed operator new push size.
// try 5: shifted RGE_Cliffs_Info to begin at number_of_cliffs_variance; fixed main stack field offsets.
// try 6: introduced separate volatile number_of_cliffs local to force default reload from [esp+0Ch]; fixed switch dispatch/jump distances through 00487807.
// try 7: loop source/destination order variants still produce src in ECX/dst in EAX rather than original dst in ECX/src in EAX.
// try 8: volatile hot_spot_count local produced a store but to wrong stack slot and worsened tail offsets; rolled back.
// fresh dossier: same-TU donors and the RGE_Cliffs_Generator constructor confirm /GX, a 0x508 allocation, and a 0x130-dword by-value copy.
// fresh probe: canonical RGE_Cliffs_Info field layout changed stack homes and worsened positional diff; restored the binary-proven aggregate home.
// fresh probe: typed RGE_Cliffs_Hot_Spots records with explicit tail preserved the 0x4C0 aggregate and kept the prior basin.
// fresh probe: typed source records (three data words plus one stride pad) and a natural x/y/radius copy loop improved diff 186 -> 116; first 351 bytes aligned.
// fresh probe: volatile loop-count materialization widened the function and worsened all metrics; rolled back.
// fresh probe: swapped typed cursor declarations returned to the old register basin; rolled back.
// fresh probe: explicit placement construction removed EH cleanup but lost the original EH frame; rolled back.
// fresh probe: a typed generator-pointer local changed early parameter reloads and worsened diff; rolled back.
// fresh probe: mirrored exact same-TU add_shallows_module's long* second-field destination cursor with a typed source; diff improved 116 -> 115, but the cursor registers remain reversed.
// new claim probe: canonical RGE_Cliffs_Info ownership plus y-anchored source/destination cursors exposed the original +20DC/+2C addresses; the natural field form still added a 46-byte structural tail and kept registers reversed, so it was rolled back.
// new claim probe: naming and assigning the proven trailing hot_spot_num reproduced the original [esp+4CC] count store; combined with y/radius cursors it reached diagnostic diff 85 but retained the 46-byte EH/new tail, so it was rolled back.
// new claim probe: direct canonical number_of_cliffs ownership removed the decompiler-only variance alias but did not change the structural basin; restored the validated donor-shaped source.
// revisit probe: a typed trailing hot_spot_num plus radius/y member cursors and a standalone new expression reduced the diagnostic diff to 10 bytes, but required volatile reloads; rejected by policy.
// revisit probe: nonvolatile natural aliases, unions, and references collapsed the two proven fallback loads and stayed at a larger mismatch; restored the clean donor-shaped source.
// final revisit state: retain the no-volatility typed model with the proven trailing count and radius/y member cursors; validation is exact-size, exact-frame, and exact-call but nonexact in bytes.
// r2 probe: real <new.h>, <stdlib.h>, and <string.h> contexts did not change codegen; typed y/x anchors and donor-style record pointers did not recover the loop basin.
// r2 probe: reversing the source/destination cursor updates recovered the original loop register assignment and reduced the edit diagnostic to 22 bytes.
// r2 exact probe: two distinct uninitialized count locals coalesced to the proven [esp+0Ch] home, preserving the original duplicate loads without volatility or assembly.
// r3 probe: removing both synthetic count locals and the synthetic final else, leaving only branch-initialized base_cliff_size and cliff_size_variance, still produced an exact match.
// r3 probe: direct number_of_cliffs plus cliff_size_variance locals mismatched by 128 bytes because the jump-table selector changed register ownership.
// Ownership: PDB lines 69-100 cover the bounded size arms and default stack reads; the dossier proves two reads from the unwritten entry-relative -0x4D0 home. Same-TU pointer donors support the natural cursor loop.
// Current exact natural candidate: source, flags, owner symbol, ordered calls, frame, and positional bytes all match without synthetic temporaries, volatility, or assembly.
// FLAGS: config/flags/00487710_init.rsp (/nologo /c /O2 /Oy /GX)

#ifndef RMM_TDBC_SHARED_CONTEXT
class RGE_Map;
class RGE_Game_World;
class RGE_Random_Map_Module;
class RGE_RMM_Cliffs_Generator;

extern void* rge_base_game;
int debug_rand(char* file, int line);
void* __cdecl operator new(unsigned int size);
inline void* __cdecl operator new(unsigned int, void* ptr) { return ptr; }

class TRIBE_Game { public: int randomizePositions(); };

struct RGE_Cliffs_Hot_Spots {
    long x;
    long y;
    long radius;
};

struct RGE_Controller_Hot_Spots {
    long x;
    long y;
    long radius;
    long pad;
};

struct RGE_Cliffs_Info {
    long number_of_cliffs_variance;
    long average_cliff_size;
    long cliff_size_variance;
    long cliff_terrain_spacing;
    long cliff_to_cliff_spacing;
    RGE_Cliffs_Hot_Spots hot_spots[99];
    long tail;
    long hot_spot_num;
};

class RGE_RMM_Database_Controller {
public:
    virtual unsigned char init(RGE_Map*, RGE_Game_World*, unsigned char, long, unsigned char);
    char gap_04[0x08];
    RGE_Map* map;
    char gap_10[0x04];
    long map_size;
};

class RGE_RMM_Cliffs_Generator {
public:
    char pad[0x508];
    RGE_RMM_Cliffs_Generator(RGE_Map*, RGE_Random_Map_Module*, RGE_Cliffs_Info);
};

class TRIBE_RMM_Database_Controller : public RGE_RMM_Database_Controller {
public:
    virtual unsigned char init(RGE_Map*, RGE_Game_World*, unsigned char, long, unsigned char);
    char gap_18[0x34-0x18];
    long map_type;
    char gap_38[0x20D8-0x38];
    RGE_Controller_Hot_Spots hot_spot_data[99];
    long hot_spot_count;
};
#endif

unsigned char TRIBE_RMM_Database_Controller::init(RGE_Map* p1, RGE_Game_World* p2, unsigned char p3, long p4, unsigned char p5)
{
    RGE_Cliffs_Info cliff_info;

    p5 = (unsigned char)((((TRIBE_Game*)rge_base_game)->randomizePositions() == 0));
    this->RGE_RMM_Database_Controller::init(p1, p2, p3, p4, p5);

    if (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0x40) > 0x1fff) {
        long base_cliff_size;
        long cliff_size_variance;
        long size = this->map_width;
        if (size <= 0x48) { base_cliff_size = 3; cliff_size_variance = 10; }
        else if (size <= 0x60) { base_cliff_size = 4; cliff_size_variance = 12; }
        else if (size <= 0x78) { base_cliff_size = 6; cliff_size_variance = 14; }
        else if (size <= 0x90) { base_cliff_size = 8; cliff_size_variance = 16; }
        else if (size <= 0xC8) { base_cliff_size = 18; cliff_size_variance = 20; }
        else if (size <= 0xFA) { base_cliff_size = 28; cliff_size_variance = 20; }

        switch (this->map_type) {
        case 0: base_cliff_size = 0; cliff_size_variance = 0; break;
        case 1: base_cliff_size -= 5; cliff_size_variance -= 6; break;
        case 2: base_cliff_size -= 3; cliff_size_variance -= 2; break;
        case 5:
        case 6:
        case 8: cliff_size_variance -= 4; break;
        }
        if (cliff_size_variance < 3) cliff_size_variance = 3;

        cliff_info.number_of_cliffs_variance = base_cliff_size;
        cliff_info.average_cliff_size = 2;
        cliff_info.cliff_to_cliff_spacing = 2;
        cliff_info.hot_spots[0].x = 2;
        if (cliff_size_variance - 3 <= 0) cliff_info.cliff_terrain_spacing = 0;
        else cliff_info.cliff_terrain_spacing = (cliff_size_variance - 3) / 2;
        cliff_info.cliff_size_variance = cliff_size_variance - cliff_info.cliff_terrain_spacing;

        long n = this->terrain_info.hot_spot_num;
        cliff_info.hot_spot_num = n;
        if (n > 0) {
            long* dst = &cliff_info.hot_spots[0].radius;
            long* src = &this->terrain_info.hot_spots[0].y;
            do {
                dst[-1] = src[-1];
                dst[0] = src[0];
                dst[1] = src[1];
                src += 4;
                dst += 3;
                n--;
            } while (n != 0);
        }

        if (cliff_info.cliff_size_variance > 0 && cliff_info.number_of_cliffs_variance > 0) {
            new RGE_RMM_Cliffs_Generator(this->map, (RGE_Random_Map_Module*)this, cliff_info);
        }
    }
    return 1;
}
