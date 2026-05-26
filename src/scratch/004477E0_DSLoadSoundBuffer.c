/* VA: 004477E0 _DSLoadSoundBuffer */
/* Dsutil.c lines 72-97 */
/* attempts: natural separate locals -> 0x1c frame + saved ESI zero; raw separate locals -> too short (160B); explicit frame stores -> saved ESI zero; aggregate frame -> best no saved regs, correct 0x18 frame/calls/tails but init order/early zero offsets differ and later blocks shift by 4B; /O1 and /Od too short, removed flags. */
/* left in scratch: behavior/calls look correct, remaining mismatch is VC5 local zero-initialization scheduling/layout around pDSB/DSBUFFERDESC before _DSGetWaveResource; not accepted_drift due broad shifted positional diff. */
/* Retry 2026-05-24 Boss pass: 12 probes. Key fix: rewriting CreateSoundBuffer check as >=0/else kept exact 170B and improved edit diff to 18.8235% (positional 74.7059%, first mismatch +12); kept. */
/* Tried adding real dwReserved to DSBUFFERDESC (worse 0x1c frame/rep stos), separate manual locals, volatile pDSB, wave-first local order (all 160B too small), no-volatile casts, named hr, wave-name temp, return temp, and flags /Ob0 /Og /Ot /G5 /GB /Oa (no change). */
/* GIVEUP: no accepted_drift proposal; remaining mismatch is still broad shifted stack-layout/zero-init scheduling and tail placement, not a localized equivalent hunk. */
/* Retry 2026-05-26 Boss pass: 10 more probes. Tried separate locals with source zero order, manual int frame[6], volatile frame, explicit zero-order frame, fail-first/early-return style, return temp, named dsBD pointer, no-volatile call prototypes, local name copy, and void Release prototype. Best positional variant was local name copy (42 positional / 29 edit) but it passed &local name instead of the original parameter slot and still had broad init scheduling drift. Current kept source remains best source-topology hypothesis: exact-size 170B, 127 positional / 32 edit, first mismatch +12. No accepted_drift: mismatch is broad stack layout/zero init and not localized. */

struct IDirectSound { int **lpVtbl; };
struct IDirectSoundBuffer { int **lpVtbl; };

typedef struct DSBUFFERDESC_LOCAL {
    unsigned int dwSize;
    unsigned int dwFlags;
    unsigned int dwBufferBytes;
    void* lpwfxFormat;
} DSBUFFERDESC_LOCAL;

struct Frame477E0 {
    struct IDirectSoundBuffer* pDSB;
    DSBUFFERDESC_LOCAL dsBD;
    void* waveData;
};

int __cdecl _DSGetWaveResource(void* hModule, char* name, void* out1, void* out2, void* out3);
int __cdecl _DSFillSoundBuffer(void* dsb, void* data, int size);

struct IDirectSoundBuffer* __cdecl _DSLoadSoundBuffer(struct IDirectSound* ds, char* name)
{
    struct Frame477E0 f = {0};

    if (_DSGetWaveResource(0, name, &f.waveData, &name, (void*)&f.dsBD.dwBufferBytes) != 0) {
        f.dsBD.dwSize = 0x14;
        f.dsBD.dwFlags = 0xe2;
        if (((int (__stdcall *)(struct IDirectSound*, volatile DSBUFFERDESC_LOCAL*, volatile struct IDirectSoundBuffer**, void*))ds->lpVtbl[3])(ds, &f.dsBD, &f.pDSB, 0) >= 0) {
            if (_DSFillSoundBuffer((struct IDirectSoundBuffer*)f.pDSB, name, f.dsBD.dwBufferBytes) == 0) {
                ((int (__stdcall *)(volatile struct IDirectSoundBuffer*))f.pDSB->lpVtbl[2])(f.pDSB);
                return 0;
            }
        } else {
            return 0;
        }
    }
    return (struct IDirectSoundBuffer*)f.pDSB;
}
