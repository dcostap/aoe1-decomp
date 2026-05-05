// attempt 2: natural allocating THelpDialog overload when non-empty text is supplied

class THelpDialog {
public:
    char data[0x5A4];
    THelpDialog(void* owner, char* title, char* text, long a, long b, long c);
};

class TEasy_Panel {
public:
    void command_help(char* title, char* text, long a, long b, long c);
};

void TEasy_Panel::command_help(char* title, char* text, long a, long b, long c) {
    if (text != 0 && *text != 0) {
        new THelpDialog(this, title, text, a, b, c);
    }
}
