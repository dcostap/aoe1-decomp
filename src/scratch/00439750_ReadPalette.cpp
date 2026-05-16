// VA: 00439750 ReadPalette
// Attempt log:
// initial reconstruction from packet: load palette bytes from file or resource, parse JASC-PAL text palette, create HPALETTE, optional gamma tweak, free owned data.
// modeled direct file path: _open/_lseek/_tell/malloc/read/close with shape_file_first gate and ownership flag.
// modeled resource fallback via RESFILE_load('anib'), malloc/memcpy when resource handle is zero, borrowed pointer otherwise.
// modeled strtok/atoi parser for palette count and RGB triples, LOGPALETTE allocation size n*4+8, CreatePalette IAT call, optional post gamma hook.
// had to hoist locals above cleanup label for VC5 C++ goto rules; current rough source compiles.
// left in scratch: rebuilt .text is 672 vs original 698, so no positional diff; behavior/surfaces approximate and not accepted_drift-safe.

extern "C" int __cdecl _open(char*, int);
extern "C" int __cdecl _lseek(int, int, int);
extern "C" int __cdecl _tell(int);
extern "C" int __cdecl _read(int, void*, int);
extern "C" int __cdecl _close(int);
extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern "C" unsigned char* __cdecl RESFILE_load(unsigned long, long, void**, int*);
extern "C" char* __cdecl strtok(char*, const char*);
extern "C" int __cdecl atoi(const char*);
extern "C" void* (__stdcall* const CreatePalette)(void*);
extern "C" void __cdecl sub_43AB80(void*);
extern unsigned char shape_file_first;
extern int global_gamma_index;
extern int gamma_table[];
extern void* rge_base_game;

void* ReadPalette(char* filename, long res_id, int do_gamma)
{
    void* data = 0;
    int own_mem = 0;
    void* hpal = (void*)-1;
    int resSize = 0;
    char* tok = 0;
    int n = 0;
    struct LOGPAL { unsigned short ver; unsigned short cnt; unsigned char e[1]; };
    LOGPAL* lp = 0;
    int ok = 0;
    unsigned char* out = 0;
    int i = 0;
    if (filename && *filename && shape_file_first) {
        int fd = _open(filename, 0x8000);
        if (fd != -1) {
            _lseek(fd, 0, 2);
            int size = _tell(fd);
            void* p = malloc(size);
            data = p;
            if (p) {
                _lseek(fd, 0, 0);
                _read(fd, p, size);
                hpal = (void*)1;
            }
            _close(fd);
        }
    }
    if (!data && res_id != -1) {
        unsigned char* p = RESFILE_load(0x62696e61, res_id, &hpal, &resSize);
        if (!hpal) {
            data = malloc(resSize);
            memcpy(data, p, resSize);
            hpal = (void*)1;
        } else {
            data = p;
        }
    }
    if (!data) return 0;
    char seps[4];
    seps[0] = ' '; seps[1] = '\t'; seps[2] = '\n'; seps[3] = 0;
    if (!strtok((char*)data, seps)) goto cleanup;
    if (!strtok(0, seps)) goto cleanup;
    tok = strtok(0, seps);
    if (!tok) goto cleanup;
    n = atoi(tok);
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
        if (i == n-1) ok = 1;
        out += 4;
    }
    if (ok && n == 0x100 && global_gamma_index >= 0) {
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
    if (ok) {
        hpal = CreatePalette(lp);
        if (do_gamma) sub_43AB80(hpal);
    }
    free(lp);
cleanup:
    if (hpal == (void*)1) free(data);
    return hpal;
}
