// TScrollTextPanel::TScrollTextPanel
// VA: 00492E70
//
// Clean baseline: the constructor is a normal derived TTextPanel constructor.
// The base size and the four derived fields are binary-proven; the optional
// setup arguments are the period API's zero/default surface.
//
// Attempt log:
// - natural base-constructor/member-init reconstruction: MATCH (211/211).
// FLAGS: config/flags/00492E70_TScrollTextPanel.rsp retains /GX for the
// original EH registration frame.

class TPanel;
class TDrawArea;

class TTextPanel {
public:
    TTextPanel();
    virtual ~TTextPanel();
    virtual void set_text(char* text);

    char gap_04[0x11C];
    unsigned long text_color1; // +0x120
    unsigned long text_color2; // +0x124
    char gap_128[0x60];

    long setup(TDrawArea* draw_area, TPanel* parent, long x, long y,
               long width, long height, void* font, long font_wid,
               long font_hgt, char* back_pic, char* fill_back,
               int back_color, int outline, unsigned char outline_color,
               short fixed_len, char* text);
    void set_alignment(int vertical, int horizontal);
    void set_word_wrap(int value);
    void set_text_color(unsigned long color1, unsigned long color2);
};

class TScrollTextPanel : public TTextPanel {
public:
    virtual ~TScrollTextPanel();

    int scroll;             // +0x188
    unsigned long last_time; // +0x18C
    int speed;              // +0x190
    int done;               // +0x194

    TScrollTextPanel(TPanel* parent, TDrawArea* draw_area, long x, long y,
                     long width, long height, int speed_value, void* font,
                     long font_wid, long font_hgt, char* text);
    virtual void set_text(char* text);
};

TScrollTextPanel::TScrollTextPanel(TPanel* parent, TDrawArea* draw_area,
                                   long x, long y, long width, long height,
                                   int speed_value, void* font, long font_wid,
                                   long font_hgt, char* text)
    : TTextPanel()
{
    this->speed = speed_value;
    this->scroll = 0;
    this->last_time = 0;
    this->done = 0;

    if (this->setup(draw_area, parent, x, y, width, height, font, font_wid,
                    font_hgt, 0, 0, 0, 0, 0, 0, 0) != 0) {
        this->set_alignment(3, 0);
        this->set_word_wrap(1);
        this->set_text(text);
        this->set_text_color(this->text_color1, this->text_color2);
    }
}
