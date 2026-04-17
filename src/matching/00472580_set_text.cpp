class TButtonPanel {
public:
    int get_string(int string_id, char* buffer, int length);
    void set_text(short state, char* text1, char* text2);
    void set_text(short state, long string_id1, long string_id2);
};

void TButtonPanel::set_text(short state, long string_id1, long string_id2) {
    char str2[256];
    char str1[256];

    get_string(string_id1, str1, 0x100);
    get_string(string_id2, str2, 0x100);
    set_text(state, str1, str2);
}
