// getdxver.cpp:54-338, 1053 bytes
// attempt 1: 880/1053 bytes - stack too small, missing proper structs
// attempt 2: 992/1053 bytes - closer but still short
// attempt 3: 1008/1053 bytes - still 45 bytes short
//   FOUND: param_1 = DX version output, param_2 = OS type output (was swapped)
//   Also: OSVERSIONINFOA uses the SDK order size/major/minor/build/platform/CSD.
// attempt 4: fix param order, correct OSVERSIONINFOA field order
// attempt 5: fix CoInitialize logic (orig: CoUninit only if result != 0, backwards bug)
//   Still 1008/1053 bytes. 45-byte structural gap:
//   1. Original uses esi (saved reg) for coInitResult, mine uses stack local
//   2. Original has interleaved prologue: lea eax,[esp+8Ch] between push esi and push edi
//   3. Original uses rep stosd for desc zeroing + neg;sbb;neg;add idiom for IsDPlay501a
//   4. Core logic correct: GetVersionExA, WinNT/Win9x paths, LoadLibraryA, GetProcAddress,
//      CoInitialize, CoCreateInstance, IsDPlay501a, COM QI, Release, SetCooperativeLevel,
//      CreateSurface, all error paths with OutputDebugStringA
// probe 6 (ABI/context): changed the Windows/OLE imports to period IAT function-pointer
//   declarations and enabled the VC5 string intrinsic surface for the proven 0x6c clear.
// probe 7 (behavior/layout): restored the DirectX SDK-shaped local ownership and
//   C-style COM __stdcall vtable ABI visible in the stack-self calls. Also restored
//   the DX1/DX2/DX3 version stores, pDDraw ownership, and DDSURFACEDESC field offsets.
// Final bounded pass: the current source is the best canonical reconstruction,
//   not a codegen scaffold. It reaches the correct 0x114 frame/1053-byte boundary,
//   47-vs-45 call-site basin, typed COM stack-self calls, canonical OSVERSIONINFOA
//   and DDSURFACEDESC ownership, and all major error-path behavior. Remaining drift
//   is structural VC5 scheduling: EBX/EBP zero/import coloring, pointer local slot
//   order, late SetCooperativeLevel/descriptor scheduling, and two duplicated
//   cleanup calls that VC5 tail-merges in this TU. No inline asm or opaque offsets.
// probe 13 (control-flow): made the CoCreateInstance failure an early negative-result guard;
//   this places its CoUninitialize block before the success path, matching the original first
//   call-map hunk and improving the ordered call prefix from 8 to 27.
// probe 15 (control-flow): made the surface QI failure an explicit cleanup path;
//   typed pDDraw ownership now emits both missing Release/FreeLibrary calls and restores
//   the original 47-call surface, but the separate path adds 16 bytes past the boundary.

// OSVERSIONINFOA stub - VC5 SDK field order (confirmed from asm offsets)
//   [esp+0x94]+0x08 = dwBuildNumber (compared with 0x549)
//   [esp+0x94]+0x0C = dwPlatformId (compared with 2)
struct OSVERSIONINFOA {
    unsigned long dwOSVersionInfoSize;
    unsigned long dwMajorVersion;
    unsigned long dwMinorVersion;
    unsigned long dwBuildNumber;
    unsigned long dwPlatformId;
    char szCSDVersion[128];
};  // 144 bytes

// The old DirectDraw record is 0x6c bytes. Only these fields are touched here,
// but retain their real offsets rather than treating the middle as a guessed
// back-buffer field: dwFlags is +4 and ddsCaps.dwCaps is +68.
struct DDSCAPS {
    unsigned long dwCaps;
};

struct DDSURFACEDESC {
    unsigned long dwSize;
    unsigned long dwFlags;
    char gap_08[0x60];
    DDSCAPS ddsCaps;
};  // 4 + 4 + 0x60 + 4 = 108

