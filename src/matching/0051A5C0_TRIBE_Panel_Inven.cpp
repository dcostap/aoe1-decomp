// Constructor for TRIBE_Panel_Inven
// Calls TPanel base constructor (004648B0h), initializes fields,
// sets vftable, calls TPanel::setup (00464A80h), then either
// sets error flag at +0D8h or calls set_player.

extern "C" void __cdecl free(void* block);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" long __cdecl __ftol(void);

struct TDrawArea;
class TPanel;
class TRIBE_Player;

extern int TRIBE_Panel_Inven_vftable[];

class TPanel {
public:
    virtual ~TPanel();
    TPanel();
    int setup(TDrawArea* area, TPanel* parent, int p3, int p4, int p5, int p6, int p7);
    char gap_04[0xF0];
};

class TRIBE_Panel_Inven : public TPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int mode);
    // TRIBE_Panel_Inven fields at offset 0xF4+ (after TPanel's 0xF4 bytes)
    char gap_F4[0x04];          // +0F4h: pics (TShape*)
    TRIBE_Player* player;       // +0F8h
    short save_attr_num;        // +0FCh
    short gap_FE;
    short* save_attr;           // +100h
    int idle_time;              // +104h
    int idle_interval;          // +108h
    void* font;                 // +10Ch
    int font_color;             // +110h
    int back_color;             // +114h

    void save_info();
    void set_player(TRIBE_Player* player_);
    TRIBE_Panel_Inven(TDrawArea* area, TPanel* parent, void* font_, TRIBE_Player* player_);
};

TRIBE_Panel_Inven::TRIBE_Panel_Inven(TDrawArea* area, TPanel* parent, void* font_, TRIBE_Player* player_)
    : TPanel()
{
    TPanel* parent_arg = parent;
    void* font_arg = font_;
    this->font = font_arg;
    this->save_attr_num = 0;
    this->save_attr = 0;
    *(int*)((char*)this + 0xF4) = 0;  // pics
    this->idle_time = 0;
    this->player = 0;
    this->back_color = 0;
    *(int**)this = TRIBE_Panel_Inven_vftable;
    this->idle_interval = 500;
    this->font_color = 0xFFFFFF;
    if (((TPanel*)this)->setup(area, parent_arg, 0, 0, 0, 0, 0) == 0) {
        *(int*)((char*)this + 0xD8) = 1;
    } else {
        set_player(player_);
    }
}
