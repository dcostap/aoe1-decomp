// 004A61A0 TRIBE_Screen_Disconnect::TRIBE_Screen_Disconnect
//
// Attempt log:
// - Earlier raw-wrapper scaffold had the right broad effects but no constructor
//   EH/vptr surface and an extra draw-area helper call.
// - Baseline candidate: natural TScreenPanel-derived constructor, named fields,
//   real panel member-call surfaces, and the proven rge_base_game draw_area.
// - Direct setup predicate removed the named result and recovered the exact
//   prologue/setup call sequence through the conditional (best codegen: 91
//   positional bytes, 219-byte rebuilt body, exact four-call set).
// - Shared-goto, arm-order, destructor-surface, qualified-call, virtuality, and
//   switch probes did not improve the remaining branch tail.
// - Final unresolved drift is structural: VC5 duplicates the normal EH cleanup
//   epilogue on the setup-failure path instead of the original short jump to the
//   shared epilogue. No call or field-ownership discrepancy remains.

class TPanel;
class TTextPanel;
class TButtonPanel;

class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    TEasy_Panel(char* name);

    char gap_04[0xD4];
    int field_D8;
    char gap_DC[0x39C];

    virtual void set_ideal_size(long width, long height);
    virtual int create_text(TPanel* parent, TTextPanel** out, char* text,
                            long x, long y, long width, long height,
                            long font, long align, long center, long wrap);
    int create_text(TPanel* parent, TTextPanel** out, long string_id,
                    long x, long y, long width, long height,
                    long font, long align, long center, long wrap);
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
    TScreenPanel(char* name);
    virtual long setup(void* draw_area, char* info, long id, int value);
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    void* draw_area;
};

extern RGE_Base_Game* rge_base_game;
extern char s_Multiplayer_Disconnect_Screen[];
extern char s_scr3[];

class TRIBE_Screen_Disconnect : public TScreenPanel {
public:
    int mode;
    TTextPanel* message;
    TButtonPanel* cancel_button;
    TButtonPanel* close_button;

    virtual ~TRIBE_Screen_Disconnect();
    TRIBE_Screen_Disconnect(int mode);
};

TRIBE_Screen_Disconnect::TRIBE_Screen_Disconnect(int mode)
    : TScreenPanel(s_Multiplayer_Disconnect_Screen)
{
    this->mode = mode;
    this->message = 0;
    this->cancel_button = 0;
    this->close_button = 0;

    if (this->setup(rge_base_game->draw_area, s_scr3, 0xC385, 0) == 0) {
        this->field_D8 = 1;
    } else {
        this->set_ideal_size(0x280, 0x1E0);
        this->create_text((TPanel*)this, &this->message, 0x4C0,
                          0x28, 0x28, 0x230, 0x190, 4, 1, 1, 1);
    }
}
