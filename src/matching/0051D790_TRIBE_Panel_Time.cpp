class TDrawArea;
struct HRGN__;
typedef HRGN__* HRGN;

class RGE_Base_Game {
public:
    char gap_00[0x1E4];
    void* font_ptr;

    void* get_font(int index);
};

extern RGE_Base_Game* rge_base_game;

class TPanel {
public:
    virtual ~TPanel();
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int mode);

    char gap_00[0x10];
    long pnl_wid;
    long pnl_hgt;
    char gap_1C[0x4];
    TDrawArea* render_area;
    char gap_24[0x5C];
    int field_80;
    char gap_84[0x54];
    int field_D8;
    char gap_DC[0x18];

    TPanel();
    int setup(TDrawArea* area, TPanel* parent, long left, long top, long width, long height, int modal);
};

class TRIBE_Panel_Time : public TPanel {
public:
    void* font;
    int color1;
    int color2;
    int clock_type;
    int old_clock_type;
    int clock_format;
    int player_id;
    int field_110;
    void* world;
    void* player;
    int start_real_time;
    int current_display_value;
    int last_display_value;
    char gap_128[0x4];
    int field_12C;
    HRGN image_clip_region;
    TDrawArea* image_buffer;
    char gap_138[0x30];
    int image_text_active;
    long last_ib_width;
    long last_ib_height;

    TRIBE_Panel_Time(TDrawArea* draw_area, TPanel* parent);
};

TRIBE_Panel_Time::TRIBE_Panel_Time(TDrawArea* draw_area, TPanel* parent) : TPanel() {
    this->field_80 = 0;
    this->font = *(void**)rge_base_game->get_font(0xB);
    this->color1 = 0xFFFFFF;
    this->color2 = 0;
    this->clock_type = 0;
    this->clock_format = 0;
    this->old_clock_type = 0;
    this->player_id = 0;
    this->field_110 = 0;
    this->world = 0;
    this->player = 0;
    this->start_real_time = 0;
    this->current_display_value = 0;
    this->last_display_value = 0;
    this->field_12C = -1;
    this->image_buffer = 0;
    this->last_ib_width = -1;
    this->last_ib_height = -1;
    this->image_text_active = 0;
    this->image_clip_region = 0;
    if (!this->setup(draw_area, parent, 0, 0, 0, 0, 0)) {
        this->field_D8 = 1;
    }
}
