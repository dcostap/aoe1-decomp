
#include "../include/getdxver.h"
#include <windows.h>
#include <objbase.h>
#include <winver.h>
#include <ddraw.h>
#include <dplay.h>
#include <string.h>

// The pinned headers do not declare these legacy API GUIDs. The module uses
// the imported constants but does not define them.
typedef HRESULT(__stdcall* DIRECTDRAWCREATE)(void*, LPDIRECTDRAW*, void*);
extern "C" const GUID CLSID_DirectPlay;
extern "C" const GUID IID_IDirectPlay3;
extern "C" const GUID IID_IDirectDrawSurface3;

void GetDXVersion(unsigned long* pdwDXVersion, unsigned long* pdwDXPlatform) {
    int hr;
    void* DDHinst = 0;
    void* DIHinst = 0;
    IDirectDraw* pDDraw;
    IDirectDrawSurface* pSurf;
    IDirectDraw2* pDDraw2;
    IUnknown* pSurf3;
    DIRECTDRAWCREATE DirectDrawCreate;
    OSVERSIONINFOA osVer;
    pDDraw = 0;
    pDDraw2 = 0;
    pSurf = 0;
    pSurf3 = 0;
    osVer.dwOSVersionInfoSize = 0x94;

    if (!GetVersionExA(&osVer)) {
        *pdwDXVersion = 0;
        *pdwDXPlatform = 0;
        return;
    }

    if (osVer.dwPlatformId == VER_PLATFORM_WIN32_NT) {
        *pdwDXPlatform = VER_PLATFORM_WIN32_NT;
        if (osVer.dwMajorVersion < 4) {
            *pdwDXPlatform = 0;
            return;
        }
        if (osVer.dwMajorVersion == 4) {
            *pdwDXVersion = 0x200;
            DIHinst = LoadLibraryA("DINPUT.DLL");
            if (DIHinst == 0) {
                OutputDebugStringA("Couldn't LoadLibrary DInput\r\n");
                return;
            }

            {
                void* DirectInputCreateA = GetProcAddress(DIHinst, "DirectInputCreateA");
                FreeLibrary(DIHinst);
                if (DirectInputCreateA == 0) {
                    OutputDebugStringA("Couldn't GetProcAddress DInputCreate\r\n");
                    return;
                }
            }

            {
                IUnknown* dp3;
                *pdwDXVersion = 0x300;
                int coInitResult = CoInitialize(0);
                hr = CoCreateInstance(CLSID_DirectPlay, 0, CLSCTX_INPROC_SERVER, IID_IDirectPlay3, (void**) &dp3);
                if (hr < 0) {
                    if (coInitResult != 0)
                        CoUninitialize();
                    return;
                }

                dp3->Release();
                if (coInitResult != 0)
                    CoUninitialize();
                *pdwDXVersion = (IsDPlay501a() != 0) + 0x500;
                return;
            }
        }

        *pdwDXVersion = 0x501;
        return;
    }

    {
        *pdwDXPlatform = VER_PLATFORM_WIN32_WINDOWS;
        if ((osVer.dwBuildNumber & 0xFFFF) > 0x549) {
            *pdwDXVersion = 0x501;
            return;
        }

        DDHinst = LoadLibraryA("DDRAW.DLL");
        if (DDHinst == 0) {
            *pdwDXVersion = 0;
            *pdwDXPlatform = 0;
            FreeLibrary(DDHinst);
            return;
        }

        DirectDrawCreate = (DIRECTDRAWCREATE) GetProcAddress(DDHinst, "DirectDrawCreate");
        if (DirectDrawCreate == 0) {
            *pdwDXVersion = 0;
            *pdwDXPlatform = 0;
            FreeLibrary(DDHinst);
            OutputDebugStringA("Couldn't LoadLibrary DDraw\r\n");
            return;
        }

        hr = DirectDrawCreate(0, &pDDraw, 0);
        if (hr < 0) {
            *pdwDXVersion = 0;
            *pdwDXPlatform = 0;
            FreeLibrary(DDHinst);
            OutputDebugStringA("Couldn't create DDraw\r\n");
            return;
        }

        *pdwDXVersion = 0x100;
        hr = pDDraw->QueryInterface(IID_IDirectDraw2, (void**) &pDDraw2);
        if (hr < 0) {
            pDDraw->Release();
            FreeLibrary(DDHinst);
            OutputDebugStringA("Couldn't QI DDraw2\r\n");
            return;
        }

        pDDraw2->Release();
        *pdwDXVersion = 0x200;
        DIHinst = LoadLibraryA("DINPUT.DLL");
        if (DIHinst == 0) {
            OutputDebugStringA("Couldn't LoadLibrary DInput\r\n");
            pDDraw->Release();
            FreeLibrary(DDHinst);
            return;
        }

        void* DirectInputCreateA = GetProcAddress(DIHinst, "DirectInputCreateA");
        FreeLibrary(DIHinst);
        if (DirectInputCreateA == 0) {
            FreeLibrary(DDHinst);
            pDDraw->Release();
            OutputDebugStringA("Couldn't GetProcAddress DInputCreate\r\n");
            return;
        }

        DDSURFACEDESC desc;
        memset(&desc, 0, sizeof(desc));
        *pdwDXVersion = 0x300;
        desc.dwSize = sizeof(desc);
        desc.dwFlags = DDSD_CAPS;
        desc.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;

        hr = pDDraw->SetCooperativeLevel(0, DDSCL_NORMAL);
        if (hr < 0) {
            pDDraw->Release();
            FreeLibrary(DDHinst);
            *pdwDXVersion = 0;
            OutputDebugStringA("Couldn't Set coop level\r\n");
            return;
        }

        hr = pDDraw->CreateSurface(&desc, &pSurf, 0);
        if (hr < 0) {
            pDDraw->Release();
            FreeLibrary(DDHinst);
            *pdwDXVersion = 0;
            OutputDebugStringA("Couldn't CreateSurface\r\n");
            return;
        }

        hr = pSurf->QueryInterface(IID_IDirectDrawSurface3, (void**) &pSurf3);
        if (hr < 0) {
            pDDraw->Release();
            FreeLibrary(DDHinst);
            return;
        }

        *pdwDXVersion = (IsDPlay501a() != 0) + 0x500;
        pSurf->Release();
        pDDraw->Release();
        FreeLibrary(DDHinst);
    }
}

int IsDPlay501a() {
    DWORD zero;
    UINT verSize = GetFileVersionInfoSizeA("dplayx.dll", &zero);
    VS_FIXEDFILEINFO* verInfo;
    unsigned int verInfoLen;
    BOOL result;

    if (verSize == 0) {
        GetLastError();
        return 0;
    }
    BYTE* pv = new BYTE[verSize];
    if (pv) {
        if (!GetFileVersionInfoA("dplayx.dll", 0, verSize, pv)) {
            GetLastError();
            return 0;
        }
        result = VerQueryValueA(pv, "\\", (void**) &verInfo, &verInfoLen);
        if (result) {
            unsigned int a = verInfo->dwFileVersionMS;
            unsigned int b = verInfo->dwFileVersionLS;
            if (a != 0x40005)
                goto check;
            if (b >= 0x1062F)
                goto yes;
        check:
            if (a <= 0x40005)
                goto no;
        yes:
            return 1;
        no:;
        }
    }
    return 0;
}
