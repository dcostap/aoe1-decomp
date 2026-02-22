#pragma once
#include "common.h"

struct TMousePointer {
    TMousePointer(int p1);
    ~TMousePointer();
    int setup(int custom_draw, struct TDrawArea* draw_area, char* filename, int file_id, int max_cursors);
    void on();
    void off();
    void Poll();
    void draw(int param_1);
    void set_facet(int facet_index);
    void set_game_facet(int facet_index);
    void set_game_mode(int mode);
    int in_game_mode();
    void set_game_window(int left, int top, int right, int bottom);
    void set_game_enable(int enabled);
    int get_game_enable();
    
    // Helper methods
    int LoadCursors(char* filename, int file_id, int reload);
    int create_surfaces();
    void delete_surfaces();
    int update_mouse_position();
    void reset();
    void center();
    void erase();
    int GetDDBltError(long err);

    int custom_draw;
    TDrawArea* render_area;
    TDrawArea* save_area;
    TDrawArea* primary_area;
    int Num_Cursors;
    int Max_Cursors;
    TDrawArea* cursors[16];
    TShape* Cursor_Shape;
    int Mouse_Mode;
    int Max_CX;
    int Max_CY;
    int cWidth;
    int cHeight;
    int gWidth;
    int gHeight;
    long mouse_x;
    long mouse_y;
    long save_x;
    long save_y;
    int facet;
    int game_facet;
    int next_facet;
    int last_facet;
    int d_top;
    int d_left;
    int d_bottom;
    int d_right;
    int g_top;
    int g_left;
    int g_bottom;
    int g_right;
    int save_area_valid;
    tagRECT save_rect;
    tagRECT mouse_rect;
    tagRECT cursor_rect;
    tagRECT new_save_rect;
    tagRECT restore_rect;
    tagRECT game_window;
    IDirectDrawSurface* restoreSurface;
    IDirectDrawSurface* renderSurface;
    IDirectDrawSurface* PrimarySurface;
    int active;
    int drawn;
    int Shutdown;
    int Setup;
    int GameMode;
    int GameEnabled;
    int MouseOnScreen;
    ulong LastDrawTime;
    long LastddError;
    char cursor_file[260];
    int cursor_file_id;
};
#include <stddef.h>
static_assert(offsetof(TMousePointer, save_rect) == 0xBC, "Offset mismatch save_rect");
static_assert(offsetof(TMousePointer, cursor_file) == 0x14C, "Offset mismatch cursor_file");
static_assert(sizeof(TMousePointer) == 0x254, "Size mismatch");
