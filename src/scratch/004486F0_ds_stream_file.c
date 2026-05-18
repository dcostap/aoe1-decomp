// 004486F0 ds_stream_file
// Dsutil.c (.c source)
// Attempt log:
// 1: C implementation from packet/decompiler using DS globals, wave helpers, DirectSound vtable calls.
// 2: Used .c scratch per PDB source; compiles and final size equals original 835 bytes.
// 3: Current diff: 465 positional bytes (55.69%), 747 edit bytes (89.46%), first mismatch at prologue register allocation.
// 4: Original uses EBX as zero (`xor ebx,ebx`) and later EBP as one; rebuilt uses EBP as zero and EBX as one, cascading through compares/stores/pushes.
// 5: Added register zero/one locals and rewrote early comparisons/stores through them; no codegen change.
// 6: Tried compiling as .cpp despite Dsutil.c source; produced wrong size / too-small .text, rolled back to .c.
// 7: Tried aliasing memset as memset2 to force calls instead of inline zeroing; generated too-small .text and worse shape, rolled back.
// 8: Call set and broad behavior are represented: ds_stream_stop, WaveOpen/Close/Start/Read, CreateSoundBuffer/Lock/Unlock/Set*, SendMessageA, timeBeginPeriod/timeSetEvent.
// 9: Mid-function DSBUFFERDESC/Lock region differs: rebuilt inlines/zeroes descriptor fields and orders arguments differently; original does `memset(&dsbd,0,0x14)` then compact stores.
// 10: Loop/fill branch is semantically represented, but register family is inverted (ESI/ECX and EBX/EBP zero/one) and branch layout is not localized.
// GIVEUP: left in scratch; no accepted_drift proposal because mismatch is broad from prologue register allocation and DSBUFFERDESC setup, not a localized equivalent drift.

extern unsigned int _bFileOpen;
extern unsigned int _bPlaying;
extern unsigned int _bTimerInstalled;
extern unsigned int _stream_paused;
extern unsigned int _wiWave;
extern unsigned int DAT_00888464;
extern unsigned int DAT_00888468;
extern unsigned int DAT_0088847c;
extern unsigned int DAT_00888490;
extern unsigned int DAT_00888494;
extern unsigned int DAT_00888498;
extern unsigned int DAT_0088849c;
extern unsigned int DAT_008884a0;
extern unsigned int DAT_008884a4;
extern unsigned int DAT_008884a8;
extern unsigned int DAT_008884ac;
extern unsigned int DAT_008884b0;
extern unsigned int DAT_008884b4;
extern unsigned int _lpDS;
extern unsigned int _lpDSBStreamBuffer;
extern unsigned int _main_wnd;
extern unsigned int _uTimerID;

void ds_stream_stop(void);
int _WaveOpenFile(char* file, unsigned int* h, unsigned int* wi, unsigned int* data);
int _WaveCloseReadFile(unsigned int* h, unsigned int* wi);
int _WaveStartDataRead(unsigned int* h, unsigned int* data, unsigned int* wi);
int _WaveReadFile(unsigned int h, void* dest, unsigned int size, unsigned int* data, unsigned int* read);
void* memset(void* dst, int c, unsigned int n);
__declspec(dllimport) int __stdcall SendMessageA(unsigned int hwnd, unsigned int msg, unsigned int w, unsigned int l);
__declspec(dllimport) int __stdcall timeBeginPeriod(unsigned int p);
__declspec(dllimport) unsigned int __stdcall timeSetEvent(unsigned int delay, unsigned int res, void* proc, unsigned int user, unsigned int flags);
void __stdcall ds_stream_time_func(void);

struct DSBUFFERDESC_MINE {
    unsigned int dwSize;
    unsigned int dwFlags;
    unsigned int dwBufferBytes;
    unsigned int dwReserved;
    void* lpwfxFormat;
};

