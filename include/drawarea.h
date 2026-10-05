#ifndef AOE1_DRAWAREA_H
#define AOE1_DRAWAREA_H

#define WIN32_LEAN_AND_MEAN

// Canonical Drawarea.cpp type surface.

typedef unsigned char uchar;

class RGE_Color_Table;

#include <ddraw.h>
#include "bitmap_info.h"

#undef WIN32_LEAN_AND_MEAN

extern "C" __declspec(dllimport) int __stdcall GetClientRect(void*, RECT*);
extern "C" __declspec(dllimport) unsigned int __stdcall GetPaletteEntries(
    void*, unsigned int, unsigned int, PALETTEENTRY*
);
extern "C" __declspec(dllimport) void* __stdcall SelectObject(void*, void*);
extern "C" __declspec(dllimport) int __stdcall DeleteObject(void*);
extern "C" __declspec(dllimport) int __stdcall DeleteDC(void*);
extern "C" int __cdecl sprintf(char*, const char*, ...);

typedef BITMAPINFO256 BitmapInfo;
typedef char draw_bitmap_info_256_size_check[(sizeof(BITMAPINFO256) == 0x428) ? 1 : -1];

class TDrawSystem;
class TDrawArea;
class TShape;
struct Shape_Info;

#ifndef AOE1_SPANLIST_TYPES_H
#define AOE1_SPANLIST_TYPES_H

struct VSpanMiniList {
    unsigned char Y_delta;
    unsigned char X_start;
    unsigned char X_end;
};

struct VSpan_Node {
    VSpan_Node* Next;
    VSpan_Node* Prev;
    int StartPx;
    int EndPx;
};

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

    TSpan_Node_List(int InitialSize, int GrowSize, int szitem);
    ~TSpan_Node_List();

  private:
    void SetNumZones(int New_Size);
    void InitNewZone(int Zone_Size);

  public:
    VSpan_Node* GetNode();
    void FreeNode(VSpan_Node* theNode);
    int FreeThread(VSpan_Node* HeadNode, VSpan_Node* TailNode);
    void ReclaimAllNodes();
    void ResetStats();
};

class TSpan_List_Manager {
  public:
    TSpan_Node_List VSList;
    VSpan_Node** Line_Head_Ptrs;
    VSpan_Node** Line_Tail_Ptrs;
    int* LeftMostPx;
    int* RightMostPx;
    int* Span_Count;
    int Num_Lines;
    int Num_Pixels;
    int Min_Span_Px;
    int Max_Span_Px;
    int Min_Line;
    int Max_Line;

    TSpan_List_Manager(int Surface_Width, int Surface_Height);
    ~TSpan_List_Manager();
    void ResetAll();
    void SetSpanRegions(int MinS, int MinL, int MaxS, int MaxL);
    void AddSpan(int LeftPx, int RightPx, int Line);
    void AddShape(TShape* theShape, int shape_num, int Xpos, int Ypos, int Mirror);
    void AddShape_Align(unsigned char* Shape_Base, Shape_Info* SI, int Xpos, int Ypos, int Mirror);
    void AddLine_Align(int x1, int y1, int x2, int y2);
    void AddMiniList(VSpanMiniList* theList, int Xpos, int Ypos);
    void SubtractMiniList(VSpanMiniList* theList, int Xpos, int Ypos);
    void DeleteSpan(int LeftPx, int RightPx, int Line);
    void DeleteShape(TShape* theShape, int shape_num, int Xpos, int Ypos, int Mirror);
    int PointVisible(int x, int Line);
    void Merge_n_Align(TSpan_List_Manager* List1, TSpan_List_Manager* List2);
    void AlignamizeSpans();
    void ScrollSpansHorizontally(int XOffset, int ClipToCurrentRegion);
    void ScrollSpansVertically(int YOffset, int ClipToCurrentRegion);
    int ValidateSpan(int Line);
    int DecodeLine(unsigned char* LineBuf, int Line, unsigned char fillC, int MaxX);
    void take_snapshot(
        char* filespec, int& index_no, TDrawArea* render_area, int scolor, TSpan_List_Manager** SpanArray,
        int* colorArray, int ArraySize
    );
};

