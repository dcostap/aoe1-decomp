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
// left in scratch: remaining drift is separator-home construction, parser block
// layout, gamma-table scheduling, and result/cleanup topology; not accepted-drift.

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
extern int global_gamma_index;
extern int gamma_table[];
extern void* rge_base_game;

void* ReadPalette(char* filename, long res_id, int do_gamma)
{
    unsigned char* data;
    void* own_mem = 0;
    void* hpal = (void*)-1;
    struct PaletteSizes { int resSize; int local_4; } sizes;
    char* tok = 0;
    int n = 0;
    struct LOGPAL { unsigned short ver; unsigned short cnt; unsigned char e[1]; };
    LOGPAL* lp = 0;
    unsigned char* out = 0;
    int i = 0;
    sizes.resSize = 0;
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
        data = RESFILE_load(0x62696e61, res_id, &hpal, &sizes.local_4);
        if (!hpal) {
            own_mem = malloc(sizes.local_4);
            memcpy(own_mem, data, sizes.local_4);
            hpal = (void*)1;
        } else {
            own_mem = data;
        }
    }
    if (!own_mem) return 0;
    char seps[4];
    seps[0] = ' '; seps[1] = '\t'; seps[2] = '\n'; seps[3] = 0;
    if (!strtok((char*)own_mem, seps)) goto cleanup;
    if (!strtok(0, seps)) goto cleanup;
    tok = strtok(0, seps);
    if (!tok) goto cleanup;
    n = (int)atol(tok);
    res_id = 0;
    lp = (LOGPAL*)malloc(n * 4 + 8);
    if (!lp) goto cleanup;
    lp->ver = 0x300;
    lp->cnt = (unsigned short)n;
    out = lp->e + 1;
    for (i=0; i<n; ++i) {
        tok = strtok(0, seps); if (!tok) break; out[-1] = (unsigned char)atoi(tok);
        tok = strtok(0, seps); if (!tok) break; out[0] = (unsigned char)atoi(tok);
        tok = strtok(0, seps); if (!tok) break; out[1] = (unsigned char)atoi(tok);
        out[2] = 0;
        if (i == n-1) res_id = 1;
        out += 4;
    }
    if (res_id && n == 0x100 && global_gamma_index >= 0) {
        int idx = global_gamma_index;
        int* g = gamma_table;
        while (idx >= 0) {
            ((unsigned char*)lp)[idx*4+4] = ((unsigned char*)g)[0];
            ((unsigned char*)lp)[idx*4+5] = ((unsigned char*)g)[1];
            ((unsigned char*)lp)[idx*4+6] = ((unsigned char*)g)[2];
            ((unsigned char*)lp)[idx*4+7] = 0;
            idx = *(int*)((char*)g+3);
            g += 2;
        }
    }
    if (res_id) {
        sizes.resSize = (int)CreatePalette(lp);
        if (do_gamma) CreateIdentityPalette((void*)sizes.resSize);
    }
    free(lp);
cleanup:
    if (hpal == (void*)1) free(own_mem);
    return (void*)sizes.resSize;
}
