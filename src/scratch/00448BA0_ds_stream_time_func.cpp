// 00448BA0 ds_stream_time_func
// Attempt log:
// try 1: direct C reconstruction from packet/Ghidra with helper clear_audio: default /O2 too small (.text 1312 vs 1332), so not comparable.
// try 2: macro-expanded CLEAR_AUDIO to recover repeated memset tests: exact-size comparable (1332/1332) but broad mismatch, 95.2703% positional / 120.1201% edit, first mismatch prologue due local initialization/control-flow topology.
// try 3: /GX no change from try 2, rolled back.
// try 4: /O1 too small (.text 1277), rolled back.
// try 5: /Od exact-size comparable but worse debug-basin mismatch (92.9429% positional / 146.8468% edit), rolled back.
// try 6-9: removed prologue zero initializers, mirrored PDB local names/order,
// and tested the local_4 GetCurrentPosition home plus shared zero/one values;
// these preserved the exact 18-call set but left the broad CFG/register basin.
// final normalized source keeps ordinary uninitialized API output locals and
// natural literal predicates rather than compiler-steering aliases.
// FLAGS: config/flags/00448BA0_ds_stream_time_func.rsp = /Oi- (five direct memset calls)
// probe 10: restored the PDB-proven unused GetCurrentPosition output home
// local_4 and the Dsutil local declaration order; emitted code was unchanged.
// probe 11: restored exact Dsutil global identities and the imported
// PostMessageA surface from donor and ABI evidence; size became 1339 bytes,
// with all 18 calls still aligned.
// probe 12: sent busy and paused guards to the shared cleanup label shown by
// the original CFG; diff improved by one byte, but the first hunk stayed open.
// Current source uses named legacy globals, typed DirectSound calls, the
// unused output home, and direct imported PostMessageA. Remaining drift starts
// at prologue save/zero scheduling and continues through Lock output homes,
// silence branches, and shared tails. Not accepted_drift.

typedef unsigned long DWORD;
typedef unsigned int UINT;
typedef int BOOL;
typedef void* HWND;
typedef unsigned char BYTE;

typedef struct WAVEFORMATEX_L { unsigned short wFormatTag; unsigned short nChannels; DWORD nSamplesPerSec; DWORD nAvgBytesPerSec; unsigned short nBlockAlign; unsigned short wBitsPerSample; unsigned short cbSize; } WAVEFORMATEX_L;

struct DSBUF;
struct DSBUFVT { void* q0; void* q4; void* q8; void* qC; long (__stdcall *GetCurrentPosition)(DSBUF*, DWORD*, DWORD*); void* q14; void* q18; void* q1C; void* q20; void* q24; void* q28; long (__stdcall *Lock)(DSBUF*, DWORD, DWORD, void**, DWORD*, void**, DWORD*, DWORD); void* q30; void* q34; void* q38; void* q3C; void* q40; void* q44; void* q48; long (__stdcall *Unlock)(DSBUF*, void*, DWORD, void*, DWORD); };
struct DSBUF { DSBUFVT* lpVtbl; };

extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" __declspec(dllimport) BOOL __stdcall PostMessageA(HWND, UINT, unsigned int, long);
extern "C" int __cdecl WaveReadFile(void*, DWORD, void*, void*, DWORD*);
extern "C" int __cdecl WaveStartDataRead(void*, void*, void*);

extern int DAT_0062e658;
extern DSBUF* DAT_00888490;
extern DWORD DAT_00888494;
extern DWORD DAT_00888498;
extern DWORD DAT_0088849c;
extern DWORD DAT_008884a0;
extern DWORD DAT_008884a4;
extern int DAT_008884a8;
extern int DAT_008884ac;
extern int DAT_008884b0;
extern int DAT_008884b4;
extern int _stream_paused;
extern HWND _main_wnd;
extern void* DAT_00888464;
extern void* DAT_00888468;
extern void* DAT_0088847c;
extern WAVEFORMATEX_L* _wiWave;

#define CLEAR_AUDIO(P,N) do { \
    WAVEFORMATEX_L* wf_ = _wiWave; \
    if (wf_ && (P)) { \
        if (wf_->wBitsPerSample == 8) memset((P), 0x80, (N)); \
        else if (wf_->wBitsPerSample == 16) memset((P), 0, (N)); \
    } \
} while (0)

