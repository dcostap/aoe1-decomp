// VA: 0049B830 TRIBE_Screen_Game::handle_anim_pal (212B)
// scr_game.cpp: period-plausible reconstruction from the executable layout.
// Attempt log:
// - Separate timestamp/palette locals matched behavior, frame, calls, and all
//   but the two stack-address bytes; the palette base was four bytes too late.
// - The executable proves that timestamp storage aliases unused palette entry
//   zero. Eight physical entries provide entry zero for the timestamp and
//   entries one through seven for the palette without out-of-bounds indexing.

struct tagPALETTEENTRY {
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

class TDrawSystem {
public:
    void ModifyPalette(int start, int count, tagPALETTEENTRY* entries);
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
};

extern unsigned long debug_timeGetTime(const char* file, int line);

union HandleAnimPalData {
    unsigned long time;
    tagPALETTEENTRY pal_entries[8];
};

struct HandleAnimPalLocals {
    HandleAnimPalData data;
};

class TRIBE_Screen_Game {
public:
    char gap_00[0x20];
    TDrawArea* render_area;
    char gap_24[0x66C];
    unsigned long anim_pal_interval;
    unsigned long last_anim_pal_time;
    short last_anim_pal_index;
    short last_anim_pal_index2;
    short last_anim_pal_index3;

    struct AnimPalEntry {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
    };

    AnimPalEntry anim_pal_table[7];

    void handle_anim_pal();
};

void TRIBE_Screen_Game::handle_anim_pal()
{
    HandleAnimPalLocals locals;

    locals.data.time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_game.cpp", 0x11EB);
    if (locals.data.time - this->last_anim_pal_time >= this->anim_pal_interval) {
        short index = this->last_anim_pal_index;

        for (int i = 0; i < 7; ++i) {
            locals.data.pal_entries[i + 1].peRed = this->anim_pal_table[index].red;
            locals.data.pal_entries[i + 1].peGreen = this->anim_pal_table[index].green;
            locals.data.pal_entries[i + 1].peBlue = this->anim_pal_table[index].blue;
            locals.data.pal_entries[i + 1].peFlags = 0;

            ++index;
            if (index == 7) {
                index = 0;
            }
        }

        if (this->last_anim_pal_index == 0) {
            this->last_anim_pal_index = 6;
        } else {
            --this->last_anim_pal_index;
        }

        this->render_area->DrawSystem->ModifyPalette(0xF8, 7, locals.data.pal_entries + 1);
        this->last_anim_pal_time = locals.data.time;
    }
}
