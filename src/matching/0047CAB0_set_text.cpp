#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    char gap_00[0x138];
    short fixed_len;

    void free_text();
    void append_line(const char* text, int p2);
    void set_text(char** texts, short count);
};
#endif

void TTextPanel::set_text(char** texts, short count) {
    free_text();
    if (count == 0) {
        if (fixed_len != 0) {
            append_line("", 0);
        }
    }
    else if (count > 0) {
        int i = count;
        do {
            append_line(texts[0], 0);
            texts++;
            i--;
        } while (i != 0);
    }
}
