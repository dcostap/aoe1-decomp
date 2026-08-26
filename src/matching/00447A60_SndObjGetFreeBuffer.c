/* VA: 00447A60 _SndObjGetFreeBuffer */
/* Dsutil.c lines 217-266, 191 bytes */

int __cdecl DSFillSoundBuffer(void* buf, void* data, int size);

typedef struct SndObjFreeBuffer SndObjFreeBuffer;
typedef struct SndObjFreeBufferVtbl SndObjFreeBufferVtbl;

struct SndObjFreeBufferVtbl {
    void* slot00;
    void* slot04;
    void* slot08;
    void* slot0C;
    void* slot10;
    void* slot14;
    void* slot18;
    void* slot1C;
    void* slot20;
    int (__stdcall *GetStatus)(SndObjFreeBuffer* self, int* status);
    void* slot28;
    void* slot2C;
    void* slot30;
    int (__stdcall *Func34)(SndObjFreeBuffer* self, int value);
    void* slot38;
    void* slot3C;
    void* slot40;
    void* slot44;
    int (__stdcall *Func48)(SndObjFreeBuffer* self);
    void* slot4C;
    int (__stdcall *Func50)(SndObjFreeBuffer* self);
};

struct SndObjFreeBuffer {
    SndObjFreeBufferVtbl* lpVtbl;
};

struct SndObj {
    void* waveData;
    int waveSize;
    int count;
    int index;
    SndObjFreeBuffer* buffers[1];
};

int __cdecl SndObjGetFreeBuffer(struct SndObj* obj) {
    SndObjFreeBuffer* buf;
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
            if (hr < 0 || DSFillSoundBuffer(buf, obj->waveData, obj->waveSize) == 0) {
                buf = 0;
            }
        }
    }

    return (int)buf;
}
