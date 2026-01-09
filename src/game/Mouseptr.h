#pragma once
#include "common.h"

class TMousePointer {
public:
    int custom_draw;                         // 0x0
    TDrawArea* render_area;                  // 0x4
    TDrawArea* save_area;                    // 0x8
    TDrawArea* primary_area;                 // 0xC
    int Num_Cursors;                         // 0x10
    int Max_Cursors;                         // 0x14
    TDrawArea* cursors[16];                  // 0x18
    TShape* Cursor_Shape;                    // 0x58
    int Mouse_Mode;                          // 0x5C
    int Max_CX;                              // 0x60
    int Max_CY;                              // 0x64
    int cWidth;                              // 0x68
    int cHeight;                             // 0x6C
    int gWidth;                              // 0x70
    int gHeight;                             // 0x74
    long mouse_x;                            // 0x78
    long mouse_y;                            // 0x7C
    long save_x;                             // 0x80
    long save_y;                             // 0x84
    int facet;                               // 0x88
    int game_facet;                          // 0x8C
    int next_facet;                          // 0x90
    int last_facet;                          // 0x94
    int d_top;                               // 0x98
    int d_left;                              // 0x9C
    int d_bottom;                            // 0xA0
    int d_right;                             // 0xA4
    int g_top;                               // 0xA8
    int g_left;                              // 0xAC
    int g_bottom;                            // 0xB0
    int g_right;                             // 0xB4
    int save_area_valid;                     // 0xB8
    tagRECT save_rect;                       // 0xBC
    tagRECT mouse_rect;                      // 0xCC
    tagRECT cursor_rect;                     // 0xDC
    tagRECT new_save_rect;                   // 0xEC
    tagRECT restore_rect;                    // 0xFC
    tagRECT game_window;                     // 0x10C
    IDirectDrawSurface* restoreSurface;      // 0x11C
    IDirectDrawSurface* renderSurface;       // 0x120
    IDirectDrawSurface* PrimarySurface;      // 0x124
    int active;                              // 0x128
    int drawn;                               // 0x12C
    int Shutdown;                            // 0x130
    int Setup;                               // 0x134
    int GameMode;                            // 0x138
    int GameEnabled;                         // 0x13C
    int MouseOnScreen;                       // 0x140
    ulong LastDrawTime;                      // 0x144
    long LastddError;                        // 0x148
    char cursor_file[260];                   // 0x14C
    int cursor_file_id;                      // 0x250

    TMousePointer(int param_1);
    ~TMousePointer();
    int Shutdown_Mouse();
    int Restore_Mouse(TDrawArea* param_1);
    int setup(int param_1, TDrawArea* param_2, char* param_3, int param_4, int param_5);
    void set_game_mode(int param_1);
    void set_game_enable(int param_1);
    int get_game_enable();
    int in_game_mode();
    void set_game_window(int param_1, int param_2, int param_3, int param_4);
    int LoadCursors(char* param_1, int param_2, int param_3);
    void delete_surfaces();
    int create_surfaces();
    int update_mouse_position();
    void draw(int param_1);
    void erase();
    void set_facet(int param_1);
    void set_game_facet(int param_1);
    void off();
    void on();
    void reset();
    void center();
    void Poll();
    int GetDDBltError(long param_1);
};

static_assert(sizeof(TMousePointer) == 0x254, "TMousePointer Size Mismatch");

