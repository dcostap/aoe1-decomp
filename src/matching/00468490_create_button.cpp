// attempt 2: string-id wrapper that resolves two labels then delegates to the real virtual create_button slot

int TEasy_Panel::create_button(TPanel* parent, TButtonPanel** out, long id1, long id2, long p5, long p6, long p7, long p8, long p9, long p10, long p11) {
    char text2[120];
    char text1[120];

    this->get_string(id1, text1, 0x78);
    this->get_string(id2, text2, 0x78);
    return this->create_button(parent, out, text1, text2, p5, p6, p7, p8, p9, p10, p11);
}
