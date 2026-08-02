/* VA: 004477E0 _DSLoadSoundBuffer */
/* Dsutil.c lines 72-97 */
/* attempts: natural separate locals -> 0x1c frame + saved ESI zero; raw separate locals -> too short (160B); explicit frame stores -> saved ESI zero; aggregate frame -> best no saved regs, correct 0x18 frame/calls/tails but init order/early zero offsets differ and later blocks shift by 4B; /O1 and /Od too short, removed flags. */
/* Earlier scratch state: behavior/calls looked correct, but aggregate-frame zero initialization shifted the first block by four bytes. */
/* Retry 2026-05-24 Boss pass: 12 probes. Key fix: rewriting CreateSoundBuffer check as >=0/else kept exact 170B and improved edit diff to 18.8235% (positional 74.7059%, first mismatch +12); kept. */
/* Tried adding real dwReserved to DSBUFFERDESC (worse 0x1c frame/rep stos), separate manual locals, volatile pDSB, wave-first local order (all 160B too small), no-volatile casts, named hr, wave-name temp, return temp, and flags /Ob0 /Og /Ot /G5 /GB /Oa (no change). */
/* GIVEUP: no accepted_drift proposal; remaining mismatch is still broad shifted stack-layout/zero-init scheduling and tail placement, not a localized equivalent hunk. */
/* Retry 2026-05-26 Boss pass: 10 more probes. Tried separate locals with source zero order, manual int frame[6], volatile frame, explicit zero-order frame, fail-first/early-return style, return temp, named dsBD pointer, no-volatile call prototypes, local name copy, and void Release prototype. Best positional variant was local name copy (42 positional / 29 edit) but it passed &local name instead of the original parameter slot and still had broad init scheduling drift. Current kept source remains best source-topology hypothesis: exact-size 170B, 127 positional / 32 edit, first mismatch +12. No accepted_drift: mismatch is broad stack layout/zero init and not localized. */
/* Retry 2026-08-02 Luna4477E0: period-plausible DSUtil sample shape matched exactly. Separate pDSB, DSBUFFERDESC={0}, and pbWaveData locals make VC5 reuse the incoming name slot for the wave-data out parameter; &dsBD.lpwfxFormat, &pbWaveData, &dsBD.dwBufferBytes plus sizeof(dsBD) recover the original 0x18 frame and zero-store schedule. */

struct IDirectSound { int **lpVtbl; };
struct IDirectSoundBuffer { int **lpVtbl; };

typedef struct DSBUFFERDESC_LOCAL {
    unsigned int dwSize;
    unsigned int dwFlags;
    unsigned int dwBufferBytes;
    unsigned int dwReserved;
    void* lpwfxFormat;
} DSBUFFERDESC_LOCAL;

int __cdecl _DSGetWaveResource(void* hModule, char* name, void* out1, void* out2, void* out3);
int __cdecl _DSFillSoundBuffer(void* dsb, void* data, int size);

struct IDirectSoundBuffer* __cdecl _DSLoadSoundBuffer(struct IDirectSound* ds, char* name)
{
    struct IDirectSoundBuffer* pDSB = 0;
    DSBUFFERDESC_LOCAL dsBD = {0};
    void* pbWaveData;

    if (_DSGetWaveResource(0, name, &dsBD.lpwfxFormat, &pbWaveData, (void*)&dsBD.dwBufferBytes) != 0) {
        dsBD.dwSize = sizeof(dsBD);
        dsBD.dwFlags = 0xe2;
        if (((int (__stdcall *)(struct IDirectSound*, DSBUFFERDESC_LOCAL*, struct IDirectSoundBuffer**, void*))ds->lpVtbl[3])(ds, &dsBD, &pDSB, 0) >= 0) {
            if (_DSFillSoundBuffer(pDSB, pbWaveData, dsBD.dwBufferBytes) == 0) {
                ((int (__stdcall *)(struct IDirectSoundBuffer*))pDSB->lpVtbl[2])(pDSB);
                return 0;
            }
        } else {
            return 0;
        }
    }
    return pDSB;
}
