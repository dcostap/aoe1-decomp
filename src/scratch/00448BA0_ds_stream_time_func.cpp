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
// Main-agent audit replaced fixed-address global macros with named extern
// ownership. The normalized source now has exact 1332-byte size and 18 calls,
// 64.58% shape, and 1248 differing bytes. Remaining drift starts at prologue
// save/zero scheduling and continues through Lock output homes, silence
// branches, and shared tails. Not accepted_drift.

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
extern "C" BOOL __stdcall PostMessageA(HWND, UINT, unsigned int, long);
extern "C" int __cdecl WaveReadFile(void*, DWORD, void*, void*, DWORD*);
extern "C" int __cdecl WaveStartDataRead(void*, void*, void*);

extern int g_in_func;
extern DSBUF* g_buffer;
extern DWORD g_buf_size;
extern DWORD g_chunk;
extern DWORD g_play;
extern DWORD g_lastplay;
extern DWORD g_total;
extern int g_end_pending;
extern int g_looped;
extern int g_starving;
extern int g_starve_count;
extern int g_paused;
extern HWND g_hwnd;
extern void* g_wavefile;
extern void* g_mmioinfo;
extern void* g_unused_end;
extern WAVEFORMATEX_L* g_wavefmt;
extern BOOL (__stdcall *g_post)(HWND, UINT, unsigned int, long);

#define CLEAR_AUDIO(P,N) do { \
    WAVEFORMATEX_L* wf_ = g_wavefmt; \
    if (wf_ && (P)) { \
        if (wf_->wBitsPerSample == 8) memset((P), 0x80, (N)); \
        else if (wf_->wBitsPerSample == 16) memset((P), 0, (N)); \
    } \
} while (0)

extern "C" void __stdcall ds_stream_time_func(HWND hwnd, UINT msg, UINT id, DWORD time, DWORD unused)
{
    DWORD dwPlay;
    DWORD dwWrite;
    void* lpWrite1;
    void* lpWrite2;
    DWORD dwLen1;
    DWORD dwLen2;
    DWORD uChkErr;

    if (g_in_func || g_paused) return;
    g_in_func = 1;
    if (g_end_pending || !g_buffer) goto done;

    g_buffer->lpVtbl->GetCurrentPosition(g_buffer, &dwPlay, &dwWrite);
    if (g_play < dwWrite) {
        DWORD t = g_play + g_chunk;
        if (t > dwWrite) goto done;
    }

    if (g_starving && !g_starve_count) {
        if (g_end_pending) goto done;
        g_end_pending = 1;
        g_post(g_hwnd, 0x500, 0, 0);
        g_in_func = 0;
        return;
    }

    {
        DWORD diff;
        if (dwWrite < g_lastplay) diff = g_buf_size + dwWrite;
        else diff = dwWrite;
        diff -= g_lastplay;
        g_lastplay = dwWrite;
        g_total += diff;
        g_post(g_hwnd, 0x502, 0, 0);
    }

    if (g_starving && g_starve_count) {
        --g_starve_count;
        if (g_starve_count <= 1) goto done;
        if (!g_buffer) goto done;
        if (g_buffer->lpVtbl->Lock(g_buffer, g_play, g_chunk, &lpWrite1, &dwLen1, &lpWrite2, &dwLen2, 0)) goto done;
        CLEAR_AUDIO(lpWrite1, dwLen1);
        g_buffer->lpVtbl->Unlock(g_buffer, lpWrite1, dwLen1, lpWrite2, dwLen2);
        g_play += g_chunk;
        if (g_play < g_buf_size) goto done;
        goto wrap_play;
    }

    if (!g_buffer) goto done;
    if (g_buffer->lpVtbl->Lock(g_buffer, g_play, g_chunk, &lpWrite1, &dwLen1, &lpWrite2, &dwLen2, 0)) goto done;

    if (lpWrite1 && !g_end_pending) {
        WaveReadFile(g_wavefile, dwLen1, lpWrite1, g_mmioinfo, &uChkErr);
        if (uChkErr < dwLen1) {
            if (!g_looped) {
                CLEAR_AUDIO((BYTE*)lpWrite1 + uChkErr, dwLen1 - uChkErr);
                if (g_play <= dwLen2) g_starve_count = (g_buf_size + g_play - dwLen2) / g_chunk;
                else g_starve_count = (g_play - dwLen2) / g_chunk;
                g_starving = 1;
            } else if (dwLen2) {
                do {
                    WaveStartDataRead(g_wavefile, g_mmioinfo, g_unused_end);
                    WaveReadFile(g_wavefile, dwLen1 - uChkErr, (BYTE*)lpWrite1 + uChkErr, g_mmioinfo, &uChkErr);
                } while (uChkErr < dwLen1);
            }
        }
    } else if (lpWrite1 && g_end_pending && g_wavefmt && dwLen1) {
        CLEAR_AUDIO(lpWrite1, dwLen1);
    }

    if (lpWrite2) {
        if (!g_end_pending) {
            WaveReadFile(g_wavefile, dwLen2, lpWrite2, g_mmioinfo, &uChkErr);
            if (uChkErr < dwLen2) {
                if (!g_looped) {
                    CLEAR_AUDIO((BYTE*)lpWrite2 + uChkErr, dwLen2 - uChkErr);
                    if (g_play <= dwLen2) g_starve_count = (g_buf_size + g_play - dwLen2) / g_chunk;
                    else g_starve_count = (g_play - dwLen2) / g_chunk;
                    g_starving = 1;
                } else if (dwLen2) {
                    do {
                        WaveStartDataRead(g_wavefile, g_mmioinfo, g_unused_end);
                        WaveReadFile(g_wavefile, dwLen2 - uChkErr, (BYTE*)lpWrite2 + uChkErr, g_mmioinfo, &uChkErr);
                    } while (uChkErr < dwLen2);
                }
            }
        } else if (g_end_pending && g_wavefmt && dwLen2) {
            CLEAR_AUDIO(lpWrite2, dwLen2);
        }
    }

    if (g_buffer) g_buffer->lpVtbl->Unlock(g_buffer, lpWrite1, dwLen1, lpWrite2, dwLen2);
    g_play += g_chunk;
    if (g_play >= g_buf_size) {
wrap_play:
        g_play -= g_buf_size;
    }

done:
    g_in_func = 0;
}
