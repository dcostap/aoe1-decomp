// getdxver.cpp:54-338, 1053 bytes
// attempt 1: 880/1053 bytes - stack too small, missing proper structs
// attempt 2: 992/1053 bytes - closer but still short
// attempt 3: 1008/1053 bytes - still 45 bytes short
//   FOUND: param_1 = DX version output, param_2 = OS type output (was swapped)
//   Also: OSVERSIONINFOA field order: dwBuildNumber before dwPlatformId (VC5 SDK)
// attempt 4: fix param order, correct OSVERSIONINFOA field order
// attempt 5: fix CoInitialize logic (orig: CoUninit only if result != 0, backwards bug)
//   Still 1008/1053 bytes. 45-byte structural gap:
//   1. Original uses esi (saved reg) for coInitResult, mine uses stack local
//   2. Original has interleaved prologue: lea eax,[esp+8Ch] between push esi and push edi
//   3. Original uses rep stosd for desc zeroing + neg;sbb;neg;add idiom for IsDPlay501a
//   4. Core logic correct: GetVersionExA, WinNT/Win9x paths, LoadLibraryA, GetProcAddress,
//      CoInitialize, CoCreateInstance, IsDPlay501a, COM QI, Release, SetCooperativeLevel,
//      CreateSurface, all error paths with OutputDebugStringA
//   BLOCKER: structural VC5 codegen differences hard to match without inline asm
//   Left in scratch after 5 probes per 10-probe rule for large functions

// OSVERSIONINFOA stub - VC5 SDK field order (confirmed from asm offsets)
//   [esp+0x94]+0x08 = dwBuildNumber (compared with 0x549)
//   [esp+0x94]+0x0C = dwPlatformId (compared with 2)
struct OSVERSIONINFOA {
    unsigned long dwOSVersionInfoSize;
    unsigned long dwMajorVersion;
    unsigned long dwBuildNumber;
    unsigned long dwPlatformId;
    unsigned long dwMinorVersion;
    char szCSDVersion[128];
};  // 144 bytes

// DDSURFACEDESC stub - 108 bytes (0x6C) matching rep stosd zeroing
struct DDSURFACEDESC {
    unsigned int dwSize;
    char gap_04[0x60];
    unsigned int dwFlags;
    unsigned int dwBackBufferCount;
};  // 4 + 0x60 + 4 + 4 = 108

// stdlib
extern void* memset( void*, int, unsigned int );

// Windows API via IAT extern pointers
extern int __stdcall GetVersionExA( void* );
extern void* __stdcall LoadLibraryA( const char* );
extern void* __stdcall GetProcAddress( void*, const char* );
extern void __stdcall FreeLibrary( void* );
extern void __stdcall OutputDebugStringA( const char* );
extern int __stdcall CoInitialize( void* );
extern int __stdcall CoCreateInstance( const void*, void*, unsigned int, const void*, void** );
extern void __stdcall CoUninitialize( void );

// COM base: QI at slot 0, AddRef at 1, Release at 2
struct IUnknown {
    virtual int QueryInterface( const void*, void** ) = 0;
    virtual void* AddRef() = 0;
    virtual void Release() = 0;
};

// IDirectDraw: extends IUnknown (slots 0-2)
// CreateSurface at slot 6 (vtbl+0x18), SetCooperativeLevel at slot 20 (vtbl+0x50)
struct IDirectDraw : IUnknown {
    virtual int vf03() = 0;
    virtual int vf04() = 0;
    virtual int vf05() = 0;
    virtual int CreateSurface( void*, void*, void** ) = 0;
    virtual int vf07() = 0;
    virtual int vf08() = 0;
    virtual int vf09() = 0;
    virtual int vf10() = 0;
    virtual int vf11() = 0;
    virtual int vf12() = 0;
    virtual int vf13() = 0;
    virtual int vf14() = 0;
    virtual int vf15() = 0;
    virtual int vf16() = 0;
    virtual int vf17() = 0;
    virtual int vf18() = 0;
    virtual int vf19() = 0;
    virtual int SetCooperativeLevel( unsigned long, unsigned long ) = 0;
};

struct IDirectDraw2 : IDirectDraw {
};
struct IDirectDrawSurface : IUnknown {
};
struct IDirectDrawSurface3 : IDirectDrawSurface {
};
struct IDirectPlay3 : IUnknown {
};

extern const void* CLSID_DirectPlay;
extern const void* IID_IDirectPlay3;
extern const void* IID_IDirectDraw2;
extern const void* IID_IDirectDrawSurface3;

int IsDPlay501a();

