// first pass: typed local reconstruction of image-buffer recreate path
// FLAGS: config/flags/004790E0_set_rect.rsp uses /GX for new/delete EH state around TDrawArea construction
extern int (__stdcall *DeleteObject)(void*);
extern void* (__stdcall *CreateRectRgn)(int, int, int, int);
void* operator new(unsigned int);
void operator delete(void*);

struct RECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    char gap_00[0x18];
    int width_limit;
    char gap_1C[0xE4];

    TDrawArea(char* name, int flags);
    ~TDrawArea(void);
    int Init(void* draw_system, long width, long height, int x, int y);
};

class TPanel {
public:
    virtual void pv0();
    virtual void pv1();
    virtual void pv2();
    virtual void pv3();
    virtual void pv4();
    virtual void pv5(int);
    virtual void pv6();
    virtual void pv7();
    virtual void redraw(int);

    char gap_004[0x10];
    long pnl_wid;
    long pnl_hgt;
    char gap_01C[4];
    TDrawArea* render_area;
    char gap_024[0xCF];
    unsigned char need_restore;

    void set_rect(long x, long y, long w, long h);
};

class TMessagePanel : public TPanel {
public:
    int message_type;
    char text[0x200];
    int showing_message;
    int start_time;
    int show_message_interval;
    void* font;
    long font_wid;
    long font_hgt;
    unsigned char font_color;
    unsigned char back_color;
    char gap_312[0x1A];
    void* image_clip_region;
    TDrawArea* ImageBuffer;
    RECT ImageRect;
    RECT UsedImageRect;
    RECT UsedScreenRect;
    int LastIBWidth;
    int LastIBHeight;

    void set_rect(long x, long y, long w, long h);
};

void TMessagePanel::set_rect(long x, long y, long w, long h) {
    TPanel::set_rect(x, y, w, h);

    if (this->pnl_wid > this->LastIBWidth || this->pnl_hgt > this->LastIBHeight || x + this->LastIBWidth >= this->render_area->width_limit) {
        if (this->image_clip_region != 0) {
            DeleteObject(this->image_clip_region);
            this->image_clip_region = 0;
        }

        TDrawArea* image_buffer = this->ImageBuffer;
        if (image_buffer != 0) {
            delete image_buffer;
            this->ImageBuffer = 0;
        }

        image_buffer = new TDrawArea("message panel", 0);
        this->ImageBuffer = image_buffer;
        image_buffer->Init(*(void**)this->render_area, this->pnl_wid, this->pnl_hgt, 0, 0);
        this->LastIBWidth = this->pnl_wid;
        this->LastIBHeight = this->pnl_hgt;

        long right = this->pnl_wid - 1;
        long bottom = this->pnl_hgt - 1;
        this->ImageRect.left = 0;
        this->ImageRect.top = 0;
        this->ImageRect.right = right;
        this->ImageRect.bottom = bottom;
        this->image_clip_region = CreateRectRgn(0, 0, right, bottom);
    }

    if (this->ImageBuffer != 0) {
        this->UsedImageRect = this->ImageRect;
    } else {
        this->LastIBWidth = -1;
        this->LastIBHeight = -1;
    }

    this->need_restore = 1;
    this->redraw(1);
}
