// 004486F0 ds_stream_file
// Dsutil.c (.c source)
// Recovery notes:
// - Keep this translation unit as C. The PDB donor is Dsutil.c.
// - Use the period Windows, WinMM, and DirectSound C-interface declarations.
//   The named DirectSound methods preserve the original vtable slots.
// - _WaveReadFile takes (handle, byte count, destination, chunk, actual count).
//   The exact donor at 00447F40 proves this order.
// - The first Lock length is the tested guard. The first output pointer is the
//   read destination. A separate retry cursor preserves the original EDI live
//   value. Update the cursor before the remaining-length store.
// - A reused result local before each helper failure test preserves the original
//   cmp-against-EBX selection. Direct call predicates emit test instead.
// - The third stream parameter reaches the second post-buffer virtual call.
//   The initial Unlock passes zero as its final argument.
// - 27 meaningful probes before exact recovery tested ABI, layout, context,
//   control-flow, declaration scope, and liveness alternatives.
// - Exact check: 835 bytes, 276 instructions, 20 ordered calls, frame 0x28,
//   and 0 positional difference.
// FLAGS: config/flags/004486F0_ds_stream_file.rsp = /Oi- (direct memset calls)

#include <windows.h>
#include <mmsystem.h>
#define CINTERFACE
#include <dsound.h>

extern unsigned int _bFileOpen;
extern unsigned int _bPlaying;
extern unsigned int _bTimerInstalled;
extern unsigned int _stream_paused;
extern void* _wiWave;
extern void* DAT_00888464;
extern MMCKINFO DAT_00888468;
extern MMCKINFO DAT_0088847c;
extern void* DAT_00888490;
extern unsigned int DAT_00888494;
extern unsigned int DAT_00888498;
extern unsigned int DAT_0088849c;
extern unsigned int DAT_008884a0;
extern unsigned int DAT_008884a4;
extern unsigned int DAT_008884a8;
extern unsigned int DAT_008884ac;
extern unsigned int DAT_008884b0;
extern unsigned int DAT_008884b4;
extern void* _lpDS;
extern void* _lpDSBStreamBuffer;
extern void* _main_wnd;
extern unsigned int _uTimerID;

int ds_stream_stop(void);
int _WaveOpenFile(char* file, HMMIO* h, LPWAVEFORMATEX* wi, MMCKINFO* data);
int _WaveCloseReadFile(HMMIO* h, LPWAVEFORMATEX* wi);
int _WaveStartDataRead(HMMIO* h, MMCKINFO* data, MMCKINFO* wi);
int _WaveReadFile(HMMIO h, unsigned int size, unsigned char* dest, MMCKINFO* data, unsigned int* read);
void* memset(void* dst, int c, unsigned int n);
void __stdcall ds_stream_time_func(unsigned int timer_id, unsigned int message,
    unsigned long user, unsigned long first, unsigned long second);

int ds_stream_file(char* filename, int param_2, long param_3)
{
    int result;
    unsigned int dwLen1;
    unsigned char* lpWrite1;
    unsigned int uChkErr;
    unsigned char* lpWrite2;
    unsigned int dwLen2;
    DSBUFFERDESC dsbd;

    if (_bFileOpen != 0) {
        ds_stream_stop();
    } else if (_bPlaying != 0) {
        ds_stream_stop();
    } else if (_bTimerInstalled != 0) {
        ds_stream_stop();
    }

    _stream_paused = 0;
    result = _WaveOpenFile(filename, &DAT_00888464, &_wiWave, &DAT_0088847c);
    if (result != 0) {
        return 0;
    }

    if (*(short*)_wiWave != 1) {
        _WaveCloseReadFile(&DAT_00888464, &_wiWave);
        return 0;
    }

    result = _WaveStartDataRead(&DAT_00888464, &DAT_00888468, &DAT_0088847c);
    if (result != 0) {
        _WaveCloseReadFile(&DAT_00888464, &_wiWave);
        return 0;
    }

    DAT_00888498 = ((((LPWAVEFORMATEX)_wiWave)->nAvgBytesPerSec * 120) / 100) / 6;
    DAT_00888494 = DAT_00888498 * 6;
    memset(&dsbd, 0, sizeof(dsbd));

    dsbd.dwSize = 20;
    dsbd.dwFlags = 0xE0;
    dsbd.dwBufferBytes = DAT_00888494;
    dsbd.lpwfxFormat = (void*)_wiWave;
    result = IDirectSound_CreateSoundBuffer((LPDIRECTSOUND)_lpDS, &dsbd,
        (LPLPDIRECTSOUNDBUFFER)&_lpDSBStreamBuffer, 0);
    if (result != 0) {
        return 0;
    }

    DAT_00888490 = _lpDSBStreamBuffer;
    DAT_008884b0 = 0;
    DAT_008884b4 = 0;
    result = IDirectSoundBuffer_Lock((LPDIRECTSOUNDBUFFER)_lpDSBStreamBuffer, 0, DAT_00888494,
        (void**)&lpWrite1, &dwLen1, (void**)&lpWrite2, &dwLen2, 0);
    if (result != 0) {
        return 0;
    }

    if (dwLen1 != 0) {
        _WaveReadFile(DAT_00888464, dwLen1, lpWrite1, &DAT_00888468, &uChkErr);
        if (uChkErr < dwLen1) {
            if (DAT_008884ac != 0) {
                unsigned char* lpWriteCursor = lpWrite1;
                do {
                    lpWriteCursor += uChkErr;
                    dwLen1 -= uChkErr;
                    _WaveStartDataRead(&DAT_00888464, &DAT_00888468, &DAT_0088847c);
                    _WaveReadFile(DAT_00888464, dwLen1, lpWriteCursor, &DAT_00888468, &uChkErr);
                } while (uChkErr < dwLen1);
            } else {
                DAT_008884b4 = uChkErr / DAT_00888498;
                DAT_008884b0 = 1;
        memset((unsigned char*)lpWrite1 + uChkErr,
            ((((LPWAVEFORMATEX)_wiWave)->wBitsPerSample != 8) - 1) & 0x80,
            dwLen1 - uChkErr);
            }
        }
    }

    IDirectSoundBuffer_Unlock((LPDIRECTSOUNDBUFFER)_lpDSBStreamBuffer,
        lpWrite1, dwLen1, lpWrite2, 0);

    DAT_008884a4 = 0;
    DAT_008884a0 = 0;
    DAT_0088849c = 0;
    DAT_008884a8 = 0;
    DAT_008884ac = param_2 & 0xff;
    _bFileOpen = 1;
    SendMessageA((HWND)_main_wnd, 0x502, 0, 0);

    IDirectSoundBuffer_SetCurrentPosition((LPDIRECTSOUNDBUFFER)_lpDSBStreamBuffer, 0);
    IDirectSoundBuffer_SetVolume((LPDIRECTSOUNDBUFFER)_lpDSBStreamBuffer, param_3);
    IDirectSoundBuffer_Play((LPDIRECTSOUNDBUFFER)_lpDSBStreamBuffer, 0, 0, 1);

    if (timeBeginPeriod(0x32) != 0) {
        IDirectSoundBuffer_Stop((LPDIRECTSOUNDBUFFER)_lpDSBStreamBuffer);
        _bTimerInstalled = 0;
        _bPlaying = 0;
        return 0;
    }

    _uTimerID = timeSetEvent(0x32, 10, ds_stream_time_func, 0, 1);
    if (_uTimerID != 0) {
        _bTimerInstalled = 1;
    }
    _bPlaying = 1;
    return 1;
}
