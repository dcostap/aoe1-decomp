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
// FLAGS: config/flags/00448BA0_ds_stream_time_func.rsp = /Oi- /TC (C ABI, direct memset calls)
// probe 10: restored the PDB-proven unused GetCurrentPosition output home
// local_4 and the Dsutil local declaration order; emitted code was unchanged.
// probe 11: restored exact Dsutil global identities and the imported
// PostMessageA surface from donor and ABI evidence; size became 1339 bytes,
// with all 18 calls still aligned.
// probe 12: sent busy and paused guards to the shared cleanup label shown by
// the original CFG; diff improved by one byte, but the first hunk stayed open.
// probe 13: switching the TU to a C extension did not change emitted code.
// probe 14: split partial-read silence from full-buffer silence so the base
// write pointer is tested before adding uChkErr; this saved EBX and improved
// the diff to 1264 bytes.
// probe 15: kept end-of-stream silence's wave/length checks inside a separate
// fill form; this reached exact 1332-byte size and diff 1248.
// probe 16: mutating retry pointers and uChkErr to model stack-home reuse grew
// the body to 1345 bytes; rolled back. A p1-only version also regressed shape.
// probe 17: separating the p2 end-silence branch and a register zero/one form
// both regressed or duplicated the 1248-byte result; rolled back.
// Current source uses named legacy globals, typed DirectSound calls, the
// unused output home, and direct imported PostMessageA. Remaining drift starts
// at prologue save/zero scheduling and continues through Lock output homes,
// silence branches, and shared tails. Not accepted_drift.
// Probes 18-21: canonical VC5 C mode (/TC), SDK DirectSound/MMIO types, the
// address-taking WaveStartDataRead ABI, pointer retry guards, and literal
// zero/one forms. Calls stayed 18; no exact block moved past 15.02%.
// Final unresolved checkpoint: 1312 rebuilt bytes, 1255 positional bytes,
// 68.47% shape, 18 aligned calls, frame 0x1C, first mismatch +8.
// New claim probes:
// - Separate post-lock returns for a8 and a null buffer improved the result
//   to 1282 bytes, 1061 positional bytes, 77.26% shape, and 34.24% blocks.
// - An outer lpWrite1 guard with independent a8 branches improved shape to
//   80.59%; it was retained with the first-segment retry form below.
// - Separate retry cursors preserve lpWrite1 and lpWrite2 for Unlock while
//   the length locals shrink. Advancing both cursors before WaveStartDataRead
//   gave 1280 bytes, 1071 positional bytes, 83.50% shape, and 35.47% blocks.
//   Directly mutating lpWrite1 gave 1050 bytes but changed the Unlock pointer,
//   so it was rejected. A typed output aggregate was also rejected. Header
//   order, pointer casts, local_4 type, dwPlay, and wrap-label edits were
//   unchanged or worse. Calls stayed 18 and frame stayed 0x1C.

#include <windows.h>
#include <mmsystem.h>
#define CINTERFACE
#include <dsound.h>

extern void* __cdecl memset(void*, int, unsigned int);
extern __declspec(dllimport) BOOL __stdcall PostMessageA(HWND, UINT, unsigned int, long);
extern int __cdecl WaveReadFile(HMMIO, DWORD, unsigned char*, MMCKINFO*, DWORD*);
extern int __cdecl WaveStartDataRead(HMMIO*, MMCKINFO*, MMCKINFO*);

extern int DAT_0062e658;
extern void* DAT_00888490;
extern unsigned int DAT_00888494;
extern unsigned int DAT_00888498;
extern unsigned int DAT_0088849c;
extern unsigned int DAT_008884a0;
extern unsigned int DAT_008884a4;
extern int DAT_008884a8;
extern int DAT_008884ac;
extern int DAT_008884b0;
extern int DAT_008884b4;
extern int _stream_paused;
extern void* _main_wnd;
extern void* DAT_00888464;
extern MMCKINFO DAT_00888468;
extern MMCKINFO DAT_0088847c;
extern void* _wiWave;

#define CLEAR_AUDIO(P,N) do { \
    LPWAVEFORMATEX wf_ = (LPWAVEFORMATEX)_wiWave; \
    if (wf_ && (P)) { \
        if (wf_->wBitsPerSample == 8) memset((P), 0x80, (N)); \
        else if (wf_->wBitsPerSample == 16) memset((P), 0, (N)); \
    } \
} while (0)

#define CLEAR_AUDIO_OFFSET(P,O,N) do { \
    LPWAVEFORMATEX wf_ = (LPWAVEFORMATEX)_wiWave; \
    if (wf_ && (P)) { \
        if (wf_->wBitsPerSample == 8) memset((BYTE*)(P) + (O), 0x80, (N)); \
        else if (wf_->wBitsPerSample == 16) memset((BYTE*)(P) + (O), 0, (N)); \
    } \
} while (0)

#define CLEAR_AUDIO_LENGTH(P,N) do { \
    LPWAVEFORMATEX wf_ = (LPWAVEFORMATEX)_wiWave; \
    if (wf_ && (N)) { \
        if (wf_->wBitsPerSample == 8) memset((P), 0x80, (N)); \
        else if (wf_->wBitsPerSample == 16) memset((P), 0, (N)); \
    } \
} while (0)

