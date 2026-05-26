// TRIBE_Screen_Sed::activate_victory_panel
// VA: 004B29E0
// Retry 2026-05-26: real thiscall member with padded virtual surfaces.

#define V0(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3();
#define V4(p) virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
#define V8(p) V0(p) V4(p)

class PanelVis {
public:
    V0(a) virtual void a4();
    virtual void set_visible(int on); // slot 5, +0x14
    V8(b) V8(c) V8(d) V8(e) V8(f) V8(g)
    virtual void h0(); virtual void h1();
    virtual void set_state(int v); // slot 56, +0xE0
};

class TScenario { public: int GetSPVictoryType(int i); };

class TDropDownPanel : public PanelVis {
public:
    void set_line(int line);
    long get_line();
};

class TRIBE_Screen_Sed {
public:
    char gap_000[0x498];
    int CurrentVictory;
    char gap_49C[0x1C];
    short player_num;
    char gap_4BA[0x24A];
    PanelVis* victory_button[12];
    TDropDownPanel* victory_drop_down;
    char gap_738[4];
    TDropDownPanel* victory_player_list;
    char gap_740[0x1C];
    PanelVis* victory_condition_text;
    char gap_760[0x1C8];
    void* world;

    void activate_victory_panel(int flag);
};

void TRIBE_Screen_Sed::activate_victory_panel(int flag)
{
    int i = 0;
    register PanelVis** pp = this->victory_button;
    do {
        (*pp)->set_visible(flag);
        int val = ((((TScenario*)*(void**)((char*)this->world + 0x5C))->GetSPVictoryType(i) ? -1 : 0) & 2) + (this->CurrentVictory == i);
        if (flag) {
            (*pp)->set_state(val);
        }
        ++i;
        ++pp;
    } while (i < 12);

    this->victory_drop_down->set_visible(flag);
    this->victory_condition_text->set_visible(flag);
    this->victory_player_list->set_visible(flag);
    if (flag) {
        this->victory_player_list->set_line((int)this->player_num - 1);
    } else {
        this->player_num = (short)(this->victory_player_list->get_line() + 1);
    }
}
