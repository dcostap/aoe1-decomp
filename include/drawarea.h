#ifndef AOE1_DRAWAREA_H
#define AOE1_DRAWAREA_H

#define WIN32_LEAN_AND_MEAN

// Canonical Drawarea.cpp type surface.
// PDB layout proves TDrawSystem size 0x47C and TDrawArea size 0x100.

typedef unsigned char uchar;

class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table();
    char color_table_name[30];
    short resource_id;
    unsigned char type;
    unsigned char map_color;
    short id;
    unsigned char table[256];
};

#include <ddraw.h>

#undef WIN32_LEAN_AND_MEAN

extern "C" __declspec(dllimport) int __stdcall GetClientRect(void*, RECT*);
extern "C" __declspec(dllimport) unsigned int __stdcall GetPaletteEntries(
    void*, unsigned int, unsigned int, PALETTEENTRY*);
extern "C" __declspec(dllimport) void* __stdcall SelectObject(void*, void*);
extern "C" __declspec(dllimport) int __stdcall DeleteObject(void*);
extern "C" __declspec(dllimport) int __stdcall DeleteDC(void*);
extern "C" int __cdecl sprintf(char*, const char*, ...);

struct BITMAPINFO256 {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[256];
};

typedef BITMAPINFO256 BitmapInfo;
typedef char draw_bitmap_info_256_size_check[
    (sizeof(BITMAPINFO256) == 0x428) ? 1 : -1];

class TDrawSystem;
class TDrawArea;

class VSpan_Node;

class TSpan_Node_List {
public:
    VSpan_Node** Zone_Ptrs;
    int* Zone_Size_Ptrs;
    int Used_Zones;
    int Max_Zones;
    VSpan_Node* Free_Head;
    int Free_Pool_Zone;
    int Free_Pool_Index;
    int Total_Blocks;
    int Free_Blocks;
    int Default_Grow_Size;
    int Element_Size;
    int Alloc_Count;
    int Dealloc_Count;
    int NewZone_Count;
    int Reset_Count;

    ~TSpan_Node_List();
};

class TSpan_List_Manager {
public:
    TSpan_Node_List VSList;
    VSpan_Node** Line_Head_Ptrs;
    VSpan_Node** Line_Tail_Ptrs;
    long* LeftMostPx;
    long* RightMostPx;
    long* Span_Count;
    int Num_Lines;
    int Num_Pixels;
    int Min_Span_Px;
    int Max_Span_Px;
    int Min_Line;
    int Max_Line;

    TSpan_List_Manager(int, int);
    ~TSpan_List_Manager();
    void ResetAll();
    void SetSpanRegions(int, int, int, int);
    void AddSpan(int, int, int);
};

struct DrawAreaNode {
    TDrawArea* DrawArea;
    DrawAreaNode* PrevNode;
    DrawAreaNode* NextNode;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;              // +0x00
    void* Wnd;                            // +0x04
    unsigned char* Bits;                  // +0x08
    BitmapInfo* BitmapInfo;               // +0x0C
    void* Bitmap;                         // +0x10
    void* OldBitmap;                      // +0x14
    int Width;                            // +0x18
    int Height;                           // +0x1C
    int Pitch;                            // +0x20
    int Orien;                            // +0x24
    tagRECT ClipRect;                    // +0x28
    void* DrawDc;                         // +0x38
    IDirectDrawSurface* DrawSurface;     // +0x3C
    _DDSURFACEDESC SurfaceDesc;         // +0x40
    DrawAreaNode* Node;                   // +0xAC
    char* Name;                           // +0xB0
    unsigned char* LastBits;              // +0xB4
    int LastPitch;                        // +0xB8
    void** DisplayOffsets;                // +0xBC
    void** CurDisplayOffsets;             // +0xC0
    void** FloatOffsets;                  // +0xC4
    RGE_Color_Table* shadow_color_table; // +0xC8
    TSpan_List_Manager* SpanList;         // +0xCC
    TSpan_List_Manager* CurSpanList;      // +0xD0
    int Float_X_Delta;                    // +0xD4
    int Float_Y_Delta;                    // +0xD8
    int DisplayOffsetsSz;                 // +0xDC
    int FloatOffsetsSz;                   // +0xE0
    int SystemMemOnly;                    // +0xE4
    int UsingVidMem;                      // +0xE8
    int UseTrans;                         // +0xEC
    int IsPrimarySurface;                 // +0xF0
    int Restored;                         // +0xF4
    int ExtendedLines;                    // +0xF8
    unsigned char TransColor;             // +0xFC
    unsigned char _pad_end[3];

