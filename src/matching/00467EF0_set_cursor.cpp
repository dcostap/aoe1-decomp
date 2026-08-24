#include <string.h>

#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    char gap_00[0x210];
    char cursor_file[0x104];
    int cursor_id;

    int set_cursor(char* cursor_name, long cursor_id_value);
};
#endif

int TEasy_Panel::set_cursor(char* cursor_name, long cursor_id_value) {
    strcpy(this->cursor_file, cursor_name);
    this->cursor_id = cursor_id_value;
    return 1;
}