extern "C" void __stdcall ds_stream_time_func(HWND hwnd, UINT msg, UINT id, DWORD time, DWORD unused)
{
    DWORD local_4;
    DWORD dwWrite;
    DWORD dwPlay;
    void* lpWrite2;
    DWORD uChkErr;
    void* lpWrite1;
    DWORD dwLen2;
    DWORD dwLen1;

    if (DAT_0062e658) goto done;
    if (_stream_paused) goto done;
    DAT_0062e658 = 1;
    if (DAT_008884a8 || !DAT_00888490) goto done;

    DAT_00888490->lpVtbl->GetCurrentPosition(DAT_00888490, &local_4, &dwWrite);
    if (DAT_0088849c < dwWrite) {
        DWORD t = DAT_0088849c + DAT_00888498;
        if (t > dwWrite) goto done;
    }

    if (DAT_008884b0 && !DAT_008884b4) {
        if (DAT_008884a8) goto done;
        DAT_008884a8 = 1;
        PostMessageA(_main_wnd, 0x500, 0, 0);
        DAT_0062e658 = 0;
        return;
    }

    {
        DWORD diff;
        if (dwWrite < DAT_008884a0) diff = DAT_00888494 + dwWrite;
        else diff = dwWrite;
        diff -= DAT_008884a0;
        DAT_008884a0 = dwWrite;
        DAT_008884a4 += diff;
        PostMessageA(_main_wnd, 0x502, 0, 0);
    }

    if (DAT_008884b0 && DAT_008884b4) {
        --DAT_008884b4;
        if (DAT_008884b4 <= 1) goto done;
        if (!DAT_00888490) goto done;
        if (DAT_00888490->lpVtbl->Lock(DAT_00888490, DAT_0088849c, DAT_00888498, &lpWrite1, &dwLen1, &lpWrite2, &dwLen2, 0)) goto done;
        CLEAR_AUDIO(lpWrite1, dwLen1);
        DAT_00888490->lpVtbl->Unlock(DAT_00888490, lpWrite1, dwLen1, lpWrite2, dwLen2);
        DAT_0088849c += DAT_00888498;
        if (DAT_0088849c < DAT_00888494) goto done;
        goto wrap_play;
    }

    if (!DAT_00888490) goto done;
    if (DAT_00888490->lpVtbl->Lock(DAT_00888490, DAT_0088849c, DAT_00888498, &lpWrite1, &dwLen1, &lpWrite2, &dwLen2, 0)) goto done;

    if (lpWrite1 && !DAT_008884a8) {
        WaveReadFile(DAT_00888464, dwLen1, lpWrite1, DAT_00888468, &uChkErr);
        if (uChkErr < dwLen1) {
            if (!DAT_008884ac) {
                CLEAR_AUDIO((BYTE*)lpWrite1 + uChkErr, dwLen1 - uChkErr);
                if (DAT_0088849c <= dwLen2) DAT_008884b4 = (DAT_00888494 + DAT_0088849c - dwLen2) / DAT_00888498;
                else DAT_008884b4 = (DAT_0088849c - dwLen2) / DAT_00888498;
                DAT_008884b0 = 1;
            } else if (dwLen2) {
                do {
                    WaveStartDataRead(DAT_00888464, DAT_00888468, DAT_0088847c);
                    WaveReadFile(DAT_00888464, dwLen1 - uChkErr, (BYTE*)lpWrite1 + uChkErr, DAT_00888468, &uChkErr);
                } while (uChkErr < dwLen1);
            }
        }
    } else if (lpWrite1 && DAT_008884a8 && _wiWave && dwLen1) {
        CLEAR_AUDIO(lpWrite1, dwLen1);
    }

    if (lpWrite2) {
        if (!DAT_008884a8) {
            WaveReadFile(DAT_00888464, dwLen2, lpWrite2, DAT_00888468, &uChkErr);
            if (uChkErr < dwLen2) {
                if (!DAT_008884ac) {
                    CLEAR_AUDIO((BYTE*)lpWrite2 + uChkErr, dwLen2 - uChkErr);
                    if (DAT_0088849c <= dwLen2) DAT_008884b4 = (DAT_00888494 + DAT_0088849c - dwLen2) / DAT_00888498;
                    else DAT_008884b4 = (DAT_0088849c - dwLen2) / DAT_00888498;
                    DAT_008884b0 = 1;
                } else if (dwLen2) {
                    do {
                        WaveStartDataRead(DAT_00888464, DAT_00888468, DAT_0088847c);
                        WaveReadFile(DAT_00888464, dwLen2 - uChkErr, (BYTE*)lpWrite2 + uChkErr, DAT_00888468, &uChkErr);
                    } while (uChkErr < dwLen2);
                }
            }
        } else if (DAT_008884a8 && _wiWave && dwLen2) {
            CLEAR_AUDIO(lpWrite2, dwLen2);
        }
    }

    if (DAT_00888490) DAT_00888490->lpVtbl->Unlock(DAT_00888490, lpWrite1, dwLen1, lpWrite2, dwLen2);
    DAT_0088849c += DAT_00888498;
    if (DAT_0088849c >= DAT_00888494) {
wrap_play:
        DAT_0088849c -= DAT_00888494;
    }

done:
    DAT_0062e658 = 0;
}
