// tried direct get_string + base create_button wrapper; close, but the prolog still allocates 4 extra bytes
// tried 0x78 and 0x7C local buffers; the remaining mismatch is the initial stack setup / buffer base (+4)
// leaving this in scratch because the body is behaviorally right but the prolog basin is still off
class TPanel;
class TButtonPanel;

class TPanel {
public:
    int get_string(int string_id, char* buffer, int length);
};

class TEasy_Panel : public TPanel {
public:
    int create_button(TPanel* panel, TButtonPanel** button, char* text, long param_5, long param_6, long param_7);
};

class TRIBE_Screen_Sed : public TEasy_Panel {
public:
    int create_button(TPanel* panel, TButtonPanel** button, long string_id, int param_4);
};

int TRIBE_Screen_Sed::create_button(TPanel* panel, TButtonPanel** button, long string_id, int param_4) {
    char str1[0x74];

    ((TPanel*)this)->get_string(string_id, str1 + 4, 0x78);
    return this->TEasy_Panel::create_button(panel, button, str1 + 4, 0, 0, 0);
}
