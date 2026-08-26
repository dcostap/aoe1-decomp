// VA: 004777C0, TInputPanel::draw, 330 bytes
// Source: Pnl_inp.cpp lines 477-525
// FLAGS: default

#include <stddef.h>
#include <windows.h>

typedef unsigned char uchar;
typedef unsigned short ushort;

typedef void* (__stdcall *SelectObjectFn)(void* hdc, void* obj);
extern SelectObjectFn g_SelectObject;

extern char pnl_inp_draw[];

class TDrawArea {
public:
    char gap[4];
    void* GetDc(const char* name);
    void ReleaseDc(const char* name);
    uchar* Lock(const char* name, int flag);
    void Unlock(const char* name);
    void DrawVertLine(int x, int y, int h, uchar color);
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(RECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(RECT*);

    // Vtable is implicit at +0x00 (from virtual declarations)
    char pad_04[0x1C];
    TDrawArea* render_area;        // +0x20
    char pad_24[0x48];
    int active;                     // +0x6C
    int visible;                    // +0x70
    char pad_74[0x04];
    int have_focus;                 // +0x78
    char pad_7C[0x10];
    RECT render_rect;               // +0x8C
    char pad_9C[0x58];             // to 0xF4
};

class TTextPanel : public TPanel {
public:
    char pad_F4[8];
    short top_line;        // +0xFC
    short bot_line;        // +0xFE
    short cur_line;        // +0x100
    short cur_col;                  // +0x102
    void* font;                     // +0x104
    char pad_108[0x80];            // to 0x188

    void draw();
    void calc_line_pos(void* dc, short a, short b, RECT* rect, int* off);
};

class TInputPanel : public TTextPanel {
public:
    uchar caret_color;              // +0x188
    char pad_189[0x0B];
    int draw_caret;                 // +0x194

    void draw();
};

void TInputPanel::draw()
{
    TTextPanel::draw();
    
    if (this->render_area == 0) return;
    if (this->visible == 0) return;
    if (this->active == 0) return;
    if (this->have_focus == 0) return;
    if (this->draw_caret == 0) return;
    if (this->cur_line < this->top_line) return;
    if (this->cur_line > this->bot_line) return;
    
    this->draw_setup(0);
    
    void* dc = this->render_area->GetDc(pnl_inp_draw);
    if (dc != 0) {
        SelectObjectFn select_object = g_SelectObject;
        void* old_font = select_object(dc, this->font);
        
        RECT line_rect;
        int cursor_x_offset;
        // Params: dc, diff, cur, rect_ptr, offset_ptr
        // To match asm: push cur before computing diff from the same register
        short cur = this->cur_line;
        short diff = cur - this->top_line;
        this->calc_line_pos(dc, diff, cur, &line_rect, &cursor_x_offset);
        
        select_object(dc, old_font);
        this->render_area->ReleaseDc(pnl_inp_draw);
        
        uchar* locked = this->render_area->Lock(pnl_inp_draw, 1);
        if (locked != 0) {
            int x = cursor_x_offset + line_rect.left;
            int y = line_rect.top;
            int h = (line_rect.bottom - line_rect.top) + 1;
            
            if (x < this->render_rect.right) {
                this->render_area->DrawVertLine(x, y, h, this->caret_color);
                this->render_area->DrawVertLine(x + 1, y, h, this->caret_color);
            }
            
            this->render_area->Unlock(pnl_inp_draw);
        }
    }
    
    this->draw_finish();
}
