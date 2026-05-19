/* VA: 00448A80 ds_stream_stop */
/* Dsutil.c lines 1638-1678, 162 bytes */

extern int _bTimerInstalled;
extern int _uTimerID;
extern int _bPlaying;
extern void* _lpDSBStreamBuffer;
extern int _bFileOpen;
extern int _wiWave;
extern int DAT_008884a8;
extern int DAT_00888464;
extern int DAT_00888490;

extern void (__stdcall *timeKillEvent)(int id);
extern void (__stdcall *timeEndPeriod)(int period);
extern int __cdecl _WaveCloseReadFile(void* a, void* b);

int __cdecl ds_stream_stop(void)
{
    DAT_008884a8 = 1;
    if (_bTimerInstalled != 0) {
        _bTimerInstalled = 0;
        timeKillEvent(_uTimerID);
        timeEndPeriod(0x32);
    }

    if (_bPlaying != 0) {
        _bPlaying = 0;
        if (_lpDSBStreamBuffer != 0) {
            (*(void (__stdcall**)(void*))(*(int*)_lpDSBStreamBuffer + 0x48))(_lpDSBStreamBuffer);
        }
    }

    if (_bFileOpen != 0) {
        if (_wiWave != 0) {
            _WaveCloseReadFile(&DAT_00888464, &_wiWave);
            _wiWave = 0;
        }
        if (_lpDSBStreamBuffer != 0) {
            (*(void (__stdcall**)(void*))(*(int*)_lpDSBStreamBuffer + 8))(_lpDSBStreamBuffer);
            _lpDSBStreamBuffer = 0;
            DAT_00888490 = 0;
        }
        _bFileOpen = 0;
    }
    return 1;
}
