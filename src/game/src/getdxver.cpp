#include <windows.h>
#include <ddraw.h>
#include <dplay.h>
#include <new>
#include <string.h>
#include <winver.h>

namespace {
static const char* kCouldntLoadDInput = "Couldn't LoadLibrary DInput\r\n";
static const char* kCouldntGetProcDInputCreate = "Couldn't GetProcAddress DInputCreate\r\n";
static const char* kCouldntLoadDDraw = "Couldn't LoadLibrary DDraw\r\n";
static const char* kCouldntCreateDDraw = "Couldn't create DDraw\r\n";
static const char* kCouldntQIDDraw2 = "Couldn't QI DDraw2\r\n";
static const char* kCouldntSetCoopLevel = "Couldn't Set coop level\r\n";
static const char* kCouldntCreateSurface = "Couldn't CreateSurface\r\n";

typedef DWORD(WINAPI* GetFileVersionInfoSizeA_t)(LPCSTR, LPDWORD);
typedef BOOL(WINAPI* GetFileVersionInfoA_t)(LPCSTR, DWORD, DWORD, LPVOID);
typedef BOOL(WINAPI* VerQueryValueA_t)(LPCVOID, LPCSTR, LPVOID*, PUINT);

// Offset: 0x0044DEE0
static int IsDPlay501a() {
    HMODULE hVersion = LoadLibraryA("version.dll");
    if (!hVersion) return 0;

    GetFileVersionInfoSizeA_t pGetFileVersionInfoSizeA =
        (GetFileVersionInfoSizeA_t)GetProcAddress(hVersion, "GetFileVersionInfoSizeA");
    GetFileVersionInfoA_t pGetFileVersionInfoA =
        (GetFileVersionInfoA_t)GetProcAddress(hVersion, "GetFileVersionInfoA");
    VerQueryValueA_t pVerQueryValueA = (VerQueryValueA_t)GetProcAddress(hVersion, "VerQueryValueA");

    if (!pGetFileVersionInfoSizeA || !pGetFileVersionInfoA || !pVerQueryValueA) {
        FreeLibrary(hVersion);
        return 0;
    }

    DWORD unused = 0;
    DWORD verSize = pGetFileVersionInfoSizeA("dplayx.dll", &unused);
    if (verSize == 0) {
        GetLastError();
        FreeLibrary(hVersion);
        return 0;
    }

    BYTE* buf = new (std::nothrow) BYTE[verSize];
    if (!buf) {
        FreeLibrary(hVersion);
        return 0;
    }

    int result = 0;
    if (pGetFileVersionInfoA("dplayx.dll", 0, verSize, buf)) {
        VS_FIXEDFILEINFO* verInfo = nullptr;
        UINT verInfoLen = 0;
        if (pVerQueryValueA(buf, "\\", (LPVOID*)&verInfo, &verInfoLen) && verInfo) {
            const DWORD fileVerMS = verInfo->dwFileVersionMS;
            const DWORD fileVerLS = verInfo->dwFileVersionLS;
            if (fileVerMS > 0x40005 || (fileVerMS == 0x40005 && fileVerLS >= 0x1062F)) {
                result = 1;
            }
        }
    } else {
        GetLastError();
    }

    delete[] buf;
    FreeLibrary(hVersion);
    return result;
}
} // namespace