// The original imports are indirect IAT calls, not direct external calls.  Keep
// these as declaration-only function pointers so the linker preserves that ABI.
#include <string.h>
// Windows API via IAT extern pointers
extern "C" int (__stdcall* const GetVersionExA)( void* );
extern "C" void* (__stdcall* const LoadLibraryA)( const char* );
extern "C" void* (__stdcall* const GetProcAddress)( void*, const char* );
extern "C" void (__stdcall* const FreeLibrary)( void* );
extern "C" void (__stdcall* const OutputDebugStringA)( const char* );
extern "C" int (__stdcall* const CoInitialize)( void* );
extern "C" int (__stdcall* const CoCreateInstance)( const void*, void*, unsigned int, const void*, void** );
extern "C" void (__stdcall* const CoUninitialize)( void );

// The DirectX SDK's C++ interface methods are __stdcall.  VC5 therefore emits
// the COM object as an explicit stack argument to each vtable call, matching
// the original ff [vtable+slot] sequences without a hand-written vtable view.
class IDirectDraw {
public:
    virtual int __stdcall QueryInterface( const void*, void** ) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual int __stdcall slot0C() = 0;
    virtual int __stdcall slot10() = 0;
    virtual int __stdcall slot14() = 0;
    virtual int __stdcall CreateSurface( DDSURFACEDESC*, void**, void* ) = 0;
    virtual int __stdcall slot1C() = 0;
    virtual int __stdcall slot20() = 0;
    virtual int __stdcall slot24() = 0;
    virtual int __stdcall slot28() = 0;
    virtual int __stdcall slot2C() = 0;
    virtual int __stdcall slot30() = 0;
    virtual int __stdcall slot34() = 0;
    virtual int __stdcall slot38() = 0;
    virtual int __stdcall slot3C() = 0;
    virtual int __stdcall slot40() = 0;
    virtual int __stdcall slot44() = 0;
    virtual int __stdcall slot48() = 0;
    virtual int __stdcall slot4C() = 0;
    virtual int __stdcall SetCooperativeLevel( void*, unsigned long ) = 0;
};

class IDirectDraw2 : public IDirectDraw {
};

