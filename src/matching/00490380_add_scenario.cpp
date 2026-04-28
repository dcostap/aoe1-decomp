// VA: 00490380 TRIBE_Campaign_Editor_Screen::add_scenario()
// Source: scr_cam.cpp lines 463-477
// Size: 124 bytes, __thiscall

class TTextPanel {
public:
    char* get_text();
    int append_line(const char* text, int index);
    long get_line(const char* text);
    long get_line();
    void set_line(long line);
    long delete_line(long line);
};

class TListPanel : public TTextPanel {
public:
    void scroll_cur_line(unsigned char dir, int param2, int param3);
};

class TRIBE_Campaign_Editor_Screen {
public:
    char _gap_00[0x478];
    unsigned char need_to_save;  // +0x478
    char _gap_479[0x13];
    TTextPanel* scenarios;       // +0x48C
    TListPanel* campaign_scenarios; // +0x490

    void add_scenario();
};

void TRIBE_Campaign_Editor_Screen::add_scenario() {
    char* text = this->scenarios->get_text();

    if (text != 0 && *text != '\0') {
        this->campaign_scenarios->append_line(text, 0);

        long line = this->campaign_scenarios->get_line(text);
        this->campaign_scenarios->set_line(line);

        long line2 = this->scenarios->get_line();
        this->scenarios->delete_line(line2);

        this->campaign_scenarios->scroll_cur_line(1, this->campaign_scenarios->get_line(), 1);
    }

    this->need_to_save = 1;
}
