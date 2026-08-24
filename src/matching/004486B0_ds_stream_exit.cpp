extern int _ds_ready;
extern unsigned int _bFileOpen;
extern unsigned int _bPlaying;
extern unsigned int _bTimerInstalled;

int ds_stream_stop(void);

void __cdecl ds_stream_exit(void) {
    if (_ds_ready != 0) {
        if ((_bFileOpen != 0) || (_bPlaying != 0) || (_bTimerInstalled != 0)) {
            ds_stream_stop();
        }
        _ds_ready = 0;
    }
}
