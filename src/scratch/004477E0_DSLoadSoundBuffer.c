/* VA: 004477E0 _DSLoadSoundBuffer */
/* Dsutil.c lines 72-97 */
/* attempts: natural separate locals -> 0x1c frame + saved ESI zero; raw separate locals -> too short (160B); explicit frame stores -> saved ESI zero; aggregate frame -> best no saved regs, correct 0x18 frame/calls/tails but init order/early zero offsets differ and later blocks shift by 4B; /O1 and /Od too short, removed flags. */
/* left in scratch: behavior/calls look correct, remaining mismatch is VC5 local zero-initialization scheduling/layout around pDSB/DSBUFFERDESC before _DSGetWaveResource; not accepted_drift due broad shifted positional diff. */

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
        if (((int (__stdcall *)(struct IDirectSound*, volatile DSBUFFERDESC_LOCAL*, volatile struct IDirectSoundBuffer**, void*))ds->lpVtbl[3])(ds, &f.dsBD, &f.pDSB, 0) < 0) {
            return 0;
        }
        if (_DSFillSoundBuffer((struct IDirectSoundBuffer*)f.pDSB, name, f.dsBD.dwBufferBytes) == 0) {
            ((int (__stdcall *)(volatile struct IDirectSoundBuffer*))f.pDSB->lpVtbl[2])(f.pDSB);
            return 0;
        }
    }
    return (struct IDirectSoundBuffer*)f.pDSB;
}
