// VA: 00447B70 _SndObjStop (65 B)
// PDB source: Dsutil.c lines 293-306

struct IDirectSoundBuffer;

struct IDSBVtbl {
    long (__stdcall* QueryInterface)(void*, void**);
    unsigned long (__stdcall* AddRef)(void*);
    unsigned long (__stdcall* Release)(void*);
    long (__stdcall* GetCaps)(void*, void*, unsigned long);
    long (__stdcall* GetCurrentPosition)(void*, unsigned long*, unsigned long*);
    long (__stdcall* GetFormat)(void*, void*, unsigned long, unsigned long*);
    long (__stdcall* GetVolume)(void*, long*);
    long (__stdcall* GetPan)(void*, long*);
    long (__stdcall* GetFrequency)(void*, unsigned long*);
    unsigned long (__stdcall* GetStatus)(void*);
    long (__stdcall* Initialize)(void*, void*, void*);
    long (__stdcall* Lock)(void*, unsigned long, unsigned long, void**, unsigned long*, void**, unsigned long*, unsigned long);
    long (__stdcall* Play)(void*, unsigned long, unsigned long, unsigned long);
    long (__stdcall* SetCurrentPosition)(void*, unsigned long);
    long (__stdcall* SetFormat)(void*, void*);
    long (__stdcall* SetVolume)(void*, long);
    long (__stdcall* SetPan)(void*, long);
    long (__stdcall* SetFrequency)(void*, unsigned long);
    long (__stdcall* Stop)(void*);
};

struct IDirectSoundBuffer {
    IDSBVtbl* lpVtbl;
};

int __cdecl _SndObjStop(void* obj) {
    if (obj == 0) {
        return 0;
    }

    {
        int i = 0;
        if (*(int*)((char*)obj + 8) > 0) {
            do {
                void** pp = (void**)((char*)obj + 0x10);
                IDirectSoundBuffer* buf = (IDirectSoundBuffer*)(pp[i]);
                buf->lpVtbl->Stop(buf);
                buf->lpVtbl->SetCurrentPosition(buf, 0);
                ++i;
            } while (i < *(int*)((char*)obj + 8));
        }
        return 1;
    }
}
