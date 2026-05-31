/* VA: 00447A60 _SndObjGetFreeBuffer */
/* Dsutil.c lines 217-266, 191 bytes */

int __cdecl _DSFillSoundBuffer(void* buf, void* data, int size);

struct IDirectSoundBuffer;

struct IDirectSoundBufferVtbl {
    void* slot00;
    void* slot04;
    void* slot08;
    void* slot0C;
    void* slot10;
    void* slot14;
    void* slot18;
    void* slot1C;
    void* slot20;
    int (__stdcall *GetStatus)(struct IDirectSoundBuffer* self, int* status);
    void* slot28;
    void* slot2C;
    void* slot30;
    int (__stdcall *Func34)(struct IDirectSoundBuffer* self, int value);
    void* slot38;
    void* slot3C;
    void* slot40;
    void* slot44;
    int (__stdcall *Func48)(struct IDirectSoundBuffer* self);
    void* slot4C;
    int (__stdcall *Func50)(struct IDirectSoundBuffer* self);
};

struct IDirectSoundBuffer {
    struct IDirectSoundBufferVtbl* lpVtbl;
};

struct SndObj {
    void* waveData;
    int waveSize;
    int count;
    int index;
    struct IDirectSoundBuffer* buffers[1];
};

int __cdecl _SndObjGetFreeBuffer(struct SndObj* obj) {
    struct IDirectSoundBuffer* buf;
    int status;
    int hr;

    if (obj == 0) return 0;

    buf = obj->buffers[obj->index];
    if (buf != 0) {
        hr = buf->lpVtbl->GetStatus(buf, &status);
        if (hr < 0) {
            status = 0;
        }
        if ((status & 1) == 1) {
            if (obj->count > 1) {
                obj->index++;
                if (obj->index >= obj->count) {
                    obj->index = 0;
                }
                buf = obj->buffers[obj->index];
                hr = buf->lpVtbl->GetStatus(buf, &status);
                if (hr >= 0 && (status & 1) == 1) {
                    buf->lpVtbl->Func48(buf);
                    buf->lpVtbl->Func34(buf, 0);
                }
            } else {
                buf = 0;
            }
        }

        if (buf != 0 && (status & 2) != 0) {
            hr = buf->lpVtbl->Func50(buf);
            if (hr < 0 || _DSFillSoundBuffer(buf, obj->waveData, obj->waveSize) == 0) {
                buf = 0;
            }
        }
    }

    return (int)buf;
}
