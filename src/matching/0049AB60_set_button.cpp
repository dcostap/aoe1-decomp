// VA: 0049AB60 set_button (475B)
// scr_game.cpp lines 4120-4186.
//
// Baseline reconstruction: named screen/button ownership, the period panel and
// game/player-style UI ABI, the button refresh sequence, and the localized
// command-hotkey switch.  The original executable is authoritative; the
// decompiler's raw offsets are retained only as layout evidence.
//
// Attempt log (orch-scrgame-fresh-03):
// - baseline: named UI/game ABI and natural refresh body reached exact size,
//   frame, 13-call order, and 229 differing bytes.
// - explicit nonnull/else text-message arms restored the oracle's shared-call
//   tail (17 differing bytes).
// - the decompiler's text1+4 stack spelling was replaced by the natural local
//   buffer base, leaving 14 differing bytes in the hotkey dispatch only.
// - PDB line order, rather than numeric decompiler case order, restored the
//   original hotkey handler layout; the default flags now match exactly.

#if !defined(SCR_GAME_TU_CONTEXT)
class TShape;
class TDrawArea;
class TDigital;

class TPanel {
public:
    virtual ~TPanel();
    virtual long vf04();
    virtual long vf08();
    virtual long vf0C();
    virtual long vf10();
    virtual void set_active(int active);

    char gap_04[0xF0];

    char* get_string(int id);
    void set_help_info(long help_id, long page_id);
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
    char gap_F4[0x1A4];
    long hotkey;
    int hotkey_shift;
    char gap_2A0[0x10];
    int disabled;
    int sound_number;

    void set_disabled(int disabled_value);
    long get_id();
    long get_id2();
    void reset();
    void set_picture(short state, TShape* picture, short frame);
    void set_id(short state, long id, long id2);
    void set_text(short state, char* text1, char* text2);
};

class TRIBE_Panel_Button : public TButtonPanel {
public:
    int display_garrison;
    int garrsion_number;
    unsigned char tribe_button_type;
    unsigned char gap_2C1[3];
    TShape* border_pic;
    unsigned char* color_table;
    int border_frame;
    char text_msg[0x100];
    int in_use;

    void set_display_garrison(int value);
    void set_text_msg(char* text);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void set_game_mode(int mode, int value);
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual char* get_string2(int id, int value1, int value2,
                              char* buffer, int length);
};

extern RGE_Base_Game* rge_base_game;

class TScreenPanel : public TPanel {
public:
    char gap_0F4[0x384];
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    char gap_478[0x50];
    TRIBE_Panel_Button* button_panel[17];

    void set_button(TShape* picture, short index, short frame,
                    long id, long id2, long string_id, long help_page_id,
                    long hotkey_id, unsigned char* color_table,
                    char* name, char* text, int disabled_value);
};
#endif

void TRIBE_Screen_Game::set_button(
    TShape* picture, short index, short frame,
    long id, long id2, long string_id, long help_page_id,
    long hotkey_id, unsigned char* color_table,
    char* name, char* text, int disabled_value) {
    char text1[512];
    TRIBE_Panel_Button* button = this->button_panel[index];

    button->in_use = 1;
    if (button->disabled != disabled_value) {
        button->set_disabled(disabled_value);
    }

    if (button->get_id() != id || button->get_id2() != id2) {
        button->reset();
        button->set_display_garrison(0);
        rge_base_game->get_string2(0x66, id, id2, text1, 0x200);
        button->set_picture(0, picture, frame);
        button->set_id(0, id, id2);
        button->color_table = color_table;
        button->set_text(0, text1, name);
        button->set_help_info(string_id, help_page_id);

        if (text != 0) {
            button->set_text_msg(text);
        } else {
            button->set_text_msg(text1);
        }

        if (id == 0x11) {
            button->border_frame = 2;
        } else {
            button->border_frame = 0;
        }

        switch (id) {
        case 3:
            hotkey_id = 0x1037;
            break;
        case 5:
            hotkey_id = 0x1038;
            break;
        case 8:
            hotkey_id = 0x1039;
            break;
        case 9:
            hotkey_id = 0x103A;
            break;
        case 0x0C:
            hotkey_id = 0x103B;
            break;
        case 0x16:
            hotkey_id = 0x103D;
            break;
        case 0x17:
            hotkey_id = 0x103E;
            break;
        case 0x1C:
            hotkey_id = 0x1048;
            break;
        case 0x1D:
            hotkey_id = 0x1049;
            break;
        case 1:
            hotkey_id = 0x104B;
            break;
        case 2:
            hotkey_id = 0x104A;
            break;
        case 0x1E:
            hotkey_id = 0x104C;
            break;
        case 0x1F:
            hotkey_id = 0x104D;
            break;
        case 7:
            hotkey_id = 0x104E;
            break;
        }

        if (hotkey_id != 0) {
            hotkey_id = (int)*this->get_string(hotkey_id);
        }
        if (id == 6 || id == 0x0B) {
            hotkey_id = 0x1B;
        }

        button->hotkey = hotkey_id;
        button->hotkey_shift = 0;
        button->set_active(1);
    }
}