void __stdcall ds_stream_time_func(HWND hwnd, UINT msg, UINT id, DWORD time, DWORD unused)
{
    DWORD dwLen1;
    DWORD dwLen2;
    unsigned char* lpWrite1;
    DWORD uChkErr;
    unsigned char* lpWrite2;
    DWORD dwPlay;
    DWORD dwWrite;
    DWORD local_4;

    // BINARY NOTE: busy and paused entry guards branch to the direct epilogue.
    if (DAT_0062e658 != 0 || _stream_paused != 0) return;
    DAT_0062e658 = 1;
    if (DAT_008884a8 != 0) {
        DAT_0062e658 = 0;
        return;
    }
    if (DAT_00888490 == (void*)0) {
        DAT_0062e658 = 0;
        return;
    }

    IDirectSoundBuffer_GetCurrentPosition((LPDIRECTSOUNDBUFFER)DAT_00888490, &local_4, &dwWrite);
    if (DAT_0088849c < dwWrite) {
        DWORD t = DAT_0088849c + DAT_00888498;
        if (t > dwWrite) goto done;
    }

    if (DAT_008884b0 && DAT_008884b4 == 0) {
        if (DAT_008884a8 != 0) goto done;
        DAT_008884a8 = 1;
        PostMessageA((HWND)_main_wnd, 0x500, 0, 0);
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
        PostMessageA((HWND)_main_wnd, 0x502, 0, 0);
    }

    if (DAT_008884b0 && DAT_008884b4) {
        --DAT_008884b4;
        if (DAT_008884b4 <= 1) goto done;
        if (DAT_00888490 == (void*)0) goto done;
        if (IDirectSoundBuffer_Lock((LPDIRECTSOUNDBUFFER)DAT_00888490, DAT_0088849c, DAT_00888498,
            (void**)&lpWrite1, &dwLen1, (void**)&lpWrite2, &dwLen2, 0)) goto done;
        CLEAR_AUDIO(lpWrite1, dwLen1);
        IDirectSoundBuffer_Unlock((LPDIRECTSOUNDBUFFER)DAT_00888490,
            lpWrite1, dwLen1, lpWrite2, dwLen2);
        DAT_0088849c += DAT_00888498;
        if (DAT_0088849c < DAT_00888494) goto done;
        goto wrap_play;
    }

    if (DAT_00888490 == (void*)0) goto done;
    if (IDirectSoundBuffer_Lock((LPDIRECTSOUNDBUFFER)DAT_00888490, DAT_0088849c, DAT_00888498,
        (void**)&lpWrite1, &dwLen1, (void**)&lpWrite2, &dwLen2, 0)) goto done;

    if (lpWrite1) {
        if (DAT_008884a8 == 0) {
            WaveReadFile(DAT_00888464, dwLen1, lpWrite1, &DAT_00888468, &uChkErr);
            if (uChkErr < dwLen1) {
                if (DAT_008884ac == 0) {
                    CLEAR_AUDIO_OFFSET(lpWrite1, uChkErr, dwLen1 - uChkErr);
                    if (DAT_0088849c <= dwLen2)
                        DAT_008884b4 = (DAT_00888494 + DAT_0088849c - dwLen2) / DAT_00888498;
                    else
                        DAT_008884b4 = (DAT_0088849c - dwLen2) / DAT_00888498;
                    DAT_008884b0 = 1;
                } else if (lpWrite1) {
                    unsigned char* retryWrite1 = lpWrite1;
                    do {
                        // BINARY NOTE: this helper receives addresses of all three stream records.
                        retryWrite1 += uChkErr;
                        dwLen1 -= uChkErr;
                        WaveStartDataRead(&DAT_00888464, &DAT_00888468, &DAT_0088847c);
                        WaveReadFile(DAT_00888464, dwLen1, retryWrite1,
                            &DAT_00888468, &uChkErr);
                    } while (uChkErr < dwLen1);
                }
            }
        }
        if (DAT_008884a8 != 0) {
            CLEAR_AUDIO_LENGTH(lpWrite1, dwLen1);
        }
    }

    if (lpWrite2) {
        if (DAT_008884a8 == 0) {
            WaveReadFile(DAT_00888464, dwLen2, lpWrite2, &DAT_00888468, &uChkErr);
            if (uChkErr < dwLen2) {
                if (DAT_008884ac == 0) {
                    CLEAR_AUDIO_OFFSET(lpWrite2, uChkErr, dwLen2 - uChkErr);
                    if (DAT_0088849c <= dwLen2)
                        DAT_008884b4 = (DAT_00888494 + DAT_0088849c - dwLen2) / DAT_00888498;
                    else
                        DAT_008884b4 = (DAT_0088849c - dwLen2) / DAT_00888498;
                    DAT_008884b0 = 1;
                } else if (lpWrite2) {
                    unsigned char* retryWrite2 = lpWrite2;
                    do {
                        retryWrite2 += uChkErr;
                        dwLen2 -= uChkErr;
                        WaveStartDataRead(&DAT_00888464, &DAT_00888468, &DAT_0088847c);
                        WaveReadFile(DAT_00888464, dwLen2, retryWrite2,
                            &DAT_00888468, &uChkErr);
                    } while (uChkErr < dwLen2);
                }
            }
        } else if (lpWrite2 && DAT_008884a8) {
            CLEAR_AUDIO_LENGTH(lpWrite2, dwLen2);
        }
    }

    if (DAT_00888490) IDirectSoundBuffer_Unlock((LPDIRECTSOUNDBUFFER)DAT_00888490,
        lpWrite1, dwLen1, lpWrite2, dwLen2);
    DAT_0088849c += DAT_00888498;
    if (DAT_0088849c < DAT_00888494) goto done;

wrap_play:
    DAT_0088849c -= DAT_00888494;

done:
    DAT_0062e658 = 0;
}