#endif // AOE1_SPANLIST_TYPES_H

struct DrawAreaNode {
    TDrawArea* DrawArea;
    DrawAreaNode* PrevNode;
    DrawAreaNode* NextNode;
};

class TDrawArea {
  public:
    TDrawSystem* DrawSystem; // +0x00
    void* Wnd;               // +0x04
    unsigned char* Bits;     // +0x08
    BitmapInfo* BitmapInfo;  // +0x0C
    void* Bitmap;            // +0x10
    void* OldBitmap;         // +0x14
    int Width;               // +0x18
    int Height;              // +0x1C
    // Row stride in bytes from DirectDraw; may exceed Width due to padding.
    int Pitch;                           // +0x20
    int Orien;                           // +0x24
    tagRECT ClipRect;                    // +0x28
    void* DrawDc;                        // +0x38
    IDirectDrawSurface* DrawSurface;     // +0x3C
    _DDSURFACEDESC SurfaceDesc;          // +0x40
    DrawAreaNode* Node;                  // +0xAC
    char* Name;                          // +0xB0
    unsigned char* LastBits;             // +0xB4
    int LastPitch;                       // +0xB8
    void** DisplayOffsets;               // +0xBC
    void** CurDisplayOffsets;            // +0xC0
    void** FloatOffsets;                 // +0xC4
    RGE_Color_Table* shadow_color_table; // +0xC8
    TSpan_List_Manager* SpanList;        // +0xCC
    TSpan_List_Manager* CurSpanList;     // +0xD0
    int Float_X_Delta;                   // +0xD4
    int Float_Y_Delta;                   // +0xD8
    int DisplayOffsetsSz;                // +0xDC
    int FloatOffsetsSz;                  // +0xE0
    int SystemMemOnly;                   // +0xE4
    int UsingVidMem;                     // +0xE8
    int UseTrans;                        // +0xEC
    int IsPrimarySurface;                // +0xF0
    int Restored;                        // +0xF4
    int ExtendedLines;                   // +0xF8
    unsigned char TransColor;            // +0xFC

    TDrawArea(char* SurfaceName, int ForceSystemMem);
    ~TDrawArea();
    int Init(TDrawSystem* draw_system_in, long wid_in, long hgt_in, int Extend, int isPrimary_in);
    void SetSize(long wid_in, long hgt_in, int ExtendSurface);
    unsigned char CheckSurface();
    unsigned char* Lock(char* caller_name, int wait);
    void Unlock(char* caller_name);
    void* GetDc(char* caller_name);
    void ReleaseDc(char* caller_name);
    void SetInfo();
    void SetAccessOffsets();
    void SetFloatOffsets(int X_Delta, int Y_Delta);
    void SetClipRect(tagRECT* rect);
    void SetClipRect(long x1, long y1, long x2, long y2);
    void Clear(tagRECT* rect, int color);
    void PtrClear(tagRECT*, int);
    long AlignedWidth();
    void Copy(TDrawArea* dest_area, long dest_x, long dest_y, RECT* src_rect, int allow_trans);
    void PtrSpanCopy(TDrawArea*, long, long, tagRECT*, unsigned char**);
    void OverlayMemCopy(tagRECT&, tagRECT&, int, int, int, int);
    void SetTrans(int use_trans_in, unsigned char trans_color_in);
    void SetOverlayTrans(int use_trans_in, unsigned char trans_color_in);
    void SetPixel(long x, long y, unsigned char color);
    void DrawLine(int x1, int y1, int x2, int y2, unsigned char color);
    void DrawRect(long x1, long y1, long x2, long y2, unsigned char color);
    void DrawRect(tagRECT* rect, unsigned char mode);
    void DrawHorzLine(long x, long y, long len, unsigned char color);
    void DrawVertLine(long x, long y, long len, unsigned char color);
    void FillRect(long x1, long y1, long x2, long y2, unsigned char color);
    void DrawBevel(long x1, long y1, long x2, long y2, unsigned char c1, unsigned char c2);
    void DrawBevel2(
        long x1, long y1, long x2, long y2, unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4
    );
    void DrawBevel3(
        long x1, long y1, long x2, long y2, unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4,
        unsigned char c5, unsigned char c6
    );
    void DrawBevel21(
        long x1, long y1, long x2, long y2, unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4
    );
    void DrawBevel32(
        long x1, long y1, long x2, long y2, unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4,
        unsigned char c5, unsigned char c6
    );
    void DrawShadowBox(long x1, long y1, long x2, long y2);
    void SetShadowTable(RGE_Color_Table* color_table_in);
    void GetPalette(PALETTEENTRY* palette1);
    void SetPalette(PALETTEENTRY* palette1);
    void take_snapshot(char* filespec, int& index_no);
};

