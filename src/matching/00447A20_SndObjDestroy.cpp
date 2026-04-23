struct IDirectSoundBuffer {
    virtual long __stdcall QueryInterface(void*, void**) = 0;
    virtual unsigned long __stdcall AddRef(void) = 0;
    virtual unsigned long __stdcall Release(void) = 0;
};

extern "C" __declspec(dllimport) void* __stdcall LocalFree(void* mem);

void __cdecl SndObjDestroy(void* obj) {
    if (obj != 0) {
        int i = 0;
        if (*(int*)((char*)obj + 8) > 0) {
            do {
                IDirectSoundBuffer* buffer = *(IDirectSoundBuffer**)((char*)obj + 0x10 + i * 4);
                if (buffer != 0) {
                    buffer->Release();
                    *(IDirectSoundBuffer**)((char*)obj + 0x10 + i * 4) = 0;
                }
                ++i;
            } while (i < *(int*)((char*)obj + 8));
        }
        LocalFree(obj);
    }
}
