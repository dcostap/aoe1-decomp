typedef struct SndObjDestroyBuffer SndObjDestroyBuffer;
typedef struct SndObjDestroyBufferVtbl SndObjDestroyBufferVtbl;

struct SndObjDestroyBufferVtbl {
    long (__stdcall *QueryInterface)(SndObjDestroyBuffer*, void*, void**);
    unsigned long (__stdcall *AddRef)(SndObjDestroyBuffer*);
    unsigned long (__stdcall *Release)(SndObjDestroyBuffer*);
};

struct SndObjDestroyBuffer {
    SndObjDestroyBufferVtbl* lpVtbl;
};

__declspec(dllimport) void* __stdcall LocalFree(void* mem);

void __cdecl SndObjDestroy(void* obj) {
    if (obj != 0) {
        int i = 0;
        if (*(int*)((char*)obj + 8) > 0) {
            do {
                SndObjDestroyBuffer* buffer = *(SndObjDestroyBuffer**)((char*)obj + 0x10 + i * 4);
                if (buffer != 0) {
                    buffer->lpVtbl->Release(buffer);
                    *(SndObjDestroyBuffer**)((char*)obj + 0x10 + i * 4) = 0;
                }
                ++i;
            } while (i < *(int*)((char*)obj + 8));
        }
        LocalFree(obj);
    }
}
