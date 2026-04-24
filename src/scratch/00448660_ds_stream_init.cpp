// first pass: initialize the dsutil globals, stash the main window / COM pointers, and mark the stream ready
// tried plain pointer types, then unsigned ints, then a local ready carrier; the remaining mismatch stayed on the final _ds_ready store shape

extern unsigned int _uLastPercent;
extern unsigned int _lpDSBStreamBuffer;
extern unsigned int _bFileOpen;
extern unsigned int _bPlaying;
extern unsigned int _bTimerInstalled;
extern unsigned int _uTimerID;
extern unsigned int _main_wnd;
extern unsigned int _lpBuffer;
extern unsigned int _lpDS;
extern unsigned int _ds_ready;

void __cdecl ds_stream_init(unsigned int main_wnd, unsigned int lpDS, unsigned int lpBuffer) {
    register unsigned int ready;

    _uLastPercent = 100;
    _lpDSBStreamBuffer = 0;
    _bFileOpen = 0;
    _bPlaying = 0;
    _bTimerInstalled = 0;
    _uTimerID = 0;
    _main_wnd = main_wnd;
    _lpBuffer = lpBuffer;
    _lpDS = lpDS;
    ready = 1;
    _ds_ready = ready;
}
