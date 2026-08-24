// attempt 1: direct draw-area acquire / SelectObject / calc_line_pos / restore / release shape
// result: the stable basin needed the local SelectObjectFn temp so VC5 would load the function pointer into EBX
// attempt 2: keep the TPanel base size at 0xF4 and the TTextPanel font at +0x104

#ifndef PNL_TXT_TU_CONTEXT
typedef struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
} RECT;

#endif
typedef void* (__stdcall *SelectObjectFn)(void* hdc, void* obj);
#ifndef PNL_TXT_TU_CONTEXT
extern SelectObjectFn SelectObject;
#endif
extern char s_pnl_txt__get_text_rect[];

#ifndef PNL_TXT_TU_CONTEXT
class TDrawArea {
public:
    void* GetDc(char* unused);
    void ReleaseDc(char* unused);
};

class TPanel {
public:
    char gap_0[0x20];
    TDrawArea* render_area;
    char gap_1[0xD0];
};

class TTextPanel : public TPanel {
public:
    char gap_0[0x10];
    void* font;

    int calc_line_pos(void* dc, int a, int b, RECT* rect, long* out);
    int get_text_rect(RECT* rect);
};
#endif

int TTextPanel::get_text_rect(RECT* rect) {
    void* dc = this->render_area->GetDc(s_pnl_txt__get_text_rect);
    if (dc != 0) {
        SelectObjectFn select_object = SelectObject;
        void* old_font = select_object(dc, this->font);
        this->calc_line_pos(dc, 0, 0, rect, 0);
        select_object(dc, old_font);
        this->render_area->ReleaseDc(s_pnl_txt__get_text_rect);
        return 1;
    }
    return 0;
}
