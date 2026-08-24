#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    int insert_line(long line, char* text1, long value);
    int insert_line(long line, char* text1, char* text2, long value);
};
#endif

int TTextPanel::insert_line(long line, char* text1, long value) {
    return insert_line(line, text1, 0, value);
}
