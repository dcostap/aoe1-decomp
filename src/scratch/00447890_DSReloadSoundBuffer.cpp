// DSReloadSoundBuffer
// VA: 00447890

int __cdecl _DSGetWaveResource(int a, int b, int c, void* d, void* e);
int __cdecl _DSFillSoundBuffer(void* a, void* b, int c);

typedef struct IDSBuffer IDSBuffer;
typedef struct IDSVTable IDSVTable;

struct IDSVTable {
        int (__stdcall* QueryInterface)(IDSBuffer*, void*);         // +0x00
        int (__stdcall* AddRef)(IDSBuffer*);                        // +0x04
        int (__stdcall* Release)(IDSBuffer*);                       // +0x08
        int (__stdcall* pad0C)(IDSBuffer*);                         // +0x0C
        int (__stdcall* pad10)(IDSBuffer*);                         // +0x10
        int (__stdcall* pad14)(IDSBuffer*);                         // +0x14
        int (__stdcall* pad18)(IDSBuffer*);                         // +0x18
        int (__stdcall* pad1C)(IDSBuffer*);                         // +0x1C
        int (__stdcall* pad20)(IDSBuffer*);                         // +0x20
        int (__stdcall* pad24)(IDSBuffer*);                         // +0x24
        int (__stdcall* pad28)(IDSBuffer*);                         // +0x28
        int (__stdcall* pad2C)(IDSBuffer*);                         // +0x2C
        int (__stdcall* pad30)(IDSBuffer*);                         // +0x30
        int (__stdcall* pad34)(IDSBuffer*);                         // +0x34
        int (__stdcall* pad38)(IDSBuffer*);                         // +0x38
        int (__stdcall* pad3C)(IDSBuffer*);                         // +0x3C
        int (__stdcall* pad40)(IDSBuffer*);                         // +0x40
        int (__stdcall* pad44)(IDSBuffer*);                         // +0x44
        int (__stdcall* pad48)(IDSBuffer*);                         // +0x48
        int (__stdcall* pad4C)(IDSBuffer*);                         // +0x4C
        int (__stdcall* func0x50)(IDSBuffer*);                      // +0x50
};

struct IDSBuffer {
    IDSVTable* lpVtbl;
};

int __cdecl _DSReloadSoundBuffer(IDSBuffer* buffer, int param2, void* param3) {
    int result = 0;
    int local_4;

    if (_DSGetWaveResource(0, param2, 0, (void*)&local_4, &param2) != 0) {
        if (buffer->lpVtbl->func0x50(buffer) >= 0) {
            if (_DSFillSoundBuffer(buffer, (void*)local_4, param2) != 0) {
                result = 1;
            }
        }
    }
    return result;
}
