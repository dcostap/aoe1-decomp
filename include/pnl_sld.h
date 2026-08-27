#ifndef PNL_SLD_H
#define PNL_SLD_H

class TDrawArea;
class TPanel;
class TShape;

class TPanel {
public:
    virtual ~TPanel();

    char gap_04[0x0C - 0x04];
    long field_0C;
    long gap_10;
    long width;
    long height;
    char gap_1C[0xF4 - 0x1C];
};

class TScrollBarPanel : public TPanel {
public:
    TPanel* list_panel;
    long list_len;
    long one_step;
    long page_step;
    long list_num;
    TShape* button_pics;
    int back_frame;
    int up_frame;
    int down_frame;
    int tab_frame;
    char gap_11C[0x134 - 0x11C];
    long min_left;
    long min_right;
    long span;
    char gap_140[0x164 - 0x140];
    long left1;
    char gap_168[4];
    long left2;
    char gap_170[4];
    long right1;
    char gap_178[4];
    long right2;
    char gap_180[0x1C4 - 0x180];

    enum Orientation { Vertical = 0, Horizontal = 1 };

    virtual ~TScrollBarPanel();
    TScrollBarPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long,
               char*, char*, char*, char*, long, long, TPanel*, long,
               Orientation);
    virtual void set_rect(long, long, long, long);
    virtual void draw();
    void calc_item_rects();
};

class TVerticalSliderPanel : public TScrollBarPanel {
public:
    int drawBox;
    int spineWidth;

    virtual ~TVerticalSliderPanel();
    TVerticalSliderPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long,
               char*, char*, long, long, long, long, int, int);
    virtual void set_rect(long, long, long, long);
    virtual void draw();
};

class THorizontalSliderPanel : public TVerticalSliderPanel {
public:
    virtual ~THorizontalSliderPanel();
    THorizontalSliderPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long,
               char*, char*, long, long, long, long, int, int);
    virtual void set_rect(long, long, long, long);
    virtual void draw();
};

typedef char pnl_sld_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];
typedef char pnl_sld_scrollbar_size_check[(sizeof(TScrollBarPanel) == 0x1C4) ? 1 : -1];
typedef char pnl_sld_vertical_size_check[(sizeof(TVerticalSliderPanel) == 0x1CC) ? 1 : -1];
typedef char pnl_sld_horizontal_size_check[(sizeof(THorizontalSliderPanel) == 0x1CC) ? 1 : -1];

#endif
