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

    TMousePointer(int MouseModeIn);
    ~TMousePointer();
    int Shutdown_Mouse();
    int Restore_Mouse(TDrawArea* render_area_in);
    int setup(
        int custom_draw_in, TDrawArea* render_area_in, char* cursor_file_name, int cursor_resId, int maxCursors_in
    );
    void set_game_mode(int mode);
    void set_game_enable(int enable);
    int get_game_enable();
    int in_game_mode();
    void set_game_window(int Left, int Top, int Right, int Bottom);
    int LoadCursors(char* cursor_file_name, int resId, int Reload);
    void delete_surfaces();
    int create_surfaces();
    int update_mouse_position();
    void draw(int dMode);
    void erase();
    void set_facet(int facet_in);
    void set_game_facet(int facet_in);
    void off();
    void on();
    void reset();
    void center();
    void Poll();
    int GetDDBltError(long theError);
};

typedef char mouseptr_tmousepointer_size[(sizeof(TMousePointer) == 0x254) ? 1 : -1];

// Original symbol: ?MouseSystem@@3PAVTMousePointer@@A.
extern TMousePointer* MouseSystem;

#endif
