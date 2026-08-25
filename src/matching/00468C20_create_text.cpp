// attempt 2: string-id wrapper that resolves text then delegates to the real virtual create_text slot

int TEasy_Panel::create_text(TPanel* parent, TTextPanel** out, int string_id, long p4, long p5, long p6, long p7, long p8, int p9, int p10, int p11) {
    char text[256];

    this->get_string(string_id, text, 0x100);
    return this->create_text(parent, out, text, p4, p5, p6, p7, p8, p9, p10, p11);
}
