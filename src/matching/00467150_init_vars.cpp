// attempt 2: direct TEasy_Panel default initialization in source-line order

class TEasy_Panel {
public:
    char gap_000[0xF4];
    long ideal_width;
    long ideal_height;
    char info_file_name[260];
    long info_id;
    void* background_pic;
    void* background_pic2;
    void* palette;
    char cursor_file[260];
    long cursor_id;
    long background_pos;
    long use_bevels;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    char gap_326[2];
    long text_color1;
    long text_color2;
    long focus_color1;
    long focus_color2;
    long state_color1;
    long state_color2;
    char popup_info_file_name[260];
    long popup_info_id;
    void* button_pics;
    void* shadow_color_table;
    long shadow_amount;
    unsigned char background_color1;
    unsigned char background_color2;
    char gap_456[2];
    long enable_ime;
    unsigned char help_mode;
    char gap_45D[3];
    long stock_brush;
    void* brush;
    long brush_color;
    void* shadow_area;
    char gap_470[4];
    long saved_mouse_mode;

    void init_vars();
};

void TEasy_Panel::init_vars() {
    this->ideal_width = 0x280;
    this->ideal_height = 0x1E0;
    this->info_file_name[0] = 0;
    this->info_id = -1;
    this->background_pic = 0;
    this->background_pic2 = 0;
    this->palette = 0;
    this->cursor_file[0] = 0;
    this->cursor_id = -1;
    this->background_pos = 0;
    this->use_bevels = 0;
    this->bevel_color1 = 0;
    this->bevel_color2 = 0;
    this->bevel_color3 = 0;
    this->bevel_color4 = 0;
    this->bevel_color5 = 0;
    this->bevel_color6 = 0;
    this->text_color1 = 0xFFFFFF;
    this->text_color2 = 0;
    this->focus_color1 = 0xFFFF;
    this->focus_color2 = 0;
    this->state_color1 = 0xFFFFFF;
    this->state_color2 = 0;
    this->popup_info_file_name[0] = 0;
    this->popup_info_id = -1;
    this->button_pics = 0;
    this->shadow_color_table = 0;
    this->background_color1 = 0;
    this->background_color2 = 0;
    this->enable_ime = 0;
    this->help_mode = 0;
    this->stock_brush = 0;
    this->brush = 0;
    this->brush_color = 0;
    this->shadow_amount = 0;
    this->shadow_area = 0;
    this->saved_mouse_mode = 0;
}
