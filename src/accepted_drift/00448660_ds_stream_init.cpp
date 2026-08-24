// ds_stream_init - initialize DSUTIL globals
// VA: 00448660
// Dsutil.c:1392-1408
// 77 bytes, 9 diff bytes (11.69%)
// Scheduling/encoding quirk: mov eax,1 + mov [addr],eax vs mov dword [addr],1.
// Original: mov eax,1 (b8) before lpBuffer/lpDS stores, reuses eax for ds_ready (a3).
// Rebuilt:  mov dword [addr],1 (c7 05) at end.
// 4+ source forms tried (order tricks, temp var). Invariant encoding choice.
// 10 relocations masked.

extern unsigned int _uLastPercent;
extern void* _lpDSBStreamBuffer;
extern unsigned int _bFileOpen;
extern unsigned int _bPlaying;
extern unsigned int _bTimerInstalled;
extern unsigned int _uTimerID;
extern void* _main_wnd;
extern unsigned int _lpBuffer;
extern void* _lpDS;
extern unsigned int _ds_ready;

void __cdecl ds_stream_init(unsigned int main_wnd, unsigned int lpDS, unsigned int lpBuffer) {
    _uLastPercent = 100;
    _lpDSBStreamBuffer = 0;
    _bFileOpen = 0;
    _bPlaying = 0;
    _bTimerInstalled = 0;
    _uTimerID = 0;
    _main_wnd = main_wnd;
    _lpBuffer = lpBuffer;
    _lpDS = lpDS;
    _ds_ready = 1;
}
