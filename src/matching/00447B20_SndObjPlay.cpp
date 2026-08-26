int __cdecl SndObjGetFreeBuffer(void* sndobj);

typedef struct SndObjPlayBuffer SndObjPlayBuffer;
typedef struct SndObjPlayBufferVtbl SndObjPlayBufferVtbl;

struct SndObjPlayBufferVtbl {
    void* fn00;
    void* fn04;
    void* fn08;
    void* fn0C;
    void* fn10;
    void* fn14;
    void* fn18;
    void* fn1C;
    void* fn20;
    void* fn24;
    void* fn28;
    void* fn2C;
    int (__stdcall *Play)(SndObjPlayBuffer* self, unsigned long, unsigned long, unsigned long);
};

struct SndObjPlayBuffer {
    SndObjPlayBufferVtbl* lpVtbl;
};

typedef struct SNDOBJ SNDOBJ;
struct SndObjPlayObject {
    unsigned char* pbWaveData;
    unsigned long cbWaveSize;
    int iAlloc;
    int iCurrent;
    SndObjPlayBuffer* Buffers[1];
};

unsigned int __cdecl SndObjPlay(struct SndObjPlayObject* sndobj, unsigned long flags) {
    unsigned int result;
    SndObjPlayBuffer* buffer;
    int hr;

    result = 0;
    if (sndobj == 0) {
        return result;
    }
    if (((flags & 1) == 0) || (sndobj->iAlloc == 1)) {
        buffer = (SndObjPlayBuffer*)SndObjGetFreeBuffer(sndobj);
        if (buffer != 0) {
            hr = buffer->lpVtbl->Play(buffer, 0, 0, flags);
            result = (unsigned int)(hr >= 0);
        }
    }
    return result;
}
