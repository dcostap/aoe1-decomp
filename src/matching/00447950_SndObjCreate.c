/* VA: 00447950 _SndObjCreate */
/* Dsutil.c lines 152-190, 203 bytes */

typedef unsigned long DWORD;
typedef unsigned char BYTE;

typedef void* (__stdcall *_LocalAllocT)(int flags, int size);
extern _LocalAllocT _LocalAlloc;

typedef struct SndObjCreateDirectSound SndObjCreateDirectSound;
typedef struct SndObjCreateDirectSoundBuffer SndObjCreateDirectSoundBuffer;

struct SndObjCreateDirectSoundVtbl {
    void* slot00;
    void* slot04;
    void* slot08;
    void* slot0C;
    void* slot10;
    int (__stdcall *DuplicateSoundBuffer)(SndObjCreateDirectSound* self, SndObjCreateDirectSoundBuffer* src, SndObjCreateDirectSoundBuffer** dst);
};

struct SndObjCreateDirectSound {
    struct SndObjCreateDirectSoundVtbl* lpVtbl;
};

struct SndObjCreateDirectSoundBuffer {
    void* lpVtbl;
};

typedef struct SndObjCreateObject SndObjCreateObject;
struct SndObjCreateObject {
    BYTE* pbData;
    DWORD cbData;
    int count;
    int index;
    SndObjCreateDirectSoundBuffer* buffers[1];
};

int __cdecl DSGetWaveResource(void* hModule, void* lpName, void* out1, void* out2, void* out3);
typedef struct DSLoadDirectSound DSLoadDirectSound;
typedef struct DSLoadDirectSoundBuffer DSLoadDirectSoundBuffer;
DSLoadDirectSoundBuffer* __cdecl DSLoadSoundBuffer(DSLoadDirectSound* pDS, void* lpName);
void __cdecl SndObjDestroy(void* obj);

SndObjCreateObject* __cdecl SndObjCreate(SndObjCreateDirectSound* pDS, void* lpName, int count)
{
    BYTE* pbData;
    DWORD cbData;
    void* pWaveHeader;
    SndObjCreateObject* obj;
    int i;
    SndObjCreateDirectSoundBuffer** buf;

    obj = 0;
    if (DSGetWaveResource(0, lpName, &pWaveHeader, &pbData, &cbData) != 0) {
        i = 1;
        if (count < i) {
            count = i;
        }
        obj = (SndObjCreateObject*)_LocalAlloc(0x40, count * 4 + 0x10);
        if (obj != 0) {
            obj->count = count;
            obj->pbData = pbData;
            obj->cbData = cbData;
            obj->buffers[0] = (SndObjCreateDirectSoundBuffer*)
                DSLoadSoundBuffer((DSLoadDirectSound*)pDS, lpName);
            if (i < obj->count) {
                buf = &obj->buffers[1];
                while (1) {
                    if (pDS->lpVtbl->DuplicateSoundBuffer(pDS, obj->buffers[0], buf) < 0) {
                        *buf = (SndObjCreateDirectSoundBuffer*)
                            DSLoadSoundBuffer((DSLoadDirectSound*)pDS, lpName);
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
                SndObjDestroy(obj);
                obj = 0;
            }
        }
    }

    return obj;
}
