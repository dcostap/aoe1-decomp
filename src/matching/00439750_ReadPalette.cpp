// VA: 00439750 ReadPalette
// Attempt log:
// - Initial reconstruction modeled file/resource loading, JASC token parsing,
//   LOGPALETTE construction, palette creation, gamma-table patching, and cleanup.
// - Restored the proven CRT/GDI call set: atol for the palette count, a direct
//   memcpy call, and the decorated CreateIdentityPalette target.
// - Recovered the original ownership surface: own_mem is the loaded-data pointer,
//   hpal remains the ownership marker, res_id is the parse-success home, and
//   resSize is the palette-result home.  A typed adjacent PaletteSizes aggregate
//   preserves the binary-proven resource-size/result local window.
// - A branch-local resource pointer plus direct own_mem allocation/memcpy restored
//   the original call-crossing register/lifetime basin.  Best validation is 421
//   differing bytes, 25/25 calls, 0x10 frame, and 664/698 bytes; first mismatch
//   is now the separator-buffer initialization.
// - Reconstructed the binary-backed three-byte space-newline separator literal;
//   assigning all three early strtok results to tok moved the best check to 130
//   differing bytes, 25/25 calls, 0x10 frame, and 668/698 bytes.
// - Delayed the loop-index and parse-success homes until after the allocation
//   check.  The precheck do-while and nested result guard were tested and rolled
//   back because they added an extra strtok or widened the structural drift.
// - Restored the binary-proven draw-system DrawType/ScreenMode guard before the
//   identity-palette call; this recovered the original 698-byte function size.
// - Moved the parse-success reset before the palette allocation check; this
//   recovered the original pre-compare zero/store topology and reduced drift.
// - Tested a natural successful-palette scope, absolute global spelling, nested
//   draw guard, declaration order, and a result alias; only the reset changed code.
// - Twenty distinct probes were run. A natural counted loop, typed result local,
//   and padded eight-byte gamma record reduced the mismatch to four bytes.
// - A 16-variant local lab found no exact variant. Its best invariant result had
//   no exact match after relocation-aware review, so it was not promoted.
// - Revisit checkpoint: the clean typed source differed at offsets +0x231,
//   +0x23B, +0x242, and +0x24E. Each byte was the displacement in one gamma
//   table load. The rebuilt anchor was one byte before the executable anchor.
// - Revisit probes tested natural record alignment, field grouping, nested
//   color ownership, complete table declarations, mutable versus const table
//   types, typed access forms, declaration and initialization order, pointer
//   update forms, loop form, and typed palette-entry ownership.  All valid
//   typed record variants stayed in the same four-byte codegen basin.
// - BINARY NOTE: PAL_TABLE is a reviewed 0x8-byte record with index at +0 and
//   red, green, blue, and reserved bytes at +4, +5, +6, and +7. The original
//   System_color_Table symbol is at 005841e0, and its repeated 0x8-byte data
//   records are referenced by both ReadPalette and CreateIdentityPalette.
// - The named System_color_Table[] declaration gives the original decorated
//   symbol and makes DAT_005841e5 the first record's green field. The loop
//   reads colors from one record, advances one record, then reads the next
//   record's index. This is the natural linked PAL_TABLE ownership model.
//   No raw DAT_005841e5 cursor or shifted record is used.
// - BINARY NOTE: the exact CreateIdentityPalette sibling uses a byte pointer
//   anchored at DAT_005841e5 for this same linked color table.  That explains
//   the shipped anchor. Its typed PAL_TABLE owner is used here instead.

#include <string.h>

