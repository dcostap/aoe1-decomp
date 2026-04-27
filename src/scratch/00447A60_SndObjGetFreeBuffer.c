/* VA: 00447A60 _SndObjGetFreeBuffer */
/* Dsutil.c lines 217-266, 191 bytes */

int __cdecl _DSFillSoundBuffer(void* buf, void* data, int size);

struct SndObj {
    void* device;
    void* data;
    int count;
    int index;
    void* buffers[1];
};

int __cdecl _SndObjGetFreeBuffer(struct SndObj* obj) {
    int idx;
    void* buf;
    int status;
    int hr;
    
    if (!obj) return 0;
    
    idx = obj->index;
    buf = obj->buffers[idx];
    if (!buf) return 0;
    
    status = 0;
    hr = ((int (__stdcall*)(void*,int*))(*(void**)buf))(buf, &status);
    if (hr < 0) status = 0;
    
    if ((status & 1) == 1) {
        if (obj->count > 1) {
            idx++;
            if (idx >= obj->count) idx = 0;
            obj->index = idx;
            buf = obj->buffers[idx];
            hr = ((int (__stdcall*)(void*,int*))(*(void**)buf))(buf, &status);
            if (hr >= 0 && (status & 1) == 1) {
                ((int (__stdcall*)(void*))(*(void**)buf))(buf);
                ((int (__stdcall*)(void*,int))(*(void**)buf))(buf, 0);
            }
        } else {
            buf = 0;
        }
    }
    
    if (buf && (status & 2)) {
        hr = ((int (__stdcall*)(void*))(*(void**)buf))(buf);
        if (hr < 0 || !_DSFillSoundBuffer(buf, obj->device, obj->data)) {
            buf = 0;
        }
    }
    
    return (int)buf;
}