    TDrawArea(char*, int);
    ~TDrawArea();
    int Init(TDrawSystem*, long, long, int, int);
    void SetSize(long, long, int);
    unsigned char CheckSurface();
    unsigned char* Lock(char*, int);
    void Unlock(char*);
    void* GetDc(char*);
    void ReleaseDc(char*);
    void SetInfo();
    void SetAccessOffsets();
    void SetFloatOffsets(int, int);
    void SetClipRect(tagRECT*);
    void SetClipRect(long, long, long, long);
    void Clear(tagRECT*, int);
    void PtrClear(tagRECT*, int);
    long AlignedWidth();
    void Copy(TDrawArea*, long, long, RECT*, int);
    void SetTrans(int, unsigned char);
    void SetOverlayTrans(int, unsigned char);
    void SetPixel(long, long, unsigned char);
    void DrawLine(int, int, int, int, unsigned char);
    void DrawRect(long, long, long, long, unsigned char);
    void DrawRect(tagRECT*, unsigned char);
    void DrawHorzLine(long, long, long, unsigned char);
    void DrawVertLine(long, long, long, unsigned char);
    void FillRect(long, long, long, long, unsigned char);
    void DrawBevel(long, long, long, long, unsigned char, unsigned char);
    void DrawBevel2(long, long, long, long, unsigned char, unsigned char,
                    unsigned char, unsigned char);
    void DrawBevel3(long, long, long, long, unsigned char, unsigned char,
                    unsigned char, unsigned char, unsigned char, unsigned char);
    void DrawBevel21(long, long, long, long, unsigned char, unsigned char,
                     unsigned char, unsigned char);
    void DrawBevel32(long, long, long, long, unsigned char, unsigned char,
                     unsigned char, unsigned char, unsigned char, unsigned char);
    void DrawShadowBox(long, long, long, long);
    void SetShadowTable(RGE_Color_Table*);
    void GetPalette(PALETTEENTRY*);
    void SetPalette(PALETTEENTRY*);
    void take_snapshot(char*, int&);
};

class TDrawSystem {
public:
    void* Inst;                          // +0x00
    void* Wnd;                           // +0x04
    void* Pal;                           // +0x08
    TDrawArea* DrawArea;                 // +0x0C
    TDrawArea* PrimaryArea;              // +0x10
    DrawAreaNode* DrawAreaList;           // +0x14
    IDirectDraw* DirDraw;                // +0x18
    IDirectDrawSurface* PrimarySurface;  // +0x1C
    IDirectDrawClipper* Clipper;         // +0x20
    IDirectDrawPalette* DirDrawPal;      // +0x24
    unsigned long Flags;                 // +0x28
    long ScreenWidth;                    // +0x2C
    long ScreenHeight;                   // +0x30
    long ColorBits;                      // +0x34
    long ErrorCode;                      // +0x38
    long ChangedMode;                    // +0x3C
    long IsBanked;                       // +0x40
    long CanSrcBlt;                      // +0x44
    long Restored;                       // +0x48
    long ModeAvail640;                   // +0x4C
    long ModeAvail800;                   // +0x50
    long ModeAvail1024;                  // +0x54
    long ModeAvail1280;                  // +0x58
    long ModeAvail320_200;               // +0x5C
    long ModeAvail320_240;               // +0x60
    long ModeAvail320_200_16;            // +0x64
    long ModeAvail320_240_16;            // +0x68
    long ModeAvail640_16;                // +0x6C
    long ModeAvail800_16;                // +0x70
    long ModeAvail1024_16;               // +0x74
    union {
        PALETTEENTRY palette[256];       // +0x78
        PALETTEENTRY Palette[256];       // +0x78
    };
    unsigned char DrawType;              // +0x478
    unsigned char ScreenMode;            // +0x479

    TDrawSystem();
    ~TDrawSystem();
    static long __stdcall CheckAvailModesCallback(_DDSURFACEDESC*, void*);
    void CheckAvailModes(int);
    int IsModeAvail(long, long, int);
    int Init(void*, void*, void*, unsigned char, unsigned char, long, long,
             unsigned long);
    int SetDisplaySize(long, long, int);
    void ClearPrimarySurface();
    void DeleteSurfaces();
    int CreateSurfaces();
    void HandleSize(void*, unsigned int, unsigned int, long);
    void HandlePaletteChanged(void*, unsigned int, unsigned int, long);
    int HandleQueryNewPalette(void*, unsigned int, unsigned int, long);
    void ModifyPalette(int, int, tagPALETTEENTRY*);
    void SetPalette(void*);
    int GetIsLostErrorNum(long);
    int GetRestoreErrorNum(long);
    int GetSetDispModeErrorNum(long);
    int GetLockErrorNum(long);
    int GetBlitErrorNum(long);
    int GetCreateErrorNum(long);
    int GetColorKeyErrorNum(long);
    unsigned char CheckSurfaces();
    void ClearRestored();
    void Paint(tagRECT*);
};

#endif
