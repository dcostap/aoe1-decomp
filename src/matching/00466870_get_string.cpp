extern char DAT_0062E670[0x200];

#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:
    int get_string(int string_id, char* buffer, int length);
    char* get_string(int string_id);
};

#endif
char* TPanel::get_string(int string_id) {
    get_string(string_id, DAT_0062E670, 0x200);
    return DAT_0062E670;
}
