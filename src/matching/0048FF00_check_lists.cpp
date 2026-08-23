// VA: 0048FF00 | TRIBE_Campaign_Editor_Screen::check_lists() | scr_cam.cpp:323-336 | 117 bytes
//
// Attempt log:
// [1] First attempt.

#include "../../include/game_types.h"

#include "../../include/scr_cam_context.h"

#if 0

// TTextPanel from Pnl_txt.cpp with methods used in this function
class TTextPanel {
public:
    int numberLines();
    char* get_text(int index);
    long get_line(char* text);
    int delete_line(long index);
};

class TRIBE_Campaign_Editor_Screen {
public:
    char _gap_00[0x48C];
    TTextPanel* scenarios;           // +0x48C
    TTextPanel* campaign_scenarios;  // +0x490

    unsigned char check_lists();
};
#endif

unsigned char TRIBE_Campaign_Editor_Screen::check_lists() {
    int count = campaign_scenarios->numberLines();

    for (int i = 0; i < count; i++) {
        char* text = campaign_scenarios->get_text(i);
        if (scenarios->get_line(text) == -1) {
            return 0;
        }
    }

    {
        for (int i = 0; i < count; i++) {
            char* text = campaign_scenarios->get_text(i);
            long index = scenarios->get_line(text);
            scenarios->delete_line(index);
        }
    }

    return 1;
}
