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
// try 10: leaving in scratch: clean behavioral source is 624B vs 626B with immediate prologue/frame/register mismatch, so not accepted_drift-safe.

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" char* __cdecl strcpy(char*, const char*);
extern "C" unsigned int __cdecl strlen(const char*);

typedef void* HDC;
typedef void* HGDIOBJ;
typedef unsigned int COLORREF;
extern "C" COLORREF (__stdcall* const SetTextColor)(HDC, COLORREF);
extern "C" int (__stdcall* const SetBkMode)(HDC, int);
extern "C" HGDIOBJ (__stdcall* const SelectObject)(HDC, HGDIOBJ);
extern "C" int (__stdcall* const TextOutA)(HDC, int, int, const char*, int);

class TRIBE_History_Info { public: unsigned char get_history_entry(char, int); };
class RGE_Player { public: char gap_00[0x44]; char* name; char gap_48[0xBD]; unsigned char civilization; char gap_106[0x736]; TRIBE_History_Info* history; };
class RGE_Game_World { public: char gap_00[0x3C]; short player_num; char gap_3E[2]; RGE_Player** players; };
class RGE_Base_Game {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10();
    virtual void vf14(); virtual void vf18(); virtual void vf1C(); virtual void vf20(); virtual void vf24();
    virtual void get_string(int, int, int, char*, int);
    char gap_04[0x3F0];
    RGE_Game_World* world;
};
extern RGE_Base_Game* rge_base_game;

class TDrawArea {
public:
    char gap_00[0x38];
    HDC hdc;
    void* GetDc(char*);
    void ReleaseDc(char*);
};

class Time_Line_Panel {
public:
    char gap_000[0x20];
    TDrawArea* draw_area;
    char gap_024[0x460];
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
        SetTextColor(this->draw_area->hdc, 0);
        if (this->draw_area->GetDc((char*)0x58B7FC) != 0) {
            SetBkMode(this->draw_area->hdc, 1);
            old_font = SelectObject(this->draw_area->hdc, this->body_font);
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
                        RGE_Player* p = *(RGE_Player**)((char*)rge_base_game->world->players + off2);
                        int seg = (int)(((float)(p->history->get_history_entry(0,0) & 0xff) / pop_total) * (float)this->y_line_hgt);
                        rge_base_game->get_string(0x69, p->civilization, 0, civ_str, 100);
                        strcpy(name_str, (*(RGE_Player**)((char*)rge_base_game->world->players + off2))->name);
                        sprintf(temp_str, (char*)0x58B7F4, name_str, civ_str);
                        TextOutA(this->draw_area->hdc, X_line_pos, Y_line_pos + (seg / 2 - this->body_font_hgt / 2), temp_str, strlen(temp_str));
                        Y_line_pos += seg;
                        off2 += 4;
                        y_line_segment_length++;
                    } while (y_line_segment_length < rge_base_game->world->player_num - 1);
                }
                SelectObject(this->draw_area->hdc, old_font);
                this->draw_area->ReleaseDc((char*)0x58B7FC);
            }
        }
    }
}