extern "C" int __cdecl _open(char*, int);
extern "C" int __cdecl _lseek(int, int, int);
extern "C" int __cdecl _tell(int);
extern "C" int __cdecl _read(int, void*, int);
extern "C" int __cdecl _close(int);
extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);
#pragma function(memcpy)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern "C" unsigned char* __cdecl RESFILE_load(unsigned long, long, void**, int*);
extern "C" char* __cdecl strtok(char*, const char*);
extern "C" long __cdecl atol(const char*);
extern "C" int __cdecl atoi(const char*);
extern "C" void* (__stdcall* const CreatePalette)(void*);
void __cdecl CreateIdentityPalette(void*);
extern unsigned char shape_file_first;
struct PAL_TABLE {
    int index;
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char reserved;
};
extern PAL_TABLE System_color_Table[];
struct DrawSystem {
    char gap_000[0x478];
    unsigned char DrawType;
    unsigned char ScreenMode;
};
struct RGEBaseGame {
    char gap_000[0x48];
    DrawSystem* draw_system;
};
extern RGEBaseGame* rge_base_game;

void* ReadPalette(char* filename, long res_id, int do_gamma)
{
    unsigned char* data;
    void* own_mem = 0;
    void* hpal = (void*)-1;
    void* result = 0;
    int local_4;
    char* tok = 0;
    int n = 0;
    struct LOGPAL { unsigned short ver; unsigned short cnt; unsigned char e[1]; };
    LOGPAL* lp = 0;
    int i = 0;
    unsigned char* out = 0;
    if (filename && *filename && shape_file_first) {
        int fd = _open(filename, 0x8000);
        if (fd != -1) {
            _lseek(fd, 0, 2);
            int size = _tell(fd);
            own_mem = malloc(size);
            if (own_mem) {
                _lseek(fd, 0, 0);
                _read(fd, own_mem, size);
                hpal = (void*)1;
            }
            _close(fd);
        }
    }
    if (!own_mem && res_id != -1) {
        data = RESFILE_load(0x62696e61, res_id, &hpal, &local_4);
        if (!hpal) {
            own_mem = malloc(local_4);
            memcpy(own_mem, data, local_4);
            hpal = (void*)1;
        } else {
            own_mem = data;
        }
    }
    if (!own_mem) return 0;
    char seps[3] = " \n";
    tok = strtok((char*)own_mem, seps);
    if (tok == 0) goto cleanup;
    tok = strtok(0, seps);
    if (tok == 0) goto cleanup;
    tok = strtok(0, seps);
    if (tok == 0) goto cleanup;
    n = (int)atol(tok);
    lp = (LOGPAL*)malloc(n * 4 + 8);
    res_id = 0;
    if (lp) {
        i = 0;
        lp->cnt = (unsigned short)n;
        lp->ver = 0x300;
        if (n <= 0) goto palette_entries_done;
        out = lp->e + 1;
        while (1) {
            tok = strtok(0, seps); if (!tok) goto palette_entries_done; out[-1] = (unsigned char)atoi(tok);
            tok = strtok(0, seps); if (!tok) goto palette_entries_done; out[0] = (unsigned char)atoi(tok);
            tok = strtok(0, seps); if (!tok) goto palette_entries_done; out[1] = (unsigned char)atoi(tok);
            out[2] = 0;
            if (i == n-1) res_id = 1;
            ++i;
            out += 4;
            if (i >= n) goto palette_entries_done;
        }
palette_entries_done:
        ;
        if (res_id && n == 0x100 && System_color_Table[0].index >= 0) {
            int idx = System_color_Table[0].index;
            PAL_TABLE* g = System_color_Table;
            while (idx >= 0) {
                lp->e[idx*4] = g->red;
                lp->e[idx*4+1] = g->green;
                lp->e[idx*4+2] = g->blue;
                lp->e[idx*4+3] = 0;
                ++g;
                idx = g->index;
            }
        }
        if (res_id) {
            result = CreatePalette(lp);
            if (do_gamma) {
                if (rge_base_game->draw_system->DrawType == 1 ||
                    rge_base_game->draw_system->ScreenMode == 1)
                    CreateIdentityPalette(result);
            }
        }
        free(lp);
    }
cleanup:
    if (hpal == (void*)1) free(own_mem);
    return result;
}
