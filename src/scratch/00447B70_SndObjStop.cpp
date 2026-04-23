struct IDirectSoundBufferVTable {
    void* slots[0x13];
};

// tried raw SNDOBJ pointer, then raw void* and register locals; mismatch stayed in prolog/basin
// tried direct vtable-slot calls for +0x48 and +0x34; call shape was close, but VC5 kept choosing EBP
extern "C" __declspec(dllimport) void* __stdcall LocalFree(void* mem);

typedef void (__stdcall *SndObjReleaseFn)(void* obj);
typedef void (__stdcall *SndObjStopFn)(void* obj, int value);

struct SNDOBJ {
    unsigned char* pbWaveData;
    unsigned long cbWaveSize;
    int iAlloc;
    int iCurrent;
    void* Buffers[1];
};

int __cdecl SndObjStop(SNDOBJ* sndObj) {
    if (sndObj == 0) {
        return 0;
    }

    if (sndObj->iAlloc > 0) {
        int index = 0;
        do {
            void* buffer = sndObj->Buffers[index];
            ((SndObjReleaseFn)((*(void***)buffer)[0x12]))(buffer);
            ((SndObjStopFn)((*(void***)buffer)[0xD]))(buffer, 0);
            ++index;
        } while (index < sndObj->iAlloc);
    }

    LocalFree(sndObj);
    return 1;
}
