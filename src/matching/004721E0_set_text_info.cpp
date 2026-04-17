class TButtonPanel {
public:
    void set_text_pos(long x, long y);
    void set_text(short state, long string_id);
    void set_font(void* font, long width, long height);
    void set_text_info(long string_id, void* font, long width, long height, long x, long y);
};

void TButtonPanel::set_text_info(long string_id, void* font, long width, long height, long x, long y) {
    set_text_pos(x, y);
    set_text(0, string_id);
    set_font(font, width, height);
}
