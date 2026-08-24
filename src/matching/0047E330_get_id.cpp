#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    unsigned char gap_00[0x100];
    short cur_line;
    long get_id(long line);
    long get_id();
};
#endif

// BINARY NOTE: cur_line is a short at +0x100 and forwards to get_id(long).
long TTextPanel::get_id() {
    return this->get_id(this->cur_line);
}
