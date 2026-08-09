// VA: 00520220 Time_Line_Panel::draw_civilization_names
// Attempt log:
// try 1: natural reconstruction from packet/Ghidra with GDI IAT function-pointer surface, game/world/player/history minimal layouts.
// try 2: initial source compiled exact-size 626 but broad drift: frame 0x148 vs original 0x144 and this kept in EBX instead of EBP.
// try 3: nested-control-flow form instead of early returns; still frame 0x148 and this kept in EBX.
// try 4: raw byte-offset player indexing for the population scan; reduced output to 624 bytes but did not recover original prologue/register allocation.
// try 5: raw byte-offset player indexing for the draw loop; same family, original wants EBX as player-array byte offset only after 00520333.
// try 6: /GX tested; no useful change, removed.
// try 7: /Od tested; exact size but completely wrong debug-basin codegen, removed.
// try 8: corrected RGE_Base_Game get_string virtual slot to +0x28; call surface now matches original vtable offset but size/register drift remains.
// try 9: kept GDI calls as extern function pointers to preserve indirect IAT call style.
// try 10: leaving in scratch: clean behavioral source was 624B vs 626B with immediate prologue/frame/register mismatch.
// try 11: corrected get_history_entry to its unsigned-char/long ABI; bytes were unchanged.
// try 12: added the period Windows/TPanel/TEasy_Panel surface and exact DrawDc ownership; size stayed 613B but the edit alignment improved.
// try 13: removed the cached second-loop player alias and restored the binary-proven repeated player-array reloads; exact 626B match.
// Exact: 626/626 bytes, 0 strict diff, exact frame/call/CFG/relocation identity.  The two named byte cursors are retained because the
// oracle has independent [players+offset] induction registers in both scans and the repeated player loads are observable; this is a
// period-plausible pointer-array traversal rather than an opaque address or register-forcing alias.

#include <windows.h>
#include <string.h>

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" {
__declspec(dllimport) COLORREF __stdcall SetTextColor(HDC, COLORREF);
__declspec(dllimport) int __stdcall SetBkMode(HDC, int);
__declspec(dllimport) HGDIOBJ __stdcall SelectObject(HDC, HGDIOBJ);
__declspec(dllimport) int __stdcall TextOutA(HDC, int, int, LPCSTR, int);
}

class TRIBE_History_Info {
public:
    unsigned char get_history_entry(unsigned char mode, long index);
};
class RGE_Player { public: char gap_00[0x44]; char* name; char gap_48[0xBD]; unsigned char civilization; char gap_106[0x736]; TRIBE_History_Info* history; };
class RGE_Game_World { public: virtual unsigned char data_load_world(void*); char gap_04[0x38]; short player_num; char gap_3E[2]; RGE_Player** players; };
class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void setup(); virtual void shutdown(); virtual void idle(); virtual void set_paused();
    virtual void vf14(); virtual void vf18(); virtual void vf1C(); virtual void vf20(); virtual void vf24();
    virtual void language(int, int, int, char*, int);
    char gap_04[0x3F0];
    RGE_Game_World* world;
};
extern RGE_Base_Game* rge_base_game;

class TDrawArea {
public:
    char gap_00[0x38];
    HDC DrawDc;
    void* GetDc(const char*);
    void ReleaseDc(const char*);
};

class TPanel {
public:
    virtual ~TPanel();
    virtual void setup();
    virtual void set_rect_1();
    virtual long set_rect_2();
    virtual void set_color();
    virtual void set_active();
    virtual void set_positioning();
    virtual void set_fixed_position();
    virtual void set_redraw(int);
    virtual long set_overlapped_redraw();
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void get_clip_rect(RECT*);

    char gap_04[8];
    long pnl_x;
    long pnl_y;
    char gap_14[0x0C];
    TDrawArea* render_area;
    RECT clip_rect;
    char gap_34[0x0C];
    TPanel* parent_panel;
    char gap_44[0x28];
    int active;
    int visible;
    char gap_74[0x80];
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
};

class Time_Line_Panel : public TEasy_Panel {
public:
    char gap_478[0x0C];
    HGDIOBJ body_font;
    char gap_488[4];
    int body_font_hgt;
    char gap_490[0x4C];
    int X_start_line_pos;
    int Y_start_line_pos;
    char gap_4E4[0x0C];
    int y_line_hgt;
    char gap_4F4[0x28];
    char timeline_flag;

    void draw_civilization_names();
};

void Time_Line_Panel::draw_civilization_names()
{
    char temp_str[100];
    char civ_str[100];
    char name_str[100];
    HGDIOBJ old_font;
    int X_line_pos;
    int Y_line_pos;
    int y_line_segment_length;
    float pop_total;

    if (this->timeline_flag != 0) {
        SetTextColor(this->render_area->DrawDc, 0);
        if (this->render_area->GetDc("tpnl_tml::draw_civilization_names") != 0) {
            SetBkMode(this->render_area->DrawDc, 1);
            old_font = SelectObject(this->render_area->DrawDc, this->body_font);
            pop_total = 0.0f;
            int i = 0;
            if (rge_base_game->world->player_num - 1 > 0) {
                int off = 4;
                do {
                    pop_total += (float)((*(RGE_Player**)((char*)rge_base_game->world->players + off))->history->get_history_entry(0,0) & 0xff);
                    i++;
                    off += 4;
                } while (i < rge_base_game->world->player_num - 1);
            }
            if (pop_total != 0.0f) {
                X_line_pos = this->X_start_line_pos + 3;
                Y_line_pos = this->Y_start_line_pos;
                if (rge_base_game->world->player_num - 1 > 0) {
                    y_line_segment_length = 0;
                    int off2 = 4;
                    do {
                        int seg = (int)(((float)((*(RGE_Player**)((char*)rge_base_game->world->players + off2))->history->get_history_entry(0,0) & 0xff) / pop_total) * (float)this->y_line_hgt);
                        rge_base_game->language(0x69, (*(RGE_Player**)((char*)rge_base_game->world->players + off2))->civilization, 0, civ_str, 100);
                        strcpy(name_str, (*(RGE_Player**)((char*)rge_base_game->world->players + off2))->name);
                        sprintf(temp_str, "%s - %s", name_str, civ_str);
                TextOutA(this->render_area->DrawDc, X_line_pos, Y_line_pos + (seg / 2 - this->body_font_hgt / 2), temp_str, strlen(temp_str));
                        Y_line_pos += seg;
                        off2 += 4;
                        y_line_segment_length++;
                    } while (y_line_segment_length < rge_base_game->world->player_num - 1);
                }
                SelectObject(this->render_area->DrawDc, old_font);
                this->render_area->ReleaseDc("tpnl_tml::draw_civilization_names");
            }
        }
    }
}