int ds_stream_file(char* filename, int param_2)
{
    unsigned int dwLen1;
    unsigned char* lpWrite1;
    unsigned int uChkErr;
    unsigned char* lpWrite2;
    unsigned int dwLen2;
    struct DSBUFFERDESC_MINE dsbd;
    register int zero = 0;
    register int one = 1;

    if (_bFileOpen != zero || _bPlaying != zero || _bTimerInstalled != zero) {
        ds_stream_stop();
    }

    _stream_paused = zero;
    if (_WaveOpenFile(filename, &DAT_00888464, &_wiWave, &DAT_0088847c) != zero) {
        return zero;
    }

    if (*(short*)_wiWave != one) {
        _WaveCloseReadFile(&DAT_00888464, &_wiWave);
        return zero;
    }

    if (_WaveStartDataRead(&DAT_00888464, &DAT_00888468, &DAT_0088847c) != zero) {
        _WaveCloseReadFile(&DAT_00888464, &_wiWave);
        return zero;
    }

    DAT_00888498 = (((*(unsigned int*)(_wiWave + 8) * 120) / 100) / 6);
    DAT_00888494 = DAT_00888498 * 6;
    memset(&dsbd, zero, 20);

    dsbd.dwSize = 20;
    dsbd.dwFlags = 0xE0;
    dsbd.dwBufferBytes = DAT_00888494;
    if ((*(int (__stdcall **)(unsigned int, struct DSBUFFERDESC_MINE*, unsigned int*, int))(*(unsigned int*)_lpDS + 0x0C))(_lpDS, &dsbd, &_lpDSBStreamBuffer, 0) != 0) {
        return 0;
    }

    DAT_00888490 = _lpDSBStreamBuffer;
    DAT_008884b0 = 0;
    DAT_008884b4 = 0;
    if ((*(int (__stdcall **)(unsigned int, int, unsigned int, void**, unsigned int*, void**, unsigned int*, int))(*(unsigned int*)_lpDSBStreamBuffer + 0x2C))(
        _lpDSBStreamBuffer, 0, DAT_00888494, (void**)&lpWrite1, &dwLen1, (void**)&lpWrite2, &dwLen2, 0) != 0) {
        return 0;
    }

    if (lpWrite1 != 0) {
        _WaveReadFile(DAT_00888464, lpWrite1, dwLen1, &DAT_00888468, &uChkErr);
        if (uChkErr < dwLen1) {
            if (DAT_008884ac != 0) {
                do {
                    dwLen1 -= uChkErr;
                    lpWrite1 += uChkErr;
                    _WaveStartDataRead(&DAT_00888464, &DAT_00888468, &DAT_0088847c);
                    _WaveReadFile(DAT_00888464, lpWrite1, dwLen1, &DAT_00888468, &uChkErr);
                } while (uChkErr < dwLen1);
            } else {
                DAT_008884b4 = uChkErr / DAT_00888498;
                DAT_008884b0 = 1;
                memset(lpWrite1 + uChkErr, ((*(short*)(_wiWave + 0x0E) != 8) - 1) & 0x80, dwLen1 - uChkErr);
            }
        }
    }

    (*(int (__stdcall **)(unsigned int, void*, unsigned int, unsigned int, int))(*(unsigned int*)_lpDSBStreamBuffer + 0x4C))(_lpDSBStreamBuffer, lpWrite1, dwLen1, 0, 0);

    DAT_008884a4 = 0;
    DAT_008884a0 = 0;
    DAT_0088849c = 0;
    DAT_008884a8 = 0;
    DAT_008884ac = param_2 & 0xff;
    _bFileOpen = 1;
    SendMessageA(_main_wnd, 0x502, 0, 0);

    (*(int (__stdcall **)(unsigned int, int))(*(unsigned int*)_lpDSBStreamBuffer + 0x34))(_lpDSBStreamBuffer, 0);
    (*(int (__stdcall **)(unsigned int, int))(*(unsigned int*)_lpDSBStreamBuffer + 0x3C))(_lpDSBStreamBuffer, param_2);
    (*(int (__stdcall **)(unsigned int, int, int, int))(*(unsigned int*)_lpDSBStreamBuffer + 0x30))(_lpDSBStreamBuffer, 0, 0, 1);

    if (timeBeginPeriod(0x32) != 0) {
        (*(int (__stdcall **)(unsigned int))(*(unsigned int*)_lpDSBStreamBuffer + 0x48))(_lpDSBStreamBuffer);
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
