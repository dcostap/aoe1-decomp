#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    int get_string(int string_id, char* buffer, int length);
    int insert_line(long line, long text, long value);
};
#endif

int TTextPanel::insert_line(long line, long text, long value)
{
    char str[256];

    get_string((int)text, str, 0x100);
    return insert_line(line, str, value);
}
