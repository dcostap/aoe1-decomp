#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    unsigned char gap_00[0x100];
    short cur_line;
    char* get_text(long line);
    char* get_text();
};
#endif

// BINARY NOTE: cur_line is a short at +0x100 and forwards to get_text(long).
char* TTextPanel::get_text() {
    return this->get_text(this->cur_line);
}
