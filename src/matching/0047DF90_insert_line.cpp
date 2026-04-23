class TTextPanel {
public:
    int get_string(int string_id, char* buffer, int length);
    int insert_line(long line, char* text, long value);
};

int TTextPanel::insert_line(long line, char* text, long value)
{
    char str[256];

    get_string((int)text, str, 0x100);
    return insert_line(line, str, value);
}
