// 00490400 TRIBE_Campaign_Editor_Screen::remove_scenario
// Source: scr_cam.cpp lines 483-497. 124 bytes. __thiscall.
//
// MATCHED. Exact 124-byte match confirmed via local check_function.py.
// Key insight: nesting get_line() as middle arg of scroll_cur_line(1,
// (short)get_line(), 1) forces VC5's right-to-left arg eval to produce
// the original's deferred push scheduling (push 1, call get_line, push
// result, push 1).

class TTextPanel {
public:
    char* get_text();
    int append_line(char* text, int a2);
    long get_line(char* text);
    void set_line(long line);
    long get_line();
    int delete_line(long line);
};

class TListPanel : public TTextPanel {
public:
    void scroll_cur_line(int a1, short a2, int a3);
};

class TRIBE_Campaign_Editor_Screen {
public:
    char gap_00[0x478];
    unsigned char need_to_save;  // at +0x478
    char gap_479[0x13];          // up to +0x48C
    TListPanel* scenarios;       // +0x48C
    TListPanel* campaign_scenarios; // +0x490

    void remove_scenario();
};

void TRIBE_Campaign_Editor_Screen::remove_scenario() {
    char* text = this->campaign_scenarios->get_text();
    if (text != 0 && text[0] != 0) {
        this->scenarios->append_line(text, 0);
        long line = this->scenarios->get_line(text);
        this->scenarios->set_line(line);
        line = this->campaign_scenarios->get_line();
        this->campaign_scenarios->delete_line(line);
        this->scenarios->scroll_cur_line(1, (short)this->scenarios->get_line(), 1);
    }
    this->need_to_save = 1;
}