// Offset: 0x0044DAC0
void GetDXVersion(unsigned long* dx_version, unsigned long* dx_platform) {
    if (dx_version) *dx_version = 0;
    if (dx_platform) *dx_platform = 0;

    OSVERSIONINFOA osVer;
    memset(&osVer, 0, sizeof(osVer));
    osVer.dwOSVersionInfoSize = sizeof(osVer);
    if (!GetVersionExA(&osVer)) return;

    if (osVer.dwPlatformId == VER_PLATFORM_WIN32_NT) {
        if (dx_platform) *dx_platform = 2;

        if (osVer.dwMajorVersion < 4) {
            if (dx_platform) *dx_platform = 0;
            return;
        }

        if (osVer.dwMajorVersion != 4) {
            if (dx_version) *dx_version = 0x501;
            return;
        }

        if (dx_version) *dx_version = 0x200;
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

        if (dx_version) *dx_version = 0x300;
        HRESULT hrInit = CoInitialize(nullptr);

        IDirectPlay3* dp3 = nullptr;
        HRESULT hrCreate = CoCreateInstance(
            CLSID_DirectPlay, nullptr, CLSCTX_INPROC_SERVER, IID_IDirectPlay3, (void**)&dp3);
        if (FAILED(hrCreate)) {
            // Parity with getdxver.cpp.asm: CoUninitialize is only called when CoInitialize() returned non-zero.
            if (hrInit != 0) CoUninitialize();
            return;
        }

        if (dp3) dp3->Release();
        // Parity with getdxver.cpp.asm: CoUninitialize is only called when CoInitialize() returned non-zero.
        if (hrInit != 0) CoUninitialize();

        if (dx_version) *dx_version = (IsDPlay501a() != 0) ? 0x501 : 0x500;
        return;
    }

    if (dx_platform) *dx_platform = 1;
    if ((osVer.dwBuildNumber & 0xFFFF) > 0x549) {
        if (dx_version) *dx_version = 0x501;
        return;
    }

    if (dx_version) *dx_version = 0;
    HMODULE hDDraw = LoadLibraryA("DDRAW.DLL");
    if (!hDDraw) {
        if (dx_platform) *dx_platform = 0;
        return;
    }

    typedef HRESULT(WINAPI* DirectDrawCreate_t)(GUID*, IDirectDraw**, IUnknown*);
    DirectDrawCreate_t pDirectDrawCreate =
        (DirectDrawCreate_t)GetProcAddress(hDDraw, "DirectDrawCreate");
    if (!pDirectDrawCreate) {
        if (dx_platform) *dx_platform = 0;
        FreeLibrary(hDDraw);
        OutputDebugStringA(kCouldntLoadDDraw);
        return;
    }

    IDirectDraw* pDDraw = nullptr;
    HRESULT hrDD = pDirectDrawCreate(nullptr, &pDDraw, nullptr);
    if (FAILED(hrDD) || !pDDraw) {
        if (dx_platform) *dx_platform = 0;
        FreeLibrary(hDDraw);
        OutputDebugStringA(kCouldntCreateDDraw);
        return;
    }

    if (dx_version) *dx_version = 0x100;
    IDirectDraw2* pDDraw2 = nullptr;
    HRESULT hrQI = pDDraw->QueryInterface(IID_IDirectDraw2, (void**)&pDDraw2);
    if (FAILED(hrQI) || !pDDraw2) {
        pDDraw->Release();
        FreeLibrary(hDDraw);
        OutputDebugStringA(kCouldntQIDDraw2);
        return;
    }
    pDDraw2->Release();

    if (dx_version) *dx_version = 0x200;
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
        OutputDebugStringA(kCouldntGetProcDInputCreate);
        pDDraw->Release();
        FreeLibrary(hDDraw);
        return;
    }

    if (dx_version) *dx_version = 0x300;

    DDSURFACEDESC desc;
    memset(&desc, 0, sizeof(desc));
    desc.dwSize = 0x6c;
    desc.dwFlags = 0x1;
    desc.ddsCaps.dwCaps = 0x200;

    HRESULT hr = pDDraw->SetCooperativeLevel(nullptr, DDSCL_NORMAL);
    if (FAILED(hr)) {
        if (dx_version) *dx_version = 0;
        OutputDebugStringA(kCouldntSetCoopLevel);
        pDDraw->Release();
        FreeLibrary(hDDraw);
        return;
    }

    IDirectDrawSurface* pSurf = nullptr;
    hr = pDDraw->CreateSurface(&desc, &pSurf, nullptr);
    if (FAILED(hr) || !pSurf) {
        if (dx_version) *dx_version = 0;
        OutputDebugStringA(kCouldntCreateSurface);
        pDDraw->Release();
        FreeLibrary(hDDraw);
        return;
    }

    IDirectDrawSurface3* pSurf3 = nullptr;
    hr = pSurf->QueryInterface(IID_IDirectDrawSurface3, (void**)&pSurf3);
    if (SUCCEEDED(hr) && pSurf3) {
        if (dx_version) *dx_version = (IsDPlay501a() != 0) ? 0x501 : 0x500;
        pSurf3->Release();
    }

    pSurf->Release();
    pDDraw->Release();
    FreeLibrary(hDDraw);
}
