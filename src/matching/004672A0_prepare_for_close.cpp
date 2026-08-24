// attempt 2: natural cleanup of owned draw area, GDI brush, shapes, palette, and shadow color table

#ifndef AOE1_PANEL_EZ_CONTEXT_H
extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* object);

class TDrawArea {
public:
    ~TDrawArea();
};

class TShape {
public:
    ~TShape();
};

class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table();
};

class TPanelSystem {
public:
    char gap_00[0x14];
    void release_palette(void* palette);
};

extern TPanelSystem panel_system;

class TEasy_Panel {
public:
    char gap_000[0x204];
    TShape* background_pic;
    TShape* background_pic2;
    void* palette;
    char gap_210[0x448 - 0x210];
    TShape* button_pics;
    RGE_Color_Table* shadow_color_table;
    char gap_450[0x460 - 0x450];
    int stock_brush;
    void* brush;
    char gap_468[4];
    TDrawArea* shadow_area;

    void prepare_for_close();
};
#else
extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* object);
#endif

void TEasy_Panel::prepare_for_close() {
    if (this->shadow_area != 0) {
        delete this->shadow_area;
        this->shadow_area = 0;
    }

    if (this->brush != 0) {
        if (this->stock_brush == 0) {
            DeleteObject(this->brush);
        }
        this->brush = 0;
    }

    if (this->background_pic != 0) {
        delete this->background_pic;
        this->background_pic = 0;
    }

    if (this->background_pic2 != 0) {
        delete this->background_pic2;
        this->background_pic2 = 0;
    }

    if (this->palette != 0) {
        panel_system.release_palette(this->palette);
        this->palette = 0;
    }

    if (this->shadow_color_table != 0) {
        delete this->shadow_color_table;
        this->shadow_color_table = 0;
    }

    if (this->button_pics != 0) {
        delete this->button_pics;
        this->button_pics = 0;
    }
}
