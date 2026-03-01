#include <windows.h>
#include <ddraw.h>
#include <dplay.h>
#include <new>
#include <string.h>
#include <winver.h>
#pragma comment(lib, "version.lib")

namespace {
static const char* kCouldntLoadDInput = "Couldn't LoadLibrary DInput\r\n";
static const char* kCouldntGetProcDInputCreate = "Couldn't GetProcAddress DInputCreate\r\n";
static const char* kCouldntLoadDDraw = "Couldn't LoadLibrary DDraw\r\n";
static const char* kCouldntCreateDDraw = "Couldn't create DDraw\r\n";
static const char* kCouldntQIDDraw2 = "Couldn't QI DDraw2\r\n";
static const char* kCouldntSetCoopLevel = "Couldn't Set coop level\r\n";
static const char* kCouldntCreateSurface = "Couldn't CreateSurface\r\n";

// Fully verified. Source of truth: getdxver.cpp.decomp @ 0x0044DEE0
static int IsDPlay501a() {
    // Fully verified. Source of truth: getdxver.cpp.decomp @ 0x0044DEE0
    DWORD zero = 0;
    DWORD verSize = GetFileVersionInfoSizeA("dplayx.dll", &zero);
    if (verSize == 0) {
        GetLastError();
        return 0;
    }

    BYTE* buf = new (std::nothrow) BYTE[verSize];
    if (!buf) {
        return 0;
    }

    if (!GetFileVersionInfoA("dplayx.dll", 0, verSize, buf)) {
        GetLastError();
        return 0;
    }

    VS_FIXEDFILEINFO* verInfo = nullptr;
    UINT verInfoLen = 0;
    if (!VerQueryValueA(buf, "\\", (LPVOID*)&verInfo, &verInfoLen)) {
        return 0;
    }

    const DWORD fileVerMS = verInfo->dwFileVersionMS;
    const DWORD fileVerLS = verInfo->dwFileVersionLS;
    if (fileVerMS == 0x40005) {
        return (fileVerLS >= 0x1062F) ? 1 : 0;
    }
    return (fileVerMS > 0x40005) ? 1 : 0;
}
} // namespace

// Fully verified. Source of truth: getdxver.cpp.decomp @ 0x0044DAC0
void GetDXVersion(unsigned long* dx_version, unsigned long* dx_platform) {
    // Fully verified. Source of truth: getdxver.cpp.decomp @ 0x0044DAC0
    OSVERSIONINFOA osVer;
    memset(&osVer, 0, sizeof(osVer));
    osVer.dwOSVersionInfoSize = sizeof(osVer);
    if (!GetVersionExA(&osVer)) {
        *dx_version = 0;
        *dx_platform = 0;
        return;
    }

    if (osVer.dwPlatformId == VER_PLATFORM_WIN32_NT) {
        *dx_platform = 2;

        if (osVer.dwMajorVersion < 4) {
            *dx_platform = 0;
            return;
        }

        if (osVer.dwMajorVersion != 4) {
            *dx_version = 0x501;
            return;
        }

        *dx_version = 0x200;
        HMODULE hDInput = LoadLibraryA("DINPUT.DLL");
        if (!hDInput) {
            OutputDebugStringA(kCouldntLoadDInput);
            return;
        }

        FARPROC diCreate = GetProcAddress(hDInput, "DirectInputCreateA");
        FreeLibrary(hDInput);
        if (!diCreate) {
            OutputDebugStringA(kCouldntGetProcDInputCreate);
            return;
        }

        *dx_version = 0x300;
        HRESULT hrInit = CoInitialize(nullptr);

        IDirectPlay3* dp3 = nullptr;
        HRESULT hrCreate = CoCreateInstance(
            CLSID_DirectPlay, nullptr, CLSCTX_INPROC_SERVER, IID_IDirectPlay3, (void**)&dp3);
        if (hrCreate < 0) {
            if (hrInit != 0) CoUninitialize();
            return;
        }

        dp3->Release();
        if (hrInit != 0) CoUninitialize();

        *dx_version = (IsDPlay501a() != 0) ? 0x501 : 0x500;
        return;
    }

    *dx_platform = 1;
    if ((osVer.dwBuildNumber & 0xFFFF) > 0x549) {
        *dx_version = 0x501;
        return;
    }

    HMODULE hDDraw = LoadLibraryA("DDRAW.DLL");
    if (!hDDraw) {
        *dx_version = 0;
        *dx_platform = 0;
        FreeLibrary(hDDraw);
        return;
    }

    typedef HRESULT(WINAPI* DirectDrawCreate_t)(GUID*, IDirectDraw**, IUnknown*);
    DirectDrawCreate_t pDirectDrawCreate =
        (DirectDrawCreate_t)GetProcAddress(hDDraw, "DirectDrawCreate");
    if (!pDirectDrawCreate) {
        *dx_version = 0;
        *dx_platform = 0;
        FreeLibrary(hDDraw);
        OutputDebugStringA(kCouldntLoadDDraw);
        return;
    }

    IDirectDraw* pDDraw = nullptr;
    HRESULT hrDD = pDirectDrawCreate(nullptr, &pDDraw, nullptr);
    if (hrDD < 0) {
        *dx_version = 0;
        *dx_platform = 0;
        FreeLibrary(hDDraw);
        OutputDebugStringA(kCouldntCreateDDraw);
        return;
    }

    *dx_version = 0x100;
    IDirectDraw2* pDDraw2 = nullptr;
    HRESULT hrQI = pDDraw->QueryInterface(IID_IDirectDraw2, (void**)&pDDraw2);
    if (hrQI < 0) {
        pDDraw->Release();
        FreeLibrary(hDDraw);
        OutputDebugStringA(kCouldntQIDDraw2);
        return;
    }
    pDDraw2->Release();

    *dx_version = 0x200;
    HMODULE hDInput = LoadLibraryA("DINPUT.DLL");
    if (!hDInput) {
        OutputDebugStringA(kCouldntLoadDInput);
        pDDraw->Release();
        FreeLibrary(hDDraw);
        return;
    }

    FARPROC diCreate = GetProcAddress(hDInput, "DirectInputCreateA");
    FreeLibrary(hDInput);
    if (!diCreate) {
        FreeLibrary(hDDraw);
        pDDraw->Release();
        OutputDebugStringA(kCouldntGetProcDInputCreate);
        return;
    }

    *dx_version = 0x300;

    DDSURFACEDESC desc;
    memset(&desc, 0, sizeof(desc));
    desc.dwSize = 0x6c;
    desc.dwFlags = 0x1;
    desc.ddsCaps.dwCaps = 0x200;

    HRESULT hr = pDDraw->SetCooperativeLevel(nullptr, DDSCL_NORMAL);
    if (hr < 0) {
        pDDraw->Release();
        FreeLibrary(hDDraw);
        *dx_version = 0;
        OutputDebugStringA(kCouldntSetCoopLevel);
        return;
    }

    IDirectDrawSurface* pSurf = nullptr;
    hr = pDDraw->CreateSurface(&desc, &pSurf, nullptr);
    if (hr < 0) {
        pDDraw->Release();
        FreeLibrary(hDDraw);
        *dx_version = 0;
        OutputDebugStringA(kCouldntCreateSurface);
        return;
    }

    IDirectDrawSurface3* pSurf3 = nullptr;
    hr = pSurf->QueryInterface(IID_IDirectDrawSurface3, (void**)&pSurf3);
    if (hr >= 0) {
        *dx_version = (IsDPlay501a() != 0) ? 0x501 : 0x500;
        pSurf->Release();
    }

    pDDraw->Release();
    FreeLibrary(hDDraw);
}
