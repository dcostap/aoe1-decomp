// 00448BA0 ds_stream_time_func
// Attempt log:
// try 1: direct C reconstruction from packet/Ghidra with helper clear_audio: default /O2 too small (.text 1312 vs 1332), so not comparable.
// try 2: macro-expanded CLEAR_AUDIO to recover repeated memset tests: exact-size comparable (1332/1332) but broad mismatch, 95.2703% positional / 120.1201% edit, first mismatch prologue due local initialization/control-flow topology.
// try 3: /GX no change from try 2, rolled back.
// try 4: /O1 too small (.text 1277), rolled back.
// try 5: /Od exact-size comparable but worse debug-basin mismatch (92.9429% positional / 146.8468% edit), rolled back.
// left in scratch: behavior skeleton covers busy/paused guards, GetCurrentPosition, PostMessage updates, Lock/Unlock, WaveReadFile/WaveStartDataRead loops, silence fill for 8/16-bit, starvation/end state, and play cursor wrap. Not accepted_drift quality; needs exact original C local topology and DirectSound/Wave prototypes/source spelling.

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

#define g_in_func (*(int*)0x0062E658)
#define g_buffer (*(DSBUF**)0x00888490)
#define g_buf_size (*(DWORD*)0x00888494)
#define g_chunk (*(DWORD*)0x00888498)
#define g_play (*(DWORD*)0x0088849C)
#define g_lastplay (*(DWORD*)0x008884A0)
#define g_total (*(DWORD*)0x008884A4)
#define g_end_pending (*(int*)0x008884A8)
#define g_looped (*(int*)0x008884AC)
#define g_starving (*(int*)0x008884B0)
#define g_starve_count (*(int*)0x008884B4)
#define g_paused (*(int*)0x008884C0)
#define g_hwnd (*(HWND*)0x008884C4)
#define g_wavefile (*(void**)0x00888464)
#define g_mmioinfo (*(void**)0x00888468)
#define g_unused_end (*(void**)0x0088847C)
#define g_wavefmt (*(WAVEFORMATEX_L**)0x00888460)
#define g_post (*(BOOL (__stdcall **)(HWND,UINT,unsigned int,long))0x0088A8B4)

#define CLEAR_AUDIO(P,N) do { \
    WAVEFORMATEX_L* wf_ = g_wavefmt; \
    if (wf_ && (P)) { \
        if (wf_->wBitsPerSample == 8) memset((P), 0x80, (N)); \
        else if (wf_->wBitsPerSample == 16) memset((P), 0, (N)); \
    } \
} while (0)

extern "C" void __stdcall ds_stream_time_func(HWND hwnd, UINT msg, UINT id, DWORD time, DWORD unused)
{
    DWORD play = 0, write = 0;
    void* p1 = 0; void* p2 = 0;
    DWORD n1 = 0, n2 = 0;
    DWORD got = 0;

    if (g_in_func || g_paused) return;
    g_in_func = 1;
    if (g_end_pending || !g_buffer) goto done;

    g_buffer->lpVtbl->GetCurrentPosition(g_buffer, &play, &write);
    if (g_play < write) {
        DWORD t = g_play + g_chunk;
        if (t > write) goto done;
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
        if (write < g_lastplay) diff = g_buf_size + write;
        else diff = write;
        diff -= g_lastplay;
        g_lastplay = write;
        g_total += diff;
        g_post(g_hwnd, 0x502, 0, 0);
    }

    if (g_starving && g_starve_count) {
        --g_starve_count;
        if (g_starve_count <= 1) goto done;
        if (!g_buffer) goto done;
        if (g_buffer->lpVtbl->Lock(g_buffer, g_play, g_chunk, &p1, &n1, &p2, &n2, 0)) goto done;
        CLEAR_AUDIO(p1, n1);
        g_buffer->lpVtbl->Unlock(g_buffer, p1, n1, p2, n2);
        g_play += g_chunk;
        if (g_play < g_buf_size) goto done;
        goto wrap_play;
    }

    if (!g_buffer) goto done;
    if (g_buffer->lpVtbl->Lock(g_buffer, g_play, g_chunk, &p1, &n1, &p2, &n2, 0)) goto done;

    if (p1 && !g_end_pending) {
        WaveReadFile(g_wavefile, n1, p1, g_mmioinfo, &got);
        if (got < n1) {
            if (!g_looped) {
                CLEAR_AUDIO((BYTE*)p1 + got, n1 - got);
                if (g_play <= n2) g_starve_count = (g_buf_size + g_play - n2) / g_chunk;
                else g_starve_count = (g_play - n2) / g_chunk;
                g_starving = 1;
            } else if (n2) {
                do {
                    WaveStartDataRead(g_wavefile, g_mmioinfo, g_unused_end);
                    WaveReadFile(g_wavefile, n1 - got, (BYTE*)p1 + got, g_mmioinfo, &got);
                } while (got < n1);
            }
        }
    } else if (p1 && g_end_pending && g_wavefmt && n1) {
        CLEAR_AUDIO(p1, n1);
    }

    if (p2) {
        if (!g_end_pending) {
            WaveReadFile(g_wavefile, n2, p2, g_mmioinfo, &got);
            if (got < n2) {
                if (!g_looped) {
                    CLEAR_AUDIO((BYTE*)p2 + got, n2 - got);
                    if (g_play <= n2) g_starve_count = (g_buf_size + g_play - n2) / g_chunk;
                    else g_starve_count = (g_play - n2) / g_chunk;
                    g_starving = 1;
                } else if (n2) {
                    do {
                        WaveStartDataRead(g_wavefile, g_mmioinfo, g_unused_end);
                        WaveReadFile(g_wavefile, n2 - got, (BYTE*)p2 + got, g_mmioinfo, &got);
                    } while (got < n2);
                }
            }
        } else if (g_end_pending && g_wavefmt && n2) {
            CLEAR_AUDIO(p2, n2);
        }
    }

    if (g_buffer) g_buffer->lpVtbl->Unlock(g_buffer, p1, n1, p2, n2);
    g_play += g_chunk;
    if (g_play >= g_buf_size) {
wrap_play:
        g_play -= g_buf_size;
    }

done:
    g_in_func = 0;
}
