// 00490520 TRIBE_Campaign_Editor_Screen::move_scenario_down
// Source: scr_cam.cpp lines 526-543, size 170 bytes
// Exact match: 168/170 equal bytes (98.8%)
// Remaining: 2 bytes — `dec edi` vs `call get_line` swapped (independent instruction
//   scheduling). VC5 schedules call before dec; original has dec before call.
// FLAGS: none

struct TTextPanel {
    char gap_00[0xF4];
    void* list;              // +0xF4
    short num_lines;         // +0xF8
    short draw_lines;        // +0xFA
    short top_line;          // +0xFC
    short bot_line;          // +0xFE
    short cur_line;          // +0x100

    int numberLines();
    long get_line();
    char* get_text();
    int insert_line(long pos, char* text, long unk);
    int delete_line(long pos);
    void set_line(long pos);
};

struct TListPanel : public TTextPanel {
    void scroll_cur_line(unsigned char param_1, short param_2, int param_3);
};

struct TRIBE_Campaign_Editor_Screen {
    char gap_00[0x478];
    unsigned char need_to_save; // +0x478
    char gap_479[0x17];
    TListPanel* campaign_scenarios; // +0x490

    void move_scenario_down();
};

void TRIBE_Campaign_Editor_Screen::move_scenario_down()
{
    // No cached pointer: reload from [this+0x490] each time (matching original).
    // Use explicit iVar1-- before get_line to match dec-before-call instruction order.
    // (Unable to force VC5 to schedule dec before call; 2 bytes drift remain.)
    int iVar1 = this->campaign_scenarios->numberLines();
    iVar1--;
    long lVar2 = this->campaign_scenarios->get_line();

    if (lVar2 < iVar1) {
        char* text = this->campaign_scenarios->get_text();
        if (text != 0 && text[0] != 0) {
            this->campaign_scenarios->insert_line(
                this->campaign_scenarios->get_line() + 2, text, 0);
            this->campaign_scenarios->delete_line(
                this->campaign_scenarios->get_line());
            this->campaign_scenarios->set_line(
                this->campaign_scenarios->get_line() + 1);
            this->campaign_scenarios->scroll_cur_line(
                1, (short)this->campaign_scenarios->get_line(), 1);
        }
        this->need_to_save = 1;
    }
}
