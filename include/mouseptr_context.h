#ifndef AOE1_MOUSEPTR_CONTEXT_H
#define AOE1_MOUSEPTR_CONTEXT_H

// Authentic Mouseptr.cpp type context. Offsets follow the original PDB and
// the reviewed all-types layout. Keep this header free of Windows SDK macros:
// several old call sites use explicit imported function-pointer declarations.
typedef unsigned char uchar;
typedef unsigned long ulong;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};
typedef tagRECT RECT4;

struct Shape_Info {
    unsigned long Shape_Data_Offsets;
    unsigned long Shape_Outline_Offset;
    long Reserved1;
    long Reserved2;
    long Width;
    long Height;
    long Hotspot_X;
    long Hotspot_Y;
};

class IDirectDraw;
class IDirectDrawClipper;
class IDirectDrawPalette;
class IDirectDrawSurface;
class TDrawArea;
class TDrawSystem;
class TShape;

class TDrawArea {
public:
    TDrawSystem* DrawSystem;       // +0x00
    void* Wnd;                     // +0x04
    uchar* Bits;                   // +0x08
    void* BitmapInfo;              // +0x0C
    void* Bitmap;                  // +0x10
    void* OldBitmap;               // +0x14
    int Width;                     // +0x18
    int Height;                    // +0x1C
    int Pitch;                     // +0x20
    int Orien;                     // +0x24
    tagRECT ClipRect;              // +0x28
    void* DrawDc;                  // +0x38
    IDirectDrawSurface* DrawSurface; // +0x3C
    char gap_40[0xC0];             // +0x40..+0xFF

    TDrawArea(char* name, int height);
    ~TDrawArea();
    int Init(TDrawSystem* draw_system, int width, int height, int x, int y);
    void Clear(tagRECT* rect, int flags);
    void SetTrans(int on, uchar value);
    uchar* Lock(char* name, int write);
    void Unlock(char* name);
    void FillRect(long x, long y, long w, long h, uchar color);
};

class TDrawSystem {
public:
    void* Inst;                    // +0x00
    void* Wnd;                     // +0x04
    void* Pal;                     // +0x08
    TDrawArea* DrawArea;           // +0x0C
    TDrawArea* PrimaryArea;        // +0x10
    char gap_14[0x04];             // +0x14 DrawAreaList
    IDirectDraw* DirDraw;          // +0x18
    IDirectDrawSurface* PrimarySurface; // +0x1C
    IDirectDrawClipper* Clipper;   // +0x20
    IDirectDrawPalette* DirDrawPal; // +0x24
    unsigned long Flags;           // +0x28
    int ScreenWidth;               // +0x2C
    int ScreenHeight;              // +0x30
    int ColorBits;                 // +0x34
    int ErrorCode;                 // +0x38
    int ChangedMode;               // +0x3C
    int IsBanked;                  // +0x40
    int CanSrcBlt;                 // +0x44
    int Restored;                  // +0x48
    char gap_4C[0x2C];             // +0x4C..+0x77 mode flags
    char palette[0x400];           // +0x78..+0x477
    uchar DrawType;                // +0x478
    uchar ScreenMode;              // +0x479
    uchar gap_47A[2];

    void Paint(tagRECT* rect);
};

class TShape {
public:
    uchar* shape;                  // +0x00
    int load_type;                 // +0x04
    int load_size;                 // +0x08
    void* shape_header;            // +0x0C
    void* head;                    // +0x10
    void* offsets;                 // +0x14
    void* FShape;                  // +0x18
    Shape_Info* shape_info;        // +0x1C

    TShape(char* filename, int file_id);
    ~TShape();
    void destroy(void);
    int is_loaded(void);
    long shape_count(void);
    uchar shape_draw(TDrawArea* area, long x, long y, long facet, uchar a, uchar* b);
};

class TMousePointer {
public:
    int custom_draw;               // +0x000
    TDrawArea* render_area;        // +0x004
    TDrawArea* save_area;          // +0x008
    TDrawArea* primary_area;       // +0x00C
    int Num_Cursors;               // +0x010
    int Max_Cursors;               // +0x014
    TDrawArea* cursors[16];        // +0x018
    TShape* Cursor_Shape;          // +0x058
    int Mouse_Mode;                // +0x05C
    int Max_CX;                    // +0x060
    int Max_CY;                    // +0x064
    int cWidth;                    // +0x068
    int cHeight;                   // +0x06C
    int gWidth;                    // +0x070
    int gHeight;                   // +0x074
    long mouse_x;                  // +0x078
    long mouse_y;                  // +0x07C
    long save_x;                   // +0x080
    long save_y;                   // +0x084
    int facet;                     // +0x088
    int game_facet;                // +0x08C
    int next_facet;                // +0x090
    int last_facet;                // +0x094
    int d_top;                     // +0x098
    int d_left;                    // +0x09C
    int d_bottom;                  // +0x0A0
    int d_right;                   // +0x0A4
    int g_top;                     // +0x0A8
    int g_left;                    // +0x0AC
    int g_bottom;                  // +0x0B0
    int g_right;                   // +0x0B4
    int save_area_valid;           // +0x0B8
    RECT4 save_rect;               // +0x0BC
    RECT4 mouse_rect;              // +0x0CC
    RECT4 cursor_rect;             // +0x0DC
    RECT4 new_save_rect;           // +0x0EC
    RECT4 restore_rect;            // +0x0FC
    RECT4 game_window;             // +0x10C
    IDirectDrawSurface* restoreSurface; // +0x11C
    IDirectDrawSurface* renderSurface;  // +0x120
    IDirectDrawSurface* PrimarySurface; // +0x124
    int active;                    // +0x128
    int drawn;                     // +0x12C
    int Shutdown;                  // +0x130
    int Setup;                     // +0x134
    int GameMode;                  // +0x138
    int GameEnabled;               // +0x13C
    int MouseOnScreen;             // +0x140
    ulong LastDrawTime;             // +0x144
    long LastddError;              // +0x148
    char cursor_file[0x104];        // +0x14C
    int cursor_file_id;             // +0x250

    TMousePointer(int mode);
    ~TMousePointer();
    int Shutdown_Mouse(void);
    int Restore_Mouse(TDrawArea* area);
    int setup(int custom_draw, TDrawArea* area, char* base, int palette, int max_cursors);
    void set_game_mode(int value);
    void set_game_enable(int value);
    int get_game_enable(void);
    int in_game_mode(void);
    void set_game_window(int left, int top, int right, int bottom);
    int LoadCursors(char* base, int file_id, int keep_name);
    void delete_surfaces(void);
    int create_surfaces(void);
    int update_mouse_position(void);
    void draw(int forced);
    void erase(void);
    void set_facet(int facet_value);
    void set_game_facet(int facet_value);
    void off(void);
    void on(void);
    void reset(void);
    void center(void);
    void Poll(void);
    int GetDDBltError(long result);
};

extern TMousePointer* MouseSystem;

// The original object is 0x254 bytes. This also prevents an incomplete local
// surface or RECT declaration from silently changing constructor allocation.
typedef char mouseptr_tmousepointer_size[(sizeof(TMousePointer) == 0x254) ? 1 : -1];
typedef char mouseptr_tdrawarea_size[(sizeof(TDrawArea) == 0x100) ? 1 : -1];
typedef char mouseptr_tdrawsystem_size[(sizeof(TDrawSystem) == 0x47C) ? 1 : -1];
typedef char mouseptr_tshape_size[(sizeof(TShape) == 0x20) ? 1 : -1];

#endif