class IDirectDrawSurface {
public:
    virtual int __stdcall QueryInterface( const void*, void** ) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

class IDirectDrawSurface3 : public IDirectDrawSurface {
};

class IDirectPlay3 {
public:
    virtual int __stdcall QueryInterface( const void*, void** ) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

typedef int (__stdcall* DIRECTDRAWCREATE)( void*, IDirectDraw**, void* );

extern const void* CLSID_DirectPlay;
extern const void* IID_IDirectPlay3;
extern const void* IID_IDirectDraw2;
extern const void* IID_IDirectDrawSurface3;

int IsDPlay501a();

// param_1 = out DX version, param_2 = out OS type
void GetDXVersion( unsigned long* param_1, unsigned long* param_2 ) {
    int hr;
    void* DDHinst = 0;
    void* DIHinst = 0;
    IDirectDraw* pDDraw = 0;
    IDirectPlay3* dp3 = 0;
    IDirectDrawSurface* pSurf;
    IDirectDraw2* pDDraw2 = 0;
    DIRECTDRAWCREATE DirectDrawCreate = 0;
    void* DirectInputCreate;
    OSVERSIONINFOA osVer;
    IDirectDrawSurface3* pSurf3 = 0;
    DDSURFACEDESC desc;
    osVer.dwOSVersionInfoSize = 0x94;

    if (!GetVersionExA( &osVer )) {
        *param_1 = 0;
        *param_2 = 0;
        return;
    }

    if (osVer.dwPlatformId == 2) {
        *param_2 = 2;
        if (osVer.dwMajorVersion < 4) {
            *param_2 = 0;
            return;
        }
        if (osVer.dwMajorVersion == 4) {
            *param_1 = 0x200;
            DIHinst = LoadLibraryA( "DINPUT.DLL" );
            if (DIHinst == 0) {
                OutputDebugStringA( "Couldn't LoadLibrary DInput\r\n" );
                return;
            }

            DirectInputCreate = GetProcAddress( DIHinst, "DirectInputCreateA" );
            FreeLibrary( DIHinst );
            if (DirectInputCreate == 0) {
                OutputDebugStringA( "Couldn't GetProcAddress DInputCreate\r\n" );
                return;
            }

            *param_1 = 0x300;
            int coInitResult = CoInitialize( 0 );
            hr = CoCreateInstance( CLSID_DirectPlay, 0, 1, IID_IDirectPlay3,
                                   (void**)&dp3 );
            if (hr < 0) {
                if (coInitResult != 0)
                    CoUninitialize();
                return;
            }

            dp3->Release();
            if (coInitResult != 0)
                CoUninitialize();
            *param_1 = (IsDPlay501a() != 0) + 0x500;
            return;
        }

        *param_1 = 0x501;
        return;
    }

    *param_2 = 1;
    if ((osVer.dwBuildNumber & 0xFFFF) > 0x549) {
        *param_1 = 0x501;
        return;
    }

    DDHinst = LoadLibraryA( "DDRAW.DLL" );
    if (DDHinst == 0) {
        *param_1 = 0;
        *param_2 = 0;
        FreeLibrary( DDHinst );
        return;
    }

    DirectDrawCreate = (DIRECTDRAWCREATE)GetProcAddress( DDHinst,
                                                           "DirectDrawCreate" );
    if (DirectDrawCreate == 0) {
        *param_1 = 0;
        *param_2 = 0;
        FreeLibrary( DDHinst );
        OutputDebugStringA( "Couldn't LoadLibrary DDraw\r\n" );
        return;
    }

    hr = DirectDrawCreate( 0, &pDDraw, 0 );
    if (hr < 0) {
        *param_1 = 0;
        *param_2 = 0;
        FreeLibrary( DDHinst );
        OutputDebugStringA( "Couldn't create DDraw\r\n" );
        return;
    }

    *param_1 = 0x100;
    hr = pDDraw->QueryInterface( IID_IDirectDraw2, (void**)&pDDraw2 );
    if (hr < 0) {
        pDDraw->Release();
        FreeLibrary( DDHinst );
        OutputDebugStringA( "Couldn't QI DDraw2\r\n" );
        return;
    }

    pDDraw2->Release();
    *param_1 = 0x200;
    DIHinst = LoadLibraryA( "DINPUT.DLL" );
    if (DIHinst == 0) {
        OutputDebugStringA( "Couldn't LoadLibrary DInput\r\n" );
        pDDraw->Release();
        FreeLibrary( DDHinst );
        return;
    }

    DirectInputCreate = GetProcAddress( DIHinst, "DirectInputCreateA" );
    FreeLibrary( DIHinst );
    if (DirectInputCreate == 0) {
        FreeLibrary( DDHinst );
        pDDraw->Release();
        OutputDebugStringA( "Couldn't GetProcAddress DInputCreate\r\n" );
        return;
    }

    memset( &desc, 0, sizeof(desc) );
    desc.dwSize = sizeof(desc);
    desc.dwFlags = 1;
    desc.ddsCaps.dwCaps = 0x200;
    *param_1 = 0x300;

    hr = pDDraw->SetCooperativeLevel( 0, 8 );
    if (hr < 0) {
        pDDraw->Release();
        FreeLibrary( DDHinst );
        *param_1 = 0;
        OutputDebugStringA( "Couldn't Set coop level\r\n" );
        return;
    }

    hr = pDDraw->CreateSurface( &desc, (void**)&pSurf, 0 );
    if (hr < 0) {
        pDDraw->Release();
        FreeLibrary( DDHinst );
        *param_1 = 0;
        OutputDebugStringA( "Couldn't CreateSurface\r\n" );
        return;
    }

    hr = pSurf->QueryInterface( IID_IDirectDrawSurface3, (void**)&pSurf3 );
    if (hr < 0) {
        pDDraw->Release();
        FreeLibrary( DDHinst );
        return;
    }

    *param_1 = (IsDPlay501a() != 0) + 0x500;
    pSurf->Release();
    pDDraw->Release();
    FreeLibrary( DDHinst );
}
