#ifndef AOE1_MOUSEPTR_H
#define AOE1_MOUSEPTR_H

#include "drawarea.h"
#include "Shape.h"

typedef unsigned long ulong;

class TMousePointer {
public:
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
    RECT save_rect;
    RECT mouse_rect;
    RECT cursor_rect;
    RECT new_save_rect;
    RECT restore_rect;
    RECT game_window;
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
    char cursor_file[0x104];
    int cursor_file_id;

    TMousePointer(int mode);
    ~TMousePointer();
    int Shutdown_Mouse();
    int Restore_Mouse(TDrawArea* area);
    int setup(int custom_draw, TDrawArea* area, char* base, int palette,
              int max_cursors);
    void set_game_mode(int value);
    void set_game_enable(int value);
    int get_game_enable();
    int in_game_mode();
    void set_game_window(int left, int top, int right, int bottom);
    int LoadCursors(char* base, int file_id, int keep_name);
    void delete_surfaces();
    int create_surfaces();
    int update_mouse_position();
    void draw(int forced);
    void erase();
    void set_facet(int facet_value);
    void set_game_facet(int facet_value);
    void off();
    void on();
    void reset();
    void center();
    void Poll();
    int GetDDBltError(long result);
};

extern TMousePointer* MouseSystem;
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);

typedef char mouseptr_tmousepointer_size[
    (sizeof(TMousePointer) == 0x254) ? 1 : -1];

#endif
