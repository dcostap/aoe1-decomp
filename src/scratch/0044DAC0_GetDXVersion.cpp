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
// probe 6 (ABI/context): changed the Windows/OLE imports to period declarations and
//   enabled the VC5 string intrinsic surface for the proven 0x6c clear.
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
// probe 20 (abi): modeled the DirectX GUIDs as const objects and passed their addresses;
//   this removes the pointer-variable loads, keeps 47-call parity, and reduces the size
//   gap to 8 bytes. Positional diff worsens from register and local-slot reassignment.
// probe 21 (control-flow, rolled back): shared the surface-QI success cleanup tail;
//   VC5 also tail-merged the DInput-load failure cleanup and lost two target calls.
// probe 22 (restore): retained the explicit surface-QI failure cleanup to preserve the
//   target's duplicated DInput error-path calls; current source remains typed and natural.
// BINARY NOTE: The header-shaped source reaches the 1053-byte boundary and all 47
// calls, but its DirectInputCreate home adds 4 bytes to the 0x114 target frame.
// LIKELY INTENT: Keep the period Windows/OLE and DirectX declarations until a proven
// local-lifetime model removes that one extra home without a synthetic union.
// BLOCKER: The period SDK donor confirms the typed DirectInputCreate declaration
// and late DDSURFACEDESC scope. Those forms still produce a 0x118 frame. The
// executable uses 0x114. All 47 calls align, but the extra four bytes change ESP
// at each external call and on every return path, so this is not accepted drift.

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

// Period Windows and OLE headers provide the imported API declarations.
#include <string.h>
#include <windows.h>
#include <objbase.h>

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
typedef int (__stdcall* DIRECTINPUTCREATE)( void*, unsigned long, void**, void* );

extern const GUID CLSID_DirectPlay;
extern const GUID IID_IDirectPlay3;
extern const GUID IID_IDirectDraw2;
extern const GUID IID_IDirectDrawSurface3;

int IsDPlay501a();

// param_1 = out DX version, param_2 = out OS type
void GetDXVersion( unsigned long* param_1, unsigned long* param_2 ) {
    int hr;
    void* DDHinst = 0;
    void* DIHinst = 0;
    IDirectDraw* pDDraw = 0;
    DIRECTINPUTCREATE DirectInputCreate;
    IDirectPlay3* dp3 = 0;
    IDirectDrawSurface* pSurf;
    IDirectDraw2* pDDraw2 = 0;
    DIRECTDRAWCREATE DirectDrawCreate = 0;
    OSVERSIONINFOA osVer;
    IDirectDrawSurface3* pSurf3 = 0;
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

            DirectInputCreate = (DIRECTINPUTCREATE)GetProcAddress( DIHinst, "DirectInputCreateA" );
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
    hr = pDDraw->QueryInterface( &IID_IDirectDraw2, (void**)&pDDraw2 );
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

    DirectInputCreate = (DIRECTINPUTCREATE)GetProcAddress( DIHinst, "DirectInputCreateA" );
    FreeLibrary( DIHinst );
    if (DirectInputCreate == 0) {
        FreeLibrary( DDHinst );
        pDDraw->Release();
        OutputDebugStringA( "Couldn't GetProcAddress DInputCreate\r\n" );
        return;
    }

    DDSURFACEDESC desc;
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

    hr = pSurf->QueryInterface( &IID_IDirectDrawSurface3, (void**)&pSurf3 );
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
