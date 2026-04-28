// 00490480 TRIBE_Campaign_Editor_Screen::move_scenario_up
// Size: 153 bytes

class TTextPanel {
public:
    char gap_00[0xF8];
    short num_lines;              // +0xF8
    char gap_FA[6];
    short cur_line;               // +0x100

    long get_line();
    char* get_text();
    void insert_line(long line, char* text, long value);
    void delete_line(long line);
    void set_line(long line);
};

class TListPanel {
public:
    char gap_00[0xF8];
    short num_lines;              // +0xF8
    char gap_FA[2];
    short scroll_top;             // +0xFC
    short scroll_bottom;          // +0xFE
    short cur_line;               // +0x100

    void scroll_cur_line(unsigned char scroll_type, short line, int flag);
};

class TRIBE_Campaign_Editor_Screen {
public:
    char gap_00[0x478];
    char need_to_save;                         // +0x478
    char gap_479[0x17];
    TTextPanel* campaign_scenarios;            // +0x490

    void move_scenario_up();
};

void TRIBE_Campaign_Editor_Screen::move_scenario_up() {
    if (this->campaign_scenarios->get_line() <= 0) {
        return;
    }

    char* text = this->campaign_scenarios->get_text();
    if (text != 0 && text[0] != 0) {
        this->campaign_scenarios->insert_line(
            this->campaign_scenarios->get_line() - 1, text, 0);

        this->campaign_scenarios->delete_line(
            this->campaign_scenarios->get_line() + 1);

        this->campaign_scenarios->set_line(
            this->campaign_scenarios->get_line() - 1);

        ((TListPanel*)this->campaign_scenarios)->scroll_cur_line(
            1, (short)this->campaign_scenarios->get_line(), 1);
    }

    this->need_to_save = 1;
}
