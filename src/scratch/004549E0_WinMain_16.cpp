// 004549E0 _WinMain@16
// Attempt log:
// try 1: broad natural WinMain skeleton from packet with strcpy calls: compile failed on VC5 __thiscall typedefs.
// try 2: changed vtable/ctor surfaces to __stdcall; default /O2 too small (.text 1328 vs 1553).
// try 3: /GX no size/codegen change for try 2; rolled back.
// try 4: /Od on try 2 even smaller (.text 991); rolled back.
// try 5: replaced strcpy calls with inline CP loop macro to mimic original inline string copies; default /O2 improved to .text 1456 vs 1553 but still too small.
// try 6: diagnostic impossible nShow/cmdLine/hPrev/hInst branches only to force exact-size compare; exact-size 1553/1553 but broad mismatch 94.6555% positional / 112.1700% edit, first mismatch prologue (rebuilt lacks original EH registration/allocation pattern); diagnostic branches rolled back.
// left in scratch: no custom flags retained. Not accepted_drift quality; likely needs real app-info struct, real TApplication constructor/destructor surface, /GX/EH cleanup context, and exact original string/aggregate initialization topology.

typedef void* HINSTANCE;
typedef void* HWND;
typedef unsigned int UINT;
typedef long LPARAM;
typedef const char* LPCSTR;

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" int __stdcall MessageBoxA(HWND,LPCSTR,LPCSTR,UINT);
extern "C" void* __cdecl CP(void*, const void*);
#define CP(D,S) do { char* d_=(char*)(D); const char* s_=(const char*)(S); while ((*d_++ = *s_++) != 0) {} } while(0)
extern "C" int __cdecl memset(void*, int, unsigned int);

struct App;
struct AppVtbl {
    int (__stdcall *destroy)(App*, int);
    int (__stdcall *get_error)(App*);
    void* f08; void* f0c; void* f10; void* f14;
    int (__stdcall *run)(App*);
    void* f1c;
    void (__stdcall *get_string)(App*, int, char*, int);
    void* f24;
    void (__stdcall *format_error)(App*, int, int, char*, int, int);
};
struct App { AppVtbl* vtbl; };

extern "C" App* __stdcall App_ctor(App*, char* info, int flag);

struct InfoBlock { char bytes[0x1430]; };

extern "C" int __stdcall WinMain(HINSTANCE hInst, HINSTANCE hPrev, char* cmdLine, int nShow)
{
    int err = 0;
    int ret = 0;
    App* app = 0;
    InfoBlock info;
    memset(&info, 0, sizeof(info));

    CP(&info.bytes[0x000], (const void*)0x584AB4);
    CP(&info.bytes[0x065], (const void*)0x584AA4);
    sprintf(&info.bytes[0x07A], (const char*)0x57F324, &info.bytes[0x000]);
    CP(&info.bytes[0x0F7], (const void*)0x584A98);
    CP(&info.bytes[0x1FC], (const void*)0x584A84);
    CP(&info.bytes[0x41C], (const void*)0x584A54);
    CP(&info.bytes[0x51C], cmdLine);
    CP(&info.bytes[0x620], (const void*)0x584A4C);
    CP(&info.bytes[0x649], (const void*)0x592A40);
    CP(&info.bytes[0x672], (const void*)0x584A44);
    CP(&info.bytes[0x777], (const void*)0x584A38);
    CP(&info.bytes[0x301], (const void*)0x584A34);

    *(HINSTANCE*)&info.bytes[0x414] = hInst;
    *(HINSTANCE*)&info.bytes[0x418] = hPrev;
    *(int*)&info.bytes[0x41C] = nShow;

    *(int*)&info.bytes[0x8CC] = 0x54;
    *(int*)&info.bytes[0x8D4] = 0x54;
    *(int*)&info.bytes[0x8DC] = 8;
    *(int*)&info.bytes[0x8E0] = 0;
    *(short*)&info.bytes[0x8E4] = 0;
    *(short*)&info.bytes[0x8E6] = 0;
    *(short*)&info.bytes[0x8E8] = 0;
    *(int*)&info.bytes[0x8EC] = 1;
    *(int*)&info.bytes[0x8F0] = 1;
    *(int*)&info.bytes[0x8F4] = 0;
    *(int*)&info.bytes[0x8F8] = 1;
    *(int*)&info.bytes[0x8FC] = 1;
    *(int*)&info.bytes[0x900] = 1;
    *(int*)&info.bytes[0x904] = 0;
    *(int*)&info.bytes[0x908] = 1;
    *(int*)&info.bytes[0x90C] = 1;
    *(int*)&info.bytes[0x920] = 1;
    *(int*)&info.bytes[0x924] = 1;
    *(int*)&info.bytes[0x928] = 3;
    *(int*)&info.bytes[0x930] = 0x54;
    *(int*)&info.bytes[0x934] = 0x54;
    *(int*)&info.bytes[0x938] = 0x40800000;
    *(int*)&info.bytes[0x93C] = 0x40800000;
    *(int*)&info.bytes[0x940] = 0x3D4CCCCD;
    *(short*)&info.bytes[0x944] = 2;
    *(int*)&info.bytes[0x948] = 0x320;
    *(int*)&info.bytes[0x94C] = 0x258;

    CP(&info.bytes[0x90C], (const void*)0x584A2C);
    CP(&info.bytes[0xE25], (const void*)0x584A24);
    CP(&info.bytes[0xA11], (const void*)0x592A40);
    CP(&info.bytes[0xB16], (const void*)0x584A18);
    CP(&info.bytes[0xC1B], (const void*)0x584A0C);
    CP(&info.bytes[0xD20], (const void*)0x584A00);
    CP(&info.bytes[0xF2E], (const void*)0x584A2C);
    CP(&info.bytes[0x1033], (const void*)0x584A2C);
    CP(&info.bytes[0x1138], (const void*)0x5849F8);

    app = App_ctor((App*)operator_new(0x1254), (char*)&info, 1);
    if (app) {
        err = app->vtbl->run(app);
        if (err == 0) {
            ret = app->vtbl->get_error(app);
            app->vtbl->run(app);
            app->vtbl->destroy(app, 1);
        } else if (err != 4) {
            char title[256];
            char msg[256];
            app->vtbl->get_string(app, 0x7D1, title, 0x100);
            app->vtbl->format_error(app, 1, ret, msg, 0x100, 0);
            app->vtbl->destroy(app, 1);
            MessageBoxA(0, msg, title, 0x10);
        }
    }
    return ret;
}