// param_1 = out DX version, param_2 = out OS type
void GetDXVersion( unsigned long* param_1, unsigned long* param_2 ) {
    IDirectDraw* pDDraw;
    IDirectDraw2* pDDraw2;
    IDirectDrawSurface* pSurf;
    IDirectDrawSurface3* pSurf3;
    IDirectPlay3* dp3;
    DDSURFACEDESC desc;

    pDDraw = 0;
    pDDraw2 = 0;
    pSurf = 0;
    pSurf3 = 0;
    dp3 = 0;

    OSVERSIONINFOA osVer;
    osVer.dwOSVersionInfoSize = 0x94;

    if (!GetVersionExA( &osVer )) {
        *param_1 = 0;
        *param_2 = 0;
        return;
    }

    if (osVer.dwPlatformId == 2) {
        *param_2 = 2;  // OS type = Windows NT
        if (osVer.dwMajorVersion < 4) {
            *param_2 = 0;
            return;
        }
        if (osVer.dwMajorVersion != 4) {
            *param_1 = 0x501;
            return;
        }

        *param_1 = 0x200;
        void* hDInput = LoadLibraryA( "DINPUT.DLL" );
        if (hDInput == 0) {
            OutputDebugStringA( "Couldn't LoadLibrary DInput\r\n" );
            return;
        }

        void* fp = GetProcAddress( hDInput, "DirectInputCreateA" );
        FreeLibrary( hDInput );
        if (fp == 0) {
            OutputDebugStringA( "Couldn't GetProcAddress DInputCreate\r\n" );
            return;
        }

        int coInitResult = CoInitialize( 0 );
        int hr = CoCreateInstance( CLSID_DirectPlay, 0, 1, IID_IDirectPlay3, (void**)&dp3 );
        if (hr >= 0) {
            if (dp3) {
                dp3->Release();
            }
            if (coInitResult != 0) {
                CoUninitialize();
            }
        } else {
            if (coInitResult != 0) {
                CoUninitialize();
                return;
            }
        }

        int isDP501a = IsDPlay501a();
        if (isDP501a == 0) {
            *param_1 = 0x500;
        } else {
            *param_1 = 0x501;
        }
        return;
    }

    // Windows 9x path
    *param_2 = 1;
    if ((osVer.dwBuildNumber & 0xFFFF) > 0x549) {
        *param_1 = 0x501;
        return;
    }

    void* hDDraw = LoadLibraryA( "DDRAW.DLL" );
    if (hDDraw == 0) {
        *param_1 = 0;
        *param_2 = 0;
        FreeLibrary( hDDraw );
        return;
    }

    void* fpDDrawCreate = GetProcAddress( hDDraw, "DirectDrawCreate" );
    if (fpDDrawCreate == 0) {
        *param_1 = 0;
        *param_2 = 0;
        FreeLibrary( hDDraw );
        OutputDebugStringA( "Couldn't LoadLibrary DDraw\r\n" );
        return;
    }

    int hr = ((int(*)(void*,void*,void**))fpDDrawCreate)( 0, 0, (void**)&pDDraw );
    if (hr < 0) {
        *param_1 = 0;
        *param_2 = 0;
        FreeLibrary( hDDraw );
        OutputDebugStringA( "Couldn't create DDraw\r\n" );
        return;
    }

    hr = pDDraw->QueryInterface( IID_IDirectDraw2, (void**)&pDDraw2 );
    if (hr < 0) {
        pDDraw->Release();
        FreeLibrary( hDDraw );
        OutputDebugStringA( "Couldn't QI DDraw2\r\n" );
        return;
    }

    pDDraw->Release();
    *param_1 = 0x200;
    void* hDInput2 = LoadLibraryA( "DINPUT.DLL" );
    if (hDInput2 == 0) {
        OutputDebugStringA( "Couldn't LoadLibrary DInput\r\n" );
        pDDraw2->Release();
        FreeLibrary( hDDraw );
        return;
    }

    fpDDrawCreate = GetProcAddress( hDInput2, "DirectInputCreateA" );
    FreeLibrary( hDInput2 );
    if (fpDDrawCreate == 0) {
        FreeLibrary( hDDraw );
        pDDraw2->Release();
        OutputDebugStringA( "Couldn't GetProcAddress DInputCreate\r\n" );
        return;
    }

    memset( &desc, 0, sizeof(desc) );
    desc.dwSize = 0x6C;
    desc.dwFlags = 1;
    *param_1 = 0x300;
    desc.dwBackBufferCount = 0x200;

    hr = pDDraw2->SetCooperativeLevel( 0, 0 );
    if (hr < 0) {
        pDDraw2->Release();
        FreeLibrary( hDDraw );
        *param_1 = 0;
        OutputDebugStringA( "Couldn't Set coop level\r\n" );
        return;
    }

    hr = pDDraw2->CreateSurface( 0, &desc, (void**)&pSurf );
    if (hr < 0) {
        pDDraw2->Release();
        FreeLibrary( hDDraw );
        *param_1 = 0;
        OutputDebugStringA( "Couldn't CreateSurface\r\n" );
        return;
    }

    hr = pSurf->QueryInterface( IID_IDirectDrawSurface3, (void**)&pSurf3 );
    if (hr >= 0) {
        int isDP501a = IsDPlay501a();
        if (isDP501a == 0) {
            *param_1 = 0x500;
        } else {
            *param_1 = 0x501;
        }
        pSurf3->Release();
    }

    pSurf->Release();
    FreeLibrary( hDDraw );
}
