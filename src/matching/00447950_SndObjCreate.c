/* VA: 00447950 _SndObjCreate */
/* Dsutil.c lines 152-190, 203 bytes */

typedef unsigned long DWORD;
typedef unsigned char BYTE;

typedef void* (__stdcall *_LocalAllocT)(int flags, int size);
extern _LocalAllocT _LocalAlloc;

struct IDirectSound;
struct IDirectSoundBuffer;

struct IDirectSoundVtbl {
    void* slot00;
    void* slot04;
    void* slot08;
    void* slot0C;
    void* slot10;
    int (__stdcall *DuplicateSoundBuffer)(struct IDirectSound* self, struct IDirectSoundBuffer* src, struct IDirectSoundBuffer** dst);
};

struct IDirectSound {
    struct IDirectSoundVtbl* lpVtbl;
};

struct IDirectSoundBuffer {
    void* lpVtbl;
};

struct SNDOBJ {
    BYTE* pbData;
    DWORD cbData;
    int count;
    int index;
    struct IDirectSoundBuffer* buffers[1];
};

int __cdecl _DSGetWaveResource(void* hModule, void* lpName, void* out1, void* out2, void* out3);
struct IDirectSoundBuffer* __cdecl _DSLoadSoundBuffer(struct IDirectSound* pDS, void* lpName);
void __cdecl _SndObjDestroy(struct SNDOBJ* obj);

struct SNDOBJ* __cdecl _SndObjCreate(struct IDirectSound* pDS, void* lpName, int count)
{
    BYTE* pbData;
    DWORD cbData;
    void* pWaveHeader;
    struct SNDOBJ* obj;
    int i;
    struct IDirectSoundBuffer** buf;

    obj = 0;
    if (_DSGetWaveResource(0, lpName, &pWaveHeader, &pbData, &cbData) != 0) {
        i = 1;
        if (count < i) {
            count = i;
        }
        obj = (struct SNDOBJ*)_LocalAlloc(0x40, count * 4 + 0x10);
        if (obj != 0) {
            obj->count = count;
            obj->pbData = pbData;
            obj->cbData = cbData;
            obj->buffers[0] = _DSLoadSoundBuffer(pDS, lpName);
            if (i < obj->count) {
                buf = &obj->buffers[1];
                while (1) {
                    if (pDS->lpVtbl->DuplicateSoundBuffer(pDS, obj->buffers[0], buf) < 0) {
                        *buf = _DSLoadSoundBuffer(pDS, lpName);
                        if (*buf == 0) {
                            goto destroy_obj;
                        }
                    }
                    i++;
                    buf++;
                    if (i < obj->count) {
                        continue;
                    }
                    return obj;
                }

destroy_obj:
                _SndObjDestroy(obj);
                obj = 0;
            }
        }
    }

    return obj;
}
