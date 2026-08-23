// VA: 00490520 TRIBE_Campaign_Editor_Screen::move_scenario_down
// Source: scr_cam.cpp lines 526-543
// Exact-finish note: initialize the bound with `numberLines() - 1`.
// This makes VC5 emit the decrement before the later get_line call.

#include "../../include/scr_cam_context.h"

#if 0
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
#endif

void TRIBE_Campaign_Editor_Screen::move_scenario_down()
{
    // No cached pointer: reload from [this+0x490] each time (matching original).
    int iVar1 = this->campaign_scenarios->numberLines() - 1;
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
                (unsigned char)1, (short)this->campaign_scenarios->get_line(), 1);
        }
        this->need_to_save = 1;
    }
}
