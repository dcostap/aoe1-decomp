#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    int get_string(int string_id, char* buffer, int length);
    void set_text(short state, char* text);
    void set_text(short state, long string_id);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::set_text(short state, long string_id) {
    char str[256];

    get_string(string_id, str, 0x100);
    set_text(state, str);
}
