// attempt 2: natural allocating THelpDialog overload after resolving string id

#ifndef AOE1_PANEL_EZ_CONTEXT_H
class THelpDialog {
public:
    char data[0x5A4];
    THelpDialog(void* owner, char* title, long string_id, long a, long b, long c);
};

class TEasy_Panel {
public:
    char* get_string(long id);
    void command_help(char* title, long string_id, long a, long b, long c);
};
#endif

void TEasy_Panel::command_help(char* title, long string_id, long a, long b, long c) {
    if (string_id >= 0) {
        char* text = this->get_string(string_id);
        if (text || *text != 0) {
            new THelpDialog(this, title, string_id, a, b, c);
        }
    }
}
