// _SndObjCreate — real pass
// VA: 00447950
#include <windows.h>

// SNDOBJ struct (from SndObjGetFreeBuffer pattern)
struct SNDOBJ {
    void* field_0;     // +0: wave data size
    void* field_4;     // +4: WAVEFORMATEX or extra pointer
    int   count;       // +8: number of buffers
    int   index;       // +0Ch: current index
    void* buffers[1];  // +10h: buffer array
};

extern int __cdecl _DSGetWaveResource(void* hModule, void* lpName, void* out1, void* out2, void* out3);
extern void* __cdecl _DSLoadSoundBuffer(void* a, void* b);
extern void __cdecl _SndObjDestroy(void* obj);
extern void* (__stdcall* _LocalAlloc)(int flags, int size);

void* __cdecl _SndObjCreate(void* hModule, void* lpName, int count)
{
    void* pWaveHeader = 0;
    int   waveSize = 0;
    void* extraPtr = 0;
    
    // Parse wave resource
    if (!_DSGetWaveResource(0, lpName, &extraPtr, &pWaveHeader, &waveSize))
        return 0;
    
    // Clamp minimum buffer count
    if (count < 1) count = 1;
    
    // Allocate SNDOBJ with room for buffer pointers
    void* obj = (*_LocalAlloc)(0x40, count * 4 + 0x10);
    if (!obj) return 0;
    
    ((SNDOBJ*)obj)->count = count;
    ((SNDOBJ*)obj)->field_0 = pWaveHeader;
    ((SNDOBJ*)obj)->field_4 = extraPtr;
    ((SNDOBJ*)obj)->buffers[0] = _DSLoadSoundBuffer(hModule, lpName);
    
    if (count > 1) {
        // Create extra duplicated buffers
        int i;
        char* bufPtr = (char*)obj + 0x14; // buffers[1]
        for (i = 1; i < count; i++) {
            void* prevBuf = ((SNDOBJ*)obj)->buffers[0];
            // vtable[0x14]: duplicate buffer
            int hr = ((int (__stdcall*)(void*,int,void*))(*(void**)(extraPtr)))(extraPtr, (int)prevBuf, bufPtr);
            if (hr < 0) {
                // Fallback: try loading another buffer
                *(void**)bufPtr = _DSLoadSoundBuffer(hModule, lpName);
                if (!*(void**)bufPtr) {
                    _SndObjDestroy(obj);
                    return 0;
                }
            }
            bufPtr += 4;
        }
    }
    
    return obj;
}