class TDrawSystem {
  public:
    void* Inst;                         // +0x00
    void* Wnd;                          // +0x04
    void* Pal;                          // +0x08
    TDrawArea* DrawArea;                // +0x0C
    TDrawArea* PrimaryArea;             // +0x10
    DrawAreaNode* DrawAreaList;         // +0x14
    IDirectDraw* DirDraw;               // +0x18
    IDirectDrawSurface* PrimarySurface; // +0x1C
    IDirectDrawClipper* Clipper;        // +0x20
    IDirectDrawPalette* DirDrawPal;     // +0x24
    unsigned long Flags;                // +0x28
    long ScreenWidth;                   // +0x2C
    long ScreenHeight;                  // +0x30
    long ColorBits;                     // +0x34
    long ErrorCode;                     // +0x38
    long ChangedMode;                   // +0x3C
    long IsBanked;                      // +0x40
    long CanSrcBlt;                     // +0x44
    long Restored;                      // +0x48
    long ModeAvail640;                  // +0x4C
    long ModeAvail800;                  // +0x50
    long ModeAvail1024;                 // +0x54
    long ModeAvail1280;                 // +0x58
    long ModeAvail320_200;              // +0x5C
    long ModeAvail320_240;              // +0x60
    long ModeAvail320_200_16;           // +0x64
    long ModeAvail320_240_16;           // +0x68
    long ModeAvail640_16;               // +0x6C
    long ModeAvail800_16;               // +0x70
    long ModeAvail1024_16;              // +0x74
    union {
        PALETTEENTRY palette[256]; // +0x78
        PALETTEENTRY Palette[256]; // +0x78
    };
    // Inferred backend: 1 = legacy WING/software (Init rejects it); 2 = DirectDraw.
    // Zero is the constructor default, not a confirmed backend.
    unsigned char DrawType; // +0x478
    // Inferred mode values: 1 = windowed; 2 = fullscreen.
    unsigned char ScreenMode; // +0x479

    TDrawSystem();
    ~TDrawSystem();
    static long __stdcall CheckAvailModesCallback(_DDSURFACEDESC* lpDDSurfaceDesc, void* lpContext);
    void CheckAvailModes(int full_screen);
    int IsModeAvail(long wid_in, long hgt_in, int color_bits);
    int Init(
        void* inst_in, void* wnd_in, void* pal_in, unsigned char type_in, unsigned char mode_in, long wid_in,
        long hgt_in, unsigned long flags_in
    );
    int SetDisplaySize(long wid_in, long hgt_in, int color_bits);
    void ClearPrimarySurface();
    void DeleteSurfaces();
    int CreateSurfaces();
    void HandleSize(void* hwnd, unsigned int msg, unsigned int wParam, long lParam);
    void HandlePaletteChanged(void* hwnd, unsigned int msg, unsigned int wParam, long lParam);
    int HandleQueryNewPalette(void* hwnd, unsigned int msg, unsigned int wParam, long lParam);
    void ModifyPalette(int start_entry, int num_entries, tagPALETTEENTRY* pal_entries);
    void SetPalette(void* pal_in);
    int GetIsLostErrorNum(long ddrval);
    int GetRestoreErrorNum(long ddrval);
    int GetSetDispModeErrorNum(long ddrval);
    int GetLockErrorNum(long ddrval);
    int GetDCErrorNum(long ddrval);
    int GetBlitErrorNum(long ddrval);
    int GetCreateErrorNum(long ddrval);
    int GetColorKeyErrorNum(long ddrval);
    unsigned char CheckSurfaces();
    void ClearRestored();
    void Paint(tagRECT* rect);
};

#endif
